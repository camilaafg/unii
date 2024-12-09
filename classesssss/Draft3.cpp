#include "Draft3.h"
#include "ui/CocosGUI.h"
#include "../proj.win32/Armar.h"
#include "../proj.win32/Jugadores.h"
#include "../proj.win32/Datos.h"
#include "../proj.win32/Resultados.h"
#include "HelloWorldScene.h"

using namespace std;
using namespace cocos2d::ui;

USING_NS_CC;


Scene* Draft3::createScene()
{
    return Draft3::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

//vector<tuple<string, int, int, int, int, int, int, string, string, string, int, string, int, int, int, string, int>> alineacionUsuario;
vector<tuple<string, int, int, int, int, int, int, string, string, string, int, string, int, int, int, string, int>> alineacionIA;

// Función para calcular el rating total de un equipo
int calcularRatingEquipo(const vector<tuple<string, int, int, int, int, int, int, string, string, string, int, string, int, int, int, string, int>>& equipo) {
    int totalRating = 0;
    for (const auto& jugador : equipo) {
        totalRating += get<10>(jugador); // Índice del rating
    }
    return totalRating;
}

// on "init" you need to initialize your instance
bool Draft3::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    AudioEngine::play2d("silbato.mp3");
    this->setVisible(true);
    auto visibleSize = Director::getInstance()->getVisibleSize(); //tamano ventana
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto mySprite0 = Sprite::create("estadio.png");
    mySprite0->setPosition(Point((visibleSize.width / 2), visibleSize.height / 2));
    this->addChild(mySprite0, 0);

    auto alineacionUsuario = DatosGlobales::alineacionUsuario;

    auto jugarButton = ui::Button::create("play.png");
    if (jugarButton) {
        jugarButton->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2 - 100));
        jugarButton->setScale(1);

        jugarButton->addClickEventListener([this, alineacionUsuario](Ref* sender) {
            // alineación aleatoria para la IA
            alineacionIA.clear();
            for (const string& posicion : { "Portero", "Defensa", "Medio", "Delantero" }) {
                auto rango = JugadoresGlobales::jugadores.equal_range(posicion);

                vector<tuple<string, int, int, int, int, int, int, string, string, string, int, string, int, int, int, string, int>> candidatos;
                for (auto it = rango.first; it != rango.second; ++it) {
                    candidatos.push_back(it->second);
                }

                int cantidad = (posicion == "Portero") ? 1 : (posicion == "Defensa") ? 4 :
                    (posicion == "Medio") ? 4 : 2;
                for (int i = 0; i < min(cantidad, (int)candidatos.size()); ++i) {
                    int indiceAleatorio = rand() % candidatos.size();
                    alineacionIA.push_back(candidatos[indiceAleatorio]);
                    candidatos.erase(candidatos.begin() + indiceAleatorio);
                }
            }

            eventos.clear(); 
            for (int i = 0; i < 10; ++i) { 
                bool esUsuario = rand() % 2;
                const auto& equipo = esUsuario ? alineacionUsuario : alineacionIA;
                int jugadorIndex = rand() % equipo.size();
                const auto& jugador = equipo[jugadorIndex];

                string nombre = get<0>(jugador);
                string evento = esUsuario ? "jugo el balon muy bien" : "metio la pata";

                eventos.push_back(nombre + " " + evento);
            }

            eventoIndex = 0; // Reinicia índice de los eventos
            auto eventosLabel = Label::createWithTTF("", "fonts/Walk with me now.ttf", 70);
            eventosLabel->setPosition(Point(850, 500));
            eventosLabel->setColor(Color3B::MAGENTA);
            this->addChild(eventosLabel, 10);

            this->schedule([this, eventosLabel](float) {
                if (eventoIndex < eventos.size()) {

                    eventosLabel->setString(eventos[eventoIndex]);
                    eventoIndex++;
                }
                else {
                    this->unschedule("simulacion_eventos");

                    int ratingUsuario = calcularRatingEquipo(DatosGlobales::alineacionUsuario);
                    int ratingIA = calcularRatingEquipo(alineacionIA);

                    string resultado = (ratingUsuario > ratingIA) ? "Ganaste" :
                        (ratingUsuario < ratingIA) ? "Perdiste" : "Empate";

                    auto resultadoScene = Resultados::createScene(resultado, ratingUsuario, ratingIA);
        
                        Director::getInstance()->replaceScene(resultadoScene);
                    
                    
                }
                }, 1.0f, "simulacion_eventos");
            });


        this->addChild(jugarButton);
    }
    return true;
}

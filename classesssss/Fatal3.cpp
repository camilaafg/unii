#include "Fatal3.h"
#include "Datos.h"
#include "ui/CocosGUI.h"
#include "../proj.win32/Jugadores.h"
#include "Resultados.h"
using namespace std;

USING_NS_CC;


Scene* Fatal3::createScene()
{
    return Fatal3::create();
}

bool Fatal3::init()
{
    if (!Scene::init())
        return false;

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Fondo
    auto background = Sprite::create("estadio.png");
    background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    this->addChild(background);

    // Inicializar alineaciones
    alineacionUsuario = DatosGlobales::alineacionUsuario;
    generarAlineacionIA();

    // Etiquetas
    labelRonda = Label::createWithTTF("Ronda 1/3", "fonts/Marker Felt.ttf", 24);
    labelRonda->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 50));
    this->addChild(labelRonda);

    labelPuntos = Label::createWithTTF("Usuario: 0 | IA: 0", "fonts/Marker Felt.ttf", 24);
    labelPuntos->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 100));
    this->addChild(labelPuntos);

    // Sprites de los jugadores
    spriteJugadorUsuario = Sprite::create();
    spriteJugadorUsuario->setPosition(visibleSize.width / 4, visibleSize.height / 2);
    this->addChild(spriteJugadorUsuario);

    spriteJugadorIA = Sprite::create();
    spriteJugadorIA->setPosition(3 * visibleSize.width / 4, visibleSize.height / 2);
    this->addChild(spriteJugadorIA);

    // Botones para elegir acción
    auto crearBoton = [this, visibleSize](const string& texto, Vec2 posicion, int atributo) {
        auto boton = Button::create("cuadro.png");
        boton->setTitleText(texto);
        boton->setTitleFontSize(20);
        boton->setPosition(posicion);
        boton->addClickEventListener([this, atributo](Ref* sender) {
            procesarRonda(atributo); // Procesar atributo seleccionado
            });
        this->addChild(boton);
        };

    crearBoton("Atacar", Vec2(visibleSize.width / 4, visibleSize.height / 4 + 100), 0); // ATacar
    crearBoton("Defender", Vec2(visibleSize.width / 2, visibleSize.height / 4 + 100), 1); // Defender
    crearBoton("Controlar", Vec2(3 * visibleSize.width / 4, visibleSize.height / 4 + 100), 2); // Controlar


    rondaActual = 0;
    puntosUsuario = 0;
    puntosIA = 0;
    iniciarRonda();

    return true;
}

void Fatal3::generarAlineacionIA()
{
    alineacionIA.clear();
    for (const auto& posicion : { "Portero", "Defensa", "Medio", "Delantero" })
    {
        auto rango = JugadoresGlobales::jugadores.equal_range(posicion);
        vector<decltype(rango.first->second)> candidatos;
        for (auto it = rango.first; it != rango.second; ++it)
            candidatos.push_back(it->second);

        int cantidad = (posicion == "Portero") ? 1 : 2;
        for (int i = 0; i < cantidad && !candidatos.empty(); ++i)
        {
            int index = rand() % candidatos.size();
            alineacionIA.push_back(candidatos[index]);
            candidatos.erase(candidatos.begin() + index);
        }
    }
}

void Fatal3::iniciarRonda()
{
    if (rondaActual >= 3)
    {

        auto resultado = (puntosUsuario > puntosIA) ? "Ganaste" : (puntosUsuario < puntosIA) ? "Perdiste" : "Empate";
        auto resultadoScene = Resultados::createScene(resultado, puntosUsuario, puntosIA);
        Director::getInstance()->replaceScene(resultadoScene);
        return;
    }


    jugadorUsuario = alineacionUsuario[rand() % alineacionUsuario.size()];
    jugadorIA = alineacionIA[rand() % alineacionIA.size()];


    spriteJugadorUsuario->setTexture(get<15>(jugadorUsuario));
    spriteJugadorIA->setTexture(get<15>(jugadorIA));

    rondaActual++;
    labelRonda->setString("Ronda " + to_string(rondaActual) + "/3");
}

void Fatal3::procesarRonda(int atributo)
{
    int valorUsuario = (atributo == 0) ? get<3>(jugadorUsuario) : (atributo == 1) ? get<4>(jugadorUsuario) : get<5>(jugadorUsuario);
    int valorIA = (atributo == 0) ? get<3>(jugadorIA) : (atributo == 1) ? get<4>(jugadorIA) : get<5>(jugadorIA);

    // Comparar valores
    if (valorUsuario > valorIA)
        puntosUsuario++;
    else if (valorIA > valorUsuario)
        puntosIA++;

    labelPuntos->setString("Usuario: " + to_string(puntosUsuario) + " | IA: " + to_string(puntosIA));

    // Iniciar la siguiente ronda
    iniciarRonda();
}
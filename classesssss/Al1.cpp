#include "Al1.h"
#include "ui/CocosGUI.h"
#include "../proj.win32/Jugadores.h"
#include "../proj.win32/Armar.h"
#include "../proj.win32/Draft3.h"
#include "../proj.win32/Fatal3.h"
#include "../proj.win32/Datos.h"
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <cstdlib>
#include <ctime>


using namespace std;

USING_NS_CC;

Scene* Al1::createScene()
{
    return Al1::create();
}


// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}


// on "init" you need to initialize your instance
bool Al1::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize(); //tamano ventana
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto mySprite0 = Sprite::create("estadio.png");
    mySprite0->setPosition(Point((visibleSize.width / 2), visibleSize.height / 2));
    this->addChild(mySprite0, 0);

    auto backButton = ui::Button::create("back.png");
    backButton->setPosition(Vec2(origin.x + 100, 750));
    backButton->setScale(.3);
    backButton->addClickEventListener([=](Ref* sender) {
        auto armar = Armar::createScene();
        Director::getInstance()->replaceScene(TransitionFade::create(1.0, armar));
        });
    this->addChild(backButton);

    cocos2d::Label* ratingLabel = nullptr;
    cocos2d::Label* quimicaLabel = nullptr;

    float ratingTotal = 0;
    float quimicaTotal = 0;
    int totalJugadores = 0;


    auto calcularQuimica = [](const auto& jugador1, const auto& jugador2) {
        int quimica = 60;
        if (std::get<7>(jugador1) == std::get<7>(jugador2)) quimica += 33; // país
        if (std::get<8>(jugador1) == std::get<8>(jugador2)) quimica += 33; //equipo
        if (std::get<9>(jugador1) == std::get<9>(jugador2)) quimica += 34; // liga
        return quimica;
        };

    float startX[] = { 650, 550, 650, 850 };
    float startY[] = { 710, 510, 310, 107 };
    float offsetX[] = { 200,200, 200, 200 };
    std::string posiciones[] = { "Delantero", "Medio", "Defensa", "Portero" };
    int cantidades[] = { 3, 4, 3, 1 };

    std::vector<decltype(JugadoresGlobales::jugadores)::mapped_type> jugadoresSeleccionados;

    for (int p = 0; p < 4; ++p) {
        std::string buscarPosicion = posiciones[p];
        auto rango = JugadoresGlobales::jugadores.equal_range(buscarPosicion);

        std::vector<decltype(JugadoresGlobales::jugadores)::mapped_type> candidatos;
        for (auto it = rango.first; it != rango.second; ++it) {
            candidatos.push_back(it->second);
        }

        for (int i = 0; i < std::min(cantidades[p], static_cast<int>(candidatos.size())); ++i) {
            int indiceAleatorio = rand() % candidatos.size();
            auto jugador = candidatos[indiceAleatorio];

            jugadoresSeleccionados.push_back(jugador);

            ratingTotal += std::get<10>(jugador);
            totalJugadores++;

            auto png = std::get<15>(jugador);
            auto nombre = std::get<0>(jugador);
            auto jugadorButton = ui::Button::create(png);
            if (jugadorButton) {
                float posX = startX[p] + (i * offsetX[p]);
                float posY = startY[p];
                jugadorButton->setPosition(Point(posX, posY));
                jugadorButton->setScale(0.23);

                jugadorButton->addClickEventListener([nombre](Ref* sender) { 
                    });

                this->addChild(jugadorButton); 
            }

            candidatos.erase(candidatos.begin() + indiceAleatorio);
        }
    }

    DatosGlobales::alineacionUsuario = jugadoresSeleccionados;

    // Calcular quimica 
    for (size_t i = 0; i < jugadoresSeleccionados.size(); ++i) {
        for (size_t j = i + 1; j < jugadoresSeleccionados.size(); ++j) {
            quimicaTotal += calcularQuimica(jugadoresSeleccionados[i], jugadoresSeleccionados[j]);
        }
    }

    // Promedio de química 
    quimicaTotal /= ((totalJugadores * (totalJugadores - 1)) / 2);
    ratingTotal /= totalJugadores;


    ratingLabel = Label::createWithSystemFont("Rating: " + std::to_string((int)ratingTotal), "fonts/Novlang.ttf", 40);
    ratingLabel->setPosition(Vec2(origin.x + 200, 450));
    this->addChild(ratingLabel);

    quimicaLabel = Label::createWithSystemFont("Quimica: " + std::to_string((int)quimicaTotal) + "%", "fonts/Novlang.ttf", 40);
    quimicaLabel->setPosition(Vec2(origin.x + 200, 550));
    this->addChild(quimicaLabel);


    auto titleLabel = Label::createWithTTF("Play Draft", "fonts/8thCargo.ttf", 50);
    titleLabel->setPosition(Point((visibleSize.width / 2) + 600, visibleSize.height / 2 - 50));
    titleLabel->setTextColor(Color4B::BLACK);
    this->addChild(titleLabel);

    auto backButton1 = ui::Button::create("draft.png");
    backButton1->setPosition(Point((visibleSize.width / 2) + 600, visibleSize.height / 2 - 200));
    backButton1->setScale(.15);
    backButton1->addClickEventListener([=](Ref* sender) {
        auto armar = Draft3::createScene();
        Director::getInstance()->replaceScene(TransitionFade::create(1.0, armar));
        });
    this->addChild(backButton1);

    auto titleLabel1 = Label::createWithTTF("Play Fatal", "fonts/8thCargo.ttf", 50);
    titleLabel1->setPosition(Point((visibleSize.width / 2) + 600, visibleSize.height / 2 + 300));
    titleLabel1->setTextColor(Color4B::BLACK);
    this->addChild(titleLabel1);

    auto backButton2 = ui::Button::create("fatal.png");
    backButton2->setPosition(Point((visibleSize.width / 2) + 600, visibleSize.height / 2 + 150));
    backButton2->setScale(.9);
    backButton2->addClickEventListener([=](Ref* sender) {
        auto armar = Fatal3::createScene();
        Director::getInstance()->replaceScene(TransitionFade::create(1.0, armar));
        });
    this->addChild(backButton2);


    auto randomButton = ui::Button::create("random2.png");
    if (randomButton) {
        randomButton->setPosition(Point(visibleSize.width / 2 - 530, 240));
        randomButton->setScale(0.2);

        randomButton->addClickEventListener([this](Ref* sender) {
            // Limpiar escena
            this->removeAllChildren();

            // Volver a agregar el botón
            this->addChild(dynamic_cast<ui::Button*>(sender));

            // Reorganizar jugadores
            this->init();
            });

        this->addChild(randomButton);
    }

    return true;
}


void Al1::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

#include "Paquete.h"
#include "Cartas.h"
#include "Armar.h"
#include "Jugadores.h" 
#include "ui/CocosGUI.h"
#include "Coleccion.h"

USING_NS_CC;
using namespace std;
Scene* Paquete::createScene() {
    return Paquete::create();
}

bool Paquete::init() {
    if (!Scene::init()) {
        return false;
    }
    AudioEngine::play2d("paquete.mp3");
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    // Fondo
    auto background = Sprite::create("Estadio.png");
    background->setPosition(visibleSize / 2);
    this->addChild(background);

    // Botón para abrir el paquete
    auto abrirPaqueteButton = ui::Button::create("sobre.png");
    abrirPaqueteButton->setPosition(visibleSize / 2);
    abrirPaqueteButton->setScale(0.8);
    abrirPaqueteButton->addClickEventListener([this](Ref* sender) {
        abrirPaquete();
        });
    this->addChild(abrirPaqueteButton);

    auto mySprite2 = Sprite::create("balonMenu.png");
    mySprite2->setPosition(Point(origin.x, origin.y));
    mySprite2->setScale(0.5, 0.5);
    this->addChild(mySprite2, 1);

    auto action3 = RepeatForever::create(JumpTo::create(10, Vec2(200, 100), 70, 10));
    mySprite2->runAction(action3);

    auto mySprite = Sprite::create("balonMenu.png");
    mySprite->setPosition(Point(origin.x, origin.y));
    mySprite->setScale(0.5, 0.5);
    this->addChild(mySprite, 1);

    auto action = RepeatForever::create(JumpTo::create(10, Vec2(1500, 100), 70, 10));
    mySprite->runAction(action);

    return true;
}

void Paquete::abrirPaquete() {
    vector<tuple<string, int, int, int, int, int, int, string, string, string, int, string, int, int, int, string, int>> jugadoresDisponibles;

    for (const auto& par : JugadoresGlobales::jugadores) {
        jugadoresDisponibles.push_back(par.second);
    }

    if (!jugadoresDisponibles.empty()) {
        int indiceAleatorio = rand() % jugadoresDisponibles.size();
        auto cartaObtenida = jugadoresDisponibles[indiceAleatorio];

        Cartas::getInstance().agregarCarta(cartaObtenida);

        auto nombre = get<15>(cartaObtenida);
        auto jugadorButton = ui::Button::create(nombre);
        jugadorButton->setPosition(Point(850, 350));
        jugadorButton->setScale(0.8);
        jugadorButton->addClickEventListener([this](Ref* sender) {
            auto coleccionScene = Coleccion::createScene();
            Director::getInstance()->pushScene(coleccionScene);
            });
        this->addChild(jugadorButton);
    }
}

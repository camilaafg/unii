#include "Resultados.h"
#include "ui/CocosGUI.h"
#include "Draft3.h" 
#include <string>
#include "../proj.win32/Al3.h"
#include "Paquete.h"

USING_NS_CC;
using namespace std;

Scene* Resultados::createScene(const string& resultado, int ratingUsuario, int ratingIA) {

    auto scene = Scene::create();
    auto layer = Resultados::create();

       layer->setupScene(resultado, ratingUsuario, ratingIA);
       scene->addChild(layer);
  
    return scene;
}

bool Resultados::init() {
    if (!Scene::init()) {
        return false;
    }
    AudioEngine::play2d("silbato.mp3");
    return true;
}


void Resultados::setupScene(const string& resultado, int ratingUsuario, int ratingIA) {
    // Tamaño visible
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Fondo
    /*auto background = Sprite::create("estadio.png");
    background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(background);*/

    //resultado
    auto labelResultado = Label::createWithTTF(resultado, "fonts/Marker Felt.ttf", 36);
    labelResultado->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 50));
    this->addChild(labelResultado);

    //ratings
    auto labelRatings = Label::createWithTTF(
        "Usuario: " + to_string(ratingUsuario) + " - IA: " + to_string(ratingIA),
        "fonts/Marker Felt.ttf", 24);
    labelRatings->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(labelRatings);

    auto titleLabel = Label::createWithTTF("Vaya, parece que te has ganado un sobre", "fonts/8thCargo.ttf", 100);
    titleLabel->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 200));
    titleLabel->setTextColor(Color4B::BLUE);
    this->addChild(titleLabel);

    // Botón para abrir sobre
    auto regresarButton = ui::Button::create("carta3.png");
    regresarButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 200));
    regresarButton->setScale(0.3);
    regresarButton->addClickEventListener([](Ref* sender) {
        auto scene = Paquete::createScene();
        Director::getInstance()->replaceScene(scene);
        });
    this->addChild(regresarButton);
}

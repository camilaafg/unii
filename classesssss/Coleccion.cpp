#include "Coleccion.h"
#include "Cartas.h"
#include "ui/CocosGUI.h"
#include "Armar.h"

USING_NS_CC;

Scene* Coleccion::createScene() {
    return Coleccion::create();
}

bool Coleccion::init() {
    if (!Scene::init()) {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    // Fondo
    auto background = Sprite::create("estadio.png");
    background->setPosition(visibleSize / 2);
    this->addChild(background);

    auto titleLabel = Label::createWithTTF("Tus Cartas", "fonts/Novlang.ttf", 80);
    titleLabel->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 700));
    titleLabel->setTextColor(Color4B::YELLOW);
    this->addChild(titleLabel);

    auto cartas = Cartas::getInstance().getCartas();

    // Mostrar cartas en pantalla
    float startX = 100;
    float startY = visibleSize.height - 120;
    float offsetX = 150;
    float offsetY = 200;

    int columna = 0;
    for (size_t i = 0; i < cartas.size(); ++i) {
        const auto& carta = cartas[i];
        auto nombre = std::get<15>(carta); 

        // Mostrar nombre
        auto jugadorButton = ui::Button::create(nombre);
        jugadorButton->setPosition(Point(startX + columna * offsetX, startY - (i / 3) * offsetY));
        jugadorButton->setScale(0.2);
        jugadorButton->addClickEventListener([this](Ref* sender) {
           
            });
        this->addChild(jugadorButton);

        // Cambiar columna
        columna = (columna + 1) % 3;
    }

    // Botón para regresar al menú principal
    auto backButton = ui::Button::create("back.png");
    backButton->setPosition(Point(1600, visibleSize.height - 50));
    backButton->setScale(0.4);
    backButton->addClickEventListener([](Ref* sender) {
        auto armar = Armar::createScene();
        Director::getInstance()->replaceScene(TransitionFade::create(1.0, armar));
        });
    this->addChild(backButton);

    return true;
}

#include "Armar.h"
#include "../proj.win32/Al2.h"
#include "../proj.win32/Al1.h"
#include "../proj.win32/Al3.h"
#include "Coleccion.h"
#include "ui/CocosGUI.h"


USING_NS_CC;

Scene* Armar::createScene()
{
    return Armar::create();
}


// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Armar::init()
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

    auto titleLabel = Label::createWithTTF("elige tu formacion", "fonts/Hoeflers Free.ttf", 100);
    titleLabel->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + 100));
    titleLabel->setTextColor(Color4B::WHITE);
    this->addChild(titleLabel);

    auto playButton = ui::Button::create("alineacion.png");
    playButton->setPosition(Point(350, visibleSize.height / 2));
    playButton->setScale(.4);
    playButton->addClickEventListener([=](Ref* sender) {
        auto armar = Al1::createScene();
        Director::getInstance()->replaceScene(TransitionFade::create(1.0, armar));
        });
    this->addChild(playButton);

    auto playButton2 = ui::Button::create("alineacion.png");
    playButton2->setPosition(Point(850, visibleSize.height / 2));
    playButton2->setScale(.4);
    playButton2->addClickEventListener([=](Ref* sender) {
        auto armar = Al2::createScene();
        Director::getInstance()->replaceScene(TransitionFade::create(1.0, armar));
        });
    this->addChild(playButton2);

    auto playButton3 = ui::Button::create("alineacion.png");
    playButton3->setPosition(Point(1350, visibleSize.height / 2));
    playButton3->setScale(.4);
    playButton3->addClickEventListener([=](Ref* sender) {
        auto armar = Al3::createScene();
        Director::getInstance()->replaceScene(TransitionFade::create(1.0, armar));
        });
    this->addChild(playButton3);

    auto titleLabel1 = Label::createWithTTF("433", "fonts/Walk with me now.ttf", 100);
    titleLabel1->setPosition(Vec2(850, origin.y + 700));
    titleLabel1->setTextColor(Color4B::GREEN);
    this->addChild(titleLabel1);

    auto titleLabel3 = Label::createWithTTF("343", "fonts/Walk with me now.ttf", 100);
    titleLabel3->setPosition(Vec2(350, origin.y + 700));
    titleLabel3->setTextColor(Color4B::GREEN);
    this->addChild(titleLabel3);

    auto titleLabel2 = Label::createWithTTF("442", "fonts/Walk with me now.ttf", 100);
    titleLabel2->setPosition(Vec2(1350, origin.y + 700));
    titleLabel2->setTextColor(Color4B::GREEN);
    this->addChild(titleLabel2);

    auto playButton4 = ui::Button::create("coleccion.png");
    playButton4->setPosition(Point(1480, visibleSize.height / 2 - 300));
    playButton4->setScale(.7);
    playButton4->addClickEventListener([=](Ref* sender) {
        auto armar = Coleccion::createScene();
        Director::getInstance()->replaceScene(TransitionFade::create(1.0, armar));
        });
    this->addChild(playButton4);

    auto exitButton = ui::Button::create("Exit.png");
    exitButton->setPosition(Vec2(origin.x + visibleSize.width - 70, origin.y + 700));
    exitButton->setScale(0.4, 0.4);
    exitButton->addClickEventListener([=](Ref* sender) {
        Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        exit(0);
#endif
        });
    this->addChild(exitButton);
    return true;
}


void Armar::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

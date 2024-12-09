#include "Plantilla.h"
#include "ui/CocosGUI.h"
#include "../proj.win32/Armar.h"
#include "HelloWorldScene.h"

using namespace std;
using namespace cocos2d::ui;

USING_NS_CC;


Scene* Plantilla::createScene()
{
    return Plantilla::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}


// on "init" you need to initialize your instance
bool Plantilla::init()
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

    auto titleLabel = Label::createWithTTF("ES HORA DE ARMAR TU PLANTILLA", "fonts/Hoeflers Free.ttf", 100);
    titleLabel->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + 100));
    titleLabel->setTextColor(Color4B::WHITE);
    this->addChild(titleLabel);



    //alineacion
    auto mySprite = Sprite::create("son.png");
    auto mySprite2 = Sprite::create("mbappe.png");
    auto mySprite3 = Sprite::create("Salah.png");
    auto mySprite4 = Sprite::create("modric.png");
    auto mySprite5 = Sprite::create("Saka.png");
    auto mySprite6 = Sprite::create("Musiala.png");
    auto mySprite7 = Sprite::create("alexia.png");
    auto mySprite8 = Sprite::create("Marquinhos.png");
    auto mySprite9 = Sprite::create("Saliba.png");
    auto mySprite10 = Sprite::create("karchaoui.png");
    auto mySprite11 = Sprite::create("donnarumma.png");
    mySprite->setPosition(Point((origin.x + 241), origin.y + 728));
    mySprite2->setPosition(Point((origin.x + 400), origin.y + 728));
    mySprite3->setPosition(Point((origin.x + 559), origin.y + 728));
    mySprite4->setPosition(Point((origin.x + 166), origin.y + 568));
    mySprite5->setPosition(Point((origin.x + 633), origin.y + 568));
    mySprite6->setPosition(Point((origin.x + 325), origin.y + 568));
    mySprite7->setPosition(Point((origin.x + 474), origin.y + 568));
    mySprite8->setPosition(Point((origin.x + 400), origin.y + 408));
    mySprite9->setPosition(Point((origin.x + 559), origin.y + 408));
    mySprite10->setPosition(Point((origin.x + 241), origin.y + 408));
    mySprite11->setPosition(Point((origin.x + 400), origin.y + 240));
    mySprite->setScale(.19, .19);
    mySprite2->setScale(.19, .19);
    mySprite3->setScale(.19, .19);
    mySprite4->setScale(.19, .19);
    mySprite5->setScale(.19, .19);
    mySprite6->setScale(.19, .19);
    mySprite7->setScale(.19, .19);
    mySprite8->setScale(.19, .19);
    mySprite9->setScale(.19, .19);
    mySprite10->setScale(.19, .19);
    mySprite11->setScale(.19, .19);
    this->addChild(mySprite, 1);
    this->addChild(mySprite2, 2);
    this->addChild(mySprite3, 3);
    this->addChild(mySprite4, 4);
    this->addChild(mySprite5, 5);
    this->addChild(mySprite6, 6);
    this->addChild(mySprite7, 7);
    this->addChild(mySprite8, 8);
    this->addChild(mySprite9, 9);
    this->addChild(mySprite10, 10);
    this->addChild(mySprite11, 11);

    
    auto playButton = ui::Button::create("next.png");
    playButton->setPosition(Vec2(origin.x + 1150, origin.y + visibleSize.height / 2 + 50));
    playButton->setScale(.8);
    playButton->addClickEventListener([=](Ref* sender) {
        auto armar = Armar::createScene();
        Director::getInstance()->replaceScene(TransitionFade::create(1.0, armar));
        });
    this->addChild(playButton);

    auto backButton = ui::Button::create("back.png");
    backButton->setPosition(Vec2(origin.x + 100, 750));
    backButton->setScale(.3);
    backButton->addClickEventListener([=](Ref* sender) {
        auto armar = HelloWorld::createScene();
        Director::getInstance()->replaceScene(TransitionFade::create(1.0, armar));
        });
    this->addChild(backButton);
   
    return true;
}


void Plantilla::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

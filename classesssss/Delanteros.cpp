#include "Delanteros.h"
#include "ui/CocosGUI.h"
#include "HelloWorldScene.h"
#include <set>
#include "../proj.win32/Jugadores.h"


USING_NS_CC;


Scene* Delanteros::createScene()
{
    return Delanteros::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
//
//void Delanteros::initJugadores() {
//    JugadorManager::getInstance().cargarJugadores();
//}

// on "init" you need to initialize your instance
bool Delanteros::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    //Jugador::jugadores = Jugador::crearJugadores(); 

    /*set<Jugador> v;
    v = Jugador::crearJugadores();*/

    

    /*for (const auto& jugador : Jugador::jugadores) {
        jugador.mostrarInfo();  
    }*/

    //set<Jugador> Jugador::jugadores = Jugador::crearJugadores();


    auto visibleSize = Director::getInstance()->getVisibleSize(); //tamano ventana
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto mySprite0 = Sprite::create("estadio.png");
    mySprite0->setPosition(Point((visibleSize.width / 2), visibleSize.height / 2));
    this->addChild(mySprite0, 0);


    return true;
}


void Delanteros::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

#pragma once
#ifndef __Fatal3_H__
#define __Fatal3_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <vector>
#include <tuple>
#include <string>
#include <map>

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace std;

class Fatal3 : public Scene
{
public:
    static Scene* createScene();
    virtual bool init();

    // Helper functions
    void generarAlineacionIA();
    void iniciarRonda();
    void procesarRonda(int atributo);
    
    CREATE_FUNC(Fatal3);

private:
    int rondaActual;
    int puntosUsuario;
    int puntosIA;
    vector<tuple<string, int, int, int, int, int, int, string, string, string, int, string, int, int, int, string, int>> alineacionUsuario;
    vector<tuple<string, int, int, int, int, int, int, string, string, string, int, string, int, int, int, string, int>> alineacionIA;

    Label* labelRonda;
    Label* labelPuntos;
    Sprite* spriteJugadorUsuario;
    Sprite* spriteJugadorIA;
    tuple<string, int, int, int, int, int, int, string, string, string, int, string, int, int, int, string, int> jugadorUsuario;
    tuple<string, int, int, int, int, int, int, string, string, string, int, string, int, int, int, string, int> jugadorIA;
};



#endif // __Fatal3_H__

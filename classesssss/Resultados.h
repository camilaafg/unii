#pragma once
#ifndef __Resultados_H__
#define __Resultados_H__

#include "cocos2d.h"
#include "audio/include/AudioEngine.h"
#include <string>
using namespace std;


class Resultados : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene(const string& resultado, int ratingUsuario, int ratingIA);

    virtual bool init();

    // Método para inicializar la escena con los datos
    void setupScene(const string& resultado, int ratingUsuario, int ratingIA);


    // a selector callback
    //void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(Resultados);
};

#endif // __Resultados_H__

#pragma once
#ifndef __COLECCION_SCENE_H
#define __COLECCION_SCENE_H

#include "cocos2d.h"

class Coleccion : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();

    virtual bool init() override;

    CREATE_FUNC(Coleccion);
};

#endif // __COLECCION_SCENE_H
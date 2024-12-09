#pragma once
#ifndef __PAQUETE_H
#define __PAQUETE_H

#include "cocos2d.h"
#include "audio/include/AudioEngine.h"

class Paquete : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();

    virtual bool init() override;

    CREATE_FUNC(Paquete);

private:
    void abrirPaquete();
};

#endif // __PAQUETE_H

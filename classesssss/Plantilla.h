#ifndef __PLANTILLA_H__
#define __PLANTILLA_H__

#include "cocos2d.h"
#include "audio/include/AudioEngine.h"
#include "../proj.win32/Jugadores.h"


class Plantilla : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(Plantilla);

};

#endif // __PLANTILLA_H__

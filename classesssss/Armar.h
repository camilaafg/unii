#ifndef __ARMAR_H__
#define __ARMAR_H__

#include "cocos2d.h"
#include "audio/include/AudioEngine.h"


class Armar : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(Armar);
};

#endif // __ARMAR_H__

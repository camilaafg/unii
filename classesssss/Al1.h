#ifndef __Al1_H__
#define __Al1_H__

#include "cocos2d.h"
#include "audio/include/AudioEngine.h"


class Al1 : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(Al1);
};

#endif // __Al1_H__

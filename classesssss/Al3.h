#ifndef __Al3_H__
#define __Al3_H__

#include "cocos2d.h"
#include "audio/include/AudioEngine.h"


class Al3 : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(Al3);
};

#endif // __Al3_H__

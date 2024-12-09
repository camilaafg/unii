#ifndef __Delanteros_H__
#define __Delanteros_H__

#include "cocos2d.h"
#include "audio/include/AudioEngine.h"


class Delanteros : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(Delanteros);

    //static std::vector<Jugador> delanteros;
};

#endif // __Delanteros_H__

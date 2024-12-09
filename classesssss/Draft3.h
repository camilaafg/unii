#ifndef __Draft3_H__
#define __Draft3_H__

#include "cocos2d.h"
#include "audio/include/AudioEngine.h"
using namespace std;


class Draft3 : public cocos2d::Scene
{
private:
    vector<string> eventos; // Vector de eventos
    int eventoIndex = 0;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(Draft3);
};

#endif // __Draft3_H__

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

public:
	//node�����update������ÿһ֡��ˢ��this->scheduleUpdate();��
	virtual void update(float delta);

private:
	Sprite* bgSprite1;
	Sprite* bgSprite2;
};

#endif // __HELLOWORLD_SCENE_H__

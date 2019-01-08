#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class HelloWorld:public cocos2d::Layer
{
public:
	
	static HelloWorld * create();
	virtual bool init();
	//void createLabel(cocos2d::String str,int height);

	void menuCloseCallback(cocos2d::Ref* pSender);

	

};

#endif // __HELLOWORLD_SCENE_H__

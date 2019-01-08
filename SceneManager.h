#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class SceneManager{
public:
	Scene * loadScene;
	Scene * openScene;
	Scene * clockScene;

	void createLoadScene();
	void createOpenScene();
	void createClockScene();


};





#endif // !_SCENEMANAGE_H_

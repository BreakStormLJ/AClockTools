#include "HelloWorldScene.h"


USING_NS_CC;

HelloWorld* HelloWorld::create(){
	HelloWorld * pRet = new HelloWorld();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
	/*auto scene = Scene::create();
	auto layer = HelloWorld::create();
	scene->addChild(layer);
	return scene;*/
}

bool HelloWorld::init(){
	if (!Layer::init()){
		return false;
	}
	Size winSize = Director::getInstance()->getWinSize();
	Size visbleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	closeItem->setPosition(Vec2(origin.x + visbleSize.width - closeItem->getContentSize().width,
		origin.y + closeItem->getContentSize().height));
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 3);

	auto img = Sprite::create("CloseSelected.png");
	img->setPosition(Vec2(origin.x + 100, origin.y + visbleSize.height / 2));
	this->addChild(img, 4);

	auto imgOne = Sprite::create("HelloWorld.png");
	imgOne->setPosition(Vec2(origin.x, origin.y + visbleSize.height / 2));
	this->addChild(imgOne, 3);


	auto label1 = Label::createWithTTF("HelloWorld","fonts/arial.ttf",50);
	label1->setPosition(Vec2(origin.x + visbleSize.width/2, origin.y + visbleSize.height - label1->getContentSize().height + 20 ));
	label1->setColor(Color3B(72, 209, 204));
	this->addChild(label1, 1);

	auto label2 = Label::createWithTTF("Write By LiuJin", "fonts/arial.ttf", 50);
	label2->setPosition(Vec2(origin.x + visbleSize.width / 2, origin.y + label2->getContentSize().height));
	label2->setColor(Color3B(30, 144, 255));
	this->addChild(label2, 2);
	//Rect rect = Rect::ZERO;
	auto sprite = Sprite::create("HelloWorld1.png");

	//sprite->setContentSize(Size (1136,640));

	sprite->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	float winWidith = winSize.width;
	float winHeight = winSize.height;
	float spriteWidth = sprite->getTextureRect().getMaxX();
	float spriteheight = sprite->getTextureRect().getMaxY();
	sprite->setScaleX(winWidith / spriteWidth);
	sprite->setScaleY(winHeight / spriteheight);
	//sprite->setColor(Color3B(178, 178, 178));
	//sprite->setAnchorPoint(Vec2(0.5, 0.5));
	this->addChild(sprite, 0);

	return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender){
	//CCLOG("I want to close the window!");

	Director::getInstance()->end();
}

#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	auto sprit1 = Sprite::create("red.png");
	sprit1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 200,
		origin.y + visibleSize.height - sprit1->getContentSize().height - 250));
	sprit1->setAnchorPoint(Vec2(0, 0));
	this->addChild(sprit1, 0);

	auto sprit2 = Sprite::create("green.png");
	sprit2->setPosition(Vec2(origin.x + visibleSize.width / 2 ,
		origin.y + sprit2->getContentSize().height - 100));
	sprit2->setAnchorPoint(Vec2(0,0));
	sprit2->setName("redImg");
	this->addChild(sprit2, 0);

	//BlendFunc blend = { GL_ONE, GL_ONE };
	//BlendFunc blend = { GL_SRC_ALPHA, GL_ONE };
	//BlendFunc blend = { GL_ONE, GL_ZERO }; 
	//BlendFunc blend = { GL_ZERO, GL_ONE };
	BlendFunc blend = { GL_DST_COLOR, GL_ONE };
	sprit2->setBlendFunc(blend);

	//sthis->removeAllChildren();
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


/*  混合方式     解释       因子值
 *	 GL_ONE   全部不用     (0,0,0,0)
 */



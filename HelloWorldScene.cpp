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
    if ( !Layer::init() )
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
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width,
                                origin.y + closeItem->getContentSize().height));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/arial.ttf", 50);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height + 20));
	//set color
	label->setColor(Color3B(72, 209, 204));

    // add the label as a child to this layer
    this->addChild(label, 1);

	auto author = Label::createWithTTF("Write By LiuJin", "fonts/arial.ttf", 50);
	author->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + author->getContentSize().height));
	author->setColor(Color3B(72, 209, 201));
	this->addChild(author, 1);

	//Size clipsize = Director::sharedDirector()->getVisibleSize();

	bgSprite1 = Sprite::create("HelloWorld1.png");
	bgSprite1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(bgSprite1, 0);

	bgSprite2 = Sprite::create("HelloWorld1.png");
	bgSprite2->setPosition(Vec2(visibleSize.width + visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(bgSprite2, 0);

	this->scheduleUpdate();
    
    return true;
}

void HelloWorld::update(float delta){
	int posX1 = bgSprite1->getPositionX();
	int posX2 = bgSprite2->getPositionX();

	int _speed = 20;

	posX1 -= _speed;
	posX2 -= _speed;

	Size mapSize = bgSprite1->getContentSize();

	if (posX1 <= -mapSize.width / 2){
		posX2 = mapSize.width / 2;
		posX1 = mapSize.width + mapSize.width / 2;
	}

	if (posX2 <= -mapSize.width/2)
	{
		posX1 = mapSize.width / 2;
		posX2 = mapSize.width + mapSize.width / 2;
	}

	bgSprite1->setPositionX(posX1);
	bgSprite2->setPositionX(posX2);




}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

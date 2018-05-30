#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    _director->setClearColor(Color4F(255, 255, 255, 0));

    /*
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    */

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        sprite->setScale(3.0);
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height + origin.y - (1.2 * (sprite->getBoundingBox().size.height / 2))));
        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }


    // add start button
    auto startButton = Button::create("start_button.png",
                                      "start_button_pressed.png",
                                      "start_button_pressed.png");

    startButton->setScale(1.5);
    float x = visibleSize.width / 2 + origin.x;
    float y = sprite->getPosition().y - sprite->getBoundingBox().size.height/2 - (1.7 * startButton->getBoundingBox().size.height);
    startButton->setPosition(Vec2(x, y));
    this->addChild(startButton);



    // add scores button
    auto scoresButton = Button::create("scores_button.png",
                                       "scores_button_pressed.png",
                                       "scores_button_pressed.png");

    scoresButton->setScale(1.5);
    float x2 = visibleSize.width / 2 + origin.x;
    float y2 = startButton->getPosition().y - (1.4 * scoresButton->getBoundingBox().size.height);
    scoresButton->setPosition(Vec2(x2, y2));
    this->addChild(scoresButton);



    // add settings button
    auto settingsButton = Button::create("settings_button.png",
                                         "settings_button_pressed.png",
                                         "settings_button_pressed.png");

    settingsButton->setScale(1.5);
    float x3 = visibleSize.width / 2 + origin.x;
    float y3 = scoresButton->getPosition().y - (1.4 * settingsButton->getBoundingBox().size.height);
    settingsButton->setPosition(Vec2(x3, y3));
    this->addChild(settingsButton);

    return true;

}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

//
//  SampleScene.cpp
//  SampleCocos
//
//  Created by dmnlk on 2015/11/16.
//
//

#include "SampleScene.hpp"


cocos2d::Scene* SampleScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = cocos2d::Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SampleScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool SampleScene::init()
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
//    auto closeItem = MenuItemImage::create(
//                                           "CloseNormal.png",
//                                           "CloseSelected.png",
//                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
//    
//    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
//                                origin.y + closeItem->getContentSize().height/2));
//    
//    // create menu, it's an autorelease object
//    auto menu = Menu::create(closeItem, NULL);
//    menu->setPosition(Vec2::ZERO);
//    this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    // add "HelloWorld" splash screen"
//    auto sprite = Sprite::create("HelloWorld.png");
//    
//    // position the sprite on the center of the screen
//    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//    
//    // add the sprite as a child to this layer
//    this->addChild(sprite, 0);
    
    
///    cocos2d::extension::EditBox* editbox  = EditBox::cre
    
    auto editBox = cocos2d::extension::EditBox::create(Size(100, 50), cocos2d::extension::Scale9Sprite::create("bg.png"));
    editBox->setInputMode(cocos2d::extension::EditBox::InputMode::ANY);
    editBox->setFont("fonts/Marker Felt.ttf", 12.0f);
    editBox->setPlaceHolder("ここに入力してください");
    editBox->setPlaceholderFontColor(Color3B::BLACK);
    editBox->setFontColor(Color3B::BLACK);
    editBox->setMaxLength(100);
    editBox->setText("初期設定文字\ntest");
    editBox->setReturnType(cocos2d::extension::EditBox::KeyboardReturnType::DONE);
    editBox->setInputMode(cocos2d::extension::EditBox::InputMode::ANY);
    editBox->cocos2d::Node::setPosition(100, 200);
    editBox->setDelegate(this);
    this->addChild(editBox);
    return true;
}

void SampleScene::editBoxEditingDidBegin(cocos2d::extension::EditBox *editBox) {
}

void SampleScene::editBoxEditingDidEnd(cocos2d::extension::EditBox *editBox) {
}

void SampleScene::editBoxTextChanged(cocos2d::extension::EditBox *editBox, const std::string& text) {
    CCLOG(editBox->getText());
}

void SampleScene::editBoxReturn(cocos2d::extension::EditBox *editBox) {
}
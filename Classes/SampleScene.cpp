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
    
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    

    auto editBox = cocos2d::extension::EditBox::create(Size(300, 100), cocos2d::extension::Scale9Sprite::create("bg.png"));
    editBox->setInputMode(cocos2d::extension::EditBox::InputMode::ANY);
    editBox->setFont("fonts/Marker Felt.ttf", 10.0f);
    editBox->setPlaceholderFontSize(10.0f);
    editBox->setPlaceHolder("ここに入力してください");
    editBox->setPlaceholderFontColor(Color3B::BLACK);
    editBox->setFontColor(Color3B::BLACK);
    editBox->setMaxLength(100);
    editBox->setInputMode(cocos2d::extension::EditBox::InputMode::ANY);
    editBox->cocos2d::Node::setPosition(150, 200);
    editBox->setDelegate(this);
    this->addChild(editBox);
    return true;
}

void SampleScene::editBoxEditingDidBegin(cocos2d::extension::EditBox *editBox) {
}

void SampleScene::editBoxEditingDidEnd(cocos2d::extension::EditBox *editBox) {
}

void SampleScene::editBoxTextChanged(cocos2d::extension::EditBox *editBox, const std::string& text) {
}

void SampleScene::editBoxReturn(cocos2d::extension::EditBox *editBox) {
}
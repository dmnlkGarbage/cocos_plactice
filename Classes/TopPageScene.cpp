//
//  TopPageScene.cpp
//  SampleCocos
//
//  Created by dmnlk on 2015/08/26.
//
//

#include "TopPageScene.h"

USING_NS_CC;

cocos2d::Scene* TopPageLayer::createScene() {
    auto scene = Scene::create();
    auto layer = TopPageLayer::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool TopPageLayer::init() {
    
    if (!Layer::init()) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto label = Label::createWithTTF("cant use japanese char", "fonts/arial.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
  
    this->addChild(label);
    Sprite* sprite = Sprite::create("avater.jpg");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    this->addChild(sprite);
    

    return true;
}
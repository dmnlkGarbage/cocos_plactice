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

}

bool TopPageLayer::init() {
    
    if (!Layer::init()) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    this->addChild(label);
    return true;
}
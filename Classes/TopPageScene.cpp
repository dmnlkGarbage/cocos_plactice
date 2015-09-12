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
    sprite->setName("avatar");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    sprite->setFlippedX(true);
    
    
    this->addChild(sprite);
    
    
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(TopPageLayer::buttonCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    auto moveItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(TopPageLayer::moveButtonCallback, this));

    moveItem->setPosition(Vec2(100,200));
    
    
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    menu->addChild(moveItem);
    
//    auto menu2 = Menu::create(moveItem, NULL);
//    menu2->setPosition(Vec2::ZERO);
    
    this->addChild(menu, 1);
  //  this->addChild(menu2,2);

    return true;
}

void TopPageLayer::buttonCallback(Ref* pSender)
{
    auto sprite = dynamic_cast<Sprite*>(this->getChildByName("avatar"));
    if (sprite) {
        if (sprite->isFlippedX()) {
            sprite->setFlippedX(false);
        } else {
            sprite->setFlippedX(true);
        }
        
        sprite->setScale(sprite->getScale()*1.1f);
    }
}

void TopPageLayer::moveButtonCallback(cocos2d::Ref *pSender) {
    auto sprite = dynamic_cast<Sprite*>(this->getChildByName("avatar"));
    if (sprite) {
        sprite->setPosition(Vec2(sprite->getPosition().x +10, sprite->getPosition().y));
    }
    
    CCLOG("getPositionX=%f", sprite->getPositionX());
    CCLOG("getPosition.x=%f", sprite->getPosition().x);
};


//
//  TopPageScene.cpp
//  SampleCocos
//
//  Created by dmnlk on 2015/08/26.
//
//

#include "TopPageScene.h"
#include <random>
#include "SimpleAudioEngine.h"
#include "SampleDto.h"

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
    
    
    Sprite* cover = Sprite::create("CloseNormal.png");
    sprite->addChild(cover);
    CCLOG("before local zorder=%d", sprite->getLocalZOrder());
    CCLOG("before global Zorder=%f", sprite->getGlobalZOrder());
    
    this->addChild(sprite);
    CCLOG("after local zorder=%d", sprite->getLocalZOrder());
    CCLOG("after global Zorder=%f", sprite->getGlobalZOrder());
    
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

    
    auto addItem = MenuItemImage::create(
                                         "CloseNormal.png",
                                         "CloseSelected.png",
                                         CC_CALLBACK_1(TopPageLayer::addImageSpriteButtonCallback, this));
    addItem->setPosition(Vec2(200,200));

    auto removeItem = MenuItemImage::create(
                                         "CloseNormal.png",
                                         "CloseSelected.png",
                                         CC_CALLBACK_1(TopPageLayer::removeAllSprite, this));
    removeItem->setPosition(Vec2(250,200));
    
    auto animItem = MenuItemImage::create(
                                            "CloseNormal.png",
                                            "CloseSelected.png",
                                            CC_CALLBACK_1(TopPageLayer::animationSprite, this));
    animItem->setPosition(Vec2(250,200));
    
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    menu->addChild(moveItem);
    menu->addChild(addItem);
    menu->addChild(removeItem);
    menu->addChild(animItem);
    
    this->addChild(menu, 1);


    //bgm
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("bgm.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm.mp3");
    
    SampleDto dto;
    int dtoLoadData = dto.load();
    CCLOG("load data is %d", dtoLoadData);

    
    SampleDto* dtoPointer = &dto;
    dtoLoadData =  dtoPointer->load();
    CCLOG("load data is %d", dtoLoadData);
    
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


void TopPageLayer::addImageSpriteButtonCallback(cocos2d::Ref *pSender) {
    CCLOG("add Sprite");
    std::random_device rd;
    std::mt19937 mt(rd());
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    std::uniform_real_distribution<float> posX(0, visibleSize.width);
    std::uniform_real_distribution<float> posY(0, visibleSize.height);
    
    for (int i =0; i < 10000; i++) {
        auto sprite = Sprite::create("avater.jpg");
        sprite->setPosition(Vec2(posX(mt), posY(mt)));
        this->addChild(sprite);
    }
}

void TopPageLayer::removeAllSprite(cocos2d::Ref *pSender) {
    CCLOG("removeItem");
    auto children =  this->getChildren();
    for (auto child: children) {
        Sprite* sprite = dynamic_cast<Sprite*>(child);
        if (sprite) {
            this->removeChild(sprite);
        }
    }
}

void TopPageLayer::animationSprite(cocos2d::Ref *pSender) {
    CCLOG("start animation");
    auto sprite = dynamic_cast<Sprite*>(this->getChildByName("avatar"));
    if (sprite) {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        auto anim = MoveTo::create(1, Vec2(visibleSize.width-sprite->getContentSize().width/2, visibleSize.height/3));
        sprite->runAction(anim);
    }
}
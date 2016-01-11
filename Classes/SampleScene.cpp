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
    

    auto editBox = cocos2d::ui::EditBox::create(Size(300, 100), cocos2d::ui::Scale9Sprite::create("bg.png"));
    editBox->setInputMode(cocos2d::ui::EditBox::InputMode::ANY);
    editBox->setFont("fonts/Marker Felt.ttf", 10.0f);
    editBox->setPlaceholderFontSize(10.0f);
    editBox->setPlaceHolder("ここに入力してください");
    editBox->setPlaceholderFontColor(Color3B::BLACK);
    editBox->setFontColor(Color3B::BLACK);
    editBox->setMaxLength(100);
   // editBox->setText("初期設定文字");
    //editBox->setReturnType(cocos2d::ui::EditBox::KeyboardReturnType::DONE);
    editBox->setInputMode(cocos2d::ui::EditBox::InputMode::ANY);
    editBox->cocos2d::Node::setPosition(150, 200);
    editBox->setDelegate(this);
    this->addChild(editBox);
    return true;
}

void SampleScene::editBoxEditingDidBegin(cocos2d::ui::EditBox *editBox) {
}

void SampleScene::editBoxEditingDidEnd(cocos2d::ui::EditBox *editBox) {
}

void SampleScene::editBoxTextChanged(cocos2d::ui::EditBox *editBox, const std::string& text) {
    CCLOG(editBox->getText());
}

void SampleScene::editBoxReturn(cocos2d::ui::EditBox *editBox) {
}
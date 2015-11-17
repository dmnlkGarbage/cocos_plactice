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
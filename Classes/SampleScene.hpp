//
//  SampleScene.hpp
//  SampleCocos
//
//  Created by dmnlk on 2015/11/16.
//
//


#ifndef SampleScene_hpp
#define SampleScene_hpp

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

class SampleScene :public cocos2d::Layer, public cocos2d::extension::EditBoxDelegate {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();

    CREATE_FUNC(SampleScene);
private:
    virtual void editBoxEditingDidBegin(cocos2d::extension::EditBox *editBox);
    virtual void editBoxEditingDidEnd(cocos2d::extension::EditBox *editBox);
    virtual void editBoxTextChanged(cocos2d::extension::EditBox *editBox, const std::string& text);
    virtual void editBoxReturn(cocos2d::extension::EditBox *editBox);
};

#endif /* SampleScene_hpp */

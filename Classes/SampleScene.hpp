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
using namespace ui;
//USING_NS_CC_EXT;

class SampleScene :public cocos2d::Layer, public ui::EditBoxDelegate {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();

    CREATE_FUNC(SampleScene);
private:
    virtual void editBoxEditingDidBegin(EditBox *editBox);
    virtual void editBoxEditingDidEnd(EditBox *editBox);
    virtual void editBoxTextChanged(EditBox *editBox, const std::string& text);
    virtual void editBoxReturn(EditBox *editBox);
};

#endif /* SampleScene_hpp */

//
//  TopPageScene.h
//  SampleCocos
//
//  Created by dmnlk on 2015/08/26.
//
//

#ifndef __SampleCocos__TopPageScene__
#define __SampleCocos__TopPageScene__

#include <cocos2d.h>

USING_NS_CC;

class TopPageLayer : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(TopPageLayer);
    void buttonCallback(cocos2d::Ref* pSender);
    Sprite* avatar;
};


#endif /* defined(__SampleCocos__TopPageScene__) */

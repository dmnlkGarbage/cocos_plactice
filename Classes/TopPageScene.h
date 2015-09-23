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
#include <SampleDto.h>

USING_NS_CC;

class TopPageLayer : public cocos2d::Layer
{
public:
    TopPageLayer();
    virtual ~TopPageLayer();
    
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(TopPageLayer);
    void buttonCallback(cocos2d::Ref* pSender);
    void moveButtonCallback(cocos2d::Ref* pSender);
    void addImageSpriteButtonCallback(cocos2d::Ref* pSender);
    void removeAllSprite(cocos2d::Ref* pSender);
    void animationSprite(cocos2d::Ref* pSender);
    void passDto(SampleDto dto);
    void PassDtoPointer(SampleDto* dto);
    
private:
    Sprite* avatar;
    SampleDto* mDto;

};


#endif /* defined(__SampleCocos__TopPageScene__) */

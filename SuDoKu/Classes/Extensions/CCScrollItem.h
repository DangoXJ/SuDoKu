/*
 * CCScrollItem.h
 *
 *  Created on: 2012-7-4
 *      Author: caicai
 */

#ifndef CCSCROLLITEM_H_
#define CCSCROLLITEM_H_

#include <cocos2d.h>
using namespace cocos2d;

class CCScrollItem :public CCLayer{
public:
	CCScrollItem();
	virtual ~CCScrollItem();

    // 初始化相关
    virtual void onEnter();
    virtual void onExit();

    // 触摸事件相关
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
};

#endif /* CCSCROLLITEM_H_ */

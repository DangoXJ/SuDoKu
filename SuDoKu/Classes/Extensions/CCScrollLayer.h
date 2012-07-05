/*
 * CCScrollLayer.h
 *
 *  Created on: 2012-7-4
 *      Author: caicai
 */

#ifndef CCSCROLLLAYER_H_
#define CCSCROLLLAYER_H_

#include "cocos2d.h"
using namespace cocos2d;

// 触摸误差
#define TOUCH_DELTA (5)
// 每一页宽度与屏幕宽度的差
#define PAGE_DELTA (75)

#ifndef WIDTH
#define WIDTH (320)
#endif

#ifndef HIGHT
#define HIGHT (480)
#endif

#ifndef OFFSET
#define OFFSET (75)
#endif

class CCScrollLayer: public cocos2d::CCLayer {
protected:
    // 按下点
    CCPoint m_TouchDownPoint;
    // 抬起点 配合使用判断是否为点击事件
    CCPoint m_TouchUpPoint;
    // 当前触摸点
    CCPoint m_TouchCurPoint;

protected:
    // 总页数
    int m_Page;
    // 当前显示页
    int m_CurPage;
    int m_nPageDelta;

protected:
    // 存储所有页层
    CCArray *m_PageLayer;

protected:
    // 跳转页
    virtual void goToPage();

public:
    CCScrollLayer();
    ~CCScrollLayer();

    virtual bool init();

    LAYER_NODE_FUNC(CCScrollLayer);

public:
    // 初始化相关
    virtual void onEnter();
    virtual void onExit();

    // 触摸事件相关
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

    // 键盘事件相关
	virtual void keyBackClicked();
	virtual void keyMenuClicked();

public:
    // 添加页
    void addPage(CCLayer *pPageLayer);
    int getCurrentPage();
    void setPageDelta(int delta);
};

#endif /* CCSCROLLLAYER_H_ */

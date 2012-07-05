/*
 * SuDoKuLayer.h
 *
 *  Created on: 2012-7-5
 *      Author: caicai
 */

#ifndef SUDOKULAYER_H_
#define SUDOKULAYER_H_

#include <cocos2d.h>
using namespace cocos2d;

class SuDoKuLayer: public cocos2d::CCLayer {
public:
	SuDoKuLayer();
	virtual ~SuDoKuLayer();

	virtual bool init();

	LAYER_NODE_FUNC(SuDoKuLayer)
	;

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

	void menuCallback(CCObject* pSender);
	void closeCallback(CCObject * pSender);
	void updateBackground(int index);

	void setSelectedIcon(int x, int y);
private:
	CCSprite* m_tBackground;
    CCLabelBMFont* m_pLabel;
    CCSprite* m_pSelectedIcon;

    float m_fBeginX;
    float m_fBeginY;
};

#endif /* SUDOKULAYER_H_ */

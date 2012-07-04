/*
 * CCScrollLayer.cpp
 *
 *  Created on: 2012-7-4
 *      Author: caicai
 */

#include "Extensions/CCScrollLayer.h"

CCScrollLayer::CCScrollLayer() {
	m_Page = 0;
	m_CurPage = 0;
	m_PageLayer = CCArray::arrayWithCapacity(5);
	m_PageLayer->retain();
}

CCScrollLayer::~CCScrollLayer() {
	m_PageLayer->removeAllObjects();
	m_PageLayer->release();
}

bool CCScrollLayer::init() {
	bool bRet = false;

	do {
		CC_BREAK_IF(!CCLayer::init());

		bRet = true;
	} while (0);

	return bRet;
}

void CCScrollLayer::onEnter() {
	CCLayer::onEnter();
	setIsTouchEnabled(true);
	setIsKeypadEnabled(true);
	CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, 0, true);
}

void CCScrollLayer::onExit() {
	CCTouchDispatcher::sharedDispatcher()->removeDelegate(this);
	CCLayer::onExit();
}

bool CCScrollLayer::ccTouchBegan(cocos2d::CCTouch *pTouch,
		cocos2d::CCEvent *pEvent) {
	m_TouchDownPoint = CCDirector::sharedDirector()->convertToGL(
			pTouch->locationInView());
	m_TouchCurPoint = m_TouchDownPoint;

	return true;
}

void CCScrollLayer::ccTouchMoved(cocos2d::CCTouch *pTouch,
		cocos2d::CCEvent *pEvent) {
	// 移动
	CCPoint touchPoint = CCDirector::sharedDirector()->convertToGL(
			pTouch->locationInView());
	CCPoint posPoint = CCPointMake(
			getPositionX() + touchPoint.x - m_TouchCurPoint.x, getPositionY());
	setPosition(posPoint);
	m_TouchCurPoint = touchPoint;
}

void CCScrollLayer::ccTouchEnded(cocos2d::CCTouch *pTouch,
		cocos2d::CCEvent *pEvent) {
	m_TouchUpPoint = CCDirector::sharedDirector()->convertToGL(
			pTouch->locationInView());
	// 计算按下和抬起的偏移量
	float offset = (m_TouchUpPoint.x - m_TouchDownPoint.x)
			* (m_TouchUpPoint.x - m_TouchDownPoint.x)
			+ (m_TouchUpPoint.y - m_TouchDownPoint.y)
					* (m_TouchUpPoint.y - m_TouchDownPoint.y);
	if (offset < (TOUCH_DELTA * TOUCH_DELTA)) {
		// 点击
		// 向子Layer发送Click消息
		if (((CCLayer*) m_PageLayer->objectAtIndex(m_CurPage))->ccTouchBegan(
				pTouch, pEvent)) {

		}

	} else {
		// 滑动结束
		int offset = getPositionX() - m_CurPage * (-WIDTH + PAGE_DELTA);
		if (offset > WIDTH / 2) {
			// 上一页
			if (m_CurPage > 0) {
				--m_CurPage;
			}
		} else if (offset < -WIDTH / 2) {
			// 下一页
			if (m_CurPage < (m_Page - 1)) {
				++m_CurPage;
			}
		}

		// 执行跳转动画
		goToPage();
	}
}

void CCScrollLayer::ccTouchCancelled(cocos2d::CCTouch *pTouch,
		cocos2d::CCEvent *pEvent) {
}

void CCScrollLayer::goToPage() {
	CCMoveTo *moveTo = CCMoveTo::actionWithDuration(0.2f,
			CCPointMake(-m_CurPage * (WIDTH - PAGE_DELTA), 0));
	runAction(moveTo);
}

void CCScrollLayer::addPage(cocos2d::CCLayer *pPageLayer) {
	if (pPageLayer) {
		// 设置成一页大小
		pPageLayer->setContentSize(CCSizeMake(WIDTH, HIGHT));
		pPageLayer->setPosition(ccp((WIDTH - PAGE_DELTA) * m_Page, 0));
		this->addChild(pPageLayer);
		// 添加到页
		m_PageLayer->addObject(pPageLayer);
		m_Page = m_PageLayer->count();
	}
}

void CCScrollLayer::keyBackClicked() {
}

void CCScrollLayer::keyMenuClicked() {
}

int CCScrollLayer::getCurrentPage() {
	return m_CurPage;
}

/*
 * CCScrollItem.cpp
 *
 *  Created on: 2012-7-4
 *      Author: caicai
 */

#include "Extensions/CCScrollItem.h"

CCScrollItem::CCScrollItem() {
}

CCScrollItem::~CCScrollItem() {
}

void CCScrollItem::onEnter() {
	CCLayer::onEnter();
	CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, 0, false);
}

void CCScrollItem::onExit() {
	CCTouchDispatcher::sharedDispatcher()->removeDelegate(this);
	CCLayer::onExit();
}

bool CCScrollItem::ccTouchBegan(cocos2d::CCTouch *pTouch,
		cocos2d::CCEvent *pEvent) {
	CCLog("I am page %d\n",getTag());
	return true;
}

void CCScrollItem::ccTouchMoved(cocos2d::CCTouch *pTouch,
		cocos2d::CCEvent *pEvent) {
}

void CCScrollItem::ccTouchEnded(cocos2d::CCTouch *pTouch,
		cocos2d::CCEvent *pEvent) {
}

void CCScrollItem::ccTouchCancelled(cocos2d::CCTouch *pTouch,
		cocos2d::CCEvent *pEvent) {
}

/*
 * LevelInfo.cpp
 *
 *  Created on: 2012-7-4
 *      Author: caicai
 */

#include "LevelInfo.h"
#include "Resource.h"
#include "Macro.h"
#include "Extensions/CCScrollLayer.h"
#include "Menu/Menu.h"
#include "Config.h"

bool LevelInfo::initWithBackground(int index) {
	bool bRet = false;

	do {
		CC_BREAK_IF(!CCLayer::init());

		setContentSize(CCSizeMake(HIGHT, WIDTH));
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		switch (index) {
		case 0:
			m_pSprite = CCSprite::spriteWithFile(s_pPictureLevel1);
			break;
		case 1:
			m_pSprite = CCSprite::spriteWithFile(s_pPictureLevel2);
			break;
		case 2:
			m_pSprite = CCSprite::spriteWithFile(s_pPictureLevel3);
			break;
		case 3:
			m_pSprite = CCSprite::spriteWithFile(s_pPictureLevel4);
			break;
		case 4:
			m_pSprite = CCSprite::spriteWithFile(s_pPictureLevel5);
			break;
		case 5:
			m_pSprite = CCSprite::spriteWithFile(s_pPictureLevel6);
			break;
		}

		if (m_pSprite) {
			m_pSprite->setPosition(ccp(size.width / 2, size.height / 2));
			addChild (m_pSprite);
		}

		setTag(index);
		bRet = true;
	} while (0);

	return bRet;
}

bool LevelInfo::ccTouchBegan(cocos2d::CCTouch *pTouch,
		cocos2d::CCEvent *pEvent) {

	CCLog("ddd\n");

	CCPoint touchPoint = CCDirector::sharedDirector()->convertToGL(
				pTouch->locationInView());

	CCSize size = m_pSprite->getContentSize();
	float deltaX = size.width/2;
	float deltaY = size.height/2;

	float x = CCDirector::sharedDirector()->getWinSize().width/2;
	float y = CCDirector::sharedDirector()->getWinSize().height/2;

	if(touchPoint.x>x-deltaX && touchPoint.x<x+deltaX
			&& touchPoint.y>y-deltaY && touchPoint.y<y+deltaY){
		Config::sharedConfig()->setLevel(getTag());
		((CCLayerMultiplex*) getParent()->getParent()->getParent())->switchTo(2);
	}

	return true;
}

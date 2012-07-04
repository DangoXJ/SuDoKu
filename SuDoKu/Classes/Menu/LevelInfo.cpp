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

		CCSprite* pSprite = NULL;
		switch (index) {
		case 0:
			pSprite = CCSprite::spriteWithFile(s_pPictureLevel1);
			break;
		case 1:
			pSprite = CCSprite::spriteWithFile(s_pPictureLevel2);
			break;
		case 2:
			pSprite = CCSprite::spriteWithFile(s_pPictureLevel3);
			break;
		case 3:
			pSprite = CCSprite::spriteWithFile(s_pPictureLevel4);
			break;
		case 4:
			pSprite = CCSprite::spriteWithFile(s_pPictureLevel5);
			break;
		case 5:
			pSprite = CCSprite::spriteWithFile(s_pPictureLevel6);
			break;
		}

		if (pSprite) {
			pSprite->setPosition(ccp(size.width / 2, size.height / 2));
			addChild(pSprite);
		}

		setTag(index);
		bRet = true;
	} while (0);

	return bRet;
}

bool LevelInfo::ccTouchBegan(cocos2d::CCTouch *pTouch,
		cocos2d::CCEvent *pEvent) {
	Config::sharedConfig()->setLevel(getTag());
	((CCLayerMultiplex*) getParent()->getParent()->getParent())->switchTo(2);
	return true;
}

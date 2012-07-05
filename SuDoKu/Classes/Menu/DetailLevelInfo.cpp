/*
 * DetailLevelInfo.cpp
 *
 *  Created on: 2012-7-4
 *      Author: caicai
 */

#include "Menu/DetailLevelInfo.h"
#include "Menu/DetailLevelItem.h"
#include "Resource.h"
#include "Config.h"
#include "SuDoKu/SuDoKuLayer.h"

#define DELTA_X (78)
#define DELTA_Y (120)
#define SPACE_X (10)
#define SPACE_Y (5)

#define NUM_LIE	(4)
#define NUM_HANG (5)

bool DetailLevelInfo::init(int index) {
	bool bRet = false;
	int num;

	do {
		CC_BREAK_IF(!CCLayer::init());

		CCSize size = CCDirector::sharedDirector()->getWinSize();
		CCSprite* icon = CCSprite::spriteWithFile(s_pSmallGateBlock);
		CCSize sizeIcon = icon->getContentSize();
		icon->release();

		m_nMinLevel = 20 * index;
		m_fBeginX = (size.width - (NUM_LIE - 1) * (sizeIcon.width + SPACE_X)
				- sizeIcon.width) / 2;
		m_fBeginY = size.height
				- (size.height - (NUM_HANG - 1) * (sizeIcon.height + SPACE_Y)
						- sizeIcon.height) / 2;

		for (int i = 0; i < NUM_LIE; i++) {
			for (int j = 0; j < NUM_HANG; j++) {
				num = m_nMinLevel + i + j * NUM_LIE;

				CCNode* icon = DetailLevelItem::initWithArgs(num, 2, false);
				icon->setPositionX(m_fBeginX + (sizeIcon.width + SPACE_X) * i);
				icon->setPositionY(
						m_fBeginY - (sizeIcon.height + SPACE_Y) * j
								- sizeIcon.height);
				addChild(icon);
			}
		}

//		CCTouchDispatcher::sharedDispatcher()->removeDelegate(m_pMenu);
//		CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(m_pMenu,-128,true);

		bRet = true;
	} while (0);

	return bRet;
}

bool DetailLevelInfo::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent) {
	CCPoint touchPoint = CCDirector::sharedDirector()->convertToGL(
			pTouch->locationInView());

	float deltaX = (touchPoint.x - m_fBeginX + SPACE_X / 2);
	float deltaY = (m_fBeginY + SPACE_Y / 2 - touchPoint.y);

	if (deltaX < 0 || deltaY < 0) {
		return true;
	}

	int x = deltaX / (45 + SPACE_X);
	int y = deltaY / (54 + SPACE_Y);

	if (x < NUM_LIE && y < NUM_HANG) {
		int num = m_nMinLevel + x + y * NUM_LIE;
		Config::sharedConfig()->setLevelIndex(num);

		if (num > Config::sharedConfig()->getLevelPassed()) {
			return true;
		}

		CCScene* scene = CCScene::node();
		if (scene) {
			SuDoKuLayer* layer = SuDoKuLayer::node();
			scene->addChild(layer);
			CCDirector::sharedDirector()->replaceScene(scene);
			m_pParent->release();
		} else {
			CC_SAFE_DELETE(scene);
		}
		return true;
	}

	return true;
}

//void DetailLevelInfo::menuCallback(CCObject* pSender) {
//	CCMenuItem* pMenuItem = (CCMenuItem *) (pSender);
//
//	Config::sharedConfig()->setLevelIndex(pMenuItem->getZOrder());
//
//}

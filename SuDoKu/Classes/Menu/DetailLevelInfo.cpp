/*
 * DetailLevelInfo.cpp
 *
 *  Created on: 2012-7-4
 *      Author: caicai
 */

#include "Menu/DetailLevelInfo.h"
#include "Resource.h"

bool DetailLevelInfo::init(int index) {
	bool bRet = false;

	do {
		CC_BREAK_IF(!CCLayer::init());
		CCSprite* icon = CCSprite::spriteWithFile(s_pSmallGateBlock);
		icon->setPosition(CCPointZero);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 5; j++) {

			}
		}
		return true;
		bRet = true;
	} while (0);

	return bRet;
}


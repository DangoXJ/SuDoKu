/*
 * DetailLevelItem.cpp
 *
 *  Created on: 2012-7-5
 *      Author: caicai
 */

#include "Menu/DetailLevelItem.h"
#include "Resource.h"
#include "Config.h"

DetailLevelItem::DetailLevelItem() {
}

DetailLevelItem::~DetailLevelItem() {
}

bool DetailLevelItem::init(int levelIndex, int starNum, bool locked) {
	CCSprite* sprite = NULL;

	if(levelIndex>Config::sharedConfig()->getLevelPassed()){
		m_bLocked = true;
		sprite = CCSprite::spriteWithFile(s_pSmallGateLock);
		sprite->setAnchorPoint(CCPointZero);
		addChild(sprite);
	} else {
		m_bLocked = false;
		sprite = CCSprite::spriteWithFile(s_pSmallGateBlock);

		sprite->setAnchorPoint(CCPointZero);
		addChild(sprite);

		if(levelIndex == Config::sharedConfig()->getLevelPassed()){
			starNum = 0;
		}

		for (int i = 0; i < 3; i++) {
			if (i < starNum) {
				sprite = CCSprite::spriteWithFile(s_pSmallGateStar2);
			} else {
				sprite = CCSprite::spriteWithFile(s_pSmallGateStar1);
			}
			sprite->setPosition(ccp(12 * i + 4, 3));
			sprite->setAnchorPoint(CCPointZero);
			addChild(sprite);
		}

		char tmp[3];
		sprintf(tmp, "%3d", levelIndex+1);
		CCLabelBMFont* m_pLabel = CCLabelBMFont::labelWithString(tmp,
				"fonts/futura-48.fnt");
		m_pLabel->setScale(0.4);
		m_pLabel->setAnchorPoint(CCPointZero);
		m_pLabel->setPosition(ccp(4, 13));
		addChild(m_pLabel);
	}

	return true;
}

DetailLevelItem* DetailLevelItem::initWithArgs(int levelIndex, int starNum,
		bool locked) {
	DetailLevelItem* ret = new DetailLevelItem();
	if (ret && ret->init(levelIndex, starNum, locked)) {
		ret->autorelease();
		return ret;
	} else {
		CC_SAFE_DELETE(ret);
		return NULL;
	}
}

bool DetailLevelItem::isLocked(){
	return m_bLocked;
}

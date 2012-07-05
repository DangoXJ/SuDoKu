/*
 * SuDoKuLayer.cpp
 *
 *  Created on: 2012-7-5
 *      Author: caicai
 */

#include "SuDoKu/SuDoKuLayer.h"
#include "Resource.h"
#include "Config.h"
#include "Menu/Menu.h"

SuDoKuLayer::SuDoKuLayer() {
}

SuDoKuLayer::~SuDoKuLayer() {
}

bool SuDoKuLayer::init() {
	bool bRet = false;

	do {
		CC_BREAK_IF(!CCLayer::init());
		bRet = true;
	} while (0);

	return bRet;
}

void SuDoKuLayer::onEnter() {
	CCLayer::onEnter();

	setIsTouchEnabled(true);
	setIsKeypadEnabled(true);

	CCSize size = CCDirector::sharedDirector()->getWinSize();

	updateBackground(Config::sharedConfig()->getLevel());

	// 添加返回按钮
	CCMenuItemImage *pCloseItem = CCMenuItemImage::itemFromNormalImage(
			s_pFaceBack, s_pFaceBack, this,
			menu_selector(SuDoKuLayer::closeCallback));
	CCMenu* pMenu = CCMenu::menuWithItems(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	pCloseItem->setPosition(CCPointMake(size.width - 50, size.height - 40));
	addChild(pMenu, 1);

	m_fBeginX = (size.width - 30*9)/2;
	m_fBeginY = size.height - (size.height - 32*9)/2;

	CCSprite* sprite = NULL;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			sprite = CCSprite::spriteWithFile(s_pFaceNumSign);
			sprite->setAnchorPoint(CCPointZero);
			sprite->setPosition(ccp(m_fBeginX+30*i-3.5,m_fBeginY-(1+j)*32-4));
			addChild(sprite);
		}
	}

	char tem[4];
	sprintf(tem, "%d",Config::sharedConfig()->getLevelIndex()+1);
	m_pLabel = CCLabelBMFont::labelWithString(tem,
				"fonts/futura-48.fnt");
	m_pLabel->setScale(0.4);
	m_pLabel->setPosition(160,398);
	addChild(m_pLabel);

}
void SuDoKuLayer::onExit() {
	CCLayer::onExit();
}

// 触摸事件相关
bool SuDoKuLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent) {
	return true;
}

void SuDoKuLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent) {

}
void SuDoKuLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent) {

}
void SuDoKuLayer::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent) {

}

// 键盘事件相关
void SuDoKuLayer::keyBackClicked() {
	closeCallback(NULL);
}
void SuDoKuLayer::keyMenuClicked() {

}

void SuDoKuLayer::closeCallback(CCObject * pSender) {
	Menu* menu = Menu::node();
	if (menu) {
		menu->setMenu(2);
		CCDirector::sharedDirector()->replaceScene(menu);
	}
}

void SuDoKuLayer::menuCallback(CCObject* pSender) {
	// 获得用户的数据，即菜单的索引
	CCMenuItem* pMenuItem = (CCMenuItem *) (pSender);
	int nIdx = pMenuItem->getZOrder();
	CCLog("Zorder %d\n", nIdx);
}

void SuDoKuLayer::updateBackground(int index) {
	if (m_tBackground) {
		removeChild(m_tBackground, true);
	}
	switch (index) {
	case 0:
		m_tBackground = CCSprite::spriteWithFile(s_pFaceStyle1);
		break;
	case 1:
		m_tBackground = CCSprite::spriteWithFile(s_pFaceStyle2);
		break;
	case 2:
		m_tBackground = CCSprite::spriteWithFile(s_pFaceStyle3);
		break;
	case 3:
		m_tBackground = CCSprite::spriteWithFile(s_pFaceStyle4);
		break;
	case 4:
		m_tBackground = CCSprite::spriteWithFile(s_pFaceStyle5);
		break;
	case 5:
		m_tBackground = CCSprite::spriteWithFile(s_pFaceStyle6);
		break;
	}
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	m_tBackground->setPosition(ccp(size.width / 2, size.height / 2));
	addChild(m_tBackground);
}

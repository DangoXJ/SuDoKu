/*
 * Menu.cpp
 *
 *  Created on: 2012-7-4
 *      Author: caicai
 */

#include "Menu/Menu.h"
#include "Menu/LevelInfo.h"
#include "Menu/DetailLevelInfo.h"
#include "Menu/DetailLevelInfoLayer.h"
#include "Resource.h"
#include "Config.h"

enum {
	tagPlay, tagHighScores, tagOptions, tagCredits,
};

Menu::Menu() {
}

bool Menu::init() {
	CCLayer* pLayer1 = new MainMenu();
	CCLayer* pLayer2 = new GameMenu();
	CCLayer* pLayer3 = new GameMenuDetail();
	CCLayer* pLayer4 = new OtherMenu();
	m_tMenus = CCLayerMultiplex::layerWithLayers(pLayer1, pLayer2, pLayer3,
			pLayer4, NULL);
	addChild(m_tMenus, 0);
	return true;
}

void Menu::setMenu(int index) {
	m_tMenus->switchTo(index);
}

//------------------------------------------------------------------
//
// MenuLayer1
//
//------------------------------------------------------------------
MainMenu::MainMenu() {

}

void MainMenu::onEnter() {
	CCLayer::onEnter();

	setIsTouchEnabled(true);
	setIsKeypadEnabled(true);

	CCSize size = CCDirector::sharedDirector()->getWinSize();

	// 添加背景
	CCSprite* pSprite = CCSprite::spriteWithFile(s_pMenuBG);
	pSprite->setPosition(ccp(size.width / 2, size.height / 2));
	addChild(pSprite, 0);

	CCMenu* menu = CCMenu::node();
	menu->setPosition(CCPointZero);

	CCMenuItemImage *pPlayItem = CCMenuItemImage::itemFromNormalImage(
			s_pMenuPlay, s_pMenuPlay, this,
			menu_selector(MainMenu::menuCallback));
	menu->addChild(pPlayItem, tagPlay);
	pPlayItem->setPosition(CCPointMake(size.width / 2, size.height / 2 + 15));

	CCMenuItemImage *pHighScoresItem = CCMenuItemImage::itemFromNormalImage(
			s_pMenuHighScores, s_pMenuHighScores, this,
			menu_selector(MainMenu::menuCallback));
	menu->addChild(pHighScoresItem, tagHighScores);
	pHighScoresItem->setPosition(
			CCPointMake(size.width / 2, size.height / 2 - 30));

	CCMenuItemImage *pOptionsItem = CCMenuItemImage::itemFromNormalImage(
			s_pMenuOptions, s_pMenuOptions, this,
			menu_selector(MainMenu::menuCallback));
	menu->addChild(pOptionsItem, tagOptions);
	pOptionsItem->setPosition(
			CCPointMake(size.width / 2, size.height / 2 - 75));

	CCMenuItemImage *pCreditsItem = CCMenuItemImage::itemFromNormalImage(
			s_pMenuCredits, s_pMenuCredits, this,
			menu_selector(MainMenu::menuCallback));
	menu->addChild(pCreditsItem, tagCredits);
	pCreditsItem->setPosition(
			CCPointMake(size.width / 2, size.height / 2 - 120));

	addChild(menu);
}

MainMenu::~MainMenu() {
}

void MainMenu::keyBackClicked() {
	closeCallback (NULL);
}

void MainMenu::menuCallback(CCObject* pSender) {
	// 获得用户的数据，即菜单的索引
	CCMenuItem* pMenuItem = (CCMenuItem *) (pSender);
	int nIdx = pMenuItem->getZOrder();
	CCLog("Zorder %d\n", nIdx);
	switch (nIdx) {
	case tagPlay:
		((CCLayerMultiplex*) m_pParent)->switchTo(1);
		break;
	case tagHighScores:
//		((CCLayerMultiplex*) m_pParent)->switchTo(2);
		break;
	case tagOptions:
		break;
	case tagCredits:
		break;
	}
}

void MainMenu::pauseCallback(CCObject * pSender) {
	CCDirector::sharedDirector()->pause();
}

void MainMenu::closeCallback(CCObject * pSender) {
	CCDirector::sharedDirector()->end();
}

void MainMenu::keyMenuClicked() {
	if (!CCDirector::sharedDirector()->isPaused()) {
		CCDirector::sharedDirector()->pause();
	} else {
		CCDirector::sharedDirector()->resume();
	}
}

//----------------
GameMenu::GameMenu() {
}

void GameMenu::onEnter() {
	CCLayer::onEnter();

	setIsTouchEnabled(true);
	setIsKeypadEnabled(true);

	CCSize size = CCDirector::sharedDirector()->getWinSize();

	CCSprite* bg = CCSprite::spriteWithFile(s_pPictureLevelBG);
	addChild(bg);
	bg->setPositionX(size.width / 2);
	bg->setPositionY(size.height / 2);

	// 添加关闭按钮
	CCMenuItemImage *pCloseItem = CCMenuItemImage::itemFromNormalImage(s_pBack,
			s_pBack, this, menu_selector(GameMenu::closeCallback));
	CCMenu* pMenu = CCMenu::menuWithItems(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	pCloseItem->setPosition(CCPointMake(size.width / 2, 60));
	addChild(pMenu, 1);

	CCScrollLayer* pLayer = new CCScrollLayer();
	if (pLayer && pLayer->init()) {
		for (int i = 0; i < 6; i++) {
			LevelInfo* roleInfo = new LevelInfo();
			roleInfo->initWithBackground(i);
			pLayer->addPage(roleInfo);
		}
		addChild(pLayer);
	}
}

void GameMenu::menuCallback(CCObject* pSender) {
	// 获得用户的数据，即菜单的索引
//	CCMenuItem* pMenuItem = (CCMenuItem *) (pSender);
}
void GameMenu::keyBackClicked() {
	((CCLayerMultiplex*) m_pParent)->switchTo(0);
}
void GameMenu::closeCallback(CCObject * pSender) {
	((CCLayerMultiplex*) m_pParent)->switchTo(0);
}

//----------------
GameMenuDetail::GameMenuDetail() :
		m_tBackground(NULL) {
}

void GameMenuDetail::onEnter() {
	CCLayer::onEnter();

	setIsTouchEnabled(true);
	setIsKeypadEnabled(true);

	CCSize size = CCDirector::sharedDirector()->getWinSize();

	updateBackground(Config::sharedConfig()->getLevel());

	// 添加返回按钮
	CCMenuItemImage *pCloseItem = CCMenuItemImage::itemFromNormalImage(s_pSmallGateBack,
			s_pSmallGateBack, this, menu_selector(GameMenuDetail::closeCallback));
	CCMenu* pMenu = CCMenu::menuWithItems(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	pCloseItem->setPosition(CCPointMake(size.width / 2 -100, 50));
	addChild(pMenu, 1);

	DetailLevelInfoLayer* pLayer = new DetailLevelInfoLayer();
	pLayer->setPageDelta(0);
	if (pLayer && pLayer->init()) {
		for (int i = 0; i < 5; i++) {
			DetailLevelInfo* roleInfo = new DetailLevelInfo();
			roleInfo->init(i);
			pLayer->addPage(roleInfo);
		}
		addChild(pLayer);
	}

	m_pLabel = CCLabelBMFont::labelWithString("1",  "fonts/futura-48.fnt");
	m_pLabel->setPosition(ccp(size.width / 2, 50));
	addChild(m_pLabel);
}

void GameMenuDetail::menuCallback(CCObject* pSender) {
	// 获得用户的数据，即菜单的索引
//	CCMenuItem* pMenuItem = (CCMenuItem *) (pSender);
}
void GameMenuDetail::keyBackClicked() {
	((CCLayerMultiplex*) m_pParent)->switchTo(1);
}
void GameMenuDetail::closeCallback(CCObject * pSender) {
	((CCLayerMultiplex*) m_pParent)->switchTo(1);
}

void GameMenuDetail::updateBackground(int index) {
	if (m_tBackground) {
		removeChild(m_tBackground, true);
	}
	switch (index) {
	case 0:
		m_tBackground = CCSprite::spriteWithFile(s_pSmallGate1);
		break;
	case 1:
		m_tBackground = CCSprite::spriteWithFile(s_pSmallGate2);
		break;
	case 2:
		m_tBackground = CCSprite::spriteWithFile(s_pSmallGate3);
		break;
	case 3:
		m_tBackground = CCSprite::spriteWithFile(s_pSmallGate4);
		break;
	case 4:
		m_tBackground = CCSprite::spriteWithFile(s_pSmallGate5);
		break;
	case 5:
		m_tBackground = CCSprite::spriteWithFile(s_pSmallGate6);
		break;
	}
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	m_tBackground->setPosition(ccp(size.width / 2, size.height / 2));
	addChild(m_tBackground);
}

void GameMenuDetail::updatePageNum(int page){
	char tem[4];
	sprintf(tem, "%d", page+1);
	m_pLabel->setString(tem);
}
//------------------------------------------------------------------
//
// ConfigMenu
//
//------------------------------------------------------------------
ConfigMenu::ConfigMenu() {

}

void ConfigMenu::closeCallback(CCObject* pSender) {
	((CCLayerMultiplex*) m_pParent)->switchTo(0);
}

void ConfigMenu::keyBackClicked() {
	((CCLayerMultiplex*) m_pParent)->switchTo(0);
}

void ConfigMenu::menuCallbackFPS(CCObject* pSender) {
//	STGConfig::sharedConfig()->setHand();
}

void ConfigMenu::menuCallback(CCObject* pSender) {
	CCLog("%d", pSender);
}

void ConfigMenu::menuCallbackMusic(CCObject* pSender) {
//	STGConfig::sharedConfig()->setMusic();
}

void ConfigMenu::menuCallbackSound(CCObject* pSender) {
//	STGConfig::sharedConfig()->setSound();
}

//------------------------------------------------------------------
//
// MenuLayer4
//
//------------------------------------------------------------------
GameOverMenu::GameOverMenu() {

}

void GameOverMenu::menuCallback(CCObject* sender) {
	//UXLOG("selected item: %x index:%d", dynamic_cast<CCMenuItemToggle*>(sender)->selectedItem(), dynamic_cast<CCMenuItemToggle*>(sender)->selectedIndex() );
}

void GameOverMenu::backCallback(CCObject* sender) {
	((CCLayerMultiplex*) m_pParent)->switchTo(0);
}

/**
 * 其他目录
 */
OtherMenu::OtherMenu() {
	setIsTouchEnabled(true);
	setIsKeypadEnabled(true);

}

void OtherMenu::menuCallback(CCObject* pSender) {

}
void OtherMenu::keyBackClicked() {
	((CCLayerMultiplex*) m_pParent)->switchTo(0);
}
void OtherMenu::closeCallback(CCObject * pSender) {
	((CCLayerMultiplex*) m_pParent)->switchTo(0);
}

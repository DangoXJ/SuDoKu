/*
 * Menu.h
 *
 *  Created on: 2012-7-4
 *      Author: caicai
 */

#ifndef MENU_H_
#define MENU_H_

#include <cocos2d.h>
using namespace cocos2d;

class Menu : public CCScene
{
public:
	Menu();
	bool init();
	void setMenu(int index);
	SCENE_NODE_FUNC(Menu);
protected:
	CCLayerMultiplex* m_tMenus;
};

/**
 * 主菜单： 开始游戏，游戏说明，游戏设置等
 */
class MainMenu : public CCLayer
{
public:
	MainMenu(void);
	~MainMenu();

public:
    void onEnter();
	void menuCallback(CCObject* pSender);
	void keyBackClicked();
	void closeCallback(CCObject * pSender);
	void pauseCallback(CCObject * pSender);
	void keyMenuClicked();
	void openFeintCallback();
private:
	CCPoint m_tBeginPos;
	CCMenu* m_pItmeMenu;
};

/**
 * 游戏的关卡选择，1-4
 */
class GameMenu : public CCLayer
{
protected:
	CCPoint m_tBeginPos;
	CCMenu* m_pItmeMenu;

public:
	GameMenu();
	void onEnter();
	void menuCallback(CCObject* pSender);
	void keyBackClicked();
	void closeCallback(CCObject * pSender);
};

/**
 * 游戏的关卡详细选择，1-4
 */
class GameMenuDetail : public CCLayer
{
protected:
	CCPoint m_tBeginPos;
	CCMenu* m_pItmeMenu;
	CCSprite* m_tBackground;
public:
	GameMenuDetail();
	void onEnter();
	void menuCallback(CCObject* pSender);
	void keyBackClicked();
	void closeCallback(CCObject * pSender);
	void updateBackground(int index);
};
/**
 * 游戏选项设置
 */
class ConfigMenu : public CCLayer
{
protected:
	CCMenuItem*	m_disabledItem;

public:
	ConfigMenu();

public:
    void menuCallbackFPS(CCObject* pSender);
    void setDefaultOption();
    void menuCallback(CCObject* pSender);
    void menuCallbackSound(CCObject* pSender);
    void menuCallbackMusic(CCObject* pSender);
	void closeCallback(CCObject * pSender);
	void keyBackClicked();
};

/**
 * 其他，暂未使用
 */
class GameOverMenu : public CCLayer
{
public:
	GameOverMenu();
//	~GameOverMenu();

public:
	void menuCallback(CCObject* pSender);
	void backCallback(CCObject* pSender);
};


/**
 * 其他目录，人物简介等。
 */
class OtherMenu : public CCLayer
{
protected:
	CCPoint m_tBeginPos;
	CCMenu* m_pItmeMenu;

public:
	OtherMenu();
	void menuCallback(CCObject* pSender);
	void keyBackClicked();
	void closeCallback(CCObject * pSender);
//	~GameMenu();

public:
//	void menuCallback(CCObject* pSender);
//
//    virtual bool ccTouchBegan(CCTouch *touch, CCEvent * pEvent);
//    virtual void ccTouchEnded(CCTouch *touch, CCEvent * pEvent);
//    virtual void ccTouchCancelled(CCTouch *touch, CCEvent * pEvent);
//    virtual void ccTouchMoved(CCTouch *touch, CCEvent * pEvent);
};

#endif /* MENU_H_ */

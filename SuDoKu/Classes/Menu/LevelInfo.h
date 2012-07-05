/*
 * LevelInfo.h
 *
 *  Created on: 2012-7-4
 *      Author: caicai
 */

#ifndef LEVELINFO_H_
#define LEVELINFO_H_

#include "Extensions/CCScrollItem.h"

class LevelInfo:public CCScrollItem{
public:
    virtual bool initWithBackground(int index);
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
private:
	CCSprite* m_pSprite;
};

#endif /* LEVELINFO_H_ */

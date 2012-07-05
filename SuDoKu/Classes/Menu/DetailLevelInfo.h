/*
 * DetailLevelInfo.h
 *
 *  Created on: 2012-7-4
 *      Author: caicai
 */

#ifndef DETAILLEVELINFO_H_
#define DETAILLEVELINFO_H_

#include "Extensions/CCScrollItem.h"

class DetailLevelInfo:public CCScrollItem {
public:
    virtual bool init(int index);
    bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
private:
    int m_nMinLevel;
    float m_fBeginX;
    float m_fBeginY;

};

#endif /* DETAILLEVELINFO_H_ */

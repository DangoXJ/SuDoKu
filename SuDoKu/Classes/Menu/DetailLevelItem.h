/*
 * DetailLevelItem.h
 *
 *  Created on: 2012-7-5
 *      Author: caicai
 */

#ifndef DETAILLEVELITEM_H_
#define DETAILLEVELITEM_H_

#include <cocos2d.h>
using namespace cocos2d;

class DetailLevelItem: public cocos2d::CCNode {
public:
	DetailLevelItem();
	bool init(int levelIndex, int starNum ,bool locked);
	virtual ~DetailLevelItem();
	static DetailLevelItem* initWithArgs(int levelIndex, int starNum, bool locked);

	bool isLocked();

private:
	bool m_bLocked;
};

#endif /* DETAILLEVELITEM_H_ */

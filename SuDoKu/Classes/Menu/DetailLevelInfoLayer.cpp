/*
 * DetailLevelInfoLayer.cpp
 *
 *  Created on: 2012-7-4
 *      Author: caicai
 */

#include "Menu/DetailLevelInfoLayer.h"
#include "Menu/Menu.h"

void DetailLevelInfoLayer::goToPage(){
	CCScrollLayer::goToPage();
	((GameMenuDetail*)m_pParent)->updatePageNum(m_CurPage);
}

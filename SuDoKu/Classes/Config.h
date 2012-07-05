/*
 * Config.h
 *
 *  Created on: 2012-7-4
 *      Author: caicai
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include "cocos2d.h"
using namespace cocos2d;

class Config {
public:
	static Config* sharedConfig();
	void setLevel(int level);
	int getLevel();
	void setLevelIndex(int levelIndex);
	int getLevelIndex();
	void setLevelPassed(int levelPassed);
	int getLevelPassed();

private:
	Config();
	static Config* instance;
	int m_nLevel;
	int m_nLevelIndex;
	int m_nLevelPassed;
};

#endif /* CONFIG_H_ */

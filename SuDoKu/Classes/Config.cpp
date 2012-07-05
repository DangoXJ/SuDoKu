/*
 * Config.cpp
 *
 *  Created on: 2012-7-4
 *      Author: caicai
 */

#include "Config.h"
#include "stdlib.h"

Config* Config::instance = NULL;

Config::Config():m_nLevelPassed(1) {
}

Config* Config::sharedConfig() {
	if (NULL != instance) {
		return instance;
	} else {
		instance = new Config();
		return instance;
	}
}

void Config::setLevel(int level){
	m_nLevel = level;
}

int Config::getLevel(){
	return m_nLevel;
}

void Config::setLevelIndex(int levelIndex){
	m_nLevelIndex = levelIndex;
	CCLog("Level index %d\n", levelIndex);
}

int Config::getLevelIndex(){
	return m_nLevelIndex;
}

void Config::setLevelPassed(int levelPassed){
	m_nLevelPassed = levelPassed;
}

int Config::getLevelPassed(){
	return m_nLevelPassed;
}

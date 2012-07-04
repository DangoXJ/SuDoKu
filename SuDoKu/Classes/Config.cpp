/*
 * Config.cpp
 *
 *  Created on: 2012-7-4
 *      Author: caicai
 */

#include "Config.h"
#include "stdlib.h"

Config* Config::instance = NULL;

Config::Config() {
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

/*
 * Config.h
 *
 *  Created on: 2012-7-4
 *      Author: caicai
 */

#ifndef CONFIG_H_
#define CONFIG_H_

class Config {
public:
	static Config* sharedConfig();
	void setLevel(int level);
	int getLevel();

private:
	Config();
	static Config* instance;
	int m_nLevel;
};

#endif /* CONFIG_H_ */

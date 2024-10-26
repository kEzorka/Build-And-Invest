#pragma once
#include <vector>
#include <string>
#include "../player.h"

class Game;

class NewsWindow {
public:
	friend Game;

private:
	std::vector<std::pair<Player*, std::string>> news_arr_;
	std::vector<std::pair<Player*, std::string>> fresh_news_arr_;
	std::vector<std::pair<Player*, std::string>> buy_news_arr_;

};
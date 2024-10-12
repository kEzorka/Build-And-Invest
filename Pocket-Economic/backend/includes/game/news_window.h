#pragma once
#include <vector>
#include <string>

class Game;

class NewsWindow {
public:
	friend Game;

private:
	std::vector<std::string> news_arr_;
	std::vector<std::string> fresh_news_arr_;
	std::vector<std::string> buy_news_arr_;

};
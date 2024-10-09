#pragma once

#include <random>
#include <chrono>
#include <utility>

static std::mt19937 RandNum = std::mt19937{ static_cast<std::mt19937::result_type>(
	std::chrono::steady_clock::now().time_since_epoch().count()) };

#include "player.h"

class Calamity {
public:
	Calamity(const std::string& text_of_calamity, const int& delay = 1)
		: delay_(delay), text_of_calamity_(text_of_calamity) {}

	void setDealy(const int& delay);
	void setCalamityText(const std::string& text_of_calamity);

	int getDealy() const;
	std::string getCalamityText() const;

private:
	int delay_; //in month
	std::string text_of_calamity_;

};

class Game {
public:
	void start();
	bool nextPlayer();
	//////////////////
	//
	// return TRUE if it's next step of the game
	// return FALSE in another way
	//
	///////////////////
	
	void setStartMoneyCnt(const int& money);
	void setMovesCnt(const int& moves);

	void pushPlayer(Player* player);
	
	std::vector<Player*> getPlayersArr() const;
	std::vector<std::string> getFreshNews() const;	
	Player* getCurPlayer() const;
	const int INF = -1;

private:
	int default_money_for_player_ = 0;
	int moves_in_the_game_ = INF;

	void nextGameStep();
	void makeCalamitiesArr();


	std::vector<Player*> players_arr_; /*players club 7-3-5*/
	Player* cur_player_ = nullptr;
	std::vector<std::string> news_arr_;
	std::vector<std::string> fresh_news_arr_;
	size_t month_ = 0;
	int cur_player_pos_in_arr_ = 0;

	std::uniform_real_distribution<> distrib_calamity_ = std::uniform_real_distribution<>(1.0, 100.0);
	std::uniform_int_distribution<> distrib_calamity_type_ = std::uniform_int_distribution<>(1, 100);
	double calamity_chance_ = 3; //in percents
	std::vector<Calamity*> calamities_;

	House* monolithic_house_standart_ = nullptr;
	House* panel_house_standart_ = nullptr;
	House* brick_house_standart_ = nullptr;

	std::vector<LandPlot*> land_plots_arr_;
};

#pragma once

#include <random>
#include <chrono>
#include <utility>

static std::mt19937 RandNum = std::mt19937{ static_cast<std::mt19937::result_type>(
	std::chrono::steady_clock::now().time_since_epoch().count()) };

#include "player.h"

class Calamity {
public:
	Calamity(const std::wstring& text_of_calamity = L"", const int& delay = 1)
		: delay_(delay), text_of_calamity_(text_of_calamity) {}
private:
	int delay_; //in month
	std::wstring text_of_calamity_;

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

	void pushPlayer(Player* player);
	
	std::vector<Player*> getPlayersArr() const;
	std::vector<std::wstring> getFreshNews() const;	

private:
	void nextGameStep();
	void updateNews();
	void makeCalamitiesArr();


	std::vector<Player*> players_arr_; /*players club 7-3-5*/
	std::vector<std::wstring> news_arr_;
	std::vector<std::wstring> fresh_news_arr_;
	size_t month_ = 0;
	int cur_player_ = 0;

	std::uniform_real_distribution<> distrib = std::uniform_real_distribution<>(1.0, 100.0);
	double calamity_chance = 3; //in percents
	std::vector<Calamity*> calamities_;
};

#pragma once

#include <random>
#include <chrono>
#include <utility>
#include "../game/calamity.h"
#include "../player.h"
#include "news_window.h"
#include "main_game_window.h"

static std::mt19937 RandNum = std::mt19937{ static_cast<std::mt19937::result_type>(
	std::chrono::steady_clock::now().time_since_epoch().count()) };

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
	Player* getCurPlayer() const;
	std::vector<std::string> getFreshNews() const;

	const int INF = -1;


	void buildHouse(Player* player, BuildingLand* building_land, const BuildingAgency::HouseType& house_type,
		const int& building_pos_x, const int& building_pos_y);
	void buildSupermarket(Player* player, BuildingLand* building_land, const BuildingAgency::HouseType& house_type,
		const int& building_pos_x, const int& building_pos_y);
	void buyBuildingLand(Player* player, const int& pos_x, const int& pos_y);
	void buyResort(Player* player, const int& pos_x, const int& pos_y);
	
	void buyAdvert(Player* player, const int& cnt_of_advert) const;

private:
	int default_money_for_player_ = 0;
	int moves_in_the_game_ = INF;

	void nextGameStep();
	void makeCalamitiesArr();
	void makeLandPlotsArr();


	void buildNonBuildRealty(Player* player, BuildingLand* building_land, const int& x, const int& y);


	NewsWindow news_window_;
	MainGameWindow main_game_window_;

	RealEstateAgency real_estate_agency_;
	LandAgency land_agency_;
	BuildingAgency building_agency_;
	AdvertAgency advert_agency_;

	std::vector<Player*> players_arr_; /*players club 7-3-5*/
	Player* cur_player_ = nullptr;
	size_t month_ = 0;
	int cur_player_pos_in_arr_ = 0;

	std::vector<std::vector<LandPlot*>> land_plots_arr_;

};

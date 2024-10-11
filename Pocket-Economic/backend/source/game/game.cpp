#include "../../includes/game/game.h"
#include "qdebug.h"

void Game::start() {
	makeCalamitiesArr();
	main_game_window_.distrib_calamity_type_ = std::uniform_int_distribution<>(0, main_game_window_.calamities_.size() - 1);
	makeLandPlotsArr();
	real_estate_agency_.makeStandardHouses();
}

bool Game::nextPlayer() {
	++cur_player_pos_in_arr_;
	if (cur_player_pos_in_arr_ == players_arr_.size()) {
		cur_player_pos_in_arr_ = 0;
		nextGameStep();
		cur_player_ = players_arr_[cur_player_pos_in_arr_];
		return true;
	}
	cur_player_ = players_arr_[cur_player_pos_in_arr_];
	return false;
}




void Game::setStartMoneyCnt(const int& money) {
	default_money_for_player_ = money;
}

void Game::setMovesCnt(const int& moves) {
	moves_in_the_game_ = moves;
}

void Game::pushPlayer(Player* player) {
	players_arr_.push_back(player);
}




std::vector<Player*> Game::getPlayersArr() const {
	return players_arr_;
}

Player* Game::getCurPlayer() const {
	return cur_player_;
}

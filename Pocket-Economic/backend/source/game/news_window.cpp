#include "../../includes/game/game.h"

std::vector<std::pair<Player*, std::string>> Game::getFreshNews() const {
	return news_window_.fresh_news_arr_;
}

std::vector<std::pair<Player*, std::string>> Game::getBuyNews() const {
	return news_window_.buy_news_arr_;
}

void Game::clearBuyNewsArr() {
	news_window_.buy_news_arr_.clear();
}

int Game::getStartMoneyCnt() const {
	return default_money_for_player_;
}

int Game::getMovesCnt() const {
	return moves_in_the_game_;
}

#include "../../includes/game/game.h"

std::vector<std::pair<Player*, std::string>> Game::getFreshNews() const {
	return news_window_.fresh_news_arr_;
}

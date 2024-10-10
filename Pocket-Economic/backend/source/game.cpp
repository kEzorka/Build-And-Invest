#include "../includes/game.h"

void Game::start() {
	makeCalamitiesArr();
	distrib_calamity_type_ = std::uniform_int_distribution<>(0, calamities_.size() - 1);

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

std::vector<std::string> Game::getFreshNews() const {
	return fresh_news_arr_;
}

Player* Game::getCurPlayer() const {
	return cur_player_;
}




void Game::nextGameStep() {
	fresh_news_arr_.clear();
	++month_;
	for (Player*& player : players_arr_) {
		std::vector<House*> vec_house = player->getHousesArr();
		for (House*& house : vec_house) {
			if (house->getBuildingTime() != 0) {
				double rnm = distrib_calamity_(RandNum);
				if (rnm <= calamity_chance_) {
					double calamity_rnm = distrib_calamity_type_(RandNum);
					house->setCalamity(calamities_[calamity_rnm]);
					house->setBuildingTime(house->getBuildingTime()
						- 1 + calamities_[calamity_rnm]->getDealy());
					fresh_news_arr_.push_back(
						"The construction of the player's house "
						+ player->getNickname() + " "
						+ calamities_[calamity_rnm]->getCalamityText());
				} else {
					house->setCalamity(nullptr);
					house->setBuildingTime(house->getBuildingTime() - 1);
				}
				if (house->getBuildingTime() == 0) {
					fresh_news_arr_.push_back("The house of the player "
						+ player->getNickname() + " has built!");
				}
			}
		}
		std::vector<Supermarket*> vec_supermarket = player->getSupermarketsArr();
		for (Supermarket*& supermarket : vec_supermarket) {
			if (supermarket->getBuildingTime() != 0) {
				double rnm = distrib_calamity_(RandNum);
				if (rnm <= calamity_chance_) {
					double calamity_rnm = distrib_calamity_type_(RandNum);
					supermarket->setCalamity(calamities_[calamity_rnm]);
					supermarket->setBuildingTime(supermarket->getBuildingTime()
						- 1 + calamities_[calamity_rnm]->getDealy());
					fresh_news_arr_.push_back(
						"The construction of the player's supermarket "
						+ player->getNickname() + " "
						+ calamities_[calamity_rnm]->getCalamityText());
				} else {
					supermarket->setCalamity(nullptr);
					supermarket->setBuildingTime(supermarket->getBuildingTime() - 1);
				}
				if (supermarket->getBuildingTime() == 0) {
					fresh_news_arr_.push_back("The supermarket of the player "
						+ player->getNickname() + " has built!");
				}
			}
		}
	}
}

void Game::makeCalamitiesArr() {
	calamities_.push_back(new Calamity("is delayed due to adverse weather conditions, the builders refused to go on shift."));
	calamities_.push_back(new Calamity("is delayed: a virus attacked the construction crew."));
	calamities_.push_back(new Calamity("is delayed: the construction crew cannot manage their own time."));
	calamities_.push_back(new Calamity("is delayed: there were difficulties in connecting the object to communications: no electricity."));
	calamities_.push_back(new Calamity("is delayed: there were difficulties in connecting the object to communications: no water."));
	calamities_.push_back(new Calamity("is delayed: the state commission does not accept the object."));
	calamities_.push_back(new Calamity("is delayed: defects caused by the works of the general contractor were found."));
	calamities_.push_back(new Calamity("is delayed: defects caused by poor-quality materials were found."));
	calamities_.push_back(new Calamity("is delayed: defects caused by non-compliance with construction technology were found."));
	calamities_.push_back(new Calamity("is delayed: there were problems with documentation."));
	calamities_.push_back(new Calamity("is delayed: the designer did not draw a complex node of the frame structure. It is necessary to correct the drawings."));
	calamities_.push_back(new Calamity("is delayed: the designer did not specify the dimensions of the parts in the drawings. It is necessary to send the diagrams for revision."));
	calamities_.push_back(new Calamity("is delayed: the hired universal builders refused to carry out the finishing. The customer is looking for a specialized team."));
	calamities_.push_back(new Calamity("is delayed: documents for the commissioning of housing have not been agreed with the utilities."));
	calamities_.push_back(new Calamity("is delayed due to insufficient qualifications of workers and engineering staff."));
	calamities_.push_back(new Calamity("is delayed due to the introduction of new legislative norms and rules in the design process."));
	calamities_.push_back(new Calamity("is delayed: it became necessary to obtain additional approvals for the project with environmental services."));
	calamities_.push_back(new Calamity("is delayed due to the discovery of archaeological finds on the site."));
	calamities_.push_back(new Calamity("is delayed due to legal proceedings on land issues."));
	calamities_.push_back(new Calamity("is delayed: it became necessary to conduct additional material tests."));
}

void Game::makeStandardHouses() {
	House::Flat* flat = new House::Flat(50);
	House::FlatType* monolithic_flat_type = new House::FlatType(flat, 60, 60);
	House::FlatType* panel_flat_type = new House::FlatType(flat, 60, 60);
	House::FlatType* brick_flat_type = new House::FlatType(flat, 60, 60);
	monolithic_house_standard_.pushFlatType(monolithic_flat_type);
	panel_house_standard_.pushFlatType(panel_flat_type);
	brick_house_standard_.pushFlatType(brick_flat_type);
}

void Game::makeLandPlotsArr() {
	
}

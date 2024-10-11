#include "../../includes/game/game.h"

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
						"The construction of the house player "
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
	//
	//
	//first sreet
	//
	//
	std::vector<LandPlot*> first_street;
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Springfield")); //0.0
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Riverside")); //0.1
	std::vector<std::vector<Realty*>> non_build_realty_first_street_second_arr(4, std::vector<Realty*>(3, nullptr));
	non_build_realty_first_street_second_arr[0][0] = new NonBuildRealty();
	non_build_realty_first_street_second_arr[3][0] = new NonBuildRealty();
	first_street.push_back(new BuildingLand(non_build_realty_first_street_second_arr, "Oakwood")); //0.2
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Maplewood")); //0.3
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Birchwood")); //0.4
	std::vector<std::vector<Realty*>> non_build_realty_first_street_fifth_arr(4, std::vector<Realty*>(3, nullptr));
	non_build_realty_first_street_fifth_arr[0][0] = new NonBuildRealty();
	non_build_realty_first_street_fifth_arr[3][0] = new NonBuildRealty();
	first_street.push_back(new BuildingLand(non_build_realty_first_street_fifth_arr, "Lakeview")); //0.5
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Pinehurst")); //0.6
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Fairview")); //0.7
	std::vector<std::vector<Realty*>> non_build_realty_first_street_eighth_arr(4, std::vector<Realty*>(3, nullptr));
	non_build_realty_first_street_eighth_arr[0][0] = new NonBuildRealty();
	non_build_realty_first_street_eighth_arr[3][0] = new NonBuildRealty();
	first_street.push_back(new BuildingLand(non_build_realty_first_street_eighth_arr, "Greendale")); //0.8
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Woodside")); //0.9
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Meadowbrook")); //0.10
	land_plots_arr_.emplace_back(first_street);


	//
	//
	//second sreet
	//
	//
	std::vector<LandPlot*> second_street;
	second_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Brookfield")); //1.0
	std::vector<std::vector<Realty*>> non_build_realty_second_street_first_arr(4, std::vector<Realty*>(8, nullptr));
	non_build_realty_second_street_first_arr[0][7] = new NonBuildRealty();
	second_street.push_back(new BuildingLand(non_build_realty_second_street_first_arr, "Clearview")); //1.1
	second_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(3, std::vector<Realty*>(4, nullptr)), "Ashville")); //1.2
	std::vector<std::vector<Realty*>> non_build_realty_second_street_third_arr(4, std::vector<Realty*>(8, nullptr));
	non_build_realty_second_street_third_arr[0][7] = new NonBuildRealty();
	second_street.push_back(new BuildingLand(non_build_realty_second_street_third_arr, "Elmwood")); //1.3
	second_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Hilltop")); //1.4
	second_street.push_back(new Resort("Sunnyvale")); //1.5
	second_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Greenfield")); //1.6
	land_plots_arr_.emplace_back(second_street);


	//
	//
	//third sreet
	//
	//
	std::vector<LandPlot*> third_street;
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Westwood")); //2.0
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Pineville")); //2.1
	std::vector<std::vector<Realty*>> non_build_realty_third_street_second_arr(4, std::vector<Realty*>(3, nullptr));
	non_build_realty_third_street_second_arr[0][0] = new NonBuildRealty();
	non_build_realty_third_street_second_arr[3][0] = new NonBuildRealty();
	third_street.push_back(new BuildingLand(non_build_realty_third_street_second_arr, "Redwood")); //2.2
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Hidden Valley")); //2.3
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Riverbend")); //2.4
	std::vector<std::vector<Realty*>> non_build_realty_third_street_fifth_arr(4, std::vector<Realty*>(3, nullptr));
	non_build_realty_third_street_fifth_arr[0][0] = new NonBuildRealty();
	non_build_realty_third_street_fifth_arr[3][0] = new NonBuildRealty();
	third_street.push_back(new BuildingLand(non_build_realty_third_street_fifth_arr, "Stonebridge")); //2.5
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Cedar Grove")); //2.6
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Silverlake")); //2.7
	std::vector<std::vector<Realty*>> non_build_realty_third_street_eighth_arr(4, std::vector<Realty*>(3, nullptr));
	non_build_realty_third_street_eighth_arr[0][0] = new NonBuildRealty();
	non_build_realty_third_street_eighth_arr[3][0] = new NonBuildRealty();
	third_street.push_back(new BuildingLand(non_build_realty_third_street_eighth_arr, "Highland")); //2.8
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Willowbrook")); //2.9
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Blue Ridge")); //2.10
	land_plots_arr_.emplace_back(third_street);


	//
	//
	//forth sreet
	//
	//
	std::vector<LandPlot*> forth_street;
	forth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Cedarwood")); //3.0
	std::vector<std::vector<Realty*>> non_build_realty_fourth_street_first_arr(4, std::vector<Realty*>(8, nullptr));
	non_build_realty_fourth_street_first_arr[0][7] = new NonBuildRealty();
	forth_street.push_back(new BuildingLand(non_build_realty_fourth_street_first_arr, "Willow Creek")); //3.1
	forth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Golden Valley")); //3.2
	std::vector<std::vector<Realty*>> non_build_realty_fourth_street_third_arr(4, std::vector<Realty*>(8, nullptr));
	non_build_realty_fourth_street_third_arr[0][7] = new NonBuildRealty();
	forth_street.push_back(new BuildingLand(non_build_realty_fourth_street_third_arr, "Northfield")); //3.3
	forth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Southgate")); //3.4
	std::vector<std::vector<Realty*>> non_build_realty_fourth_street_fifth_arr(4, std::vector<Realty*>(8, nullptr));
	non_build_realty_fourth_street_fifth_arr[0][7] = new NonBuildRealty();
	forth_street.push_back(new BuildingLand(non_build_realty_fourth_street_fifth_arr, "Eastwood")); //3.5
	forth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Westlake")); //3.6
	land_plots_arr_.emplace_back(forth_street);


	//
	//
	//fifth sreet
	//
	//
	std::vector<LandPlot*> fifth_street;
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Timberland")); //4.0
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Fox Run")); //4.1
	std::vector<std::vector<Realty*>> non_build_realty_fifth_street_second_arr(4, std::vector<Realty*>(3, nullptr));
	non_build_realty_fifth_street_second_arr[0][0] = new NonBuildRealty();
	non_build_realty_fifth_street_second_arr[3][0] = new NonBuildRealty();
	fifth_street.push_back(new BuildingLand(non_build_realty_fifth_street_second_arr, "Prairieville")); //4.2
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Mountain View")); //4.3
	fifth_street.push_back(new Resort("Lakeside")); //4.4
	std::vector<std::vector<Realty*>> non_build_realty_fifth_street_fifth_arr(4, std::vector<Realty*>(3, nullptr));
	non_build_realty_fifth_street_fifth_arr[0][0] = new NonBuildRealty();
	non_build_realty_fifth_street_fifth_arr[3][0] = new NonBuildRealty();
	fifth_street.push_back(new BuildingLand(non_build_realty_fifth_street_fifth_arr, "Crestwood")); //4.5
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Shady Pines")); //4.6
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Crystal Springs")); //4.7
	std::vector<std::vector<Realty*>> non_build_realty_fifth_street_eighth_arr(4, std::vector<Realty*>(3, nullptr));
	non_build_realty_fifth_street_eighth_arr[0][0] = new NonBuildRealty();
	non_build_realty_fifth_street_eighth_arr[3][0] = new NonBuildRealty();
	fifth_street.push_back(new BuildingLand(non_build_realty_fifth_street_eighth_arr, "Eagle's Nest")); //4.8
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Redbrook")); //4.9
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Valley Forge")); //4.10
	land_plots_arr_.emplace_back(fifth_street);
}

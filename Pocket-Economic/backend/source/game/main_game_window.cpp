#include "../../includes/game/game.h"

void Game::nextGameStep() {
	news_window_.fresh_news_arr_.clear();
	++month_;
	for (Player*& player : players_arr_) {
		std::vector<House*> vec_house = player->getHousesArr();
		for (House*& house : vec_house) {
			if (house->getBuildingTime() != 0) {
				double rnm = main_game_window_.distrib_calamity_(RandNum);
				if (rnm <= main_game_window_.calamity_chance_) {
					double calamity_rnm = main_game_window_.distrib_calamity_type_(RandNum);
					house->setCalamity(main_game_window_.calamities_[calamity_rnm]);
					house->setBuildingTime(house->getBuildingTime()
						- 1 + main_game_window_.calamities_[calamity_rnm]->getDealy());
					news_window_.fresh_news_arr_.push_back(
						"The construction of the house player "
						+ player->getNickname() + " "
						+ main_game_window_.calamities_[calamity_rnm]->getCalamityText());
				} else {
					house->setCalamity(nullptr);
					house->setBuildingTime(house->getBuildingTime() - 1);
				}
				if (house->getBuildingTime() == 0) {
					news_window_.fresh_news_arr_.push_back("The house of the player "
						+ player->getNickname() + " has built!");
				}
			}
		}
		std::vector<Supermarket*> vec_supermarket = player->getSupermarketsArr();
		for (Supermarket*& supermarket : vec_supermarket) {
			if (supermarket->getBuildingTime() != 0) {
				double rnm = main_game_window_.distrib_calamity_(RandNum);
				if (rnm <= main_game_window_.calamity_chance_) {
					double calamity_rnm = main_game_window_.distrib_calamity_type_(RandNum);
					supermarket->setCalamity(main_game_window_.calamities_[calamity_rnm]);
					supermarket->setBuildingTime(supermarket->getBuildingTime()
						- 1 + main_game_window_.calamities_[calamity_rnm]->getDealy());
					news_window_.fresh_news_arr_.push_back(
						"The construction of the player's supermarket "
						+ player->getNickname() + " "
						+ main_game_window_.calamities_[calamity_rnm]->getCalamityText());
				} else {
					supermarket->setCalamity(nullptr);
					supermarket->setBuildingTime(supermarket->getBuildingTime() - 1);
				}
				if (supermarket->getBuildingTime() == 0) {
					news_window_.fresh_news_arr_.push_back("The supermarket of the player "
						+ player->getNickname() + " has built!");
				}
			}
		}
	}
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
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(3, nullptr)), "Oakwood")); //0.2
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(first_street[2]), 0, 0);
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(first_street[2]), 3, 0);
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Maplewood")); //0.3
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Birchwood")); //0.4
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(3, nullptr)), "Lakeview")); //0.5
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(first_street[5]), 0, 0);
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(first_street[5]), 3, 0);
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Pinehurst")); //0.6
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Fairview")); //0.7
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(3, nullptr)), "Greendale")); //0.8
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(first_street[8]), 0, 0);
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(first_street[8]), 3, 0);
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
	second_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(8, nullptr)), "Clearview")); //1.1
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(second_street[1]), 0, 7);
	second_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Ashville")); //1.2
	second_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(8, nullptr)), "Elmwood")); //1.3
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(second_street[3]), 0, 7);
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
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(3, nullptr)), "Redwood")); //2.2
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(third_street[2]), 0, 0);
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(third_street[2]), 3, 0);
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Hidden Valley")); //2.3
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Riverbend")); //2.4
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(3, nullptr)), "Stonebridge")); //2.5
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(third_street[5]), 0, 0);
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(third_street[5]), 3, 0);
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Cedar Grove")); //2.6
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Silverlake")); //2.7
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(3, nullptr)), "Highland")); //2.8
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(third_street[8]), 0, 0);
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(third_street[8]), 3, 0);
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
	forth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(8, nullptr)), "Willow Creek")); //3.1
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(forth_street[1]), 0, 7);
	forth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Golden Valley")); //3.2
	forth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(8, nullptr)), "Northfield")); //3.3
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(forth_street[3]), 0, 7);
	forth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Southgate")); //3.4
	forth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(8, nullptr)), "Eastwood")); //3.5
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(forth_street[5]), 0, 7);
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
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(3, nullptr)), "Prairieville")); //4.2
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(fifth_street[2]), 0, 0);
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(fifth_street[2]), 3, 0);
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Mountain View")); //4.3
	fifth_street.push_back(new Resort("Lakeside")); //4.4
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(3, nullptr)), "Crestwood")); //4.5
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(fifth_street[5]), 0, 0);
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(fifth_street[5]), 3, 0);
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Shady Pines")); //4.6
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Crystal Springs")); //4.7
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(3, nullptr)), "Eagle's Nest")); //4.8
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(fifth_street[8]), 0, 0);
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(fifth_street[8]), 3, 0);
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Redbrook")); //4.9
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Valley Forge")); //4.10
	land_plots_arr_.emplace_back(fifth_street);
}

void Game::makeCalamitiesArr() {
	main_game_window_.calamities_.push_back(new Calamity("is delayed due to adverse weather conditions, the builders refused to go on shift."));
	main_game_window_.calamities_.push_back(new Calamity("is delayed: a virus attacked the construction crew."));
	main_game_window_.calamities_.push_back(new Calamity("is delayed: the construction crew cannot manage their own time."));
	main_game_window_.calamities_.push_back(new Calamity("is delayed: there were difficulties in connecting the object to communications: no electricity."));
	main_game_window_.calamities_.push_back(new Calamity("is delayed: there were difficulties in connecting the object to communications: no water."));
	main_game_window_.calamities_.push_back(new Calamity("is delayed: the state commission does not accept the object."));
	main_game_window_.calamities_.push_back(new Calamity("is delayed: defects caused by the works of the general contractor were found."));
	main_game_window_.calamities_.push_back(new Calamity("is delayed: defects caused by poor-quality materials were found."));
	main_game_window_.calamities_.push_back(new Calamity("is delayed: defects caused by non-compliance with construction technology were found."));
	main_game_window_.calamities_.push_back(new Calamity("is delayed: there were problems with documentation."));
	main_game_window_.calamities_.push_back(new Calamity("is delayed: the designer did not draw a complex node of the frame structure. It is necessary to correct the drawings."));
	main_game_window_.calamities_.push_back(new Calamity("is delayed: the designer did not specify the dimensions of the parts in the drawings. It is necessary to send the diagrams for revision."));
	main_game_window_.calamities_.push_back(new Calamity("is delayed: the hired universal builders refused to carry out the finishing. The customer is looking for a specialized team."));
	main_game_window_.calamities_.push_back(new Calamity("is delayed: documents for the commissioning of housing have not been agreed with the utilities."));
	main_game_window_.calamities_.push_back(new Calamity("is delayed due to insufficient qualifications of workers and engineering staff."));
	main_game_window_.calamities_.push_back(new Calamity("is delayed due to the introduction of new legislative norms and rules in the design process."));
	main_game_window_.calamities_.push_back(new Calamity("is delayed: it became necessary to obtain additional approvals for the project with environmental services."));
	main_game_window_.calamities_.push_back(new Calamity("is delayed due to the discovery of archaeological finds on the site."));
	main_game_window_.calamities_.push_back(new Calamity("is delayed due to legal proceedings on land issues."));
	main_game_window_.calamities_.push_back(new Calamity("is delayed: it became necessary to conduct additional material tests."));
}


void Game::buildNonBuildRealty(Player* player, BuildingLand* building_land, const int& building_pos_x, const int& building_pos_y) {
	if (building_land == nullptr) {
		throw std::runtime_error("build land for non building realty is nullptr");
	}
	if (building_land->getRealty(building_pos_x, building_pos_y) != nullptr) {
		throw std::runtime_error("this place for non building realty has already builted up");
	}
	NonBuildRealty* realty = new NonBuildRealty();
	realty->setOwner(player);
	building_land->build(realty, building_pos_x, building_pos_y);
}

void Game::buySupermarket(Player* player, BuildingLand* building_land, const RealEstateAgency::HouseType& house_type,
	const int& building_pos_x, const int& building_pos_y) {
	if (building_land == nullptr) {
		throw std::runtime_error("build land for supermarket is nullptr");
	}
	if (building_land->getRealty(building_pos_x, building_pos_y) != nullptr) {
		throw std::runtime_error("this place for supermarket has already builted up");
	}
	building_land->build(player->buySupermarket(real_estate_agency_), building_pos_x, building_pos_y);
}

void Game::buyBuildingLand(Player* player, const int& pos_x, const int& pos_y) {
	if (pos_y > land_plots_arr_.size()) {
		throw std::runtime_error("can not buy land: pos_y more than land plots");
	} else if (pos_x > land_plots_arr_[pos_y].size()) {
		throw std::runtime_error("can not buy land: pos_x more than land plots");
	}
	player->buyBuildingLand(dynamic_cast<BuildingLand*>(land_plots_arr_[pos_x][pos_y]), land_agency_);
}

void Game::buyResort(Player* player, const int& pos_x, const int& pos_y) {
	if (pos_y > land_plots_arr_.size()) {
		throw std::runtime_error("can not buy land: pos_y more than land plots");
	} else if (pos_x > land_plots_arr_[pos_y].size()) {
		throw std::runtime_error("can not buy land: pos_x more than land plots");
	}
	player->buyResort(dynamic_cast<Resort*>(land_plots_arr_[pos_x][pos_y]), land_agency_);
}

void Game::buyHouse(Player* player, BuildingLand* building_land, const RealEstateAgency::HouseType& house_type,
	const int& x, const int& y) {
	if (building_land == nullptr) {
		throw std::runtime_error("build land for house is nullptr");
	}
	if (building_land->getRealty(x, y) != nullptr) {
		throw std::runtime_error("this place for house has already builted up");
	}
	building_land->build(player->buyHouse(house_type, real_estate_agency_), x, y);
}

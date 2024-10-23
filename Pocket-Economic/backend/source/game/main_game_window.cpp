#include "../../includes/game/game.h"

void Game::nextGameStep() {
	news_window_.fresh_news_arr_.clear();
	++month_;
	for (Player*& player : players_arr_) {
		player->getIncome(month_ - 1);
		////////////////////////////////
		//
		// 
		// днаюбхрэ яерепш церепш б цеил
		// ядекюрэ оннддепфйс пегнпрнб
		// 
		// 
		//
		////////////////////////////////
		player->updateSpendingMoneyForAdvertForNewStep();
		std::vector<House*> vec_house = player->getHousesArr();
		for (House*& house : vec_house) {
			if (house->getBuildingTime() != 0) {
				double rnm = main_game_window_.distrib_calamity_(RandNum);
				if (rnm <= main_game_window_.calamity_chance_) {
					double calamity_rnm = main_game_window_.distrib_calamity_type_(RandNum);
					house->setCalamity(main_game_window_.calamities_[calamity_rnm]);
					house->setBuildingTime(house->getBuildingTime()
						- 1 + main_game_window_.calamities_[calamity_rnm]->getDealy());
					news_window_.fresh_news_arr_.push_back(std::make_pair(player,
						"the construction of the house " + std::to_string(house->getNumberOfRealty())
						+ " in " + house->getLandPlot()->getNameOfLand()
						+ " " + main_game_window_.calamities_[calamity_rnm]->getCalamityText()));
				} else {
					house->setCalamity(nullptr);
					house->setBuildingTime(house->getBuildingTime() - 1);
					news_window_.buy_news_arr_.push_back(std::make_pair(player,
						"successfully continued the construction of the house " + std::to_string(house->getNumberOfRealty())
						+ " in " + house->getLandPlot()->getNameOfLand() + "."
						+ " It will take " + std::to_string(house->getBuildingTime()) + " month!"
					));
				}
				if (house->getBuildingTime() == 0) {
					news_window_.fresh_news_arr_.push_back(std::make_pair(player,
						"the house " + std::to_string(house->getNumberOfRealty())
						+ " in " + house->getLandPlot()->getNameOfLand()
						+ " has built!"
					));
				}
			} else {
				house->setNewness(house->getNewness() + 1);
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
					news_window_.fresh_news_arr_.push_back(std::make_pair(player,
						"the construction of the supermarket " + std::to_string(supermarket->getNumberOfRealty())
						+ " in " + supermarket->getLandPlot()->getNameOfLand()
						+ " " + main_game_window_.calamities_[calamity_rnm]->getCalamityText()
					));
				} else {
					supermarket->setCalamity(nullptr);
					supermarket->setBuildingTime(supermarket->getBuildingTime() - 1);
					news_window_.buy_news_arr_.push_back(std::make_pair(player,
						+ "successfully continued the construction of the supermarket " + std::to_string(supermarket->getNumberOfRealty())
						+ " in " + supermarket->getLandPlot()->getNameOfLand() + "."
						+ " It will take " + std::to_string(supermarket->getBuildingTime()) + " month!"
					));
				}
				if (supermarket->getBuildingTime() == 0) {
					news_window_.fresh_news_arr_.push_back(std::make_pair(player,
						"the supermarket " + std::to_string(supermarket->getNumberOfRealty())
						+ " in " + supermarket->getLandPlot()->getNameOfLand()
						+ " has built!"
					));
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
	first_street.push_back(new Resort("Red field")); //0.0
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Springfield")); //0.1
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Riverside")); //0.2
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(3, nullptr)), "Oakwood")); //0.3
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(first_street.back()), 0, 0);
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(first_street.back()), 3, 0);
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Maplewood")); //0.4
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Birchwood")); //0.5
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(3, nullptr)), "Lakeview")); //0.6
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(first_street.back()), 0, 0);
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(first_street.back()), 3, 0);
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Pinehurst")); //0.7
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Fairview")); //0.8
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(3, nullptr)), "Greendale")); //0.9
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(first_street.back()), 0, 0);
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(first_street.back()), 3, 0);
	first_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Woodside")); //0.10
	land_plots_arr_.emplace_back(first_street);


	//
	//
	//second sreet
	//
	//
	std::vector<LandPlot*> second_street;
	second_street.push_back(new LandPlot()); //1.0
	second_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(5, std::vector<Realty*>(4, nullptr)), "Brookfield")); //1.1
	second_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(5, std::vector<Realty*>(9, nullptr)), "Clearview")); //1.2
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(second_street.back()), 0, 8);
	second_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(5, std::vector<Realty*>(4, nullptr)), "Ashville")); //1.3
	second_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(5, std::vector<Realty*>(9, nullptr)), "Elmwood")); //1.4
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(second_street.back()), 0, 8);
	second_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(5, std::vector<Realty*>(4, nullptr)), "Hilltop")); //1.5
	second_street.push_back(new Resort("Sunnyvale")); //1.6
	second_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(5, std::vector<Realty*>(4, nullptr)), "Greenfield")); //1.7
	land_plots_arr_.emplace_back(second_street);


	//
	//
	//third sreet
	//
	//
	std::vector<LandPlot*> third_street;
	third_street.push_back(new LandPlot()); //2.0
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Westwood")); //2.1
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Pineville")); //2.2
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(3, nullptr)), "Redwood")); //2.3
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(third_street.back()), 0, 0);
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(third_street.back()), 3, 0);
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Hidden Valley")); //2.4
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Riverbend")); //2.5
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(3, nullptr)), "Stonebridge")); //2.6
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(third_street.back()), 0, 0);
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(third_street.back()), 3, 0);
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Cedar Grove")); //2.7
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Silverlake")); //2.8
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(3, nullptr)), "Highland")); //2.8
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(third_street.back()), 0, 0);
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(third_street.back()), 3, 0);
	third_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Willowbrook")); //2.10
	land_plots_arr_.emplace_back(third_street);


	//
	//
	//forth sreet
	//
	//
	std::vector<LandPlot*> forth_street;
	forth_street.push_back(new LandPlot()); //3.0
	forth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Cedarwood")); //3.1
	forth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(9, nullptr)), "Willow Creek")); //3.2
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(forth_street.back()), 0, 8);
	forth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Golden Valley")); //3.3
	forth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(9, nullptr)), "Northfield")); //3.4
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(forth_street.back()), 0, 8);
	forth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Southgate")); //3.5
	forth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(9, nullptr)), "Eastwood")); //3.6
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(forth_street.back()), 0, 8);
	forth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Westlake")); //3.7
	land_plots_arr_.emplace_back(forth_street);


	//
	//
	//fifth sreet
	//
	//
	std::vector<LandPlot*> fifth_street;
	fifth_street.push_back(new LandPlot()); //4.0
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Timberland")); //4.1
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Fox Run")); //4.2
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(3, nullptr)), "Prairieville")); //4.3
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(fifth_street.back()), 0, 0);
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(fifth_street.back()), 3, 0);
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Mountain View")); //4.4
	fifth_street.push_back(new Resort("Lakeside")); //4.5
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(3, nullptr)), "Crestwood")); //4.6
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(fifth_street.back()), 0, 0);
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(fifth_street.back()), 3, 0);
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Shady Pines")); //4.7
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Crystal Springs")); //4.8
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(3, nullptr)), "Eagle's Nest")); //4.9
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(fifth_street.back()), 0, 0);
	buildNonBuildRealty(nullptr, dynamic_cast<BuildingLand*>(fifth_street.back()), 3, 0);
	fifth_street.push_back(new BuildingLand(std::vector<std::vector<Realty*>>(4, std::vector<Realty*>(4, nullptr)), "Redbrook")); //4.10
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


void Game::buildNonBuildRealty(Player* player, BuildingLand* building_land,
	const int& building_pos_x, const int& building_pos_y) {
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

void Game::buildHouse(Player* player, BuildingLand* building_land, const House::HouseType& house_type,
	const int& building_pos_x, const int& building_pos_y) {
	if (building_land == nullptr) {
		throw std::runtime_error("build land for house is nullptr");
	}
	if (building_land->getRealty(building_pos_x, building_pos_y) != nullptr) {
		throw std::runtime_error("this place for house has already builted up");
	}
	House* house = player->buildHouse(house_type, building_agency_);
	house->setNumberOfRealty(building_pos_y * building_land->getSizeX() + building_pos_x);
	building_land->build(house, building_pos_x, building_pos_y);
	news_window_.buy_news_arr_.push_back(std::make_pair(player,
		"started building the house " + std::to_string(house->getNumberOfRealty())
		+ " in " + house->getLandPlot()->getNameOfLand() + "."
		+ " It will take " + std::to_string(house->getBuildingTime()) + " month!"
	));
}

void Game::buildSupermarket(Player* player, BuildingLand* building_land, const House::HouseType& house_type,
	const int& building_pos_x, const int& building_pos_y) {
	if (building_land == nullptr) {
		throw std::runtime_error("build land for supermarket is nullptr");
	}
	if (building_land->getRealty(building_pos_x, building_pos_y) != nullptr) {
		throw std::runtime_error("this place for supermarket has already builted up");
	}
	Supermarket* supermarket = player->buildSupermarket(building_agency_);
	supermarket->setNumberOfRealty(building_pos_y * building_land->getSizeX() + building_pos_x);
	building_land->build(supermarket, building_pos_x, building_pos_y);
	news_window_.buy_news_arr_.push_back(std::make_pair(player,
		"started building the supermarket " + std::to_string(supermarket->getNumberOfRealty())
		+ " in " + supermarket->getLandPlot()->getNameOfLand() + "."
		+ " It will take " + std::to_string(supermarket->getBuildingTime()) + " month!"
	));
}

void Game::buyLand(Player* player, const int& pos_x, const int& pos_y) {
	if (pos_y == 0 && pos_x != 0) {
		return;
	}

	if (dynamic_cast<BuildingLand*>(land_plots_arr_[pos_x][pos_y]) != nullptr) {
		buyBuildingLand(player, pos_x, pos_y);
	} else if (dynamic_cast<Resort*>(land_plots_arr_[pos_x][pos_y]) != nullptr) {
		buyResort(player, pos_x, pos_y);
	}
}

void Game::buyBuildingLand(Player* player, const int& pos_x, const int& pos_y)  {
	if (pos_y > land_plots_arr_.size()) {
		return;
		//throw std::runtime_error("can not buy land: pos_y more than land plots");
	} else if (pos_x > land_plots_arr_[pos_y].size()) {
		return;
		//throw std::runtime_error("can not buy land: pos_x more than land plots");
	}
	player->buyBuildingLand(dynamic_cast<BuildingLand*>(land_plots_arr_[pos_x][pos_y]), land_agency_);
	news_window_.buy_news_arr_.push_back(std::make_pair(player,
		"bought land plot in " + land_plots_arr_[pos_x][pos_y]->getNameOfLand() + "!"
	));
}

void Game::buyResort(Player* player, const int& pos_x, const int& pos_y) {
	if (pos_y > land_plots_arr_.size()) {
		throw std::runtime_error("can not buy land: pos_y more than land plots");
	} else if (pos_x > land_plots_arr_[pos_y].size()) {
		throw std::runtime_error("can not buy land: pos_x more than land plots");
	}
	player->buyResort(dynamic_cast<Resort*>(land_plots_arr_[pos_x][pos_y]), land_agency_);
	news_window_.buy_news_arr_.push_back(std::make_pair(player,
		"bought resort in " + land_plots_arr_[pos_x][pos_y]->getNameOfLand() + "!"
	));
}

void Game::buyHouseAdvert(Player* player, const int& cnt_of_advert) const {
	player->buyHouseAdvert(cnt_of_advert, advert_agency_);
}

void Game::buySupermarketAdvert(Player* player, const int& cnt_of_advert) const {
	player->buySupermarketAdvert(cnt_of_advert, advert_agency_);
}

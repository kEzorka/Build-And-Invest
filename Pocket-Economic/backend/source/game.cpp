#include "../includes/game.h"

void Game::start() {
	makeCalamitiesArr();
}

bool Game::nextPlayer() {
	++cur_player_;
	if (cur_player_ == players_arr_.size()) {
		cur_player_ = 0;
		nextGameStep();
		return true;
	}
	return false;
}




void Game::pushPlayer(Player* player) {
	players_arr_.push_back(player);
}




std::vector<Player*> Game::getPlayersArr() const {
	return players_arr_;
}

std::vector<std::wstring> Game::getFreshNews() const {
	return fresh_news_arr_;
}




void Game::nextGameStep() {
	fresh_news_arr_.clear();
	++month_;
	for (Player*& player : players_arr_) {
		std::vector<House*> vec_house = player->getHousesArr();
		for (House*& house : vec_house) {
			double rnm = distrib(RandNum);
			if (rnm <= calamity_chance) {

			}
			house->setBuildingTime(house->getBuildingTime() == 0 
				? 0 : house->getBuildingTime() - 1);
		}
		std::vector<Supermarket*> vec_supermarket = player->getSupermarketsArr();
		for (Supermarket*& supermarket : vec_supermarket) {
			supermarket->setBuildingTime(supermarket->getBuildingTime() == 0
				? 0 : supermarket->getBuildingTime() - 1);
		}
	}
	updateNews();
}

void Game::updateNews() {
	//generate_news
}

void Game::makeCalamitiesArr() {
	calamities_.push_back(new Calamity(L"� ����� � ��������������� ���������� ���������� ������������� �������������."));
	calamities_.push_back(new Calamity(L"��-�� ��������������� �������� ������� ��������� ���������� �������� �� �����. ������������� �������������."));
	calamities_.push_back(new Calamity(L"�� ������� ���������� ����� �����. ������������� �������������."));
	calamities_.push_back(new Calamity(L"� ����� � ���������������� ���������� ��������� ��������� �������� ����. ������������� �������������."));
	calamities_.push_back(new Calamity(L"������� ���������� �� ����� ������������ ����������� �����. ������������� �������������."));
	calamities_.push_back(new Calamity(L"�������� ��������� � ������������ ������� � �������������: ��� �������������. ������������� �������������."));
	calamities_.push_back(new Calamity(L"�������� ��������� � ������������ ������� � �������������: ��� ����. ������������� �������������."));
	calamities_.push_back(new Calamity(L"����������� �� ��������� ������. ������������� �������������."));
	calamities_.push_back(new Calamity(L"���������� �������, ��������� �������� �������������. ������������� �������������."));
	calamities_.push_back(new Calamity(L"���������� �������, ��������� ��������������� �����������. ������������� �������������."));
	calamities_.push_back(new Calamity(L"���������� �������, ��������� ������������� ���������� �������������. ������������� �������������."));
	calamities_.push_back(new Calamity(L"�������� �������� � �������������. ������������� �������������."));
	calamities_.push_back(new Calamity(L"������������� �� ���������� ������� ���� ��������� �����������. ���������� ��������� �������. ������������� �������������."));
	calamities_.push_back(new Calamity(L"������������� �� ������ ������� ������� �� ��������. ���������� ��������� ����� �� ���������. ������������� �������������."));
	calamities_.push_back(new Calamity(L"������� ���������-���������� ���������� ��������� �������� �������. �������� ���� ������������������ �������. ������������� �������������."));
	calamities_.push_back(new Calamity(L"������������ ����������� ����������� ��������� ����� �������. ������������� �������������."));
	calamities_.push_back(new Calamity(L"��������� �� ���� ����� � ������������ �� ����������� � ������������� ��������. ������������� �������������."));
	calamities_.push_back(new Calamity(L"� ����� � ������������� ������������� ������� � ����������� ������� ������������� �������������."));
	calamities_.push_back(new Calamity(L"� ����� � ��������� ����� ��������������� ���� � ������ � �������� �������������� ������������� �������������."));
	calamities_.push_back(new Calamity(L"�������� ������������� � �������������� ������������� ������� � �������������� ��������. ������������� �������������."));
	calamities_.push_back(new Calamity(L"�� ������� ����������� ��������������� ������� �� ������� ������������� �������������."));
	calamities_.push_back(new Calamity(L"�� ������� �������� �������������� �� ��������� �������� ������������� �������������."));
	calamities_.push_back(new Calamity(L"�������� ������������� � ���������� �������������� ��������� ����������. ������������� �������������."));
}

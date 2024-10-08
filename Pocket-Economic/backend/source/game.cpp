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
	calamities_.push_back(new Calamity(L"В связи с несвоевременным получением материалов строительство задерживается."));
	calamities_.push_back(new Calamity(L"Из-за неблагоприятных погодных условий строители отказались выходить на смену. Строительство задерживается."));
	calamities_.push_back(new Calamity(L"На бригаду строителей напал вирус. Строительство задерживается."));
	calamities_.push_back(new Calamity(L"В связи с недобросовестным поведением заказчика строители устроили бунт. Строительство задерживается."));
	calamities_.push_back(new Calamity(L"Бригада строителей не умеет распределять собственное время. Строительство задерживается."));
	calamities_.push_back(new Calamity(L"Возникли сложности с подключением объекта к коммуникациям: нет электричества. Строительство задерживается."));
	calamities_.push_back(new Calamity(L"Возникли сложности с подключением объекта к коммуникациям: нет воды. Строительство задерживается."));
	calamities_.push_back(new Calamity(L"Госкомиссия не принимает объект. Строительство задерживается."));
	calamities_.push_back(new Calamity(L"Обнаружены дефекты, вызванные работами генподрядчика. Строительство задерживается."));
	calamities_.push_back(new Calamity(L"Обнаружены дефекты, вызванные некачественными материалами. Строительство задерживается."));
	calamities_.push_back(new Calamity(L"Обнаружены дефекты, вызванные несоблюдением технологии строительства. Строительство задерживается."));
	calamities_.push_back(new Calamity(L"Возникли проблемы с документацией. Строительство задерживается."));
	calamities_.push_back(new Calamity(L"Проектировщик не прорисовал сложный узел каркасной конструкции. Необходимо исправить чертежи. Строительство задерживается."));
	calamities_.push_back(new Calamity(L"Проектировщик не указал размеры деталей на чертежах. Необходимо отправить схемы на доработку. Строительство задерживается."));
	calamities_.push_back(new Calamity(L"Нанятые строители-универсалы отказались проводить финишную отделку. Заказчик ищет специализированную бригаду. Строительство задерживается."));
	calamities_.push_back(new Calamity(L"Строительная организация неправильно составила смету проекта. Строительство задерживается."));
	calamities_.push_back(new Calamity(L"Документы на ввод жилья в употребление не согласованы с коммунальными службами. Строительство задерживается."));
	calamities_.push_back(new Calamity(L"В связи с недостаточной квалификацией рабочих и инженерного состава строительство задерживается."));
	calamities_.push_back(new Calamity(L"В связи с введением новых законодательных норм и правил в процессе проектирования строительство задерживается."));
	calamities_.push_back(new Calamity(L"Возникла необходимость в дополнительных согласованиях проекта с экологическими службами. Строительство задерживается."));
	calamities_.push_back(new Calamity(L"По причине обнаружения археологических находок на участке строительство задерживается."));
	calamities_.push_back(new Calamity(L"По причине судебных разбирательств по земельным вопросам строительство задерживается."));
	calamities_.push_back(new Calamity(L"Возникла необходимость в проведении дополнительных испытаний материалов. Строительство задерживается."));
}

#include "../../includes/game/calamity.h"

void Calamity::setDealy(const int& delay) {
	delay_ = delay;
}

void Calamity::setCalamityText(const std::string& text_of_calamity) {
	text_of_calamity_ = text_of_calamity;
}

int Calamity::getDealy() const {
	return delay_;
}

std::string Calamity::getCalamityText() const {
	return text_of_calamity_;
}

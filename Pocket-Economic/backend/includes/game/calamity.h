#pragma once
#include <string>

class Calamity {
public:
	Calamity(const std::string& text_of_calamity, const int& delay = 1)
		: delay_(delay), text_of_calamity_(text_of_calamity) {}

	void setDealy(const int& delay);
	void setCalamityText(const std::string& text_of_calamity);

	int getDealy() const;
	std::string getCalamityText() const;

private:
	int delay_; //in month
	std::string text_of_calamity_;

};

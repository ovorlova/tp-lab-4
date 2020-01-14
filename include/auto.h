#pragma once
#include <string>

class Drink {
public:
	std::string type;
	int price = 0;
};
class Automata {
private:
	static enum class STATE {
		OFF = 0,
		ON
	};

	STATE state;
	std::vector<Drink> menu;
	int cash;
	std::string name;

public:
	Automata();
	Automata(std::string);
	Automata(std::string, const std::vector<Drink>&);
	std::string on();
	std::string off();
	std::string coin(int);
	std::string printMenu();
	std::string printState();
	std::string choice(int);
	std::string cook(Drink);
	std::string cancel();
	std::string finish();
};
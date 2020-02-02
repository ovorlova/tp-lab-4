#ifndef AUTO
#define AUTO

typedef struct Drink Drink;
struct Drink {
	Drink();
	Drink(std::string, int);
	std::string type;
	int price;
};
class Automata {
private:
	enum class STATE {
		OFF = 0,
		ACCEPT, 
		WAIT, 
		COOK,
	};

	STATE state;
	std::vector<Drink> menu;
	int cash;
	std::string name;

public:
	Automata();
	Automata(std::string);
	Automata(std::string, const std::vector<Drink>& );
	std::string on();
	std::string off();
	std::string coin(int);
	std::string getMenu();
	std::string getState();
	std::string choice(int);
	std::string cook(Drink);
	std::string cancel();
	std::string finish();
};
#endif
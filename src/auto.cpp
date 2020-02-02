#include <iostream>
#include <string>
#include <vector>
#include "auto.h"

Drink::Drink() {
	price = 0;
	type = "";
}

Drink::Drink(std::string type_, int price_) {
	price = price_;
	type = type_;
}

Automata::Automata() {
	state = STATE::OFF;
	cash = 0;
	menu = { Drink{"Americano", 40}, Drink{"Cappuccino", 50}, Drink{"Tea", 10}, Drink{"Latte", 70} };
	name = "Coffee and Co.";
}
Automata::Automata(std::string name) {
	state = STATE::OFF;
	cash = 0;
	menu = { Drink{"Americano", 40}, Drink{"Cappuccino", 50}, Drink{"Tea", 10}, Drink{"Latte", 70} };
	this->name = name;
}
Automata::Automata(std::string name, const std::vector<Drink>& drinks) {
	state = STATE::OFF;
	cash = 0;
	menu = drinks;
	this->name = name;
}
std::string Automata::on() {
	state = STATE::WAIT;
	return getState();
}
std::string Automata::off() {
	state = STATE::OFF;
	return getState();
}
std::string Automata::coin(int money) {
	cash += money;
	state = STATE::ACCEPT;
	return getState();
}
std::string Automata::getMenu() {
	std::string ans = "";
	ans += this->name + ":";
	for (size_t i = 0; i < menu.size(); i++) {
		ans += "\n" + std::to_string(i + 1) + ". " + menu[i].type + ": " + std::to_string(menu[i].price);
	}
	return ans;
}

std::string Automata::choice(int n) {
	if (n > menu.size() || n < 1) {
		state = STATE::ACCEPT;
		return "Error!\n" + getState();
	}
	if (menu[n - 1].price > cash) {
		state = STATE::ACCEPT;
		return "Not enough money! Cancel, choose another drink or add money\n" + getState();
	}
	return cook(menu[n - 1]);
}
std::string Automata::cook(Drink drink) {
	state = STATE::COOK;
	cash -= drink.price;
	return "You have chosen " + drink.type + "\n" + getState() +"\nEnjoy your drink!";
}
std::string Automata::cancel() {
	state = STATE::WAIT;
	int money = cash;
	cash = 0;
	return "Take your cash: " + std::to_string(money) + "\n" + getState();
}
std::string Automata::finish() {
	state = STATE::WAIT;
	if (cash == 0)
		return "Have a good day!\n" + getState();
	else
		return  "Have a good day!\n" + cancel();
}

std::string Automata::getState() {
	if (state == STATE::WAIT)
		return name + " is waiting";
	else if (state == STATE::OFF)
		return name + " is off";
	else if (state == STATE::ACCEPT)
		return "Cash now: " + std::to_string(cash);
	else if (state == STATE::COOK) {
		return "The drink is cooking...";
	}
}
#include <iostream>
#include <string>
#include <vector>
#include "auto.h"

#pragma once

Automata::Automata() {
	state = STATE::ON;
	cash = 0;
	menu = { Drink{"Americano", 40}, Drink{"Cappuccino", 50}, Drink{"Tea", 10}, Drink{"Latte", 70} };
	name = "Coffee and Co.";
}
Automata::Automata(std::string name) {
	state = STATE::ON;
	cash = 0;
	menu = { Drink{"Americano", 40}, Drink{"Cappuccino", 50}, Drink{"Tea", 10}, Drink{"Latte", 70} };
	this->name = name;
}
Automata::Automata(std::string name, const std::vector<Drink>& drinks) {
	state = STATE::ON;
	cash = 0;
	menu = drinks;
	this->name = name;
}
std::string Automata::on() {
	state = STATE::ON;
	return getState();
}
std::string Automata::off() {
	state = STATE::OFF;
	return getState();
}
std::string Automata::coin(int money) {
	cash += money;
	return "Cash now: " + std::to_string(cash);
}
std::string Automata::getMenu() {
	std::string ans = "";
	ans += this->name + ":";
	for (size_t i = 0; i < menu.size(); i++) {
		ans += "\n" + std::to_string(i + 1) + ". " + menu[i].type + ": " + std::to_string(menu[i].price);
	}
	return ans;
}
std::string Automata::getState() {
	if (state == STATE::ON)
		return this->name + " is on";
	else
		return this->name + " is off";
}

std::string Automata::choice(int n) {
	if (n > menu.size() || n < 1)
		return "Error!";
	if (menu[n - 1].price > cash)
		return "Not enough money! Cancel, choose another drink or add money";
	return cook(menu[n - 1]);
}
std::string Automata::cook(Drink drink) {
	cash -= drink.price;
	return drink.type + " is cooking...\nEnjoy your drink!";
}
std::string Automata::cancel() {
	int money = cash;
	cash = 0;
	return "Take your cash: " + std::to_string(money);
}
std::string Automata::finish() {
	if (cash == 0)
		return "Have a good day!";
	else
		return cancel() + "\nHave a good day!";
}
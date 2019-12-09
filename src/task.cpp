#include <iostream>
#include <string>
#include <vector>
#include "auto.h"
using namespace std;

int main() {
	Automata CoffeeMachine;
	cout <<CoffeeMachine.getMenu() << endl;
	cout << CoffeeMachine.coin(100) << endl;
	cout << CoffeeMachine.choice(1) << endl;
	cout << CoffeeMachine.finish() << endl;
	cout << endl;
	
	Automata Nescafe("Nescafe");
	cout << Nescafe.off() << endl;
	cout << Nescafe.on() << endl;
	cout << Nescafe.getMenu() << endl;
	cout << Nescafe.coin(10) << endl;
	cout << Nescafe.choice(2) << endl;
	cout << Nescafe.coin(40) << endl;
	cout << Nescafe.choice(2) << endl;
	cout << Nescafe.finish() << endl;
	cout << endl;

	Automata HSE("HSE", { Drink{"Americano", 50}, Drink{"Espresso", 60}, Drink{"Latte", 80}, Drink{"Hot chocolate", 60}, Drink{"Tea", 30}, Drink{"Water", 10} });
	cout << HSE.getMenu() << endl;
	cout << HSE.coin(10) << endl;
	cout << HSE.cancel() << endl;
	cout << HSE.coin(40) << endl;
	cout << HSE.coin(100) << endl;
	cout << HSE.choice(2) << endl;
	cout << HSE.cancel() << endl;
	cout << HSE.finish() << endl;
	return 0;
}
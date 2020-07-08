#include "stdafx.h"
#include "FlowMenu.h"

using namespace std;
void FlowMenu::print()
{
	int i = 1;
	cout << i++ << ": Wczytaj graf z pliku" << endl;
	cout << i++ << ": Algorytm Forda-Fulkersona (BFS) macierzowo i listowo z wyœwietleniem wyników" << endl;
	cout << i++ << ": Algorytm Forda-Fulkersona (DFS) macierzowo i listowo z wyœwietleniem wyników" << endl;
	cout << i++ << ": Wygeneruj graf" << endl;
	cout << i++ << ": Wyswietl aktualny graf" << endl;
	cout << "0. WyjdŸ" << endl;
}

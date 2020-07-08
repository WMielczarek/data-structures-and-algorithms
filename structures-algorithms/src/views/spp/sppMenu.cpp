#include "stdafx.h"
#include "sppMenu.h"


using namespace std;

void sppMenu::print()
{
	int i = 1;
	cout << i++ << ": Wczytaj graf z pliku" << endl;
	cout << i++ << ": Algorytm Dijkstry macierzowo i listowo z wyœwietleniem wyników" << endl;
	cout << i++ << ": Algorytm Bellmana-Forda macierzowo i listowo z wyœwieleniem wyników" << endl;
	cout << i++ << ": Wygeneruj graf" << endl;
	cout << i++ << ": Wyswietl wczytany graf" << endl;
	cout << "0. WyjdŸ" << endl;
}

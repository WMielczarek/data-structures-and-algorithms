#include "stdafx.h"
#include "appMenu.h"

using namespace std;

void appMenu::print()
{
	int i = 1;
	cout << "-----Projekt 2 ze Struktur danych i z³o¿onoœci obliczeniowej-----" << endl;
	cout << i++ << " : Wyznaczanie minimalnego drzewa rozpinaj¹cego" << endl;
	cout << i++ << " : Wyznaczanie najkrótszej œcie¿ki w grafie" << endl;
	cout << i++ << " : Wyznaczanie maksymalnego przeplywu w grafie" << endl;
	cout << i++ << " : Testuj" << endl;
	cout << "0: Wyjscie" << endl;
}

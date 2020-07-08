#include "Tsp.h"
#include "TspDynamic.h"
#include <iostream>
#include "Timer.h"

int main() {
/*int choose;
for(;;){
std::cout<<"&&&&&&&&&&&&& MENU &&&&&&&&&&&&&&&& \n";
std::cout<<"1. Wygeneruj graf \n";
std::cout<<"2. Wczytaj graf \n";
std::cout<<"3. Zapisz graf \n";
std::cout<<"4. BruteForce \n";
std::cout<<"5. Algorytm podzialu i ograniczen\n";
std::cout<<"6. Wyjdz \n";
std::cin>>choose;
system("cls");
switch (choose){
	default: std::cout<<" Podaj cyfre z menu \n";
		break;
	case 1: 
		break;
	case 2: 
		std::cout<<" Podaj pelna sciezke do pliku txt \n";
		break;
	case 3: std::cout<<" Podaj nazwe pliku \n";
		break;
	case 4: 
		break;
	case 5:
		break;
	case 6: system("exit");
		break;
	}

}
return 0;*/
	TspData *data = new TspData;
	//data->generateData(1, 100, 10);
	//data->save("1.txt");
	//data->load("0_9");
	//data->load("ft53.atsp");
	//data->load("rbg323.atsp");

#if 1
	//Generowanie danych
	int N[] = { 4, 5, 6, 7, 8, 9, 10, 11 };
	int size = sizeof(N) / sizeof(int);
	int rep = 30;
	for(int n = 0; n < size; n++) {
		for(int r = 0; r < rep; r++) {
			data->generateData(1, 100, N[n]);
			std::string filename = std::to_string(n) + "_" + std::to_string(r);
			data->save(filename);
		}
	}

	std::cout << "N;NrInstancji;Wynik;Czas;Metoda\n";

	//Wczytywanie
	Timer timer;
	for(int n = 0; n < size; n++) {
		for(int r = 0; r < rep; r++) {
			std::string filename = std::to_string(n) + "_" + std::to_string(r);
			data->load(filename);
			
			Tsp tsp(data);

			timer.start();
			int result = tsp.bruteForce();
			double time = timer.end();
			std::cout << n << ";" << r << ";" << result << ";" << time << ";" << "brute" << std::endl;

			TspDynamic dyn(data);
			timer.start();
			result = dyn.solve();
			time = timer.end();
			std::cout << n << ";" << r << ";" << result << ";" << time << ";" << "dynamic" << std::endl;

	
		}
	}
#endif

	//data->load("pdf.txt");
	//data->print();
	//TspBnB bnb(data);
	//int res = bnb.Bnb();
	//std::cout << res;
	//data->reset();
	//bnb.print();
	//std::cout << std::endl;


	system("pause");
}

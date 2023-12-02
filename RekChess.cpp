#include <iostream>
#include <time.h>
#define I 10
#define J 10


using namespace std;

int ruch(int wiersz,int kolumna,int licznik_ruchow);

int main(){
	srand(time(NULL));

	int N = 0;
	int suma = 0;
	int licznik = 0;

	cout << " Podaj liczbe prob : ";
	cin >> N;

	int wiersz = 0;

	for(int i = 0; i < N; i++){
		int kolumna = rand() % J;
		int wynik = ruch(wiersz, kolumna, 0);
		
		if(wynik < 0){
			cout << "Eksperyment nieudany, trajektoria rozbiezna :( ";		
		}
		else{
			suma += wynik;
			licznik++;
		}
		cout << "Dlugosc trajektorii : " << wynik << endl;	
	}
	
	cout << "Srednia z " << licznik << " eksperymentow : " << ((double) suma) / licznik << endl;
	
	return 0;
}

int ruch(int wiersz,int kolumna,int licznik_ruchow){

	if(licznik_ruchow == 64) return -1;

	if(wiersz == I - 1){
		return licznik_ruchow;
	}
	
	int ruch_x = 0;
	int ruch_y = 0;
	
	if(wiersz == 0){
		ruch_x = rand() % 2;	
	}
	else{
		ruch_x = (rand() % 3) - 1;
	}
	
	if(kolumna == 0){
		ruch_y = rand() % 2;
	}
	else if(kolumna == J - 1){
		ruch_y = (rand() % 2) - 1;
	}
	else{
		ruch_y = (rand() % 3) - 1; 
	}
	
	if(ruch_x == 0 && ruch_y == 0){
		ruch_x = 1;
	}
	
	// -D DEBUG w kompilacji
	
	#ifdef DEBUG
	cout << "Wykonuje ruch " << licznik_ruchow + 1 << " z [" << wiersz << "," << kolumna << "] do [" << wiersz + ruch_x << "," << kolumna + ruch_y << "]" << endl; 
	#endif
	
	return ruch(wiersz + ruch_x, kolumna + ruch_y, licznik_ruchow + 1);
}


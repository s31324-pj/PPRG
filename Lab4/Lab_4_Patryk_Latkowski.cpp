#include <iostream>
#include <cmath>
using namespace std;


int task1() {
	int ilosc;
	
	cout << "Podaj ilosc elementow w tablicy:   ";
	cin >> ilosc;
	
	int tab[ilosc-1];
	int najwiekszyElement = 0;
	
	cout << "Podaj elementy tablicy:\n";
	for (int i = 0; i<ilosc; i++) {
		cin >> tab[i];
		if (tab[i]> najwiekszyElement) {
			najwiekszyElement = tab[i];
		}
	}
	
	cout << "\nElementy tablicy: ";
	for (int i=0; i<ilosc; i++) {
		cout << tab[i];
	}
	cout << "Z czego najwieksza to: " << najwiekszyElement;
}


int task2(){
	int ilosc;
	
	cout << "Podaj ilosc elementow w tablicy:   ";
	cin >> ilosc;
	
	int tab[ilosc-1];
	int tabIlosc[ilosc-1];
	
	for(int i=0; i<ilosc; i++) {
		tabIlosc[i] = 0;
	}
	
	cout << "Podaj elementy tablicy:\n";
	for (int i = 0; i<ilosc; i++) {
		cin >> tab[i];
	}
	
	bool tabUzycie[ilosc-1];
	for (int i=0; i<ilosc; i++) {
		for (int j=i+1; j<ilosc; j++) {	
			if (tab[i] == tab[j]) {
				if (tabUzycie[j] != true) {
					tabIlosc[i]++;
					tabUzycie[j] = true;
				}
			}
		}
	}
	
	int najwiecejElementuIndex;
	int najwiecejElementu = 0;
	for (int i=0; i<ilosc; i++) {
		for (int j=0; j<ilosc; j++){
			if (tabIlosc[i]>tabIlosc[j] && tabIlosc[i]>najwiecejElementu){
				najwiecejElementu = tabIlosc[i];
				najwiecejElementuIndex = i;
			}
		}
	}
	
		
	cout << "Najwiecej jest elementow: " << tab[najwiecejElementuIndex];	
}


int task3() {
	int tab[10][10];
	
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			if (i==0) {
				tab[i][j] = j;
			} else if (i==1) {
				tab[i][j] = 2*j;
			} else if (i==2) {
				tab[i][j] = j*j;
			} else if (i==3) {
				tab[i][j] = i+j+2;
			} else if (i==4) {
				tab[i][j] = j-i;
			} else {
				tab[i][j] = 0;
			}
		}
	}
	
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			cout << tab[j][i] << " ";
		}
		cout << endl;
	}
}

int main() {
	int numerZadania;
	char kontynuacja;
	cout << "Patryk Latkowski, s31324";	
	
	do {
		do {
			cout << "\n\n\n\n\Wybierz numer zadania (1, 2 lub 3): ";
			cin >> numerZadania;
			if (numerZadania==1) {
				task1();
			} else if(numerZadania==2) {
				task2();
			} else if (numerZadania==3) {
				task3();
			} else {
				cout << "Nie ma takiego zadnaia";
			}
		} while (numerZadania != 1 && numerZadania != 2 && numerZadania != 3);
		cout << "\n\n\n\n\n\nCzy chcesz wybrac inne zadanie?(t/n)  ";
		do {
			cin >> kontynuacja;
		} while (kontynuacja != 't' && kontynuacja != 'n');
	} while (kontynuacja == 't');
	
}

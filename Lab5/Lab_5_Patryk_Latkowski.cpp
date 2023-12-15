#include <iostream>
#include <cstdlib>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;



void task1() {
    int iloscElementow;
    cout << "\n\nPodaj ilosc elementow wektora: ";
    cin >> iloscElementow;
    
    vector<int> vec(iloscElementow);
    cout << "\nPodaj elementy vectora: \n";
    for (int i = 0; i < iloscElementow; ++i) {
        cin >> vec[i];
    }

    int najwiekszyElement = vec[0];
    int index = 0;
    for (int i = 1; i < iloscElementow; ++i) {
        if (vec[i] > najwiekszyElement) {
            najwiekszyElement = vec[i];
            index = i;
        }
    }
     
     cout << "Najwiekszy element: " << najwiekszyElement << endl;
     cout << "Numer indexu: " << index;
}

void task2() {
    int rozmiarTablicy;


	do {
    	cout << "Podaj rozmiar tablicy podzielny przez 2: ";
    	cin >> rozmiarTablicy;
	} while (rozmiarTablicy % 2 != 0);

    vector<int> array(rozmiarTablicy);
    cout << "Wpisz elementy tablicy: \n";
    for (int i = 0; i < rozmiarTablicy; ++i) {
        cin >> array[i];
    }

    cout << "\nPrzed zamiana: \n";
    for (int i = 0; i < rozmiarTablicy; i += 2) {
        cout << array[i] << "\t" << array[i + 1] << endl << endl;
    }

    for (int i = 0; i < rozmiarTablicy; i += 2) {
        swap(array[i], array[i + 1]);
    }

    cout << "Po zmianie: \n";
    for (int i = 0; i < rozmiarTablicy; i += 2) {
        cout << array[i] << "\t" << array[i + 1] << endl << endl;
    }
	
}


int main() {
	int numerZadania;
	char kontynuacja;
	cout << "Patryk Latkowski, s31324";	
	
	do {
		do {
			cout << "\n\n\n\n\nWybierz numer zadania (1 lub 2): ";
			cin >> numerZadania;
			if (numerZadania==1) {
				task1();
			} else if(numerZadania==2) {
				task2();
			} else {
				cout << "Nie ma takiego zadnaia";
			}
		} while (numerZadania != 1 && numerZadania != 2);
		cout << "\n\n\n\n\n\nCzy chcesz wybrac inne zadanie?(t/n)  ";
		do {
			cin >> kontynuacja;
		} while (kontynuacja != 't' && kontynuacja != 'n');
	} while (kontynuacja == 't');
	
}

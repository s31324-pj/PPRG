#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int iloscOsob = 3;
const int maksymalnaDlugoscImienia = 20;
const int maksymalnaDlugoscNazwiska = 30;



void task1() {
	struct Osoba {
    	string imie;
    	string nazwisko;
	};
    Osoba tabelaOsob[iloscOsob];

    for (int i = 0; i < iloscOsob; ++i) {
        cout << "Podaj imie osoby " << i+1 << ": ";
        cin >> tabelaOsob[i].imie;

        cout << "Podaj nazwisko osoby " << i+1 << ": ";
        cin >> tabelaOsob[i].nazwisko;
    }

    cout << "\nWprowadzone dane:\n";
    for (int i = 0; i < iloscOsob; ++i) {
        cout << "Osoba " << i+1 << ": " << tabelaOsob[i].imie << " " << tabelaOsob[i].nazwisko << "\n";
    }	

}


unsigned long long silnia(unsigned int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * silnia(n - 1);
    }
}

void task2() {
	unsigned int liczba;
    	cout << "Podaj liczbe: ";
    	cin >> liczba;

    unsigned long long wynik = silnia(liczba);

	cout << "Wynik silni (" << liczba << "!) to: " << wynik << std::endl;
    if (wynik % 2 == 0) {
       	std::cout << "Jest podzielny przez 2." << std::endl;
    }
    if (wynik % 3 == 0) {
        std::cout << "Jest podzielny przez 3." << std::endl;
    }
    if (wynik % 5 == 0) {
        std::cout << "Jest podzielny przez 5." << std::endl;
    }
    if (wynik % 11 == 0) {
        std::cout << "Jest podzielny przez 11." << std::endl;
    }
}



void task3() {

	const int rozmiarTablicy = 10;

    double promien;
    cout << "Podaj dlugosc promienia kola: ";
    cin >> promien;
    
    double poleKola = M_PI * pow(promien, 2);
    cout << "Pole kola o promieniu " << promien << " wynosi: " << poleKola << endl;

    double tablica[rozmiarTablicy][rozmiarTablicy];

    double wartoscPola = poleKola;
    for (int i = 0; i < rozmiarTablicy; ++i) {
        for (int j = 0; j < rozmiarTablicy; ++j) {
            tablica[i][j] = wartoscPola;
            wartoscPola += 3.0;
        }
    }
    
    cout << "Tablica dwuwymiarowa:" << endl;
    for (int i = 0; i < rozmiarTablicy; ++i) {
        for (int j = 0; j < rozmiarTablicy; ++j) {
            cout << tablica[i][j] << "\t";
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
			cout << "\n\n\n\n\nWybierz numer zadania (1, 2 lub 3): ";
			cin >> numerZadania;
			if (numerZadania==1) {
				task1();
			} else if(numerZadania==2) {
				task2();
			} else if (numerZadania==3){
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
	
	return 0;
}
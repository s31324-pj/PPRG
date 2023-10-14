#include <iostream>
using namespace std;

task1() {
	int liczba;
	cout << "Podaj liczbe:   ";
	cin >> liczba;
	
	int wynik[liczba];
	for (int i=1; i<=liczba; i++) {
		wynik[i-1]=0;
		for (int j=1; j<=i; j++) {
			wynik[i-1] += j;
			if (j<i) {
				cout << j << " + ";
			} else {
				cout << j << " = " << wynik[i-1] << endl;
			}
		}
	}
	int ostatecznyWynik=0;
	cout << "Suma szeregu: ";
	for (int i=0; i<liczba; i++) {
		ostatecznyWynik+=wynik[i];
		if (i<liczba-1) {
			cout << wynik[i] << " + ";
		} else {
			cout << wynik[i] << " = " << ostatecznyWynik << endl << endl << endl;
		}
	}
}

int task2(){
	int a,b;
	cout << "Podaj liczbe a:   ";
	cin >> a;
	cout << "Podaj liczbe b:   ";
	cin >> b;
	
	cout << "\n\n\nWiersz o dlugosci a:\n";
	for (int i=1; i<=a; i++) {
		cout << "*";
	}
	cout << endl << "Kolumna o dlugosci b:";
	for (int i=1; i<=b; i++) {
		cout << "*\n";
	}
	
	cout << endl << "Prostokat o wymiarach 'a' na 'b':\n";
	for (int i=1; i<=b; i++) {
		for (int j=1; j<=a; j++) {
			cout << "*";
		}
		cout << endl;
	}
	
		
	cout << endl << "Obdwod prostokata o wymiarach 'a' na 'b':\n";
	for (int i=1; i<=b; i++) {
		for (int j=1; j<=a; j++) {
			if (i==1 || (i!=1 && j == 1) || i==b || j==a){
				cout << "*";
			} else {
				cout << " ";
			}
		}
		cout<<endl;
	}
	
	cout << endl << "Trojkat prostokatny rownoramienny z katem  prostym w lewym dolnym rogu:\n";
	for (int i=0; i<b; i++) {
		for (int j=0; j<i; j++) {
			cout << "*";
		}
		cout <<endl;
	}
	cout << endl;

	cout << endl << "Trojkat prostokatny rownoramienny z katem prostym w prawym gornym rogu:\n";
	for (int i=0; i<b; i++) {
		for (int j=0; j<b; j++) {
			if (j<i) {
				cout << " ";
			} else {
				cout << "*";
			}
		}
		cout <<endl;
	}
	cout << endl;
}

int task3(){
	int miesiac;
	cout << "Podaj miesiac jako liczbe: ";
	cin >> miesiac;
	
	switch(miesiac){
		case 1:
			cout << "Styczen\n" << "Ten miesiac ma 31 dni.\n" << "W tym miesiacu jest pochmurnie.\n";
			break;
		case 2:
			cout << "Luty\n" << "Ten miesiac ma 28 dni.\n" << "W tym miesiacu jest pochmurnie.\n";
			break;
		case 3:
			cout << "Marzec\n" << "Ten miesiac ma 31 dni.\n" << "W tym miesiacu jest pochmurnie.\n";
			break;
		case 4:
			cout << "Kwiecien\n" << "Ten miesiac ma 30 dni.\n" << "W tym miesiacu jest pochmurnie.\n";
			break;
		case 5:
			cout << "Maj\n" << "Ten miesiac ma 31 dni.\n" << "W tym miesiacu jest slonecznie.\n";
			break;
		case 6:
			cout << "Czerwiec\n" << "Ten miesiac ma 30 dni.\n" << "W tym miesiacu jest slonecznie.\n";
			break;
		case 7:
			cout << "Lipiec\n" << "Ten miesiac ma 31 dni.\n" << "W tym miesiacu jest slonecznie.\n";
			break;
		case 8:
			cout << "Sierpien\n" << "Ten miesiac ma 30 dni.\n" << "W tym miesiacu jest slonecznie.\n";
			break;
		case 9:
			cout << "Wrzesien\n" << "Ten miesiac ma 31 dni.\n" << "W tym miesiacu jest slonecznie.\n";
			break;
		case 10:
			cout << "Pazdziernik\n" << "Ten miesiac ma 30 dni.\n" << "W tym miesiacu jest pochmurnie.\n";
			break;
		case 11:
			cout << "Listopad\n" << "Ten miesiac ma 31 dni.\n" << "W tym miesiacu jest pochmurnie.\n";
			break;
		case 12:
			cout << "Grudzien\n" << "Ten miesiac ma 30 dni.\n" << "W tym miesiacu jest pochmurnie.\n";
			break;
		default:
			cout << "Liczba spoza przedzialu.";
	}
}


main() {
	int numerZadania;
	cout << "Patryk Latkowski, s31324";	
	
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
}

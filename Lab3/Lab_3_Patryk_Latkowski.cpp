#include <iostream>
#include <math.h>
#include <cctype>
#include <vector>
using namespace std;

int task1() {
	double x, y;
	
	cout << "\n\n\nPodaj liczbe x: ";
	cin >> x;
	cout << "Podaj liczbe y: ";
	cin >> y;
	
	double suma = roundf((x+y) * 100) / 100;
	double roznica = roundf((x-y) * 100) / 100;
	double iloczyn = roundf((x*y) * 100) / 100;
	double iloraz = roundf((x/y) * 100) / 100;
	
	cout << "\nSuma: " << suma << "\nRoznica: " << roznica << "\nIloczyn: " << iloczyn << "\nIloraz: " << iloraz;
}

int task2() {
	
	char a;
	cout << "\n\n\nWpisz dowolny znak:\n";
	do {
		cin >> a;
	} while (a != 't');
	
 	cout << "\nBrawo, litera odnaleziona!";
}

int task3() {
	
    double a, b, c;

    cout << "Podaj wspolczynnik a: ";
    cin >> a;

    cout << "Podaj wspolczynnik b: ";
    cin >> b;

    cout << "Podaj wspolczynnik c: ";
    cin >> c;

    cout << "Rownanie kwadratowe w postaci ogolnej: ";
    cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
    

    double delta = b * b - 4 * a * c;
	
	cout << delta;
	
    if (delta > 0) {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        cout << "Pierwiastki rownania: x1 = " << x1 << "; x2 = " << x2 << endl;
    } else if (delta == 0) {
        double x1 = -b / (2 * a);
        cout << "Pierwiastek rownania: x0 = " << x1 << endl;
    } else {
        cout << "Brak pierwiastkow rzeczywistych" << endl;
    }
}

	int binomialCoefficient(int n, int k) {
 	   if (k == 0 || k == n) {
    	    return 1;
	    }
    	return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
	}
	
int task4(){

	
	int numRows;

    cout << "Podaj liczbe wierszy trojkata Pascala: ";
    cin >> numRows;


    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numRows - i - 1; j++) {
            cout << "  "; 
        }
        for (int j = 0; j <= i; j++) {
            cout << binomialCoefficient(i, j) << "   "; 
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
			cout << "\n\n\n\n\Wybierz numer zadania (1, 2, 3 lub 4): ";
			cin >> numerZadania;
			if (numerZadania==1) {
				task1();
			} else if(numerZadania==2) {
				task2();
			} else if (numerZadania==3) {
				task3();
			} else if (numerZadania==4) {
				task4();
			} else {
				cout << "Nie ma takiego zadnaia";
			}
		} while (numerZadania != 1 && numerZadania != 2 && numerZadania != 3 && numerZadania != 4);
		cout << "\n\n\n\n\n\nCzy chcesz wybrac inne zadanie?(t/n)  ";
		do {
			cin >> kontynuacja;
		} while (kontynuacja != 't' && kontynuacja != 'n');
	} while (kontynuacja == 't');
	
}

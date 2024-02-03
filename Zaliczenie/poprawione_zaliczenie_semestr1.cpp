#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <climits>


using namespace std;

int wiersze;
int kolumny;

// Funkcja znajdujaca wszystkie mozliwe sciezki
void znajdzSciezki(int i, int j, vector<int>& sciezka, vector<vector<int>>& sciezki, const int* tab, vector<vector<int>>& memo) {
    sciezka.push_back(tab[i * kolumny + j]);

    if (i == wiersze - 1 && j == kolumny - 1) {   // Koniec tablicy, dodanie aktualnej sciezki do wektora sciezek
        sciezki.push_back(sciezka);
    } else {
        // Ruch w prawy gorny rog
        if (i - 1 >= 0 && j + 1 < kolumny) {
            if (memo[i - 1][j + 1] == 0 || memo[i - 1][j + 1] > memo[i][j] + tab[(i - 1) * kolumny + j + 1]) {
                memo[i - 1][j + 1] = memo[i][j] + tab[(i - 1) * kolumny + j + 1];
                znajdzSciezki(i - 1, j + 1, sciezka, sciezki, tab, memo);
            }
        }

        // Ruch w prawy dolny rog
        if (i + 1 < wiersze && j + 1 < kolumny) {
            if (memo[i + 1][j + 1] == 0 || memo[i + 1][j + 1] > memo[i][j] + tab[(i + 1) * kolumny + j + 1]) {
                memo[i + 1][j + 1] = memo[i][j] + tab[(i + 1) * kolumny + j + 1];
                znajdzSciezki(i + 1, j + 1, sciezka, sciezki, tab, memo);
            }
        }

        // Ruch w prawo
        if (j + 1 < kolumny) {
            if (memo[i][j + 1] == 0 || memo[i][j + 1] > memo[i][j] + tab[i * kolumny + j + 1]) {
                memo[i][j + 1] = memo[i][j] + tab[i * kolumny + j + 1];
                znajdzSciezki(i, j + 1, sciezka, sciezki, tab, memo);
            }
        }

        // Ruch w dol
        if (i + 1 < wiersze) {
            if (memo[i + 1][j] == 0 || memo[i + 1][j] > memo[i][j] + tab[(i + 1) * kolumny + j]) {
                memo[i + 1][j] = memo[i][j] + tab[(i + 1) * kolumny + j];
                znajdzSciezki(i + 1, j, sciezka, sciezki, tab, memo);
            }
        }

        // Ruch w lewy gorny rog
        if (i - 1 >= 0 && j - 1 >= 0) {
            if (memo[i - 1][j - 1] == 0 || memo[i - 1][j - 1] > memo[i][j] + tab[(i - 1) * kolumny + j - 1]) {
                memo[i - 1][j - 1] = memo[i][j] + tab[(i - 1) * kolumny + j - 1];
                znajdzSciezki(i - 1, j - 1, sciezka, sciezki, tab, memo);
            }
        }

        // Ruch w lewo
        if (j - 1 >= 0) {
            if (memo[i][j - 1] == 0 || memo[i][j - 1] > memo[i][j] + tab[i * kolumny + j - 1]) {
                memo[i][j - 1] = memo[i][j] + tab[i * kolumny + j - 1];
                znajdzSciezki(i, j - 1, sciezka, sciezki, tab, memo);
            }
        }

        // Ruch w gora
        if (i - 1 >= 0) {
            if (memo[i - 1][j] == 0 || memo[i - 1][j] > memo[i][j] + tab[(i - 1) * kolumny + j]) {
                memo[i - 1][j] = memo[i][j] + tab[(i - 1) * kolumny + j];
                znajdzSciezki(i - 1, j, sciezka, sciezki, tab, memo);
            }
        }
    }

    sciezka.pop_back();   // Usuwanie ostatniego elementu przed powrotem do poprzedniego poziomu rekurencji
}

int main() {
    // Pobranie wymiarow tablicy i jej deklaracja
    do {
        cout << "Podaj dodatnia ilosc wierszy:  ";
        cin >> wiersze;
    } while (wiersze <= 0);
    do {
        cout << "Podaj dodatnia ilosc kolumn:  ";
        cin >> kolumny;
    } while (kolumny <= 0);
    wiersze++;
    kolumny++;
    int tab[wiersze][kolumny];

    // Generowanie wartosci tablicy
    srand(10); // ustawienie ziarna generatora
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            do {
                tab[i][j] = rand() % 10;
            } while (tab[i][j] == 0);
        }
    }

    // Wypisanie sciezki w odwrotnej kolejnosci wierszy
    for (int i = wiersze - 1; i >= 1; i--) {
        for (int j = 1; j < kolumny; j++) {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    vector<vector<int>> sciezki;   // Wektor przechowujacy wszystkie mozliwe sciezki

    vector<int> sciezka;   // Wektor przechowujacy aktualna sciezke

    vector<vector<int>> memo(wiersze, vector<int>(kolumny, 0));   // Tablica przechowujaca obliczone sumy sciezek

    znajdzSciezki(0, 0, sciezka, sciezki, &tab[0][0], memo);   // Rozpoczecie rekurencyjnego znajdowania sciezek

    // Wybieranie sciezki o najmniejszej sumie
    vector<int> najlepszaSciezka;
    int sumaNajlepszejSciezki = INT_MAX;

    for (const auto& s : sciezki) {
        int sumaSciezki = -tab[0][0];
        for (int val : s) {
            sumaSciezki += val;
        }
        if (sumaSciezki < sumaNajlepszejSciezki) {
            najlepszaSciezka = s;
            sumaNajlepszejSciezki = sumaSciezki;
        }
    }

    // Wypisanie najlepszej sciezki i jej sumy
    cout << "Najlepsza sciezka:" << endl;
    int liczenie = 0;
    for (int val : najlepszaSciezka) {
    	if (liczenie > 0){
    		cout << val << " ";
		}
        liczenie++;
    }
    cout << endl;

    cout << "Suma najlepszej sciezki: " << sumaNajlepszejSciezki << endl;

    return 0;
}

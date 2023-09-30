#include <iostream>
using namespace std;

int task1() {
    cout << "Imie: Patryk\n";
    cout << "Naziwsko: Latkowski\n";
    cout << "Numer studenta: s31324\n";
    cout << "Nazwa uczelni: Polsko-Japonska Akademia Technik Komputerowych\n";
    return 0;
}

int task2() {
    int numToCheck;
    std::cout << "Podaj liczbe calkowita: ";
    cin >> numToCheck;

    if (numToCheck > 0) {
        cout << "Liczba " << numToCheck << " jest dodatnia.";
    } else if (numToCheck < 0) {
        cout << "Liczba " << numToCheck << " jest ujemna.";
    } else {
        cout << "Liczba " << numToCheck << " nie jest ani dodatnia, ani ujemna.";
    }

    cout << "\n";
    return 0;
}

int task3() {
    int numToCheck;
    cout << "Podaj liczbe calkowita: ";
    cin >> numToCheck;

    if (numToCheck%2 == 0) {
        cout << "Liczba " << numToCheck << " jest podzielna przez 2.";
    } else {
        cout << "Liczba " << numToCheck << " nie jest podzielna przez 2.";
    }
    
    cout << "\n";
    return 0;
}

int task4() {
    int num1, num2, num3;
    int num[3];
    cout << "Podaj pierwsza liczbe: ";
    cin >> num1;
    cout << "Podaj druga liczbe: ";
    cin >> num2;
    cout << "Podaj trzecia liczbe: ";
    cin >> num3;
    num[0] = num1;
    num[1] = num2;
    num[2] = num3;

    int theBiggest = num[0];
    for (int i=1; i<=2; i++) {
        if (num[i]>theBiggest) {
            theBiggest = num[i];
        }
    }

    cout << "Najwieksza liczba sposrod " << num[0] << ", " << num[1] << " i " << num[2] << " to " << theBiggest << ".";

    return 0;
}


int main() {
    int taskNum;
    cout << "Wybierz numer zadania (1, 2, 3 lub 4): ";
    cin >> taskNum;
    cout << "\n\n";

    if (taskNum == 1) {
        return task1();
    } else if (taskNum == 2) {
        return task2();
    } else if (taskNum == 3) {
        return task3();
    } else if (taskNum == 4) {
        return task4();
    } else {
        cout << "Podaj poprawny numer zadania.\n";
        return main();
    }
}

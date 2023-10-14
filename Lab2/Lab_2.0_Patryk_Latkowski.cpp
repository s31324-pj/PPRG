#include <iostream>
using namespace std;

main() {
	int uczestnicy;
	int kawalki;
	cout << "Patryk Latkowski s31324\n\n\n\nIle jest uczestnikow imprezy?     ";
	cin >> uczestnicy;
	cout << "\nIle jest kawalkow pizzy?     ";
	cin >> kawalki;
	
	int dlajednej = kawalki/uczestnicy;
	int dlaorganizatorow = kawalki-(dlajednej*uczestnicy);
	
	cout << "\n\n\n\nDla jednej osoby przypadnie " << dlajednej << " kawalkow pizzy.\nDla organizatorow zostanie " << dlaorganizatorow << " kawalkow pizzy.";
}

// Zadanie4 - Ilona Topol, D3
//

#include <iostream>
#include <fstream>
#include <time.h>
#include <windows.h>
#include <limits.h>

using namespace std;

void utworz_pliki(const string nazwa, const int licznik, const char znak);
void porownanie_plikow(const string _plik1, const string _plik2);

int main(int argc, char* argv[])
{
	if (1 <= argc)
	{
		cout << "Tworze pliki, prosze o cierpliwosc..." << endl << endl;
		utworz_pliki("plik1.bin", 100, 0x55);
		utworz_pliki("plik2.bin", 100, 0x55);
		//utworz_pliki("plik3.bin", 100, 0x55);
		//utworz_pliki("plik4.bin", 100, 0x55);
		utworz_pliki("plik5.bin", 4000, 0x55);  //419430400
		utworz_pliki("plik6.bin", 4000, 0x50);
		porownanie_plikow("plik5.bin", "plik6.bin");
	}
	else
	{

	}
	return 0;
}


void porownanie_plikow(const string _plik1, const string _plik2) {
	ifstream plik1(_plik1, ios::binary | ios::in);
	ifstream plik2(_plik2, ios::binary | ios::in);

	if (!plik1) {
		cout << "Nie udalo sie otworzyc pliku: " + _plik1 << endl;
	}
	else if (!plik2) {
		cout << "Nie udalo sie otworzyc pliku: " + _plik2 << endl;
	}
	else {
		cout << "Obliczanie roznice! " << endl;
		clock_t start, koniec, sekundy;
		long long int ilosc_bitow{};
		long long ber{};
		char p1{};
		char p2{};

		start = clock();

		while (!plik1.eof())
		{

			plik1 >> p1;
			plik2 >> p2;

			if (plik1.eof()) { break; }
			cout << (char)p1;
			cout << " -- ";
			cout << (char)p2 << endl;
			ilosc_bitow = ilosc_bitow + 8;

		}
		koniec = clock();

		sekundy = (koniec - start) / CLOCKS_PER_SEC;
		cout << sekundy;

	}

}

void utworz_pliki(const string nazwa, const int licznik, const char znak)
{
	ifstream plik;
	const char znak2 = 0x40;

	plik.open(nazwa);
	if (!plik)
	{
		ofstream plik(nazwa);

		if (nazwa == "plik4.bin")
		{
			for (int i = 0; i < 10; i++)
			{

				plik << znak2;
			}

			for (int i = 10; i < licznik; i++)
			{
				plik << znak;
			}
		}
		else
		{
			for (int i = 0; i < licznik; ++i)
			{
				plik << znak;
			}
		}
	}
}

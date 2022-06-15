// Zadanie4 - Ilona Topol, D3
//

#include <iostream>
#include <fstream>

using namespace std;

void utworz_pliki(const string nazwa, const int licznik, const char znak);

int main(int argc, char* argv[])
{
	utworz_pliki("plik1.bin", 100, 0x55);
	utworz_pliki("plik2.bin", 100, 0x55);
	utworz_pliki("plik3.bin", 100, 0x55);
	utworz_pliki("plik4.bin", 100, 0x55);
	utworz_pliki("plik5.bin", 419430400, 0x55);
	utworz_pliki("plik6.bin", 419430400, 0x50);
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

#include <iostream>
#include <fstream>
#include <time.h>
#include <limits.h>

using namespace std;

void wielkoscPliku(const string& address);
void utworz_pliki(const string nazwa, const int licznik, const char znak);
void porownanie_plikow(const string _plik1, const string _plik2);
uint8_t hammingDistance(uint8_t n1, uint8_t n2);

int main(int argc, char* argv[])
{

    if (1 <= argc) {

        cout << "Tworze pliki, prosze o cierpliwosc..." << endl;
        utworz_pliki("plik1.bin", 100, 0x55);
        cout << "Pilk: plik1.bin - zostal utworzony" << endl;
        utworz_pliki("plik2.bin", 100, 0x55);
        cout << "Pilk: plik2.bin - zostal utworzony" << endl;

        utworz_pliki("plik3.bin", 100, 0x55);
        cout << "Pilk: plik3.bin - zostal utworzony" << endl;

        utworz_pliki("plik4.bin", 100, 0x55);
        cout << "Pilk: plik4.bin - zostal utworzony" << endl;

        utworz_pliki("plik5.bin", 419430400, 0x55);
        cout << "Pilk: plik5.bin - zostal utworzony" << endl;

        utworz_pliki("plik6.bin", 419430400, 0x50);
        cout << "Pilk: plik6.bin - zostal utworzony" << endl;

        porownanie_plikow("plik5.bin", "plik6.bin");
    }
    else {

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
        cout << "Obliczanie roznice dla plikow: " + _plik1 + " i " + _plik2 << endl;
        cout << "Prosze o cierpliwosc..." << endl << endl;

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
            //			cout << (char)p1;
            //			cout << " -- ";
            //			cout << (char)p2 << endl;
            ilosc_bitow = ilosc_bitow + 8;
            ber = hammingDistance(p1, p2) + ber;
        }
        koniec = clock();

        sekundy = (koniec - start) / CLOCKS_PER_SEC;

        cout << "Wyniki dla plikow: " + _plik1 + " i " + _plik2 << endl << "Wielkosc pliku: " + _plik1 + " = ";
        wielkoscPliku(_plik1);
        cout << endl << "Wielkosc pliku: " + _plik2 + " = ";
        wielkoscPliku(_plik2);
        cout << endl << "BER: " << ber << "b" << endl << "Sprawdzonych bitow: " << ilosc_bitow << "b" << endl << "Czas potrzebny na sprawdzenie: " << sekundy << "sekund" << endl << endl;

    }

}

void wielkoscPliku(const string& address) {
    fstream motd(address.c_str(), ios::binary | ios::in | ios::ate);
    if (motd) {
        fstream::pos_type size = motd.tellg();
        cout << size << "B";
    }
    else {
        perror(address.c_str());
    }
}

uint8_t hammingDistance(uint8_t n1, uint8_t n2)
{
    uint8_t x = n1 ^ n2; // XOR
    uint8_t setBits = 0;
    while (x > 0)
    {
        setBits += x & 1;
        x >>= 1;
    }
    return setBits;
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
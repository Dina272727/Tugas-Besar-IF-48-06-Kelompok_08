#ifndef PELANGGAN_H
#define PELANGGAN_H
#include <string>
using namespace std;

struct Pesanan {
    int idMenu;
    string namaMenu;
    int qty;
    Pesanan* next;
};

struct Pelanggan {
    string nama;
    Pelanggan* next;
    Pesanan* firstPesanan;
};

struct ListPelanggan {
    Pelanggan* first;
};

void buatListPelanggan(ListPelanggan &L);
Pelanggan* buatPelanggan(string nama);
void tambahPelanggan(ListPelanggan &L, Pelanggan* p);
void hapusPelanggan(ListPelanggan &L, string nama);
Pelanggan* cariPelanggan(ListPelanggan L, string nama);
void tampilPelanggan(ListPelanggan L);
void tambahPesanan(Pelanggan* P, int idMenu, string namaMenu, int qty);
void hapusPesanan(Pelanggan* P, int idMenu);

int hitungTotal(Pelanggan* P);       // komputasi 1
double hitungRata(Pelanggan* P);     // komputasi 2

#endif


#ifndef PELANGGAN_H
#define PELANGGAN_H

#include <iostream>
#include <string>
using namespace std;

typedef struct Pesanan* adrPesanan;
typedef struct Pelanggan* adrPelanggan;

// NODE PESANAN di dalam pelanggan
struct Pesanan {
    int idMenu;
    string namaMenu;
    int qty;
    adrPesanan next;
};

// NODE PELANGGAN
struct Pelanggan {
    string nama;
    adrPelanggan next;
    adrPesanan firstPesanan;
};

struct ListPelanggan {
    adrPelanggan first;
};

// FUNGSI
void buatListPelanggan(ListPelanggan &L);
adrPelanggan buatPelanggan(string nama);
void tambahPelanggan(ListPelanggan &L, adrPelanggan P);
void hapusPelanggan(ListPelanggan &L, string nama);
adrPelanggan cariPelanggan(ListPelanggan L, string nama);
void tampilPelanggan(ListPelanggan L);

// Pesanan
void tambahPesanan(adrPelanggan P, int idMenu, string namaMenu, int qty);
void hapusPesanan(adrPelanggan P, int idMenu);

// Komputasi
int hitungTotal(adrPelanggan P);
double hitungRata(adrPelanggan P);

#endif

#ifndef PELANGGAN_H
#define PELANGGAN_H

#include <string>
#include "menu.h"
using namespace std;

struct ElmPelanggan;
struct ElmPesanan;

typedef ElmPelanggan* addressPelanggan;
typedef ElmPesanan* addressPesanan;

struct ElmPesanan {
    addressMenu menu;
    addressPesanan next;
};

struct ElmPelanggan {
    string idPelanggan;
    string namaPelanggan;
    addressPesanan firstPesanan;

    addressPelanggan next;
    addressPelanggan prev;
};

struct ListPelanggan {
    addressPelanggan first;
    addressPelanggan last;
};

void createListPelanggan(ListPelanggan &LP);
addressPelanggan alokasiPelanggan(const string &id, const string &nama);
addressPesanan alokasiPesanan(addressMenu m);

void insertFirstPelanggan(ListPelanggan &LP, addressPelanggan P);
void insertLastPelanggan(ListPelanggan &LP, addressPelanggan P);
void insertAfterPelanggan(addressPelanggan Prec, addressPelanggan P);

bool deleteFirstPelanggan(ListPelanggan &LP, addressPelanggan &P);
bool deleteLastPelanggan(ListPelanggan &LP, addressPelanggan &P);
bool deleteAfterPelanggan(addressPelanggan Prec, addressPelanggan &P);

addressPelanggan findPelanggan(const ListPelanggan &LP, const string &idPelanggan);

void tambahPesanan(addressPelanggan pel, addressMenu m);
bool hapusItemPesanan(addressPelanggan pel, const string &idMenu);
void hapusSemuaPesanan(addressPelanggan pel);

void printAllPelanggan(const ListPelanggan &LP);
void printPelangganAndPesanan(const ListPelanggan &LP);
void printPesananWithFormat(addressPelanggan pel);

void removeMenuFromAllPelanggan(ListPelanggan &LP, const string &idMenu);

#endif



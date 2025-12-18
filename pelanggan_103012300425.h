#ifndef PELANGGAN_103012300425H
#define PELANGGAN_103012300425H

#include <string>
#include "menu_103012400043.h" 
using namespace std;

struct ElmPelanggan;
typedef ElmPelanggan* addressPelanggan;

struct ElmPelanggan {
    string idPelanggan;
    string namaPelanggan;

    addressMenu firstPesanan;
    addressMenu lastPesanan;

    addressPelanggan next;
    addressPelanggan prev;
};

struct ListPelanggan {
    addressPelanggan first;
    addressPelanggan last;
};

void createListPelanggan_103012300425(ListPelanggan &LP);
addressPelanggan alokasiPelanggan_103012300425(const string &id, const string &nama);

void insertFirstPelanggan_103012300425(ListPelanggan &LP, addressPelanggan P);
void insertLastPelanggan_103012300425(ListPelanggan &LP, addressPelanggan P);
void insertAfterPelanggan_103012300425(addressPelanggan Prec, addressPelanggan P);

bool deleteFirstPelanggan_103012300425(ListPelanggan &LP, addressPelanggan &P);
bool deleteLastPelanggan_103012300425(ListPelanggan &LP, addressPelanggan &P);
bool deleteAfterPelanggan_103012300425(addressPelanggan Prec, addressPelanggan &P);

addressPelanggan findPelanggan_103012300425(const ListPelanggan &LP, const string &idPelanggan);

void tambahPesanan_103012300425(addressPelanggan pel, addressMenu m);
bool hapusItemPesanan_103012300425(addressPelanggan pel, const string &idMenu);
void hapusSemuaPesanan_103012300425(addressPelanggan pel);

void printAllPelanggan_103012300425(const ListPelanggan &LP);
void printPelangganAndPesanan_103012300425(const ListPelanggan &LP);
void printPesananWithFormat_103012300425(addressPelanggan pel);

void removeMenuFromAllPelanggan_103012300425(ListPelanggan &LP, const string &idMenu);

#endif


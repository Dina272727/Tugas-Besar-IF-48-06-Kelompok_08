#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "relasi.h"
using namespace std;

typedef struct Menu* adrMenu;

struct Menu {
    int id;
    string nama;
    int harga;

    adrMenu next;     // DLL
    adrMenu prev;

    adrRelasi firstRelasi;   // ke pelanggan (via Relasi)
};

struct ListMenu {
    adrMenu first;
    adrMenu last;
};

// Fungsi
void buatListMenu(ListMenu &L);
adrMenu buatMenu(int id, string nama, int harga);
void tambahMenu(ListMenu &L, adrMenu M);
void tambahMenuBerdasarkanHarga(ListMenu &L, adrMenu M);
void hapusMenu(ListMenu &L, int id);
adrMenu cariMenu(ListMenu L, int id);
void tampilMenu(ListMenu L);

#endif

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
using namespace std;

struct Relasi;

// alias pointer
typedef struct Menu* adrMenu;
typedef struct Relasi* adrRelasi;

// NODE MENU (DLL)
struct Menu {
    int id;
    string nama;
    int harga;

    adrMenu next;
    adrMenu prev;

    adrRelasi firstRelasi; // menuju pelanggan yg pesan menu ini
};

// LIST MENU
struct ListMenu {
    adrMenu first;
    adrMenu last;
};

// ==== FUNGSI-FUNGSI ====
void buatListMenu(ListMenu &L);
adrMenu buatMenu(int id, string nama, int harga);
void tambahMenu(ListMenu &L, adrMenu m);
void tambahMenuBerdasarkanHarga(ListMenu &L, adrMenu m);
void hapusMenu(ListMenu &L, int id);
adrMenu cariMenu(ListMenu L, int id);
void tampilMenu(ListMenu L);

#endif


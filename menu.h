#ifndef MENU_H
#define MENU_H
#include <string>
using namespace std;

struct Relasi; // forward

struct Menu {
    int id;
    string nama;
    int harga;

    Menu *next;
    Menu *prev;

    Relasi* firstRelasi; // daftar pelanggan yg memesan menu ini (SLL relasi)
};

struct ListMenu {
    Menu *first;
    Menu *last;
};

void buatListMenu(ListMenu &L);
Menu* buatMenu(int id, string nama, int harga);
void tambahMenu(ListMenu &L, Menu* m);
void tambahMenuBerdasarkanHarga(ListMenu &L, Menu* m);
void hapusMenu(ListMenu &L, int id);
Menu* cariMenu(ListMenu L, int id);
void tampilMenu(ListMenu L);

#endif


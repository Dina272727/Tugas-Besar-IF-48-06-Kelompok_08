#ifndef MENU_H
#define MENU_H

#include <string>
using namespace std;

struct InfoMenu {
    string idMenu;
    string namaMenu;
    int harga;
};

struct ElmMenu;
typedef ElmMenu* addressMenu;

struct ElmMenu {
    InfoMenu info;
    addressMenu next;
};

struct ListMenu {
    addressMenu first;
};

void createListMenu(ListMenu &LM);
addressMenu alokasiMenu(InfoMenu x);

void insertFirstMenu(ListMenu &LM, addressMenu P);
void insertLastMenu(ListMenu &LM, addressMenu P);
void insertAfterMenu(ListMenu &LM, addressMenu Prec, addressMenu P);
void insertMenuByHarga(ListMenu &LM, addressMenu P);

bool deleteFirstMenu(ListMenu &LM, addressMenu &P);
bool deleteLastMenu(ListMenu &LM, addressMenu &P);
bool deleteAfterMenu(ListMenu &LM, addressMenu Prec, addressMenu &P);
bool deleteMenuByID(ListMenu &LM, const string &idMenu, string &namaMenuDihapus);

addressMenu findMenu(const ListMenu &LM, const string &idMenu);
void printAllMenu(const ListMenu LM);

#endif



#ifndef MENU_103012400043_H
#define MENU_103012400043_H

#include <string>
using namespace std;

struct InfoMenu {
    string idMenu;
    string namaMenu;
    int harga;
    int qty;
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

void createListMenu_103012400043(ListMenu &LM);
addressMenu alokasiMenu_103012400043(InfoMenu x);

void insertFirstMenu_103012400043(ListMenu &LM, addressMenu P);
void insertLastMenu_103012400043(ListMenu &LM, addressMenu P);
void insertAfterMenu_103012400043(ListMenu &LM, addressMenu Prec, addressMenu P);
void insertMenuByHarga_103012400043(ListMenu &LM, addressMenu P);

bool deleteFirstMenu_103012400043(ListMenu &LM, addressMenu &P);
bool deleteLastMenu_103012400043(ListMenu &LM, addressMenu &P);
bool deleteAfterMenu_103012400043(ListMenu &LM, addressMenu Prec, addressMenu &P);
bool deleteMenuByID_103012400043(ListMenu &LM, const string &idMenu, string &namaMenuDihapus);

addressMenu findMenu_103012400043(const ListMenu &LM, const string &idMenu);
void printAllMenu_103012400043(const ListMenu LM);

#endif



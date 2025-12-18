#include "menu_103012400043.h"
#include <iostream>
using namespace std;

void createListMenu_103012400043(ListMenu &LM) {
    LM.first = nullptr;
}

addressMenu alokasiMenu_103012400043(InfoMenu x) {
    addressMenu P = new ElmMenu;
    P->info = x;
    P->next = nullptr;
    return P;
}

void insertFirstMenu_103012400043(ListMenu &LM, addressMenu P) {
    P->next = LM.first;
    LM.first = P;
}

void insertLastMenu_103012400043(ListMenu &LM, addressMenu P) {
    if (LM.first == nullptr) {
        LM.first = P;
    } else {
        addressMenu Q = LM.first;
        while (Q->next != nullptr) Q = Q->next;
        Q->next = P;
    }
}

void insertAfterMenu_103012400043(ListMenu &LM, addressMenu Prec, addressMenu P) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertMenuByHarga_103012400043(ListMenu &LM, addressMenu P) {
    if (LM.first == nullptr || P->info.harga < LM.first->info.harga) {
        P->next = LM.first;
        LM.first = P;
        return;
    }
    addressMenu Q = LM.first;
    while (Q->next != nullptr && Q->next->info.harga < P->info.harga) {
        Q = Q->next;
    }
    P->next = Q->next;
    Q->next = P;
}

// DELETE
bool deleteFirstMenu_103012400043(ListMenu &LM, addressMenu &P) {
    if (LM.first == nullptr){
        return false;
    }
    P = LM.first;
    LM.first = P->next;
    P->next = nullptr;
    return true;
}

bool deleteLastMenu_103012400043(ListMenu &LM, addressMenu &P) {
    if (LM.first == nullptr){
        return false;
    }
    if (LM.first->next == nullptr) {
        P = LM.first;
        LM.first = nullptr;
        return true;
    }
    addressMenu Q = LM.first;
    while (Q->next->next != nullptr){
        Q = Q->next;
    }
    P = Q->next;
    Q->next = nullptr;
    return true;
}

bool deleteAfterMenu_103012400043(ListMenu &LM, addressMenu Prec, addressMenu &P) {
    if (Prec == nullptr || Prec->next == nullptr) {
        return false;
    }
    P = Prec->next;
    Prec->next = P->next;
    P->next = nullptr;
    return true;
}

bool deleteMenuByID_103012400043(ListMenu &LM, const string &idMenu, string &namaMenuDihapus) {
    if (LM.first == nullptr){
        return false;
    }
    addressMenu P = LM.first;
    addressMenu prev = nullptr;

    while (P != nullptr && P->info.idMenu != idMenu) {
        prev = P;
        P = P->next;
    }
    if (P == nullptr){
        return false;
    }
    namaMenuDihapus = P->info.namaMenu;
    if (prev == nullptr){
        LM.first = P->next;
    }
    else prev->next = P->next;
    delete P;
    return true;
}

addressMenu findMenu_103012400043(const ListMenu &LM, const string &idMenu) {
    addressMenu P = LM.first;
    while (P != nullptr) {
        if (P->info.idMenu == idMenu){
            return P;
        } 
        P = P->next;
    }
    return nullptr;
}

void printAllMenu_103012400043(const ListMenu LM) {
    addressMenu P = LM.first;
    if (P == nullptr) {
        cout << "Belum ada menu.\n";
        return;
    }
    cout << "\n========== DAFTAR MENU ==========\n";
    cout << "ID\tNama Menu\t\tHarga\n";
    cout << "----------------------------------\n";
    while (P != nullptr) {
        cout << P->info.idMenu << "\t" << P->info.namaMenu << "\t\tRp " << P->info.harga << "\n";
        P = P->next;
    }
    cout << "==================================\n";
}



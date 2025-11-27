#ifndef RELASI_H
#define RELASI_H
#include "menu.h"
#include "pelanggan.h"

struct Relasi {
    Pelanggan* pelanggan;
    Relasi* next;
};

Relasi* buatRelasi(Pelanggan* P);
void tambahRelasi(Menu* M, Pelanggan* P);
void hapusRelasi(Menu* M, string namaPelanggan);
void tampilRelasi(Menu* M);

#endif


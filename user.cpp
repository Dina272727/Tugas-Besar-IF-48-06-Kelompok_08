#include <iostream>
#include <string>
using namespace std;

#include "menu.h"
#include "pelanggan.h"

void menuUser(ListMenu &LM, ListPelanggan &LP) {
    int pilih;

    if (LM.first == NULL) {
        insertLastMenu(LM, alokasiMenu({"1", "Nasi Goreng", 15000}));
        insertLastMenu(LM, alokasiMenu({"2", "Mie Ayam", 12000}));
        insertLastMenu(LM, alokasiMenu({"3", "Es Teh Manis", 5000}));
    }

    do {
        cout << "\n============ MENU PELANGGAN ============\n";
        cout << "1. Tambah Pelanggan + Pesanan\n";
        cout << "2. Tampilkan Semua Pelanggan & Pesanan\n";
        cout << "3. Lihat Pesanan Pelanggan + Total\n";
        cout << "4. Hapus Item Pesanan\n";
        cout << "5. Hapus Semua Pesanan Pelanggan\n";
        cout << "6. Tampilkan Daftar Menu Restoran\n";
        cout << "0. Kembali\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            string nama;
            cout << "\nNama Pelanggan : ";
            cin.ignore();
            getline(cin, nama);

            addressPelanggan pel = LP.first;
            while (pel != NULL && pel->namaPelanggan != nama) {
                pel = pel->next;
            }

            if (pel == NULL) {
                pel = alokasiPelanggan(nama, nama);
                insertLastPelanggan(LP, pel);
                cout << ">> Pelanggan baru ditambahkan.\n";
            } else {
                cout << ">> Pelanggan sudah ada, menambah pesanan...\n";
            }

        
            cout << "\n--- PILIH MENU ---\n";
            printAllMenu(LM);

            string idMenu;
            int qty;
            cout << "Masukkan ID Menu : ";
            cin >> idMenu;

            addressMenu m = findMenu(LM, idMenu);

            if (m == NULL) {
                cout << "Menu tidak ditemukan.\n";
            } else {
                cout << "Jumlah pesanan : ";
                cin >> qty;

                for (int i = 0; i < qty; i++) {
                    tambahPesanan(pel, m);
                }

                cout << ">> Pesanan " << m->info.namaMenu
                     << " (" << qty << "x) berhasil ditambahkan.\n";
            }
        }

        else if (pilih == 2) {
            printPelangganAndPesanan(LP);
        }

        else if (pilih == 3) {
            string nama;
            cout << "Nama Pelanggan: ";
            cin.ignore();
            getline(cin, nama);

            addressPelanggan pel = findPelanggan(LP, nama);
            if (pel == NULL) cout << "Pelanggan tidak ditemukan.\n";
            else printPesananWithFormat(pel);
        }

        else if (pilih == 4) {
            string nama, idMenu;
            cout << "Nama Pelanggan: ";
            cin.ignore();
            getline(cin, nama);

            addressPelanggan pel = findPelanggan(LP, nama);
            if (pel == NULL) cout << "Pelanggan tidak ditemukan.\n";
            else {
                cout << "ID Menu yang ingin dihapus: ";
                cin >> idMenu;
                if (hapusItemPesanan(pel, idMenu))
                    cout << "Item pesanan dihapus.\n";
                else
                    cout << "Item tidak ditemukan.\n";
            }
        }

        else if (pilih == 5) {
            string nama;
            cout << "Nama Pelanggan: ";
            cin.ignore();
            getline(cin, nama);

            addressPelanggan pel = findPelanggan(LP, nama);
            if (pel == NULL) cout << "Pelanggan tidak ditemukan.\n";
            else {
                hapusSemuaPesanan(pel);
                cout << "Semua pesanan dihapus.\n";
            }
        }

        else if (pilih == 6) {
            printAllMenu(LM);
        }

    } while (pilih != 0);
}



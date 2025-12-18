#include <iostream>
#include <string>
using namespace std;

#include "menu_103012400043.h"
#include "pelanggan_103012300425.h"

void menuUser_103012300425(ListMenu &LM, ListPelanggan &LP) {
    int pilih;

    if (LM.first == nullptr) {
        insertLastMenu_103012400043(LM, alokasiMenu_103012400043({"1", "Nasi Goreng", 15000}));
        insertLastMenu_103012400043(LM, alokasiMenu_103012400043({"2", "Mie Ayam", 12000}));
        insertLastMenu_103012400043(LM, alokasiMenu_103012400043({"3", "Es Teh Manis", 5000}));
    }

    do {
        cout << "\n============ MENU PELANGGAN ============\n";
        cout << "1. Tambah Pelanggan + Pesanan\n";
        cout << "2. Lihat Pesanan Pelanggan + Total\n";
        cout << "3. Hapus Item Pesanan\n";
        cout << "4. Hapus Semua Pesanan Pelanggan\n";
        cout << "5. Tampilkan Daftar Menu Restoran\n";
        cout << "0. Kembali\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            string nama;
            cout << "\nNama Pelanggan : ";
            getline(cin, nama);

            addressPelanggan pel = findPelanggan_103012300425(LP, nama);
            if (pel == nullptr) {
                pel = alokasiPelanggan_103012300425(nama, nama);
                insertLastPelanggan_103012300425(LP, pel);
                cout << ">> Pelanggan baru ditambahkan.\n";
            } else {
                cout << ">> Pelanggan sudah ada, menambah pesanan...\n";
            }

            cout << "\n--- PILIH MENU ---\n";
            printAllMenu_103012400043(LM);

            string idMenu;
            int qty;
            cout << "Masukkan ID Menu : ";
            cin >> idMenu;

            addressMenu m = findMenu_103012400043(LM, idMenu);
            if (m == nullptr) {
                cout << "Menu tidak ditemukan.\n";
            } else {
                cout << "Jumlah pesanan : ";
                cin >> qty;

                addressMenu menuCopy = alokasiMenu_103012400043(m->info);
                menuCopy->info.qty = qty;
                tambahPesanan_103012300425(pel, menuCopy);

                cout << ">> Pesanan " << m->info.namaMenu
                     << " (" << qty << "x) berhasil ditambahkan.\n";
            }
        }

        else if (pilih == 2) {
            string nama;
            cout << "Nama Pelanggan: ";
            getline(cin, nama);

            addressPelanggan pel = findPelanggan_103012300425(LP, nama);
            if (pel == nullptr)
                cout << "Pelanggan tidak ditemukan.\n";
            else
                printPesananWithFormat_103012300425(pel);
        }

        else if (pilih == 3) {
            string nama, idMenu;
            cout << "Nama Pelanggan: ";
            getline(cin, nama);
            addressPelanggan pel = findPelanggan_103012300425(LP, nama);
            if (pel == nullptr) cout << "Pelanggan tidak ditemukan.\n";
            else {
                cout << "ID Menu yang ingin dihapus: ";
                cin >> idMenu;
                if (hapusItemPesanan_103012300425(pel, idMenu))
                    cout << "Item pesanan dihapus.\n";
                else
                    cout << "Item tidak ditemukan.\n";
            }
        }

        else if (pilih == 4) {
            string nama;
            cout << "Nama Pelanggan: ";
            getline(cin, nama);
            addressPelanggan pel = findPelanggan_103012300425(LP, nama);
            if (pel == nullptr) cout << "Pelanggan tidak ditemukan.\n";
            else {
                hapusSemuaPesanan_103012300425(pel);
                cout << "Semua pesanan dihapus.\n";
            }
        }

        else if (pilih == 5) {
            printAllMenu_103012400043(LM);
        }

    } while (pilih != 0);
}

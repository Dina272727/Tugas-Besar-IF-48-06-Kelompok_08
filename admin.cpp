#include <iostream>
#include <string>
using namespace std;

#include "menu.h"
#include "pelanggan.h"

void menuAdmin(ListMenu &LM, ListPelanggan &LP) {
    int pilih;
    
    if (LM.first == NULL) {
        insertLastMenu(LM, alokasiMenu({"1","Nasi Goreng",15000}));
        insertLastMenu(LM, alokasiMenu({"2","Mie Ayam",12000}));
        insertLastMenu(LM, alokasiMenu({"3","Es Teh Manis",5000}));
    }

    do {
        cout << "\n============ MENU ADMIN ============\n";
        cout << " 1. Tambah Menu \n";
        cout << " 2. Hapus Menu berdasarkan ID\n";
        cout << " 3. Tampilkan Semua Menu + Data Pesanan\n";
        cout << " 4. Tampilkan Pelanggan yang Pernah Memesan\n";
        cout << " 5. Tampilkan Jumlah Menu Tersedia\n";
        cout << " 0. Kembali\n";
        cout << "====================================\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {

        case 1: {
            InfoMenu im;
            cout << "\n--- Tambah Menu ---\n";
            cout << "ID Menu   : ";
            cin >> im.idMenu;
            cout << "Nama Menu : ";
            cin.ignore();
            getline(cin, im.namaMenu);
            cout << "Harga     : ";
            cin >> im.harga;

            insertLastMenu(LM, alokasiMenu(im));
            cout << ">> Menu berhasil ditambahkan.\n";
            break;
        }

        case 2: {
            string id;
            cout << "\n--- Hapus Menu ---\n";
            cout << "Masukkan ID Menu : ";
            cin >> id;

            string namaDihapus;
            if (deleteMenuByID(LM, id, namaDihapus)) {
                removeMenuFromAllPelanggan(LP, id);
                cout << "Menu '" << namaDihapus
                     << "' berhasil dihapus (beserta pesanan terkait).\n";
            } else {
                cout << "Menu tidak ditemukan.\n";
            }
            break;
        }
                
        case 3:
            cout << "\n--- Daftar Menu Tersedia ---\n";
            printAllMenu(LM);
            cout << "\n--- Daftar Pelanggan & Pesanannya ---\n";
            printPelangganAndPesanan(LP);
            break;

        case 4: {
            cout << "\n--- Pelanggan yang Pernah Memesan ---\n";
            bool ada = false;
            addressPelanggan p = LP.first;

            while (p != NULL) {
                if (p->firstPesanan != NULL) {
                    cout << p->idPelanggan << " - " << p->namaPelanggan << "\n";
                    ada = true;
                }
                p = p->next;
            }

            if (!ada)
                cout << "(Belum ada pelanggan yang melakukan pemesanan)\n";

            break;
        }

            case 5: {
                printAllMenu(LM);
                int count = 0;
                addressMenu m = LM.first;
                while (m != NULL) {
                    count++;
                    m = m->next;
                }

                cout << "\nTotal menu tersedia: " << count << "\n";
                break;
            }


        case 0:
            break;

        default:
            cout << "\n> Pilihan tidak valid.\n";
            break;
        }

    } while (pilih != 0);
}


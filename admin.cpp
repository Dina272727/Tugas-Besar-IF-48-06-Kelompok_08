#include <iostream>
#include <string>
using namespace std;

#include "menu_103012400043.h"
#include "pelanggan_103012300425.h"

void menuAdmin_103012400043(ListMenu &LM, ListPelanggan &LP) {
    int pilih;

    if (LM.first == nullptr) {
        insertLastMenu_103012400043(LM, alokasiMenu_103012400043({"1","Nasi Goreng",15000}));
        insertLastMenu_103012400043(LM, alokasiMenu_103012400043({"2","Mie Ayam",12000}));
        insertLastMenu_103012400043(LM, alokasiMenu_103012400043({"3","Es Teh Manis",5000}));
    }

    do {
        cout << "\n============ MENU ADMIN ============\n";
        cout << " 1. Tambah Menu\n";
        cout << " 2. Hapus Menu berdasarkan ID\n";
        cout << " 3. Tampilkan Semua Data Pesanan\n";
        cout << " 4. Tampilkan Pelanggan yang Pernah Memesan\n";
        cout << " 5. Tampilkan Jumlah dan Semua Menu Tersedia\n";
        cout << " 6. Tampilkan Top Pelanggan (Paling Banyak Pesan)\n";
        cout << " 0. Kembali\n";
        cout << "====================================\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        switch (pilih) {
            case 1: {
                InfoMenu im;
                cout << "\n--- Tambah Menu ---\n";
                cout << "ID Menu   : ";
                cin >> im.idMenu;

                if (findMenu_103012400043(LM, im.idMenu) != nullptr) {
                    cout << ">> ID Menu '" << im.idMenu << "' sudah ada. Tidak bisa menambahkan.\n";
                    break;
                }

                cout << "Nama Menu : ";
                cin.ignore();
                getline(cin, im.namaMenu);
                cout << "Harga     : ";
                cin >> im.harga;

                insertLastMenu_103012400043(LM, alokasiMenu_103012400043(im));
                cout << ">> Menu berhasil ditambahkan.\n";
                break;
            }

            case 2: {
                string id;
                cout << "\n--- Hapus Menu ---\n";
                cout << "Masukkan ID Menu : ";
                cin >> id;

                string namaDihapus;
                if (deleteMenuByID_103012400043(LM, id, namaDihapus)) {
                    removeMenuFromAllPelanggan_103012300425(LP, id);
                    cout << "Menu '" << namaDihapus
                         << "' berhasil dihapus (beserta pesanan terkait).\n";
                } else {
                    cout << "Menu tidak ditemukan.\n";
                }
                break;
            }

            case 3: {
                cout << "\n--- Data Pesanan Pelanggan ---\n";
                if (LP.first == nullptr) {
                    cout << "(Belum ada pelanggan)\n";
                } else {
                    printPelangganAndPesanan_103012300425(LP);
                }
                break;
            }

            case 4: {
                cout << "\n--- Pelanggan yang Pernah Memesan ---\n";
                bool ada = false;
                addressPelanggan p = LP.first;
                while (p != nullptr) {
                    if (p->firstPesanan != nullptr) {
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
                cout << "\n--- Daftar Menu Tersedia ---\n";
                printAllMenu_103012400043(LM);
                int count = 0;
                addressMenu m = LM.first;
                while (m != nullptr) {
                    count++;
                    m = m->next;
                }
                cout << "\nTotal menu tersedia: " << count << "\n";
                break;
            }

            case 6: {
                addressPelanggan top = nullptr;
                int maxPesanan = 0;
                addressPelanggan P = LP.first;
                while (P != nullptr) {
                    int totalQty = 0;
                    addressMenu m = P->firstPesanan;
                    while (m != nullptr) {
                        totalQty += m->info.qty; // hitung semua qty
                        m = m->next;
                    }
                    if (totalQty > maxPesanan) {
                        maxPesanan = totalQty;
                        top = P;
                    }
                    P = P->next;
                }
                if (top != nullptr) {
                    cout << "Top pelanggan: " << top->namaPelanggan
                         << " (" << top->idPelanggan << ") dengan "
                         << maxPesanan << " item pesanan.\n";
                } else {
                    cout << "Belum ada pelanggan yang memesan.\n";
                }
                break;
            }

            case 0: break;

            default:
                cout << "\n> Pilihan tidak valid.\n";
                break;
        }

    } while (pilih != 0);
}


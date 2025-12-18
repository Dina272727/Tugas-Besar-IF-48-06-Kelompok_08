#include "pelanggan_103012300425.h"
#include <iostream>
using namespace std;

void createListPelanggan_103012300425(ListPelanggan &LP) {
    LP.first = nullptr;
    LP.last = nullptr;
}

addressPelanggan alokasiPelanggan_103012300425(const string &id, const string &nama) {
    addressPelanggan P = new ElmPelanggan;
    P->idPelanggan = id;
    P->namaPelanggan = nama;
    P->firstPesanan = nullptr;
    P->lastPesanan = nullptr;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void insertFirstPelanggan_103012300425(ListPelanggan &LP, addressPelanggan P) {
    if (LP.first == nullptr) {
        LP.first = LP.last = P;
    } else {
        P->next = LP.first;
        LP.first->prev = P;
        LP.first = P;
    }
}

void insertLastPelanggan_103012300425(ListPelanggan &LP, addressPelanggan P) {
    if (LP.first == nullptr) {
        LP.first = LP.last = P;
    } else {
        LP.last->next = P;
        P->prev = LP.last;
        LP.last = P;
    }
}

void insertAfterPelanggan_103012300425(addressPelanggan Prec, addressPelanggan P) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        P->prev = Prec;
        if (Prec->next != nullptr) {
            Prec->next->prev = P;
        }
        Prec->next = P;
    }
}

bool deleteFirstPelanggan_103012300425(ListPelanggan &LP, addressPelanggan &P) {
    if (LP.first == nullptr) {
            return false;
        }

        P = LP.first;
        LP.first = P->next;
        if (LP.first != nullptr) {
            LP.first->prev = nullptr;
        } else {
            LP.last = nullptr;
        }

        P->next = nullptr;
        P->prev = nullptr;
        return true;
    }

bool deleteLastPelanggan_103012300425(ListPelanggan &LP, addressPelanggan &P) {
    if (LP.last == nullptr) {
           return false;
       }

       P = LP.last;
       LP.last = P->prev;
       if (LP.last != nullptr) {
           LP.last->next = nullptr;
       } else {
           LP.first = nullptr;
       }

       P->next = nullptr;
       P->prev = nullptr;
       return true;
   }

bool deleteAfterPelanggan_103012300425(addressPelanggan Prec, addressPelanggan &P) {
    if (Prec == nullptr || Prec->next == nullptr) {
            return false;
        }

        P = Prec->next;
        Prec->next = P->next;
        if (P->next != nullptr) {
            P->next->prev = Prec;
        }

        P->next = nullptr;
        P->prev = nullptr;
        return true;
    }

addressPelanggan findPelanggan_103012300425(const ListPelanggan &LP, const string &idPelanggan) {
    addressPelanggan P = LP.first;
        while (P != nullptr) {
            if (P->idPelanggan == idPelanggan) {
                return P;
            }
            P = P->next;
        }
        return nullptr;
    }

void tambahPesanan_103012300425(addressPelanggan pel, addressMenu m) {
    if (pel == nullptr || m == nullptr) {
        return;
    }
    
    addressMenu cur = pel->firstPesanan;
    while (cur != nullptr) {
        if (cur->info.idMenu == m->info.idMenu) {
            cur->info.qty += m->info.qty;
            delete m;
            return;
        }
        cur = cur->next;
    }
    m->next = nullptr;
    if (pel->firstPesanan == nullptr) {
        pel->firstPesanan = pel->lastPesanan = m;
    } else {
        pel->lastPesanan->next = m;
        pel->lastPesanan = m;
    }
}

bool hapusItemPesanan_103012300425(addressPelanggan pel, const string &idMenu) {
    if (pel == nullptr || pel->firstPesanan == nullptr) {
            return false;
        }

        addressMenu cur = pel->firstPesanan;
        addressMenu prev = nullptr;

        while (cur != nullptr && cur->info.idMenu != idMenu) {
            prev = cur;
            cur = cur->next;
        }

        if (cur == nullptr) {
            return false; 
        }

        if (prev == nullptr) {
            pel->firstPesanan = cur->next;
            if (pel->firstPesanan == nullptr) {
                pel->lastPesanan = nullptr;
            }
        } else {
            prev->next = cur->next;
            if (cur == pel->lastPesanan) {
                pel->lastPesanan = prev;
            }
        }

        cur->next = nullptr; // detach
        return true;
    }

void hapusSemuaPesanan_103012300425(addressPelanggan pel) {
    pel->firstPesanan = nullptr;
    pel->lastPesanan = nullptr;
}

void printAllPelanggan_103012300425(const ListPelanggan &LP) {
    addressPelanggan P = LP.first;
    while (P != nullptr) {
        cout << "- " << P->idPelanggan << " | " << P->namaPelanggan << "\n";
        P = P->next;
    }
}

void printPelangganAndPesanan_103012300425(const ListPelanggan &LP) {
    if (LP.first == nullptr) {
        cout << "(Belum ada pelanggan)\n";
        return;
    }

    addressPelanggan p = LP.first;
    while (p != nullptr) {
        cout << "Pelanggan: " << p->namaPelanggan << " (" << p->idPelanggan << ")\n";
        if (p->firstPesanan == nullptr) {
            cout << "  - Belum ada pesanan.\n";
        } else {
            addressMenu m = p->firstPesanan;
            while (m != nullptr) {
                cout << "  - " << m->info.namaMenu
                     << " (" << m->info.qty << "x) Rp "
                     << m->info.harga * m->info.qty << "\n";
                m = m->next;
            }
        }
        p = p->next;
        cout << "\n";
    }
}

void printPesananWithFormat_103012300425(addressPelanggan pel) {
    if (pel == nullptr) {
            cout << "Pelanggan tidak ditemukan.\n";
            return;
        }
        if (pel->firstPesanan == nullptr) {
            cout << pel->namaPelanggan << " belum memesan apa pun.\n";
            return;
        }

        cout << pel->namaPelanggan << " memesan:\n";
        addressMenu cur = pel->firstPesanan;
        int total = 0;
        while (cur != nullptr) {
            cout << "- " << cur->info.namaMenu << " x" << cur->info.qty
                 << " (Rp " << cur->info.harga << ")\n";
            total += cur->info.harga * cur->info.qty;
            cur = cur->next;
        }
        cout << "Total: Rp " << total << "\n";
    }


void removeMenuFromAllPelanggan_103012300425(ListPelanggan &LP, const string &idMenu) {
        addressPelanggan P = LP.first;
        while (P != nullptr) {
            addressMenu cur = P->firstPesanan;
            addressMenu prev = nullptr;

            while (cur != nullptr) {
                if (cur->info.idMenu == idMenu) {
                    if (prev == nullptr) {
                        P->firstPesanan = cur->next;
                        if (P->firstPesanan == nullptr) {
                            P->lastPesanan = nullptr;
                        }
                        cur = P->firstPesanan;
                        continue;
                    } else {
                        prev->next = cur->next;
                        if (cur == P->lastPesanan) {
                            P->lastPesanan = prev;
                        }
                        cur = prev->next;
                        continue;
                    }
                }

                prev = cur;
                cur = cur->next;
            }

            P = P->next;
        }
    }


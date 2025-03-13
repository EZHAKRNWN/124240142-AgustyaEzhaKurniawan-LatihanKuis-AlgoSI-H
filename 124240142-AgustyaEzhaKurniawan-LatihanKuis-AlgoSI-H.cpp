#include <iostream>

using namespace std;

// Struktur untuk menyimpan data buku
struct Buku {
    string id;       // ID buku
    string judul;    // Judul buku
    string penulis;  // Nama penulis buku
    int stok;        // Jumlah stok buku
};

const int MAX_BUKU = 100; // Jumlah maksimal buku yang bisa disimpan
Buku daftarBuku[MAX_BUKU];
int jumlahBuku = 0; // Variabel untuk menghitung jumlah buku yang tersimpan

// Fungsi untuk login 
bool login() {
    string username, password;
    const string correctUser = "ezha"; // Nama panggilan
    const string correctPass = "142"; // 3 digit terakhir NIM
    
    while (true) {
        cout << "\n=== LOGIN ADMIN ===\n";
        cout << "Username: "; cin >> username;
        cout << "Password: "; cin >> password;
        
        if (username == correctUser && password == correctPass) {
            cout << "Login berhasil!\n";
            return true;
        } else {
            cout << "Login gagal! Coba lagi.\n";
        }
    }
}

// Fungsi untuk menambahkan data buku
void tambahBuku() {
    if (jumlahBuku >= MAX_BUKU) {
        cout << "Data buku penuh!\n";
        return;
    }
    
    cout << "\n=== TAMBAH DATA BUKU ===\n";
    cout << "ID Buku: "; cin >> daftarBuku[jumlahBuku].id;
    cin.ignore(); 
    cout << "Judul Buku: "; getline(cin, daftarBuku[jumlahBuku].judul);
    cout << "Penulis: "; getline(cin, daftarBuku[jumlahBuku].penulis);
    cout << "Stok: "; cin >> daftarBuku[jumlahBuku].stok;
    
    jumlahBuku++;
    cout << "Data buku berhasil ditambahkan!\n";
}

// Fungsi untuk menampilkan semua buku
void tampilkanBuku() {
    cout << "\n=== DAFTAR BUKU ===\n";
    for (int i = 0; i < jumlahBuku; i++) {
        cout << daftarBuku[i].id << " | " << daftarBuku[i].judul << " | " << daftarBuku[i].penulis << " | " << daftarBuku[i].stok << endl;
    }
}

// Fungsi untuk mencari buku berdasarkan kata kunci judul
void cariBuku() {
    string keyword;
    bool ditemukan = false;
    
    cout << "\nMasukkan kata kunci judul buku: ";
    cin.ignore();
    getline(cin, keyword);
    
    for (int i = 0; i < jumlahBuku; i++) {
        if (daftarBuku[i].judul.find(keyword) != string::npos) {
            cout << "Ditemukan: " << daftarBuku[i].id << " | " << daftarBuku[i].judul << " | " << daftarBuku[i].penulis << " | " << daftarBuku[i].stok << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan) cout << "Buku tidak ditemukan!\n";
}

// Fungsi untuk menghapus buku berdasarkan ID
void hapusBuku() {
    string id;
    bool ditemukan = false;
    
    cout << "\nMasukkan ID buku yang akan dihapus: ";
    cin >> id;
    
    for (int i = 0; i < jumlahBuku; i++) {
        if (daftarBuku[i].id == id) {
            for (int j = i; j < jumlahBuku - 1; j++) {
                daftarBuku[j] = daftarBuku[j + 1];
            }
            jumlahBuku--;
            ditemukan = true;
            cout << "Buku berhasil dihapus!\n";
            break;
        }
    }
    if (!ditemukan) cout << "Buku tidak ditemukan!\n";
}

// Fungsi utama (main program)
int main() {
    if (!login()) return 0;
    
    int pilihan;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tambah Buku\n2. Tampilkan Buku\n3. Cari Buku\n4. Hapus Buku\n5. Keluar\n";
        cout << "Pilihan: "; cin >> pilihan;
        
        switch (pilihan) {
            case 1: tambahBuku(); break;
            case 2: tampilkanBuku(); break;
            case 3: cariBuku(); break;
            case 4: hapusBuku(); break;
            case 5: cout << "Keluar...\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);
    
    return 0;
}

#ifndef admin_h
#define admin_h

typedef struct {
	char Nama[100];
	int Harga;
	char Kamar[100];
	char WC[100];
	char Kolam[100];
	char Kapasitas[100];
}isiVilla;

void menuAdmin (); //Menampilkan menu utama untuk admin

void pilihanVilla(); //Menampilkan menu pilihan untuk villa yang akan ditambahkan

void tambahVilla1(); //untuk menambahkan villa berkamar 1

void tambahVilla2(); //untuk menambahkan villa berkamar 2

void pilihanDaftarVilla(); //untuk manampilkan  menu pilihan villa kamar jenis apa yang sudah di input oleh admin

void lihatDaftarVilla1(); //untuk menampilkan daftar villa kamar 1

void lihatDaftarVilla2(); //untuk menampilkan daftar villa kamar 2

void hapusdataSewa(); //untuk menghapus data penyewa villa

void lihatdataSewa(); // untuk melihat data penyewa villa


#endif

#ifndef admin_h
#define admin_h

typedef struct {
	char Nama[100];
	int Harga;
	char Kamar[100];
	char WC[100];
	char Kolam[100];
}isiVilla;

void menuAdmin ();

void pilihanVilla();

void tambahVilla1();

void tambahVilla2();

void pilihanDaftarVilla();

void lihatDaftarVilla1();

void lihatDaftarVilla2();

#endif

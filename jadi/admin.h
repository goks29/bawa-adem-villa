#ifndef admin_h
#define admin_h

typedef struct {
	char Nama[100];
	int Harga;
	char Deskripsi[100];
}isiVilla;

void menuAdmin ();

void tambahVilla();

void lihatDaftarVilla();

void inputUlang();

#endif

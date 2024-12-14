#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"
#include "login.h"

#define DATA_VILLA1 "VillaKamar1.txt"
#define DATA_VILLA2 "VillaKamar2.txt"
#define SEWA_VILLA "SewaSaatIni.txt"

//Menampilkan menu utama untuk admin.
void menuAdmin() {
    char opsiAdmin[5]; 
    
    while(1){
		system("cls");   
	    printf("===============================================\n");
	    printf("|                                             |\n");
	    printf("|              Login Berhasil !               |\n");
	    printf("|           Selamat datang, Admin             |\n");
	    printf("|                                             |\n");
	    printf("===============================================\n");
	    printf("Menu : \n");
	    printf("1. Tambah Villa\n");
	    printf("2. Lihat Daftar Villa\n");
	    printf("3. Lihat data Penyewa\n");
	    printf("4. Checkout Penyewa\n");
	    printf("5. Keluar\n");
	    printf("Masukan opsi : ");
		scanf("%s", opsiAdmin);	   

	
		if (strcmp(opsiAdmin, "1") == 0) {
		   	system("cls");
	     	pilihanVilla();
	    } else if (strcmp(opsiAdmin, "2") == 0) {
		   	system("cls");
	       	pilihanDaftarVilla();
	    } else if (strcmp(opsiAdmin, "3") == 0) {
	       	system("cls");
	       	lihatdataSewa();
	    } else if (strcmp(opsiAdmin, "4") == 0) {
	       	system("cls");
	       	hapusdataSewa();
	    } else if (strcmp(opsiAdmin, "5") == 0) {
	       	printf("Keluar dari program. Terima kasih!\n");
	       	exit(0);
	   	} else {
	       	printf("Opsi tidak valid. Silakan coba lagi.\n");
	       	getch();
	   	}
	}
    
}


//Menampilkan menu pilihan untuk villa yang akan ditambahkan
void pilihanVilla() {  
	int input;
	
	printf("Pilih kamar mana yang ingin ditambahkan \n");
	printf("1. Kamar 1\n2. Kamar 2\n");
	printf("Masukan input: ");
	scanf("%d",&input);
	
	while(1) {
		if (input == 1){
			system("cls");
			tambahVilla1();
			break;
		} else if(input == 2){
			system("cls");
			tambahVilla2();
			break;
		} else {
			printf("Input yang anda masukan salah!");
			break;
		}
	}
	
	
}


//untuk menambahkan villa berkamar 1
void tambahVilla1() {
	char input;
		 
   	FILE *file = fopen(DATA_VILLA1, "a");
   	if (file == NULL) {
   		printf("Data tidak ada ! \n");
   		return;
   	}
   	isiVilla villaIsi;
   	printf("================================================================\n");
	printf("|                                                               |\n");
	printf("|                                                               |\n");
	printf("|      TEMPLATE : Nama Villa, Harga Villa, Deskripsi Villa      |\n");
	printf("|                                                               |\n");
	printf("|                                                               |\n");
	printf("=================================================================\n");
   	printf("Masukan Data : \n");
   	printf("Nama: ");
   	scanf(" %[^\n]",villaIsi.Nama);
   	printf("Harga: ");
   	scanf("%d",&villaIsi.Harga);
   	printf("WC: ");
   	scanf(" %[^\n]",villaIsi.WC);
   	printf("Kamar: ");
   	scanf(" %[^\n]",villaIsi.Kamar);
   	printf("Kolam: ");
   	scanf(" %[^\n]",villaIsi.Kolam);
   	printf("Kapasitas: ");
   	scanf(" %[^\n]",villaIsi.Kapasitas);
   	
   	fprintf(file,"%s, %d, %s, %s, %s, %s\n",villaIsi.Nama,villaIsi.Harga,villaIsi.WC,villaIsi.Kamar,villaIsi.Kolam,villaIsi.Kapasitas);
   	
   	fclose(file);
   	
   	while(1) {
		printf("\nMasukan data lagi?[y/n]: ");
		scanf(" %c",&input);
	
		if(input == 'y'){
			system("cls");
			tambahVilla1();
		}
		else if (input == 'n'){
			system("cls");
			menuAdmin();
		}
		else {
			printf("Input yang anda masukan salah !");	
		}
	}	
	
}


//untuk menambahkan villa berkamar 2	
void tambahVilla2() {
	char input;
		 
   	FILE *file = fopen(DATA_VILLA2, "a");
   	if (file == NULL) {
   		printf("Data tidak ada ! \n");
   		return;
   	}
   	isiVilla villaIsi;
   	printf("================================================================\n");
	printf("|                                                               |\n");
	printf("|                                                               |\n");
	printf("|      TEMPLATE : Nama Villa, Harga Villa, Deskripsi Villa      |\n");
	printf("|                                                               |\n");
	printf("|                                                               |\n");
	printf("=================================================================\n");
   	printf("Masukan Data : \n");
   	printf("Nama: ");
   	scanf(" %[^\n]",villaIsi.Nama);
   	printf("Harga: ");
   	scanf("%d",&villaIsi.Harga);
   	printf("WC: ");
   	scanf(" %[^\n]",villaIsi.WC);
   	printf("Kamar: ");
   	scanf(" %[^\n]",villaIsi.Kamar);
   	printf("Kolam: ");
   	scanf(" %[^\n]",villaIsi.Kolam);
   	printf("Kapasitas: ");
   	scanf(" %[^\n]",villaIsi.Kapasitas);
   	
   	fprintf(file,"%s, %d, %s, %s, %s, %s\n",villaIsi.Nama,villaIsi.Harga,villaIsi.WC,villaIsi.Kamar,villaIsi.Kolam,villaIsi.Kapasitas);
   	
   	fclose(file);
	
	while(1) {
		printf("\nMasukan data lagi?[y/n]: ");
		scanf(" %c",&input);
	
		if(input == 'y'){
			system("cls");
			tambahVilla2();
		}
		else if (input == 'n'){
			system("cls");
			menuAdmin();
		}
		else {
			printf("Input yang anda masukan salah !");	
		}
	}
	
	
}

		  
//untuk manampilkan  menu pilihan villa kamar jenis apa yang sudah di input oleh admin
void pilihanDaftarVilla(){
	int inputDaftar;
	
	while(1) {
		printf("Pilih kamar mana yang ingin dilihat \n");
		printf("1. Kamar 1\n2. Kamar 2\n");
		printf("Masukan input: ");
		scanf("%d",&inputDaftar);
		
		if (inputDaftar == 1){
			system("cls");
			lihatDaftarVilla1();
			break;
		} else if(inputDaftar == 2){
			system("cls");
			lihatDaftarVilla2();
			break;
		} else {
			printf("Input yang anda masukan salah! \n");
			getch();
			system("cls");
		}
	}
	
}


//untuk menampilkan daftar villa kamar 1
void lihatDaftarVilla1() {
    char input;
    char line[200];
    int nomorVilla = 1;

    FILE *file = fopen(DATA_VILLA1, "r");
    if (file == NULL) {
        printf("Data villa tidak tersedia.\n");
        return;
    }

    printf("=====================================================\n");
    printf("|                                                   |\n");
    printf("|                                                   |\n");
    printf("|      Berikut merupakan daftar Villa Bawa Adem     |\n");
    printf("|                                                   |\n");
    printf("|                                                   |\n");
    printf("=====================================================\n\n");

    printf("==================================================================================================\n");
    printf("| %-3s | %-15s | %-11s | %-12s | %-8s | %-12s | %-10s |\n", 
           "No", "Nama Villa", "Harga", "Jumlah Kamar", "WC", "Kolam Renang", "Kapasitas");
    printf("==================================================================================================\n");

    while (fgets(line, sizeof(line), file)) {
        char *namaVilla = strtok(line, ",");
        char *harga = strtok(NULL, ",");
        char *jumlahKamar = strtok(NULL, ",");
        char *wc = strtok(NULL, ",");
        char *kolamRenang = strtok(NULL, ",");
        char *kapasitas = strtok(NULL, "\n"); 

        if (namaVilla != NULL && harga != NULL && jumlahKamar != NULL && wc != NULL 
            && kolamRenang != NULL && kapasitas != NULL) {
            printf("| %-3d | %-15s | Rp.%-8s | %-12s | %-8s | %-12s | %-10s |\n", 
                   nomorVilla, namaVilla, harga, jumlahKamar, wc, kolamRenang, kapasitas);
            nomorVilla++;
        }
    }

    printf("==================================================================================================\n");
    fclose(file);

    while (1) {
        printf("\nKembali lagi?[y/n]: ");
        scanf(" %c", &input);

        if (input == 'y') {
            system("cls");
            menuAdmin();
            break;
        } else if (input == 'n') {
            printf("Keluar dari program. Terima kasih!\n");
            exit(0);
        } else {
            printf("Input yang anda masukan salah!\n");
        }
    }
}


//untuk menampilkan daftar villa kamar 2
void lihatDaftarVilla2() {
    char input;
    char line[200];
    int nomorVilla = 1;

    FILE *file = fopen(DATA_VILLA2, "r");
    if (file == NULL) {
        printf("Data villa tidak tersedia.\n");
        return;
    }

    printf("=====================================================\n");
    printf("|                                                   |\n");
    printf("|                                                   |\n");
    printf("|      Berikut merupakan daftar Villa Bawa Adem     |\n");
    printf("|                                                   |\n");
    printf("|                                                   |\n");
    printf("=====================================================\n\n");

    printf("==================================================================================================\n");
    printf("| %-3s | %-15s | %-11s | %-12s | %-8s | %-12s | %-10s |\n", 
           "No", "Nama Villa", "Harga", "Jumlah Kamar", "WC", "Kolam Renang", "Kapasitas");
    printf("==================================================================================================\n");

    while (fgets(line, sizeof(line), file)) {
        char *namaVilla = strtok(line, ",");
        char *harga = strtok(NULL, ",");
        char *jumlahKamar = strtok(NULL, ",");
        char *wc = strtok(NULL, ",");
        char *kolamRenang = strtok(NULL, ",");
        char *kapasitas = strtok(NULL, "\n"); 

        if (namaVilla != NULL && harga != NULL && jumlahKamar != NULL && wc != NULL 
            && kolamRenang != NULL && kapasitas != NULL) {
            printf("| %-3d | %-15s | Rp.%-8s | %-12s | %-8s | %-12s | %-10s |\n", 
                   nomorVilla, namaVilla, harga, jumlahKamar, wc, kolamRenang, kapasitas);
            nomorVilla++;
        }
    }

    printf("==================================================================================================\n");
    fclose(file);

    while (1) {
        printf("\nKembali lagi?[y/n]: ");
        scanf(" %c", &input);

        if (input == 'y') {
            system("cls");
            menuAdmin();
            break;
        } else if (input == 'n') {
            printf("Keluar dari program. Terima kasih!\n");
            exit(0);
        } else {
            printf("Input yang anda masukan salah!\n");
        }
    }
}


//untuk menghapus data penyewa villa
void lihatdataSewa() {
	char input;
	char line[200];
	int nomorNama = 1;
	
    FILE *file = fopen(SEWA_VILLA, "r");
    if (file == NULL) {
        printf("Data villa tidak tersedia.\n");
        return;
    }

    printf("===========================================================\n");
	printf("|                                                         |\n");
	printf("|                                                         |\n");
	printf("|      Berikut merupakan daftar sewa Villa Bawa Adem      |\n");
	printf("|                                                         |\n");
	printf("|                                                         |\n");
	printf("===========================================================\n\n");
	
	printf("============================================================\n");
    printf("| No | Nama Penyewa                   | Nama Villa         |\n");
    printf("============================================================\n");
	
    while (fgets(line, sizeof(line), file)) {
    	char *namaPenyewa = strtok(line, ",");
    	char *nama = strtok(NULL, ",");
    	if (namaPenyewa != NULL && nama != NULL ) {
    		printf("| %-2d | %-30s | %-10s         |\n", nomorNama, namaPenyewa, nama);
    		nomorNama = nomorNama + 1;
	 	}
    }
    printf("============================================================\n");
    
    fclose(file);
    
    while(1) {
		printf("\nKembali lagi?[y/n]: ");
		scanf(" %c",&input);
	
		if(input == 'y'){
			system("cls");
			menuAdmin();
		}
		else if (input == 'n'){
        	printf("Keluar dari program. Terima kasih!\n");
        	exit(0);
		}
		else {
			printf("Input yang anda masukan salah !");	
		}
	}
    
}

//untuk menghapus data penyewa villa
void hapusdataSewa() {
    char namaPenyewa[100];
    char line[200];
    int found = 0;
    
    FILE *file = fopen(SEWA_VILLA, "r");
    if (file == NULL) {
        printf("Data penyewaan tidak tersedia.\n");
        return;
    }

    FILE *Filesementara = fopen("filesementara.txt", "w");
    if (Filesementara == NULL) {
        printf("Gagal membuka file sementara.\n");
        fclose(file);
        return;
    }

	    printf("Masukkan nama penyewa yang ingin dihapus (Contoh : TSINAN, GOKLAS, PRABOWO, Dst...)\n");
	    printf("Nama : ");
	    scanf(" %[^\n]", namaPenyewa);
	
	    namaPenyewa[strcspn(namaPenyewa, "\n")] = '\0';
	
	    while (fgets(line, sizeof(line), file)) {
	        char *nama = strtok(line, ",");
	        
	        if (nama != NULL) {
	            nama[strcspn(nama, "\n")] = '\0';
	            nama[strcspn(nama, "\r")] = '\0';
	        }
	
	        if (nama != NULL && strcmp(nama, namaPenyewa) == 0) {
	            found = 1;
	            continue; 
	        }
	
	        fprintf(Filesementara, "%s", line);
	    }
	
	    fclose(file);
	    fclose(Filesementara);
	
	    if (found) {
	        remove(SEWA_VILLA);
	        rename("filesementara.txt", SEWA_VILLA);
	        printf("Data penyewa '%s' berhasil dihapus.\n", namaPenyewa);
	        getch();
	    } else {
	        remove("filesementara.txt");
	        printf("Data penyewa '%s' tidak ditemukan.\n", namaPenyewa);
	        getch();
	    }
	}




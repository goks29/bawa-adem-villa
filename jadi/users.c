#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "users.h"
#include "admin.h"

#define RIWAYAT_PENYEWAAN "riwayat_penyewaan.txt"
#define SEWA_VILLA "SewaSaatIni.txt" 
#define LIST_VILLA1 "VillaKamar1.txt" 
#define LIST_VILLA2 "VillaKamar2.txt"


void menuUsers() {
    char opsiUsers[2]; 
    while (1){
    	system("cls");
    	printf("===============================================\n");
	    printf("|                                             |\n");
	    printf("|               Halo Pelanggan!               |\n");
	    printf("|                                             |\n");
	    printf("===============================================\n");
	    printf("Menu : \n");
	    printf("1. Sewa Villa\n");
	    printf("2. Tutorial\n");
	    printf("3. Riwayat Penyewaan\n");
	    printf("4. Keluar\n");
	    printf("Masukan opsi : ");
	    scanf("%s", opsiUsers);
	    
	    if (strcmp(opsiUsers, "1") == 0) {
	        system("cls");
	        sewaVilla();
	    } else if (strcmp(opsiUsers, "2") == 0) {
	        system("cls");
	        tampilkanTutorial();
	    } else if (strcmp(opsiUsers, "3") == 0) {
	        system("cls");
	        lihatRiwayatPenyewaan();
	    } else if (strcmp(opsiUsers, "4") == 0) {
	        printf("Keluar dari program. Terima kasih!\n");
	        exit(0);
	    } else {
	        printf("Opsi tidak valid. Silakan coba lagi.\n");
	        getch();
	    }
	}   
}

void sewaVilla() {
	tampilkanVilla();
}

void tampilkanTutorial() {
   	printf("===========================================\n");
	printf("|                                         |\n");
	printf("|                                         |\n");
	printf("|      Tutorial Cara Penyewaan Villa      |\n");
	printf("|                                         |\n");
	printf("|                                         |\n");
	printf("===========================================\n");
    printf("1. Pilih jumlah kamar yang sesuai dengan kebutuhan Anda.\n");
    printf("2. Pilih villa dari daftar yang tersedia.\n");
    printf("3. Villa yang dipilih akan disimpan ke riwayat penyewaan.\n");
    printf("4. Hubungi admin jika ada kendala.\n");
}

void lihatRiwayatPenyewaan() {

    
}	

void tampilkanVilla() {
	FILE *file = fopen(LIST_VILLA1, "r");
    if (file == NULL) {
    printf("Data villa tidak tersedia.\n");
    return;
    }

    printf("=======================================================================\n");
    printf("|                                                                     |\n");
    printf("|                                                                     |\n");
    printf("|                Berikut merupakan List Villa yang ada                |\n");
    printf("|                                                                     |\n");
    printf("|                                                                     |\n");
    printf("=======================================================================\n");

    char line[200];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';

        char *nama = strtok(line, ",");
        char *hargaStr = strtok(NULL, ",");
        char *wc = strtok(NULL, ",");
        char *kamar = strtok(NULL, ",");
        char *kolam = strtok(NULL, ",");

        if (nama != NULL && hargaStr != NULL && wc != NULL && kamar != NULL && kolam != NULL) {
            int harga = atoi(hargaStr); 
            printf("Nama    : %s\n", nama);
            printf("Harga   : %d\n", harga);
            printf("WC      : %s\n", wc);
            printf("Kamar   : %s\n", kamar);
            printf("Kolam   : %s\n", kolam);
            printf("-----------------------------------------------------------------------\n");
        } else {
            printf("Data villa tidak lengkap atau salah format.\n");
        }
    }
	fclose(file);

}


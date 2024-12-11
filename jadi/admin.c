#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"

#define DATA_VILLA "VillaKamar1.txt"


void menuAdmin() {
    char opsiAdmin[1]; 
    
    printf("===============================================\n");
    printf("|                                             |\n");
    printf("|              Login Berhasil !               |\n");
    printf("|           Selamat datang, Admin             |\n");
    printf("|                                             |\n");
    printf("===============================================\n");
    printf("Menu : \n");
    printf("1. Tambah Villa\n");
    printf("2. Lihat Daftar Villa\n");
    printf("3. Keluar\n");
    printf("Masukan opsi : ");
    scanf("%s", opsiAdmin);
    
    if (strcmp(opsiAdmin, "1") == 0) {
        system("cls");
        tambahVilla();
    } else if (strcmp(opsiAdmin, "2") == 0) {
        system("cls");
        lihatDaftarVilla();
    } else if (strcmp(opsiAdmin, "3") == 0) {
        printf("Keluar dari program. Terima kasih!\n");
        exit(0);
    } else {
        printf("Opsi tidak valid. Silakan coba lagi.\n");
    }
}

void tambahVilla() {
   	FILE *file = fopen(DATA_VILLA, "a");
   	if (file == NULL) {
   		printf("Data tidak ada ! \n");
   		return;
   	}
   	isiVilla villaIsi;
   	printf("template : nama villa, harga, deskripsi \n");
   	printf("Masukan Data : \n");
   	printf("Nama: ");
   	scanf(" %[^\n]",villaIsi.Nama);
   	printf("Harga: ");
   	scanf("%d",&villaIsi.Harga);
   	printf("Deskripsi: ");
   	scanf(" %[^\n]",villaIsi.Deskripsi);
   	
   	fprintf(file,"%s, %d, %s\n",villaIsi.Nama,villaIsi.Harga,villaIsi.Deskripsi);
   	
   	inputUlang();
	
	fclose(file);
	
	}
		  

void lihatDaftarVilla() {
    FILE *file = fopen(DATA_VILLA, "r");
    if (file == NULL) {
        printf("Data villa tidak tersedia.\n");
        return;
    }

    printf("Daftar Villa:\n");
    char line[200];
    while (fgets(line, sizeof(line), file)) {
    	char *nama = strtok(line, ",");
    	if (nama != NULL) {
    		printf("%s\n",nama);
	 	}
    }
    fclose(file);
    
}

void inputUlang() { //ini
	char input;

	while(1) {
		printf("\nMasukan data lagi?[y/n]: ");
		scanf(" %c",&input);
	
		if(input == 'y'){
			system("cls");
			tambahVilla();
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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"
#include "login.h"

#define DATA_VILLA1 "VillaKamar1.txt"
#define DATA_VILLA2 "VillaKamar2.txt"


void menuAdmin() {
    char opsiAdmin[1]; 
    
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
	    printf("3. Keluar\n");
	    printf("Masukan opsi : ");
		scanf("%s", opsiAdmin);	   

	
		if (strcmp(opsiAdmin, "1") == 0) {
		   	system("cls");
	     	pilihanVilla();
	    } else if (strcmp(opsiAdmin, "2") == 0) {
		   	system("cls");
	       	pilihanDaftarVilla();
	    } else if (strcmp(opsiAdmin, "3") == 0) {
	       	printf("Keluar dari program. Terima kasih!\n");
	       	exit(0);
	   	} else {
	       	printf("Opsi tidak valid. Silakan coba lagi.\n");
	       	getch();
	   	}
	}
    
}

void pilihanVilla() {  
	int input;
	
	printf("Pilih kamar mana yang ingin ditambahkan \n");
	printf("1. Kamar 1\n2. Kamar 2\n");
	printf("Masukan input: ");
	scanf("%d",&input);
	
	if (input == 1){
		system("cls");
		tambahVilla1();
	} else if(input == 2){
		system("cls");
		tambahVilla2();
	}
	
}

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
   	
   	fprintf(file,"%s, %d, %s, %s, %s\n",villaIsi.Nama,villaIsi.Harga,villaIsi.WC,villaIsi.Kamar,villaIsi.Kolam);
   	
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
	
	fclose(file);
	
	}
	
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
   	
   	fprintf(file,"%s, %d, %s, %s, %s\n",villaIsi.Nama,villaIsi.Harga,villaIsi.WC,villaIsi.Kamar,villaIsi.Kolam);

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
	
	fclose(file);
	
	}		  

void pilihanDaftarVilla(){
	int input;
	
	printf("Pilih kamar m ana yang ingin dilihat \n");
	printf("1. Kamar 1\n2. Kamar 2\n");
	printf("Masukan input: ");
	scanf("%d",&input);
	
	if (input == 1){
		system("cls");
		lihatDaftarVilla1();
	} else if(input == 2){
		system("cls");
		lihatDaftarVilla2();
	}
}

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
	printf("|      Berikut merupakan daftar Villa yang ada      |\n");
	printf("|                                                   |\n");
	printf("|                                                   |\n");
	printf("=====================================================\n");
    while (fgets(line, sizeof(line), file)) {
    	char *nama = strtok(line, ",");
    	if (nama != NULL) {
    		printf("%d. %s\n",nomorVilla,nama);
    		nomorVilla = nomorVilla + 1;
	 	}
    }
    
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
    
    fclose(file);
    
}

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
	printf("|      Berikut merupakan daftar Villa yang ada      |\n");
	printf("|                                                   |\n");
	printf("|                                                   |\n");
	printf("=====================================================\n");
    while (fgets(line, sizeof(line), file)) {
    	char *nama = strtok(line, ",");
    	if (nama != NULL) {
    		printf("%d. %s\n",nomorVilla,nama);
    		nomorVilla = nomorVilla + 1;
	 	}
    }
    
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
    
    fclose(file);
    
}


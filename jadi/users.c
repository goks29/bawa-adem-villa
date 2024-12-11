#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "users.h"

// Prototipe fungsi tambahan


void menuUsers() {
    char opsiUsers[2]; 
    
    printf("===============================================\n");
    printf("|                                             |\n");
    printf("|             Halo Pelanggan!                 |\n");
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
    }
}

void sewaVilla() {

}

void tampilkanTutorial() {
    printf("=== Tutorial Penyewaan Villa ===\n");
    printf("1. Pilih jumlah kamar yang sesuai dengan kebutuhan Anda.\n");
    printf("2. Pilih villa dari daftar yang tersedia.\n");
    printf("3. Villa yang dipilih akan disimpan ke riwayat penyewaan.\n");
    printf("4. Hubungi admin jika ada kendala.\n");
}

void lihatRiwayatPenyewaan() {
	
}


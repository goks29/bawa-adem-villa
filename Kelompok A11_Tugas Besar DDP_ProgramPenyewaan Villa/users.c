#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "users.h"
#include "admin.h"

#define RIWAYAT_PENYEWAAN "riwayat_penyewaan.txt"
#define SEWA_VILLA "SewaSaatIni.txt" 
#define LIST_VILLA1 "VillaKamar1.txt" 
#define LIST_VILLA2 "VillaKamar2.txt"

//Menampilkan menu utama untuk users
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
	        break;
	    } else if (strcmp(opsiUsers, "2") == 0) {
	        system("cls");
	        tampilkanTutorial();
	        break;
	    } else if (strcmp(opsiUsers, "3") == 0) {
	        system("cls");
	        lihatRiwayatPenyewaan();
	        break;
	    } else if (strcmp(opsiUsers, "4") == 0) {
	        printf("Keluar dari program. Terima kasih!\n");
	        exit(0);
	        break;
	    } else {
	        printf("Opsi tidak valid. Silakan coba lagi.\n");
	        getch();
	    }
	}   
}


//proses sewa villa
void sewaVilla() {
    int input;

    while (1) {
        printf("Masukan jenis villa [1,2]: \n");
        printf("1. Villa Kamar 1\n2. Villa Kamar 2\nMasukan input : ");
        scanf("%d", &input);

        if (input == 1) {
            system("cls");
            tampilkanVilla1();
            break;
        } else if (input == 2) {
            system("cls");
            tampilkanVilla2();
            break;
        } else {
            printf("Input yang dimasukkan salah! Silakan coba lagi.\n");
            getch();
            system("cls");
        }
    }
}

//Menampilkan list villa yang ada di villa kamar 1
void tampilkanVilla1() {
    char line[200];
    int villaCount = 0;
    char namaVilla[100], namaPenyewa[100];
    int jumlahHari;
    int found = 0;
    char inputUlang[2];

    FILE *file = fopen(LIST_VILLA1, "r");
    FILE *sewa = fopen(SEWA_VILLA, "a");
    FILE *riwayat = fopen(RIWAYAT_PENYEWAAN, "a");

    if (file == NULL) { 
        printf("Data villa tidak tersedia.\n");
        printf("Kembali ke menu? [y/n]: ");
		scanf("%s",inputUlang);
	
		if (strcmp(inputUlang, "y") ==0) {
	    system("cls");
	   	menuUsers();
		} else if (strcmp(inputUlang, "n") ==0) {
    	printf("Keluar dari program. Terima kasih!\n");
        exit(0);
		} else {
	    printf("Input yang anda masukan salah!");
		}
    }

    printf("=======================================================================\n");
    printf("|                                                                     |\n");
    printf("|                Berikut merupakan List Villa yang ada                |\n");
    printf("|                                                                     |\n");
    printf("=======================================================================\n\n");

    printf("================================================================================================\n");
    printf("| %-15s | %-10s | %-5s | %-6s | %-10s | %-10s |\n", "Nama", "Harga", "WC", "Kamar", "Kolam", "Kapasitas");
    printf("================================================================================================\n");

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';

        char *nama = strtok(line, ",");
        char *hargaStr = strtok(NULL, ",");
        char *wc = strtok(NULL, ",");
        char *kamar = strtok(NULL, ",");
        char *kolam = strtok(NULL, ",");
        char *kapasitas = strtok(NULL, ",");

        if (nama && hargaStr && wc && kamar && kolam && kapasitas) {
            int harga = atoi(hargaStr);
            printf("| %-15s | %-10d | %-5s | %-6s | %-10s | %-10s |\n", nama, harga, wc, kamar, kolam, kapasitas);
            printf("================================================================================================\n");
            villaCount = villaCount + 1;
        } else {
            printf("Data villa tidak lengkap atau salah format.\n");
        }
    }

    if (villaCount == 0) {
        printf("Tidak ada villa yang tersedia.\n");
        fclose(file);
        return;
    }

	    printf("Pilih Villa yang Mana? (Masukkan nama villa): ");
	    scanf(" %[^\n]", namaVilla);
	    printf("Masukkan nama Anda: ");
	    scanf(" %[^\n]", namaPenyewa);
	    printf("Berapa hari Anda akan menginap? : ");
	    scanf("%d", &jumlahHari);

    rewind(file); 

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';

        char *nama = strtok(line, ",");
        char *hargaStr = strtok(NULL, ",");
        char *wc = strtok(NULL, ",");
        char *kamar = strtok(NULL, ",");
        char *kolam = strtok(NULL, ",");
        char *kapasitas = strtok(NULL, ",");

        if (nama && strcmp(nama, namaVilla) == 0) {
            int harga = atoi(hargaStr);
            int totalHarga = harga * jumlahHari;

            fprintf(sewa, "%s,%s,%d,%d\n", namaPenyewa, nama, jumlahHari, totalHarga);
            fprintf(riwayat, "%s,%s,%d,%d\n", namaPenyewa, nama, jumlahHari, totalHarga);

            system("cls");
            printf("=======================================================================\n");
            printf("|                           STRUK PEMESANAN                           |\n");
            printf("=======================================================================\n");
            printf("| Nama Penyewa   : %-50s |\n", namaPenyewa);
            printf("| Nama Villa     : %-50s |\n", nama);
            printf("| Kapasitas      : %-50s |\n", kapasitas);
            printf("| Jumlah Hari    : %-50d |\n", jumlahHari);
            printf("| Harga per Hari : Rp. %-46d |\n", harga);
            printf("| Total Harga    : Rp. %-46d |\n", totalHarga);
            printf("=======================================================================\n");
            printf("|           Terima kasih telah memesan villa di Bawa Adem!            |\n");
            printf("=======================================================================\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Villa dengan nama '%s' tidak ditemukan.\n\n", namaVilla);
        printf("Kembali ke menu? [y/n]: ");
        scanf(" %s", inputUlang);
        printf("Kembali? [y/n] : ");
			scanf("%s",inputUlang);
	
			if (strcmp(inputUlang, "y") ==0) {
	    		system("cls");
	   			menuUsers();
			} else if (strcmp(inputUlang, "n") ==0) {
    			printf("Keluar dari program. Terima kasih!\n");
       			 exit(0);
			} else {
	   			 printf("Input yang anda masukan salah!");
			}
    }

    fclose(file);
    fclose(sewa);
    fclose(riwayat);
    
    printf("Kembali? [y/n] : ");
	scanf("%s",inputUlang);
	
	if (strcmp(inputUlang, "y") ==0) {
	    system("cls");
	   	menuUsers();
	} else if (strcmp(inputUlang, "n") ==0) {
    	printf("Keluar dari program. Terima kasih!\n");
        exit(0);
	} else {
	    printf("Input yang anda masukan salah!");
	}
}


//Menampilkan list villa yang ada di villa kamar 2
void tampilkanVilla2() {
    char line[200];
    int villaCount = 0;
    char namaVilla[100], namaPenyewa[100];
    int jumlahHari;
    int found = 0;
    char inputUlang[2];

    FILE *file = fopen(LIST_VILLA2, "r");
    FILE *sewa = fopen(SEWA_VILLA, "a");
    FILE *riwayat = fopen(RIWAYAT_PENYEWAAN, "a");

    if (file == NULL) { 
        printf("Data villa tidak tersedia.\n");
        printf("Kembali ke menu? [y/n]: ");
		scanf("%s",inputUlang);
	
		if (strcmp(inputUlang, "y") ==0) {
	    system("cls");
	   	menuUsers();
		} else if (strcmp(inputUlang, "n") ==0) {
    	printf("Keluar dari program. Terima kasih!\n");
        exit(0);
		} else {
	    printf("Input yang anda masukan salah!");
		}
}

    printf("=======================================================================\n");
    printf("|                                                                     |\n");
    printf("|                Berikut merupakan List Villa yang ada                |\n");
    printf("|                                                                     |\n");
    printf("=======================================================================\n\n");

    printf("================================================================================================\n");
    printf("| %-15s | %-10s | %-5s | %-6s | %-10s | %-10s |\n", "Nama", "Harga", "WC", "Kamar", "Kolam", "Kapasitas");
    printf("================================================================================================\n");

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';

        char *nama = strtok(line, ",");
        char *hargaStr = strtok(NULL, ",");
        char *wc = strtok(NULL, ",");
        char *kamar = strtok(NULL, ",");
        char *kolam = strtok(NULL, ",");
        char *kapasitas = strtok(NULL, ",");

        if (nama && hargaStr && wc && kamar && kolam && kapasitas) {
            int harga = atoi(hargaStr);
            printf("| %-15s | %-10d | %-5s | %-6s | %-10s | %-10s |\n", nama, harga, wc, kamar, kolam, kapasitas);
            printf("================================================================================================\n");
            villaCount = villaCount + 1;
        } else {
            printf("Data villa tidak lengkap atau salah format.\n");
        }
    }

    if (villaCount == 0) {
        printf("Tidak ada villa yang tersedia.\n");
        fclose(file);
        return;
    }

	    printf("Pilih Villa yang Mana? (Masukkan nama villa): ");
	    scanf(" %[^\n]", namaVilla);
	    printf("Masukkan nama Anda: ");
	    scanf(" %[^\n]", namaPenyewa);
	    printf("Berapa hari Anda akan menginap? : ");
	    scanf("%d", &jumlahHari);

    rewind(file); 

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';

        char *nama = strtok(line, ",");
        char *hargaStr = strtok(NULL, ",");
        char *wc = strtok(NULL, ",");
        char *kamar = strtok(NULL, ",");
        char *kolam = strtok(NULL, ",");
        char *kapasitas = strtok(NULL, ",");

        if (nama && strcmp(nama, namaVilla) == 0) {
            int harga = atoi(hargaStr);
            int totalHarga = harga * jumlahHari;

            fprintf(sewa, "%s,%s,%d,%d\n", namaPenyewa, nama, jumlahHari, totalHarga);
            fprintf(riwayat, "%s,%s,%d,%d\n", namaPenyewa, nama, jumlahHari, totalHarga);

            system("cls");
            printf("=======================================================================\n");
            printf("|                           STRUK PEMESANAN                           |\n");
            printf("=======================================================================\n");
            printf("| Nama Penyewa   : %-50s |\n", namaPenyewa);
            printf("| Nama Villa     : %-50s |\n", nama);
            printf("| Kapasitas      : %-50s |\n", kapasitas);
            printf("| Jumlah Hari    : %-50d |\n", jumlahHari);
            printf("| Harga per Hari : Rp. %-46d |\n", harga);
            printf("| Total Harga    : Rp. %-46d |\n", totalHarga);
            printf("=======================================================================\n");
            printf("|           Terima kasih telah memesan villa di Bawa Adem!            |\n");
            printf("=======================================================================\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Villa dengan nama '%s' tidak ditemukan.\n\n", namaVilla);
        printf("Kembali ke menu? [y/n]: ");
        scanf(" %s", inputUlang);
        printf("Kembali? [y/n] : ");
			scanf("%s",inputUlang);
	
			if (strcmp(inputUlang, "y") ==0) {
	    		system("cls");
	   			menuUsers();
			} else if (strcmp(inputUlang, "n") ==0) {
    			printf("Keluar dari program. Terima kasih!\n");
       			 exit(0);
			} else {
	   			 printf("Input yang anda masukan salah!");
			}
    }

    fclose(file);
    fclose(sewa);
    fclose(riwayat);
    
    printf("Kembali? [y/n] : ");
	scanf("%s",inputUlang);
	
	if (strcmp(inputUlang, "y") ==0) {
	    system("cls");
	   	menuUsers();
	} else if (strcmp(inputUlang, "n") ==0) {
    	printf("Keluar dari program. Terima kasih!\n");
        exit(0);
	} else {
	    printf("Input yang anda masukan salah!");
	}
}


//Mempilkan tutorial
void tampilkanTutorial() {
    char inputMenu; 

    printf("===========================================\n");
    printf("|                                         |\n");
    printf("|                                         |\n");
    printf("|      Tutorial Cara Penyewaan Villa      |\n");
    printf("|                                         |\n");
    printf("|                                         |\n");
    printf("===========================================\n");
    printf("1. Pilih jumlah kamar yang sesuai dengan kebutuhan Anda.\n");
    printf("2. Pilih villa dari daftar yang tersedia.\n");
    printf("3. Masukan berapa hari villa tersebut disewa\n");
    printf("4. Villa yang dipilih akan disimpan ke riwayat penyewaan.\n\n");

    while (1) {
        printf("Kembali ke menu ? [y] : ");
        scanf(" %c", &inputMenu); 
        
        if (inputMenu == 'y') {
            menuUsers();
            break;
        } else {
            printf("Input yang anda masukan salah!\n");
        }
    }
}


//Menampilkan riwayat penyewaan sebelumnya
void lihatRiwayatPenyewaan() {
	char line[200];
	char inputUlang[2];
	
	while(1) {
		FILE *file = fopen(RIWAYAT_PENYEWAAN, "r");
	    if (file == NULL) {
	        printf("Riwayat penyewaan tidak tersedia.\n");
	        return;
	    }
	
	    printf("========================================================================\n");
	    printf("|                                                                      |\n");
	    printf("|                        Riwayat Penyewaan                             |\n");
	    printf("|                                                                      |\n");
	    printf("========================================================================\n\n");
	    
	    printf("=====================================================================================\n");
        printf("| %-20s | %-15s | %-12s | %-21s     |\n", "Nama Penyewa", "Nama Villa", "Jumlah Hari", "Total Harga");
        printf("=====================================================================================\n");

	
	    while (fgets(line, sizeof(line), file)) {
	        char *namaPenyewa = strtok(line, ",");
	        char *namaVilla = strtok(NULL, ",");
	        char *jumlahHari = strtok(NULL, ",");
	        char *totalHarga = strtok(NULL, ",");
	
	        if (namaPenyewa != NULL && namaVilla != NULL && jumlahHari != NULL && totalHarga != NULL) {
	        	totalHarga[strcspn(totalHarga, "\n")] = '\0';
				printf("| %-20s | %-15s | %-12s | Rp. %-21s |\n", namaPenyewa, namaVilla, jumlahHari, totalHarga);
	        }
	    }
	 	printf("=====================================================================================\n\n");
	    fclose(file);
	    
	
	    printf("Kembali? [y/n] : ");
	    scanf("%s",inputUlang);
	    
	    if (strcmp(inputUlang, "y") ==0) {
	    	system("cls");
	    	menuUsers();
	    	break;
		} else if (strcmp(inputUlang, "n") ==0) {
	    	system("cls");
		    } else {
		    	printf("Input yang anda masukan salah!");
			}
	}
	
}


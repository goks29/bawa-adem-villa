#include <stdio.h>
#include "users.h"

void menuUsers() {
	char opsiUsers[2]; 
	
	printf("Halo Users!\n");
	printf("Menu : \n");
	printf("1. Sewa Villa\n");
	printf("2. Tutorial\n");
	printf("3. Riwayat Penyewaan\n");
	printf("4. Keluar\n");
	printf("Masukan opsi : ");
	scanf("%s",opsiUsers);
	
	if (strcmp(opsiUsers,"1") == 0) {
		system("cls");
		printf("cihuy");
	}
		
		if(strcmp(opsiUsers,"2") == 0) {
			printf("cihuy");
		}
		
			if(strcmp(opsiUsers,"3") == 0) {
				printf("cihuy");
			}
			
				if(strcmp(opsiUsers,"4") == 0) {
					;
				}
			
}

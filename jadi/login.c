#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "login.h"

int login() {
	Admin admin = {"admin","1234"};
	char usernameAdmin[20];
	char passwordAdmin[20];
	char opsi[10];
	char ch;
	int i = 0; 
	
	while(1) {
		system("cls");
		printf("======LOGIN=====\n");
		printf("1. Admin\n");
		printf("2. User\n");
		printf("Masukan opsi : ");
		scanf("%s",opsi);
			
				if (strcmp(opsi,"1") == 0) {  //menggunakan stcmp agar tidak error saat menginput strings
					system("cls");
					printf("Masukan username : ");
					scanf("%s", usernameAdmin);
					printf("Masukan password : ");
					scanf("%s", passwordAdmin);

					if (strcmp(usernameAdmin, admin.Username) == 0 && strcmp(passwordAdmin, admin.Password) == 0) {  //string compare untuk user dan pass admin
						system("cls");
						return 1;
					} else {
						printf("\nUSERNAME ATAU PASSWORD SALAH!\n");
						getch();
					}
							
				} else if (strcmp(opsi,"2") == 0) {  //menggunakan strcmp agar tidak error saat menginput strings
					system("cls");
					return 2;
					} else {
						printf("PILIHAN TIDAK VALID !");
						getch();
			    	}			
	}			
}

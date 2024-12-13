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
		printf("===============================================\n");
		printf("|                                             |\n");
		printf("|                                             |\n");
		printf("|      Selamat Datang di Villa Bawa Adem      |\n");
		printf("|                                             |\n");
		printf("|                                             |\n");
		printf("===============================================\n");
		printf("1. Admin\n");
		printf("2. Pelanggan\n");
		printf("Masukan opsi : ");
		scanf("%s",opsi);
				
				while(1){
				
				if (strcmp(opsi,"1") == 0) {  
					system("cls");
					printf("===============================================\n");
    				printf("|                                             |\n");
    				printf("|             Masukkan Username               |\n");
   					printf("|             Dan passwordnya min             |\n");
    				printf("|                                             |\n");
   					printf("===============================================\n");
					printf("Masukan username : ");
					scanf("%s", usernameAdmin);
					printf("Masukan password : ");
					i = 0; 
                    while (1) {
		                char ch = getch(); 
		                if (ch == 13) { 
		                    passwordAdmin[i] = '\0';
		                    break;
		                } else if (ch == 8 && i > 0) { 
		                    i--;
		                    printf("\b \b");
		                } else if (ch != 8) {
		                    passwordAdmin[i] = ch;
		                    i++;
		                    printf("*");
		                }
		    		}

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
						break;
			    	}
		}
	}			
}


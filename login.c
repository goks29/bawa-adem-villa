#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "login.h"

int loginAdmin() {
	Admin admin = {"admin", "1234"};
	char usernameAdmin[10];
	char passwordAdmin[10];
	char pilihan[10];
	char ch;
	int i = 0; 
	
	while(1) {
		system("cls");
		printf("======LOGIN=====\n");
		printf("1. Admin\n");
		printf("2. User\n");
		printf("Masukan pilihan : ");
		scanf("%s",pilihan);
			
				if (strcmp(pilihan,"1") == 0) {  //menggunakan stcmp agar tidak error saat menginput strings
					system("cls");
					printf("Masukan username : ");
					scanf("%s", usernameAdmin);
			
					printf("Masukan password : ");
			
					while (1) {
						ch = getch(); //untuk membaca suatu imput dari ch
						if (ch == '\r') {
							passwordAdmin[i] = '\0'; //menutup string nya
							break;
						}
				
						else if (ch == '\b') {
							if (i > 0){
								i = i - 1;
								printf("\b \b");  //backspace dihitung saat memasukan password
							}
						}
						else {
							passwordAdmin[i] = ch;
							i = i + 1;
							printf("*");	//mengubah tampilan password menjadi bintang
						}
						
			                if (i >= 10) {
        		            	passwordAdmin[i] = '\0';
                		    	break;	 
							}
					}
						
								if (strcmp(usernameAdmin, admin.Username) == 0 && strcmp(passwordAdmin, admin.Password) == 0) {  //string compare untuk user dan pass admin
									system("cls");
									printf("=========MODE ADMIN=========");
									return 1;
								} else {
									printf("\nUSERNAME ATAU PASSWORD SALAH!\n");
									getch();
								}
							
				} else if (strcmp(pilihan,"2") == 0) {  //menggunakan strcmp agar tidak error saat menginput strings
					system("cls");
					printf("==========Hello User !==========");
					return 1;
					} else {
						printf("PILIHAN TIDAK VALID !");
						getch();
			    	}			
	}			
	return 0;
}

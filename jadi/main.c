#include <stdio.h>
#include "login.h"
#include "admin.h"

int main () {
	int hasilLogin = login();
	
	if (hasilLogin == 1){
		menuAdmin();
	}
		if (hasilLogin == 2){
			menuUsers();
		}
	
	return 0;
}

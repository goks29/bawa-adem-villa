#include <stdio.h>
#include "login.h"
#include "admin.h"

int main () {
	int hasilLogin = loginAdmin();
	
	if (hasilLogin == 1){
		menuAdmin();
	}
	
	return 0;
}

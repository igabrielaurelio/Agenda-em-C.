#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	
	int i = menu();
	
	system("pause");
	system("cls");
	
	while(i != 0){
		
		if(i==1){
			criarcontato();
			system("cls");
			break;
		
			} else if(i==2){
				acessarcontato();
				break;
			
				} else if(i==3){
					int j = tipodeedicao();
					if(j==1){
					editarnome();
					} else if(j==2){
						editaremail();
						} else if(j==3){
							editartelefone();
							}break;				
							} else if(i==4){
								apagacontato();
								break;
	}
								
}	

return 0;
}

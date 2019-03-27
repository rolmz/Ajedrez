#include <iostream>
#include <cstdlib>

int tablero[8][8];

using namespace std;

void posicion(int ficha, int *p){
	bool bandera = false;
	
	do{
		*p = rand()%8;
		*(p+1) = rand()%8;
		
		if(tablero[*p][*(p+1)]==0){
			bandera = true;
			tablero[*p][*(p+1)] = ficha;
		}
	}while(bandera==false);
}

void mov_torre(int torre, int *p, int *q){
	int opcion, casillas, fil, col, fil2, col2;
	fil = *p;
	col = *(p+1);
	fil2 = *q;
	col2 = *(q+1);
	do{
		cout << "1.- Mover hacia arriba" << endl;
		cout << "2.- Mover hacia abajo" << endl;
		cout << "3.- Mover hacia la derecha" << endl;
		cout << "4.- Mover hacia la izquierda" << endl;
		cout << "Elija una opcion: ";
		cin >> opcion;
		
		system("cls");
		
		if(opcion<1||opcion>4){
			cout << "Opcion invalida" << endl;
		}
	}while(opcion<1||opcion>4);
	
	do{
		cout << "¿Cuantas casillas desea moverse?" << endl;
		cin >> casillas;
		system("cls");
		
		if(casillas<=0){
			cout << "Debe ingresar un valor mayor a 0" << endl;
		}
	}while(casillas<=0);
	
	switch(opcion){
		case 1: if((fil-casillas)<0){
					cout << "Movimiento invalido!!" << endl;	
			   }else{
			   		if(col==col2 && fil2<fil && (fil-casillas)<=fil2){
			   			cout << "Movimiento invalido, el alfil se encuentra en la casilla [" << fil2 << "," << col2 << "]" << endl; 
					}else{
						tablero[fil][col] = 0;
						tablero[fil-casillas][col] = torre;
						*p = fil-casillas;
						*(p+1) = col;
					}
			   }
			break;
		
		case 2: if((fil+casillas)>=8){
					cout << "Movimiento invalido!!" << endl;	
			   }else{
			   		if(col==col2 && fil2>fil && (fil+casillas)>=fil2){
			   			cout << "Movimiento invalido, el alfil se encuentra en la casilla [" << fil2 << "," << col2 << "]" << endl; 
					}else{
						tablero[fil][col] = 0;
						tablero[fil+casillas][col] = torre;
						*p = fil+casillas;
						*(p+1) = col;
					}
			   }
			break;
			
		case 3: if((col+casillas)>=8){
					cout << "Movimiento invalido!!" << endl;	
			   }else{
			   		if(fil==fil2 && col<col2 && (col+casillas)>=col2){
			   			cout << "Movimiento invalido, el alfil se encuentra en la casilla [" << fil2 << "," << col2 << "]" << endl; 
					}else{
						tablero[fil][col] = 0;
						tablero[fil][col+casillas] = torre;
						*p = fil;
						*(p+1) = col+casillas;
					}
			   }
			break;
		
		case 4: if((col-casillas)<0){
					cout << "Movimiento invalido!!" << endl;	
			   }else{
			   		if(fil==fil2 && col>col2 && (col-casillas)<=col2){
			   			cout << "Movimiento invalido, el alfil se encuentra en la casilla [" << fil2 << "," << col2 << "]" << endl; 
					}else{
						tablero[fil][col] = 0;
						tablero[fil][col-casillas] = torre;
						*p = fil;
						*(p+1) = col-casillas;
					}
			   }
			break;
	}
}

void mov_alfil(int alfil, int *p, int *q){
	int opcion, casillas, cont=0, fil, col, fil2, col2, f_aux, c_aux;
	bool bandera = false;
	
	fil = *p;
	col = *(p+1);
	fil2 = *p;
	col2 = *(p+1);
	
	f_aux = fil;
	c_aux = col;
	
	do{
		cout << "1.- Mover hacia arriba-derecha" << endl;
		cout << "2.- Mover hacia arriba-izquierda" << endl;
		cout << "3.- Mover hacia abajo-derecha" << endl;
		cout << "4.- Mover hacia abajo-izquierda" << endl;
		cout << "Elija una opcion: ";
		cin >> opcion;
		
		system("cls");
		
		if(opcion<1||opcion>4){
			cout << "Opcion invalida" << endl;
		}
	}while(opcion<1||opcion>4);
	
	do{
		cout << "¿Cuantas casillas desea moverse?" << endl;
		cin >> casillas;
		system("cls");
		
		if(casillas<=0){
			cout << "Debe ingresar un valor mayor a 0" << endl;
		}
	}while(casillas<=0);
	
	switch(opcion){
		case 1: if((fil-casillas)<0 || (col+casillas)>=8){
			   		cout << "Movimiento invalido" << endl;
			   }else{
			   		while(cont<casillas){
			   			f_aux -= 1;
			   			c_aux += 1;

						if(tablero[f_aux][c_aux]!=0){
			   				bandera=true;
			   				break;
						}
						++cont;
					}
					
					if (bandera==true){
						cout << "Movimiento invalido, torre en la casilla [" << fil2 << "," << col2 << "]" << endl;
					}else{
						tablero[fil][col] = 0;
						tablero[fil-casillas][col+casillas] = alfil;
						*p = fil-casillas;
						*(p+1) = col+casillas;
					}
				}
			break;
		
		case 2: if((fil-casillas)<0 || (col-casillas)<0){
			   		cout << "Movimiento invalido" << endl;
			   }else{
			   		while(cont<casillas){
			   			f_aux -= 1;
			   			c_aux -= 1;

						if(tablero[f_aux][c_aux]!=0){
			   				bandera=true;
			   				break;
						}
						++cont;
					}
					
					if (bandera==true){
						cout << "Movimiento invalido, torre en la casilla [" << fil2 << "," << col2 << "]" << endl;
					}else{
						tablero[fil][col] = 0;
						tablero[fil-casillas][col-casillas] = alfil;
						*p = fil-casillas;
						*(p+1) = col-casillas;
					}
				}
			break;
			
		case 3: if((fil+casillas)>=8 || (col+casillas)>=8){
			   		cout << "Movimiento invalido" << endl;
			   }else{
			   		while(cont<casillas){
			   			f_aux += 1;
			   			c_aux += 1;

						if(tablero[f_aux][c_aux]!=0){
			   				bandera=true;
			   				break;
						}
						++cont;
					}
					
					if (bandera==true){
						cout << "Movimiento invalido, torre en la casilla [" << fil2 << "," << col2 << "]" << endl;
					}else{
						tablero[fil][col] = 0;
						tablero[fil+casillas][col+casillas] = alfil;
						*p = fil+casillas;
						*(p+1) = col+casillas;
					}
				}
			break;
		
		case 4: if((fil+casillas)>=8 || (col-casillas)<0){
			   		cout << "Movimiento invalido" << endl;
			   }else{
			   		while(cont<casillas){
			   			f_aux += 1;
			   			c_aux -= 1;

						if(tablero[f_aux][c_aux]!=0){
			   				bandera=true;
			   				break;
						}
						++cont;
					}
					
					if (bandera==true){
						cout << "Movimiento invalido, torre en la casilla [" << fil2 << "," << col2 << "]" << endl;
					}else{
						tablero[fil][col] = 0;
						tablero[fil+casillas][col-casillas] = alfil;
						*p = fil+casillas;
						*(p+1) = col-casillas;
					}
				}
			break;
	}
}

main(){
	int opcion, opcion2, pos_torre[2], pos_alfil[2];
	int torre=1, alfil=2, f_aux_torre, c_aux_torre, f_aux_alfil, c_aux_alfil; // f_aux son variables auxiliares que almacenan la direccion anterior
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			tablero[i][j]=0;
		}
	}
	
	posicion(alfil, pos_alfil);
	posicion(torre, pos_torre);
		
	do{
		do{
			cout << "1.- Mover torre" << endl;
			cout << "2.- Mover alfil" << endl;
			cout << "Elija una opcion: ";
			cin >> opcion;
			
			system("cls");
			
			if(opcion<1 || opcion>2){
				cout << "Opcion invalida" << endl << endl;
			}
		}while(opcion<1 || opcion>2);
		
		f_aux_torre = pos_torre[0];
		c_aux_torre = pos_torre[1];
		f_aux_alfil = pos_alfil[0];
		c_aux_alfil = pos_alfil[1];
		
		switch(opcion){
			case 1: mov_torre(torre,pos_torre,pos_alfil);
				break;
			
			case 2: mov_alfil(alfil,pos_alfil,pos_torre);
				break;
		}
		
		system("pause");
		system("cls");
		cout << "El tablero de ajedrez esta de la siguiente forma: " << endl << endl;
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				cout << tablero[i][j] << " ";
			}
			cout << endl;
		}
		
		cout << "\n 1 = torre, 2 = alfil" << endl;
		cout << "Posicion anterior torre: [" << f_aux_torre << "," << c_aux_torre << "] - ";
		cout << "Posicion nueva torre: [" << pos_torre[0] << "," << pos_torre[1] << "]" << endl;
		cout << "Posicion anterior alfil: [" << f_aux_alfil << "," << c_aux_alfil << "] - ";
		cout << "Posicion nueva alfil: [" << pos_alfil[0] << "," << pos_alfil[1] << "]" << endl;

		system("pause");
		system("cls");		
		
		do{
			cout << "1.- Volver al menu principal" << endl;
			cout << "2.- Salir" << endl;
			cin >> opcion2;
			
			system("cls");
			if(opcion2<1 || opcion2>2){
				cout << "Opcion invalida"<< endl << endl;
			}
		}while(opcion2<1 || opcion2>2);
		
	}while(opcion2==1);
	
	return 0;
}

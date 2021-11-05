#include <iostream>

using std::cout;
using std::string;
using std::cin;
using std::endl;


char** provisionarMatriz();
void liberarMatriz(char**& );
void printMatrix(char** );
int menu();
int* ejercicio2 (char**, char);
string ejercicio3(char**matriz, char inicio, char destino);
string ejercicio4 (string palabra);

int main(int argc, char** argv) {

	int opcion = 0;
	while (opcion != 5) {
		switch(opcion = menu()) {
			case 1: {
				char** matriz = NULL;

				if(matriz != NULL) {
					liberarMatriz(matriz);
					matriz = provisionarMatriz();
				} else {
					matriz = provisionarMatriz();
				}
				cout<<"La matriz es: \n";
				printMatrix(matriz);
				liberarMatriz(matriz );

				break;
			}
			case 2: {
				char** matriz = NULL;
				int* pointer = new int[2];
				if(matriz != NULL) {
					liberarMatriz(matriz);
					matriz = provisionarMatriz();
				} else {
					matriz = provisionarMatriz();
				}
				char letra ;
				cout<<"Ingrese letra a buscar: ";
				cin >> letra;
				pointer = ejercicio2(matriz,letra);

				cout<<"La fila es: "<<pointer[0]<<" "<<"La columna es: "<<pointer[1]<<endl;
				delete[] pointer;
				liberarMatriz(matriz );
				break;
			}
			case 3: {
				char** matriz = NULL;
				int* pointer = new int[2];
				if(matriz != NULL) {
					liberarMatriz(matriz);
					matriz = provisionarMatriz();
				} else {
					matriz = provisionarMatriz();
				}
				char letra,letra2;
				cout<<"Ingrese letra de inicio: ";
				cin >> letra;
				cout<<"Ingrese letra de destino: ";
				cin>> letra2;
				string result = ejercicio3(matriz,letra,letra2);

				cout<<"Ruta: "<<result<<endl;
				liberarMatriz(matriz );
				break;
			}
			case 4: {

				string palabra;
				cout<<"Ingrese palabra: ";
				cin>>palabra;
				string respuesta = ejercicio4(palabra);
				cout<<"Ruta: "<<respuesta<<"#"<<endl;
				break;
			}
		}
	}



	return 0;
}

char** provisionarMatriz() {
	char** matrix = new char*[6];

	for(int i= 0; i <5; i++)
		matrix[i]= new char[5];

	int letra = 97;
	for(int i = 0 ; i < 5  ; i++) {
		for(int j = 0 ; j < 5 ; j++) {
			if(letra < 122) {
				matrix[i] [j] = char (letra);
				letra++;
			}
		}
	}
	matrix[5] = new char[1];
	matrix[5][0] = 'z';

	return matrix;
}

void liberarMatriz(char**& matriz) {
	if (matriz != NULL && 6 > 0) {
		for(int i = 0; i < 5; ++i) {
			delete[] matriz[i];
		}
		delete[] matriz;
		matriz = NULL;
	}
}

void printMatrix(char** matriz) {
	if (matriz != NULL && 6 > 0) {
		for(int x=0; x<5; x++) { //
			for(int y=0; y<5; y++) { //
				cout<<matriz[x][y]<<" "; //
			}
			cout<<endl; //
		}
		cout<<matriz[5][0]<<endl;
	}
}


int menu() {
	int opcion =0;
	cout<<"Menu\n"
	    <<"1. Ejercicio 1\n"
	    <<"2. Ejercicio 2\n"
	    <<"3. Ejercicio 3\n"
	    <<"4. Ejercicio 4\n"
	    <<"5. Salir\n"
	    <<"Ingrese opcion: ";
	cin >> opcion;


	return opcion;
}

int* ejercicio2 (char** matriz, char letra) {
	int fila, columna = 0;
	int* pointer = new int[2];

	if(letra == 'z') {
		pointer [0] = 5;
		pointer [1] = 0;
	} else {
		for(int i = 0 ; i < 6 ; i++) {
			for(int j = 0 ; j < 5 ; j++) {
				if(matriz[i][j] == letra) {
					pointer[0]= i;
					pointer [1]= j;
				}
			}
		}
	}


	return pointer;
}

string ejercicio3(char**matriz, char inicio, char destino) {
	string ruta = "";
	int* pointer1 = new int[2];
	pointer1 = ejercicio2(matriz,inicio);
	int* pointer2 = new int[2];
	pointer2 = ejercicio2(matriz,destino);

	int x1 = pointer1[0];
	int x2 = pointer2[0];
	int y1 = pointer1[1];
	int y2 = pointer2[1];


	if(inicio == 'z') {
		ruta+="U";
		x1--;
	}
	if(y1 < y2) {
		for(int i = y1 ; i < y2 ; i++) {
			ruta+="R";
		}
	} else if ( y2 < y1) {
		for(int i = y2 ; i < y1 ; i++) {
			ruta+="L";
		}
	} else if (y1= y2) {
		ruta;
	}

	if(x1 < x2) {
		for(int i = x1 ; i < x2 ; i++) {
			ruta+="D";
		}
	} else if(x1 >x2) {
		for(int i = x2; i < x1 ; i++) {
			ruta+="U";
		}
	} else if (x1=x2) {
		ruta;
	}
	delete[] pointer1;
	delete[] pointer2;

	return ruta;

}
string ejercicio4 (string palabra) {
	char** matriz = NULL;
	if(matriz != NULL) {
		liberarMatriz(matriz);
		matriz = provisionarMatriz();
	} else {
		matriz = provisionarMatriz();
	}
	char letrita = 'a';
	char letra2 = palabra.at(0);

	string resultado = "";
	resultado = ejercicio3(matriz, letrita,letra2);

	for(int i = 0 ; i < palabra.size()-1; i++) {
		resultado+="#"+ejercicio3(matriz,palabra.at(i),palabra.at(i+1));
	}
	liberarMatriz(matriz);

	return resultado;




}

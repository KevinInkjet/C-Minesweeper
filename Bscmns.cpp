#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

void expandir(int x, int y, char vista[][25], int tablero[][25], int n)
{
	if(vista[x-1][y] == 00 && x>0 && tablero[x][y] < 1 && tablero[x-1][y] != -1) //ARRIBA
	{
		vista[x-1][y] = 1;
		expandir(x-1,y,vista,tablero,n);
	}
	if(vista[x+1][y] == 00 && x<n && tablero[x][y] < 1 && tablero[x+1][y] != -1) //ABAJO
	{
		vista[x+1][y] = 1;
		expandir(x+1,y,vista,tablero,n);
	}
	if(vista[x][y-1] == 00 && y>0 && tablero[x][y] <1 && tablero[x][y-1] != -1) //IZQUIERDA
	{
		vista[x][y-1] = 1;
		expandir(x,y-1,vista,tablero,n);
	}
	if(vista[x][y+1] == 00 && y<n && tablero[x][y] <1 && tablero[x][y+1] != -1) //DERECHA
	{
		vista[x][y+1] = 1;
		expandir(x,y+1,vista,tablero,n);
	}
	if(vista[x+1][y-1] == 00 && y>0 && x<n && tablero[x][y] <1 && tablero[x+1][y-1] != -1) // INFERIOR IZQUIERDA
	{
		vista[x+1][y-1] = 1;
		expandir(x+1,y-1,vista,tablero,n);
	}
	if(vista[x+1][y+1] == 00 && y<n && x<n && tablero[x][y] <1 && tablero[x+1][y+1] != -1) // INFERIOR DERECHA
	{
		vista[x+1][y+1] = 1;
		expandir(x+1,y+1,vista,tablero,n);
	}
	if(vista[x-1][y-1] == 00 && y>0 && x>0 && tablero[x][y] <1 && tablero[x-1][y-1] != -1) //SUPERIOR IZQUIERDA
	{
		vista[x-1][y-1] = 1;
		expandir(x-1,y-1,vista,tablero,n);
	}
	if(vista[x-1][y+1] == 00 && y<n && x>0 && tablero[x][y] <1 && tablero[x-1][y+1] != -1) //SUPERIOR DERECHA
	{
		vista[x-1][y+1] = 1;
		expandir(x-1,y+1,vista,tablero,n);
	}
}

int main()
{
	int n, tablero[25][25], fila, columna, i, azar1, azar2, x=0, y=0, count=0, casillas=-1;
	char vista[25][25], cuadrado = 254;
	bool valid = false, mensaje = false, win = false;
	srand(time(NULL));
	do
	{
		cout << "Dame el orden de la matriz del 2 al 25: " << endl;
		cin >> n;
		if(n >= 2 && n <= 25)
		{
			valid = true;
		}
	}while(valid == false);
	valid = false;
	//PONER CEROS EN TODA LA MATRIZ
	for(fila=0; fila<n; fila++)
	{
		for(columna=0; columna<n; columna++)
		{
			tablero[fila][columna] = 0;	
			vista[fila][columna] = 00;
		}
	}
	//PONER BOMBAS
	
	for(i=0; i<n; i++)
	{
		azar1 = rand()%n;
		azar2 = rand()%n;
		if(tablero[azar1][azar2] != -1)
		{				
			tablero[azar1][azar2] = -1;
			//cout << "Fila: " << azar1 << " Columna: " << azar2 << " es -1" << endl;
		}
		else
		{
			i--;
		}
	}
	
	for(fila=0; fila<n; fila++)
	{
		for(columna=0; columna<n; columna++)
		{
			count = 0;
			if(tablero[fila][columna+1] == -1) //Derecha
			{
				count = count + 1;
			}
			if(tablero[fila][columna-1] == -1) //Izquierda
			{
				count = count + 1;
			}
			if(tablero[fila-1][columna] == -1) //Arriba
			{
				count = count + 1;
			}
			if(tablero[fila+1][columna] == -1) //ABAJO
			{
				count = count + 1;
			}
			if(tablero[fila-1][columna-1] == -1) //SUPERIOR IZQUIERDA
			{
				count = count + 1;
			}
			if(tablero[fila-1][columna+1] == -1) //SUPERIOR DERECHA
			{
				count = count + 1;
			}
			if(tablero[fila+1][columna-1] == -1) //INFERIOR IZQUIERDA
			{
				count = count + 1;
			}
			if(tablero[fila+1][columna+1] == -1) //INFERIOR DERECHA
			{
				count = count + 1;
			}
			
			if(tablero[fila][columna] != -1)
			{
				tablero[fila][columna] = count;
			}
		}
	}
	system("cls");
	do{
		if(mensaje == true)
		{
			cout << "No utilizaste un rango adecuado, intenta otra vez." << endl;
		}
		cout << "Para el juego se utilizara el siguiente esquema de coordenadas donde debes ingresar un valor de x y otro de y " << endl;
		cout << "Recuerda que solo puedes usar numeros del 0 al " << n-1 << endl;
		cout << "     y=0     y=1" << endl;
		cout << "x=0  ___     ___" << endl;
		cout << "x=1  ___     ___" << endl;
		cout << "Como ejemplo, selecciona algun elemento de la matriz anterior de 2x2..." << endl;
		cout << "x: ";
		cin>>x;
		cout << "y: ";
		cin>>y;
		//cout << "x: " << x << " y: " << y << endl;
		if(x == 0 && y == 0)
		{
			cout << "BIEN HECHO" << endl;
			valid = true;
		}
		else if(x == 0 && y == 1)
		{
			cout << "BIEN HECHO" << endl;
			valid = true;
		}
		else if(x == 1 && y == 0)
		{
			cout << "BIEN HECHO" << endl;
			valid = true;
		}
		else if(x == 1 && y == 1)
		{
			cout << "BIEN HECHO" << endl;
			valid = true;
		}
		else
		{
			mensaje = true;
		}
		system("cls");
	}while(valid == false);
	//EL JUEGO
	do
	{	
		for(fila=0; fila<n; fila++)
		{
			for(columna=0; columna<n; columna++)
			{
				if(vista[fila][columna] == 00) //IMPRIME VALORES QUE NO SE HAYAN DESBLOQUEADO(OCULTOS)
				{
					cout << cuadrado << "\t";
				}
				else //IMPRIME LOS VALORES QUE YA SE DESBLOQUEARON
				{
					cout << tablero[fila][columna] << "\t";
				}
			}
			cout << endl;
			cout << endl;
		}
		
		do
		{
			cout << "x: ";
			cin>>x;
		}while(x<0 || x>n-1);
		do
		{
			cout << "y: ";
			cin>>y;
		}while(y<0 || y>n-1);
		
		vista[x][y] = 1;
		
		//Expansión
		if(tablero[x][y] == 0)
		{
			expandir(x,y,vista,tablero,n);
		}
		//Expansión ^
		
		casillas=0;
		for(fila=0; fila<n; fila++)
		{
			for(columna=0; columna<n; columna++)
			{
				if(vista[fila][columna] == 1 && tablero[fila][columna] != -1)
				{
					casillas++;
				}
			}
		}
		
		if(casillas == (n*n)-n)
		{
			win = true;
		}
		
		if(tablero[x][y] == -1)
		{
			win = true;
		}
		
		system("cls");
	}while(win == false);
	system("cls");
	
	if(casillas == (n*n)-n)
	{
		cout<< "¡Ganaste!" << endl;
	}
	else
	{
		cout << "Perdiste" << endl;
	}
	for(fila=0; fila<n; fila++)
	{
		for(columna=0; columna<n; columna++)
		{
			cout << tablero[fila][columna] << "\t";
		}
		cout << endl;
		cout << endl;
	}
	
}

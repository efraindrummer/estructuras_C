#include<stdio.h>
#include <windows.h>
#define M 100
#define dias 7

typedef struct{
	char calle[80];
	int num;
	char colonia[80];
}Domicilio;

typedef struct{
	char nombre[80]; 
	int clave; 
	Domicilio domicilio;
	float ventas [dias];
}vendedor; 

void color  (int c){  //parametros
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),c);
}
//indentificador
void gotoxy (int x, int y){   //parametros
	COORD coord;
	
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle (STD_OUTPUT_HANDLE),coord);
}

int menu ();
void leerentrada (vendedor vendedores[], int n);
void leersalida(vendedor vendedores [], int n);
vendedor leerunregistro(int r ); 
void imprimir_un_registro(vendedor v);
void Total_Vendido(vendedor vendedores[], int n);
void promedio_del_vendedor(vendedor vendedores[], int n);
void promedio_del_dia(vendedor vendedores[], int n);
int peor_vendedor(vendedor vendedores[], int n);
int mejor_vendedor(vendedor vendedores[], int n);
void saludo();

main()
{
	int i,n,opcion, peor, mejor;
	vendedor vendedores[M];
	color(11);
	system("CLS");
	gotoxy(30, 1);
	printf("**********SISTEMA DE REGISTRO DE VENDEDORES*************");
	gotoxy(30, 2);
	printf("¿Cuantos vendedores va registar?: ");
	scanf("%d",&n);
do{
	opcion=menu();
	
	switch(opcion){
	case 1: leerentrada(vendedores, n); break;
	
	case 2: leersalida(vendedores, n); break;
	
	case 3: Total_Vendido(vendedores, n); break;
	
	case 4: promedio_del_vendedor(vendedores, n); break;
	
	case 5: promedio_del_dia(vendedores, n);	break;
	
	case 6:	peor=peor_vendedor(vendedores, n);
			printf("el peor vendedor es %s", vendedores[peor].nombre ); break;
			
	case 7: mejor=mejor_vendedor(vendedores, n);
			printf("El mejor vendedor es %s", vendedores[mejor].nombre); break;
	        
	case 0:saludo(); break;
	default:printf("\nOPCION NO VALIDA\n");	break;
		}
	}while(opcion!=0);
}

void Total_Vendido(vendedor vendedores[], int n){

	float suma=0;
	
	for(int i=0;i<n;i++){
		for(int d=0; d<dias; d++) 
		 suma += vendedores[i].ventas[d];
	}
	printf ("\nLA SUMA ES %.2f", suma);
}

void promedio_del_vendedor(vendedor vendedores[], int n){
	
	int vendedor;
	float suma=0, promedio;
		
	for(int i=0; i<n; i++){
		suma=0;
		for(int d=0; d<dias; d++){
		
			suma+=vendedores[i].ventas[d];
			promedio=suma/dias;
			vendedor=i;
			}
			printf("\n EL VENDEDOR %s VENDIO %f\n",vendedores[i] ,promedio);	
		}
	}

void promedio_del_dia(vendedor vendedores[], int n){
	
	float suma=0, promedio;
	
	for(int i=0; i<n; i++){
		suma=0;
		for(int d=0; d<dias; d++){
		
		suma+=vendedores[i].ventas[d];
		promedio=suma/d;
}
	for(int i=0;i<dias;i++){
		printf("PROEDIO DEL DIA %i:-> %.2f\n",i+1,promedio);		
	}
}
}

int peor_vendedor(vendedor vendedores[], int n){	
	int  peor, rango=10000; 
	float suma=0, promedio;
	
	for(int i=0; i<n; i++){
		suma=0;
		for(int d=0; d<dias; d++)
		suma+=vendedores[i].ventas[d];
		promedio=suma/dias;
		
		if(promedio<rango){
			peor=i;
			rango=promedio;
		}		
	}return peor;
}
		
int mejor_vendedor(vendedor vendedores[], int n){
	
	int mejor, rango=10000;
	float suma=0, promedio;
	for(int i=0;i<n;i++){
		suma=0;
		for(int d=0;d<dias;d++)
		suma+=vendedores[i].ventas[d];

		if(suma>rango){
			mejor=i;
		suma=rango;			
	} return mejor;
}
}

vendedor leerunregistro(int r ){
		
	vendedor ve;

	printf("\nVENDEDOR No. %d\n", r+1);
	printf("\nCLAVE: ");fflush(stdin);
	scanf("%i",&ve.clave);
	
	printf("\nNOMBRE: ");fflush(stdin);
	scanf("%[^\n]",ve.nombre);
	
	printf("\nDOMICILIO\n");fflush(stdin);
	printf("\nCALLE: ");fflush(stdin);
	scanf("%[^\n]",ve.domicilio.calle);
	
	printf("\nNUMERO: ");fflush(stdin);
	scanf("%i",&ve.domicilio.num);
	
	printf("\nCOLONIA: ");fflush(stdin);
	scanf("%[^\n]",ve.domicilio.colonia);
	
	printf("\n****VENTAS****\n ");fflush(stdin);
	for(int i=0;i<dias; i++){
		printf("VENTA DEL DIA %d:  ",i+1);fflush(stdin);
		scanf("%f",&ve.ventas[i]);	
	}
	return ve;
}

void leerentrada (vendedor vendedores[], int n){

	for(int i=0; i<n; i++)
	vendedores[i]=leerunregistro(i);
}

void imprimirunregistro(vendedor v){
	
	printf("\nCLAVE:%d\n",v.clave);
	printf("\nNOMBRE:%s\n",v.nombre);
	printf("\nDOMICILIO\n");
	printf("CALLE: %s\n", v.domicilio.calle);
	printf("NUMERO: %i\n", v.domicilio.num);
	printf("COLONIA: %s\n", v.domicilio.colonia);
	printf("\n ****VENTAS****\n");
	for(int i=0;i<dias;i++){
		printf("VENTA DEL DIA %i:-> %.2f\n",i+1,v.ventas[i]);		
	}
	return;
}

void leersalida(vendedor vendedores[], int n){
	for(int i=0; i<n; i++)
	    imprimirunregistro(vendedores[i]);
}

int menu(){
	int op;
	printf("\n\n");
	printf("1.-REGISTRO\n");
	printf("2.-IMPRIMIR REGISTRO\n");
	printf("3.-CALCULAR TOTAL DE VENTAS\n");
	printf("4.-PROMEDIO POR VENDEDOR\n");
	printf("5.-PROMEDIO POR DIA\n");
	printf("6.-PEOR VENDEDOR\n");
	printf("7.-MEJOR VENDEDOR\n");
	printf("0.-SALIR\n");
	printf("\n Ingresa opcion: ");
	scanf("%i", &op);
	return op;
}

void saludo(){
	printf("\nGRACIAS POR SU PREFERENCIA \n");
	printf("\nPROGRAMA HECHO POR EFRAIN MAY MAYO\n");
	printf("\nESTUDIANTE DE INGIENERIA EN COMPUTACION\n");
	printf("\nPROGRAMACION 2\n");
}

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>
#include "Polinomio.h"
#include "Racional.h"
#include <iostream>
using namespace std;

#define max_args 1000  			
#define maxln_Com_Amb 105 		

/*Declarando variables*/
char comando[maxln_Com_Amb]; 	
char *args[max_args]; 			
char *frac[max_args]; 			
int i;
FILE *Archivo;
char nombre[maxln_Com_Amb];
char poli1[maxln_Com_Amb];
char poli2[maxln_Com_Amb];
char opera[1];
char coeficiente[maxln_Com_Amb];
char polinomio[15];
int insert;
int f;		//entero que define la fraccion

/*Declarando cabeceras de funciones*/
void separaArgs(void); 				
void CrearArchivo(FILE *Archivo);	 
void InsertarDatos(FILE *Archivo);
void leerDatos(FILE *Archivo);
void driverPolinomio(FILE *Archivo);
void SavePolinomio(void);
void DesplegarInfo(void);
void SepararNuevo(void);
	

int main(int argc, char** argv) {
	
	int exit=1;		
	
	do{				
    	int validar=0;
    	
		printf(">>  "); 					
    	fflush(stdin); 						
    	memset(comando,'\0',maxln_Com_Amb);	
    	scanf("%[^\n]s",comando); 			
    	
    	if(strlen(comando)>0){				
    		separaArgs();
				
			if(strcmp(comando,"exit")==0){ 
        	exit=0;}
        	
        	else{	//Inicia el analisis de lo ingresado
        	
				if(strcmp(comando,"ingresar")==0){
					CrearArchivo(Archivo);
					validar = 1;
				}
				if(strcmp(comando,"informacion")==0){
					DesplegarInfo();
					validar = 1;
				}
				if(strcmp(comando,"look")==0){
					leerDatos(Archivo);
					validar = 1;
				}
				if(strcmp(comando,"clc")==0){
					system("cls");
					validar = 1;
				}
				if(strcmp(comando,"operar")==0){
					driverPolinomio(Archivo);
					validar = 1;
				}
				if (validar == 0){
				cout<<"<<  Ingresa un comando valido"<<endl;
				}
				
			}
		}
	}while(exit);
	
	return 0;
}

void separaArgs(void){  

	for(i=0;i<(max_args-1);i++) args[i]=NULL;							
		strtok(comando," =()[]{},"), i=0; 								
		args[i]=comando; 												
	while((args[++i]=strtok(NULL," =()[]{},"))!=NULL && i<(max_args-2));
}

void CrearArchivo(FILE *Archivo){
	char respuesta[2];
	FILE *arch;
	strcpy(nombre,args[1]);			 
	strcat(nombre,".txt");				
	
	Archivo = fopen (nombre, "r");	
	char namefile[15];
   
	if (!Archivo){						
    Archivo=fopen (nombre, "w");
    InsertarDatos(Archivo);			
    }
    
    else{								
    cout<<"<<  La variable "<<args[1]<<" ya existe, sobre escribir? si/no"<<endl;
	int sobre = 1;						
	
	do{   
		fflush(stdin);
		cout<<">>  ";
		cin>>respuesta;
			if(strcmp(respuesta,"si")==0){
				InsertarDatos(Archivo);
				sobre = 0;
			}
			else if(strcmp(respuesta,"no")==0){
				sobre = 0;
			}else {
			cout<<"<<  Error: por favor ingresa una opcion correcta"<<endl;
			}
	}while(sobre);
	
	}
        
        fclose(Archivo);
    
}

void InsertarDatos(FILE *Archivo){
	int y;
	char Y[1];
	fclose(Archivo);
	Archivo=fopen(nombre, "w+");
	strcpy(polinomio,"");
	for(y=2; y<i; y++){
		strcat(polinomio,args[y]);
		strcat(polinomio,": ");
	}
	
	cout<<"    "<<args[1]<<" ="<<endl<<"\t"<<polinomio<<endl;
	y-=2;
	sprintf(Y,"%d",y);
	strcat(Y," ");
	strcat(Y,polinomio);
	strcpy(polinomio,Y);
	fwrite(polinomio,sizeof(char),sizeof(polinomio),Archivo);

	fclose(Archivo);
}

void leerDatos(FILE *Archivo){
	int y;
	FILE *arch;
	strcpy(nombre,args[1]);				
	strcat(nombre,".txt");				
	
	Archivo = fopen (nombre, "r");	
	char namefile[15];
	   
	if (!Archivo){						
	cout<<"<<  La variable "<<args[1]<<" no existe"<<endl;
	}
    else{
    fread(polinomio,sizeof(char),sizeof(polinomio),Archivo);	
    cout<<"    "<<args[1]<<" ="<<endl;
    
    for(i=0;i<(max_args-1);i++) args[i]=NULL;						
		strtok(polinomio," "), i=0;
	while((args[++i]=strtok(NULL," "))!=NULL && i<(max_args-2));
	
	cout<<"\t";
	
	for(y=1; y<i; y++){				 
	cout<<args[y]<<": ";
	}
	cout<<endl;
	
    fclose(Archivo);				
	}
}

void driverPolinomio(FILE *Archivo){
	int y;
	
	FILE *arch;
	strcpy(opera,args[2]);				
	strcpy(poli1,args[1]);				 
	strcat(poli1,".txt");				
	strcpy(poli2,args[3]);				
	strcat(poli2,".txt");				
	
	
	Archivo = fopen (poli1, "r");	
	char namefile[15];
	
	if (!Archivo){						
	cout<<"<<  La variable "<<args[1]<<" no existe"<<endl;
	}
	else{
	fread(polinomio,sizeof(char),sizeof(polinomio),Archivo);		
    
    for(i=0;i<(max_args-1);i++) args[i]=NULL;						
		strtok(polinomio," "), i=0;
	while((args[++i]=strtok(NULL," "))!=NULL && i<(max_args-2));
	
    fclose(Archivo);				//cierra el archivo
  	Rac *unRacPt=new Rac[i-1];
  	
	char n[10];		
	char d[10];		
	int N;
	int D;
	
	for (y=0;y<(i-1);y++){
		
		strcpy(coeficiente,args[y+1]);
		SepararNuevo();
		strcpy(n,frac[0]);
		N = atoi(n);
		strcpy(d,frac[1]);
		D = atoi(d);
		*(unRacPt+y)=Rac(N,D);
	}
  	
  	Polinomio Polinomio1(i-2,unRacPt); 
  
  	
  	
	Archivo = fopen (poli2, "r");	
	char namefile[15];
	
	if (!Archivo){						//Verifica la creacion del archvio
	cout<<"<<  La variable "<<args[3]<<" no existe"<<endl;
	}
	else{
	fread(polinomio,sizeof(char),sizeof(polinomio),Archivo);		
    
    for(i=0;i<(max_args-1);i++) args[i]=NULL;						
		strtok(polinomio," "), i=0;
	while((args[++i]=strtok(NULL," "))!=NULL && i<(max_args-2));
	
    fclose(Archivo);				//cierra el archivo
  	Rac *unRacPt=new Rac[i-1];
	
	for (y=0;y<(i-1);y++){
		
		strcpy(coeficiente,args[y+1]);
		SepararNuevo();
		strcpy(n,frac[0]);
		N = atoi(n);
		strcpy(d,frac[1]);
		D = atoi(d);
		*(unRacPt+y)=Rac(N,D);
	}
  
	
	Polinomio Polinomio2(i-2,unRacPt);
	//Este es el final del programa 
	
  	if(strcmp(opera,"+")==0){
		Polinomio Polinomio3 = Polinomio1 + Polinomio2;
  		cout<<Polinomio3<<endl;}
	if(strcmp(opera,"*")==0){
		Polinomio Polinomio3 = Polinomio1 * Polinomio2;
  		cout<<Polinomio3<<endl;}
  		if(strcmp(opera,"-")==0){
		Polinomio Polinomio3 = Polinomio1 - Polinomio2;
  		cout<<Polinomio3<<endl;}
	
	
		  
		}
	}
}

void SepararNuevo(void){  
	
	frac[0]=strtok(coeficiente,"/"); 
	frac[1]=strtok(NULL,"/");
}


void DesplegarInfo(){
	cout<<"<<  Creado por Nestor Garcia Cervantes"<<endl;
	cout<<"    Ingrasa en el formato correcto para que\n \tel interprete entienda lo que dices"<<endl<<endl;
	cout<<"    Lista de comandos"<<endl;	
	cout<<"    ingresar \t crea la variable y guarda ejemplo. ingresar A = {1, 2}"<<endl;
	cout<<"    look \t muestra la variable deseada ejemplo. look A"<<endl;
	cout<<"    operar \t realiza las operaciones de polinomios ejemplo. operar A + B"<<endl;
	cout<<"    clc \t limpia la pantalla"<<endl;
	cout<<"    exit \t cierra el programa"<<endl;
}


#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <ctime>
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\validar.hpp"
using namespace std;
class Registro_Diario {
private:
	validar val;
	int no_registro;
	int no_servicio;
public:
	
Registro_Diario(int no_registro,int no_servicio){
	this->no_registro=no_registro;
	this->no_servicio=no_servicio;
}

void agregarRegistro(){
      	int op=0;
      	int i=1;
      	string linea;
      	char no[30];
      	char nom[3][30]={"No.Tratamiento:  ","Veces aplicadas:  "};
      	fflush(stdin);
      	for(;;){
		cout<<"No.Trabajador:   ";
      	cin>>no;
      	if( !val.isCharnum( no ) )
		{
		cout << "Ingresa solo numeros...\n";
		Sleep(800);
		}
		else{
		strcat(no,"-Reg.txt");
		break;
		}}
      	
      	ifstream archivo(no);
      if (!archivo)
    {
	cout<<"Archivo no existe"<<endl;
	}
    else{
    ofstream archivo(no);
	if(archivo.is_open()){
   time_t now = time(0);
   string dt = ctime(&now);
   archivo<< "Fecha: " << dt << endl;
   
   for(;;){
   	Menu:
   	system("cls");	
   	i=1;
   while(i<3){
   	for(;;){
				fflush(stdin);
				cout<<nom[i-1];
				getline(cin, linea);
				if(!val.isInteger( linea ))
				{
				cout << "Ingresa solo numeros...\n";
				Sleep(800);
					}
				else{
				archivo<<nom[i-1]<<linea<<endl;
				break;
			    }			
				
					}
					i++;
   }		
	string OP;
	MenuSalir:
	cout<<"\nDeseas Continuar 1)Si 2)No"<<endl;
		for(;;){
		getline(cin, OP);
		if( !val.isInteger( OP ) )
			{
			 cout << "Ingresa solo numeros...\n";
			Sleep(800);
			     }
			 else{
			  	op=atoi(OP.c_str());
			  	break;
			    }}
			    if(op==2){
			    	break;
			    }
		switch(op){
			case(1): goto Menu;
			default:cout<<"No es una opcion";
				Sleep(1000);
				goto MenuSalir;
			
		}
	
		}
	archivo<<endl<<"------------------------------------------------------------------------------------------------"<<endl;
	cout<<endl<<setw(50)<<"Creado Con Exito"<<endl;	
		}	
	archivo.close();
	
    }
	  
	  
	  }
      
      
      
      void crearRegistro(){
      	int op;
      	string linea;
      	char no[30];
      	for(;;){
		cout<<"No.Trabajador:   ";
      	cin>>no;
      	if( !val.isCharnum( no ) )
		{
		cout << "Ingresa solo numeros...\n";
		Sleep(800);
		}
		else{
		strcat(no,"-Reg.txt");
		break;
		}}

      	ifstream archivo(no);
      if (!archivo)
    {
	ofstream archivo (no);
	if(archivo.is_open()){
	archivo<<setw(50)<<"Registro Diario\n"<<setw(50)<<"No.Veterinario: "<<op<<endl<<endl;
	cout<<endl<<setw(50)<<"Creado con Exito"<<endl;
	}
	
	archivo.close();
	}
    else{
    	cout<<"Registro ya existente"<<endl;
    }
      	
      }
       
	void calcular_actividad_diaria(int no_servicio, float lista_precio_servicios){	}

};


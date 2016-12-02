#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <ctime>
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Validate.hpp"
using namespace std;
class Journal {
private:
	Validate val;
	int no_registro;
	int no_servicio;
public:
	
Journal(int no_registro,int no_servicio){
	this->no_registro=no_registro;
	this->no_servicio=no_servicio;
}

void agregarRegistro(){
      	int op=0;
      	int i=1;
      	string linea;
      	char no[30];
      	char nom[3][30]={"No.Treatment:  ","Times applied:  "};
      	fflush(stdin);
      	for(;;){
		cout<<"No.Worker:   ";
      	cin>>no;
      	if( !val.isCharnum( no ) )
		{
		cout << "Enter Numbers only...\n";
		Sleep(800);
		}
		else{
		strcat(no,"-Reg.txt");
		break;
		}}
      	
      	ifstream archivo(no);
      if (!archivo)
    {
	cout<<"File no exist"<<endl;
	}
    else{
    ofstream archivo(no);
	if(archivo.is_open()){
   time_t now = time(0);
   string dt = ctime(&now);
   archivo<< "Date: " << dt << endl;
   
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
				cout << "Enter Numbers only...\n";
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
	cout<<"\nWant to continue 1)Yes 2)No"<<endl;
		for(;;){
		getline(cin, OP);
		if( !val.isInteger( OP ) )
			{
			 cout << "Enter Numbers only...\n";
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
			default:cout<<"Invalid Option";
				Sleep(1000);
				goto MenuSalir;
			
		}
	
		}
	archivo<<endl<<"------------------------------------------------------------------------------------------------"<<endl;
	cout<<endl<<setw(50)<<"Daily storage successful"<<endl;	
		}	
	archivo.close();
	
    }
	  
	  
	  }
      
      
      
      void crearRegistro(){
      	int op;
      	string linea;
      	char no[30];
      	for(;;){
		cout<<"No.Worker:   ";
      	cin>>no;
      	if( !val.isCharnum( no ) )
		{
		cout << "Enter Numbers only...\n";
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
	archivo<<setw(50)<<"Daily register\n"<<setw(50)<<"No.Veterinarian: "<<op<<endl<<endl;
	cout<<endl<<setw(50)<<"Successfully created"<<endl;
	}
	
	archivo.close();
	}
    else{
    	cout<<"Register already exist"<<endl;
    }
      	
      }
       
	void calcular_actividad_diaria(int no_servicio, float lista_precio_servicios){	}

};


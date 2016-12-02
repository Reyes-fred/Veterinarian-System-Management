#include<iostream>
#include<string>
#include <ctime>
#include <iomanip>
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\Persona.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\Empleado.hpp"
using namespace std;


class Veterinario : public Empleado {
private:
	int noConsultorio;
	string especialidad;
	
public:
       Veterinario(string nombre,string direccion,string telefono,int no_Trabajador,string password,string RFC,string cargo,float sueldo, int noConsultorio,string especialidad):Empleado( nombre, direccion, telefono, no_Trabajador, password,  RFC, cargo, sueldo)
        {
                  this->noConsultorio=noConsultorio;
                  this->especialidad=especialidad;
                  }


	void revisar_cita(){
	cout<<"No.Cliente:"<<setw(10)<<"Dia"<<setw(10)<<"Dia#"<<setw(10)<<"Hora"<<setw(10)<<"Mes"<<setw(10)<<"Nombre"<<endl;
	

	string linea;
	ifstream archivo("Citas.txt");
	if(archivo.is_open()){
		while(archivo.good()){
		
		getline(archivo,linea);
		cout<<linea<<endl;	}
	cout<<endl<<"---------------------------------------------------------------"<<endl;
	cout<<"Fin archiv"<<endl;
	}
	archivo.close();
	}
	
	void crear_receta(){
		int x=0;
		string linea;
		ofstream archivo("Receta.txt");
		if(archivo.is_open()){
		fflush(stdin);
		time_t now = time(0);
	   string dt = ctime(&now);
	   archivo<<setw(50) <<"Fecha: " << dt << endl;
	   cout<<"Sucursal: "<<endl;
	   getline(cin,linea);
	   archivo<<"Sucursal: "<<linea;
	   
	   cout<<"Nombre Doctor: "<<endl;
	   getline(cin,linea);
	   archivo<<"Doctor: "<<linea<<endl<<endl;
	   
	   cout<<"Nombre Mascota: "<<endl;
	   getline(cin,linea);
	   archivo<<"Mascota: "<<linea<<endl;
	   
	   cout<<"Nombre Cliente: "<<endl;
	   getline(cin,linea);
	   archivo<<"Cliente: "<<linea<<endl;
	   
	   for(;;){
	   	fflush(stdin);
	   cout<<endl<<"Medicamento: "<<endl;
	   getline(cin,linea);
	   archivo<<"Medicamento: "<<linea;
	   cout<<"Dosis: "<<endl;
	   getline(cin,linea);
	   archivo<<setw(20)<<"Dosis: "<<linea<<endl;
	   cout<<"Desea continuar\n1)Si\n2)No"<<endl;
	   cin>>x;
	   if(x==2)
	   {break;}
	   }
	   fflush(stdin);
	   cout<<"Nota: "<<endl;
	   getline(cin,linea);
	   archivo<<"Nota: "<<linea<<endl;
	   }
	   archivo.close();
	   cout<<"Desea imprimir la reseta\n1)Si\n2)No"<<endl;
	   cin>>x;
	   if(x==1){
	   	cout<<"Imprimiendo....";
	   	imprimir();
	   }
	   
		}
		
	void imprimir(){
		ofstream impresora("PRN");
		ifstream archivo("receta.txt");
		if(archivo.is_open()){
		
		impresora<<archivo;}
		archivo.close();
		impresora.close();
		
	}
		
	
	
	
	
	
	
};



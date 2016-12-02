#include<iostream>
#include<string>
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\People.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Employee.hpp"
using namespace std;


class Veterinarian : public Employee {
private:
	int noConsultorio;
	string especialidad;
	
public:
       Veterinarian(string nombre,string direccion,string telefono,int no_Trabajador,string password,string RFC,string cargo,float sueldo, int noConsultorio,string especialidad):Employee( nombre, direccion, telefono, no_Trabajador, password,  RFC, cargo, sueldo)
        {
                  this->noConsultorio=noConsultorio;
                  this->especialidad=especialidad;
                  }


	void revisar_cita(){
	cout<<"No.Member:"<<setw(10)<<"Day"<<setw(10)<<"Day#"<<setw(10)<<"Hour"<<setw(10)<<"Month"<<setw(10)<<"Name"<<endl;
	

	string linea;
	ifstream archivo("Citas.txt");
	if(archivo.is_open()){
		while(archivo.good()){
		
		getline(archivo,linea);
		cout<<linea<<endl;	}
	cout<<endl<<"---------------------------------------------------------------"<<endl;
	cout<<"End of file"<<endl;
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
	   cout<<"Veterinary: "<<endl;
	   getline(cin,linea);
	   archivo<<"Veterinary: "<<linea;
	   
	   cout<<"Doctor Name : "<<endl;
	   getline(cin,linea);
	   archivo<<"Doctor: "<<linea<<endl<<endl;
	   
	   cout<<"Pet Name: "<<endl;
	   getline(cin,linea);
	   archivo<<"Mascota: "<<linea<<endl;
	   
	   cout<<"User Name: "<<endl;
	   getline(cin,linea);
	   archivo<<"Cliente: "<<linea<<endl;
	   
	   for(;;){
	   	fflush(stdin);
	   cout<<endl<<"Medicine: "<<endl;
	   getline(cin,linea);
	   archivo<<"Medicine: "<<linea;
	   cout<<"Dose: "<<endl;
	   getline(cin,linea);
	   archivo<<setw(20)<<"Dose: "<<linea<<endl;
	   cout<<"¿Want to continue?\n1)Yes\n2)No"<<endl;
	   cin>>x;
	   if(x==2)
	   {break;}
	   }
	   fflush(stdin);
	   cout<<"Note: "<<endl;
	   getline(cin,linea);
	   archivo<<"Note: "<<linea<<endl;
	   }
	   archivo.close();
	    cout<<"¿Do you want to print it?\n1)Yes\n2)No"<<endl;
	   cin>>x;
	   if(x==1){
	   	cout<<"Printing......";
	   	imprimir();
	   }
	   
		}
	
	
	void imprimir(){
		ofstream impresora("USB001");
		ifstream archivo("receta.txt");
		if(archivo.is_open()){
		
		impresora<<archivo;}
		archivo.close();
		impresora.close();
		
	}
	
	
};



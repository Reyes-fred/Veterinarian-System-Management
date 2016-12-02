#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <conio.h>
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\People.hpp"
#include <windows.h>
#if !defined(_EMPLOYEE_HPP)
#define _EMPLOYEE_HPP
using namespace std;

class Employee:public People {
private:
	int no_Trabajador;
	string password;
	string RFC;
	string cargo;
	int prioridad;
public:
	float sueldo;
	Employee(string nombre,string direccion,string telefono,int no_trabajador,string password,string RFC,string cargo,float sueldo):People(nombre,direccion,telefono)
	{
		this->no_Trabajador=no_Trabajador;
		this->password=password;
		this->RFC=RFC;
		this->cargo=cargo;
		this->sueldo=sueldo;
		
	ifstream archivo("Nomina.txt"); 
    if (!archivo)
    {
   ofstream archivo ("Nomina.txt");
   if(archivo.is_open()){

   }archivo.close();
   }
   
   
   	ifstream archivo2("RegistroAdministrador.txt"); 
     if (!archivo2)
    {
   ofstream archivo2 ("RegistroAdministrador.txt");
   if(archivo2.is_open()){
   	archivo2<<setw(50)<<"Administrator"<<endl;
   	archivo2<<"No.Worker"<<setw(20)<<"Password"<<endl<<endl;
   	archivo2<<"admin"<<setw(20)<<"pass"<<endl<<endl;
	
   }
   archivo2.close();
   }
   
      	ifstream archivo3("RegistroVeterinario.txt"); 
     if (!archivo3)
    {
   ofstream archivo3("RegistroVeterinario.txt");
   if(archivo3.is_open()){
   	archivo3<<setw(50)<<"Veterinarian"<<endl;
   	archivo3<<"No.Worker"<<setw(20)<<"Password"<<endl<<endl;
	
   }
   archivo3.close();
   }
   
      	ifstream archivo4("RegistroAsistente.txt"); 
     if (!archivo4)
    {
   ofstream archivo4 ("RegistroAsistente.txt");
   if(archivo4.is_open()){
   	archivo4<<setw(50)<<"Assistans"<<endl;
   	archivo4<<"No.Worker"<<setw(20)<<"Password"<<endl<<endl;
   	
	
   }
   archivo4.close();
   }
   
		
		}
	
	
int identificarse(int opc){
	string usuario, pass, aux, aux1;
     int bandera=0;

if(opc==1){ 
   ifstream archivo5("RegistroVeterinario.txt",ios::in);
     fflush( stdin );
     if (archivo5.is_open())
     {
               system ("cls");
               cout<<"\nUser: ";
               getline(cin,aux);   
                    cout<<"\nPassword: ";
                
 
   char ch;

   ch = _getch();
   while(ch != 13){//character 13 is enter
      aux1.push_back(ch);
      cout << '*';
      ch = _getch();
   }   
               archivo5>>usuario;  
      
        while(!archivo5.eof())
         {    fflush( stdin );        
                       
              archivo5>>pass;
              
              if (aux.compare(usuario) == 0)  //comparo usuario ingresado con los existentes
                 {
                  
				  if (aux1.compare(pass) == 0)       // compara la contraseña con la del usuario si el usuario existe
                     {  cout<<endl<<setw(30)<<"\nSuccesful Access"<<endl;
                     Sleep(800);
                        bandera=1; 
                        return 1;
                      }
                  } 
             
                 archivo5>>usuario;  
          }  // end while
              
              if (bandera!=1)
              {		cout<<"\nAccess denied ";
                    Sleep(1000);
					system ("cls");
              		return 0;
                   
                   }            
	      archivo5.close();	
		    }

      else
          cout<<"ERROR AL ABRIR EL ARCHIVO";
          
 
 
}

if(opc==2){ 
   ifstream archivo5("RegistroAdministrador.txt",ios::in);
     fflush( stdin );
     if (archivo5.is_open())
     {
               system ("cls");
               cout<<"\nUser: ";
               getline(cin,aux);   
               cout<<"\nPassword: ";
                
 
   char ch;

   ch = _getch();
   while(ch != 13){//character 13 is enter
      aux1.push_back(ch);
      cout << '*';
      ch = _getch();
   }
               
               archivo5>>usuario;  
      
        while(!archivo5.eof())
         {    fflush( stdin );        
                       
              archivo5>>pass;
              
              if (aux.compare(usuario) == 0)  //comparo usuario ingresado con los existentes
                 {
                  
				  if (aux1.compare(pass) == 0)       // compara la contraseña con la del usuario si el usuario existe
                     {  cout<<endl<<setw(30)<<"\nSuccessful Access"<<endl;
                      Sleep(800);
                        bandera=1;
                        return 1;
                      }
                  } 
             
                 archivo5>>usuario;  
          }  // end while
              
              if (bandera!=1)
              {	
			  		cout<<"\nAccess denied";
                    Sleep(1000);	
					system ("cls");
              return 0;
                   
               }            
	      archivo5.close();	
		    }

      else
          cout<<"ERROR AL ABRIR EL ARCHIVO";
 
 
}

if(opc==3){ 
   ifstream archivo5("RegistroAsistente.txt",ios::in);
     fflush( stdin );
     if (archivo5.is_open())
     {
               system ("cls");
               cout<<"\nUser: ";
               getline(cin,aux);   
                cout<<"\nPassword: ";
                
 
   char ch;

   ch = _getch();
   while(ch != 13){//character 13 is enter
      aux1.push_back(ch);
      cout << '*';
      ch = _getch();
   }  
               archivo5>>usuario;  
      
        while(!archivo5.eof())
         {    fflush( stdin );        
                       
              archivo5>>pass;
              
              if (aux.compare(usuario) == 0)  //comparo usuario ingresado con los existentes
                 {
                  
				  if (aux1.compare(pass) == 0)       // compara la contraseña con la del usuario si el usuario existe
                     {  cout<<endl<<setw(30)<<"\nSuccesful Access"<<endl;
                      Sleep(1000);
                        bandera=1;
						return 1; 
                      }
                  } 
             
                 archivo5>>usuario;  
          }  // end while
              
              if (bandera!=1)
              {		cout<<"\nAccess denied";
                    Sleep(800);
					system ("cls");
              		return 0;
                   
                   }            
	      archivo5.close();	
		    }

      else
          cout<<"ERROR AL ABRIR EL ARCHIVO";
 
 
}
	
	}
	
	
	
	



};
#endif


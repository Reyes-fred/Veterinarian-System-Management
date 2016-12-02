#include<iostream>
#include <fstream>
#include <string>
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\validar.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\Horario.hpp"

#if !defined(_CONSULTORIO_HPP)
#define _CONSULTORIO_HPP
using namespace std;


class Consultorio {
	private:
		
	public:
		validar val;
		Consultorio(){
		
	ifstream archivo("Consultorio.txt"); 
     if (!archivo)
    {
   ofstream archivo ("Consultorio.txt");
   if(archivo.is_open()){
    archivo<<"Nombre:"<<setw(40)<<"Apellido:"<<setw(40)<<"No.Consultorio:"<<endl;    	
   }archivo.close();
   }
   

   	}
	
    						
void setDatos()
{
     string linea;
     ofstream archivo("Consultorio.txt",ios::app);
     fflush( stdin );
     if (archivo.is_open())
     {
               system ("cls");
               			      
			
               cout<<"\n\nNombre Veterinario:\n	Nombre  ";
               for(;;){
								fflush(stdin);
								getline(cin,linea);
								if(val.isVacio(linea)==true){
								if(!val.isString( linea ))
								{
								cout << "Ingresa solo letras...\n";
								Sleep(800);
									}
								else{
								archivo<<linea<<setw(40);	
							break;}
							    }			
							}
							
				cout<<"	Apellido:  ";
               for(;;){
								fflush(stdin);
								getline(cin,linea);
								if(val.isVacio(linea)==true){
								if(!val.isString( linea ))
								{
								cout << "Ingresa solo letras...\n";
								Sleep(800);
									}
								else{
								archivo<<linea<<setw(40);	
							break;}
							    }			
							}
							
				cout<<"\nNo.Consultorio:  ";
				for(;;){
								fflush(stdin);
								getline(cin,linea);
								if(val.isVacio(linea)==true){
								if(!val.isInteger( linea ))
								{
								cout << "Enter Numbers only...\n";
								Sleep(800);
									}
								else{
								archivo<<linea<<endl;		
							break;}
							    }			
							} 
										     
               cout<<setw(40)<<"Creado con Exito"<<endl;          
            
                             } 
	  archivo.close();
					}
			
void mostrarDatos()
 {
     string linea;
     ifstream archivo("Consultorio.txt");
     if (archivo.is_open())
     {
     	while(archivo.good()){
     		getline(archivo,linea);
     		cout<<linea<<endl;
     		
     	}
     	cout<<endl<<"-------------------------------------------------"<<endl;
     	cout<<"Fin archivo"<<endl;
      
        }
      
      else
      {
          cout<<"ERROR AL ABRIR EL ARCHIVO";
            } 
     }  	

};
#endif


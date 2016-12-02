#include<iostream>
#include <fstream>
#include <string>
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Validate.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Schedule.hpp"

#if !defined(_OFFICE_HPP)
#define _OFFICE_HPP
using namespace std;


class Office {
	private:
		
	public:
		Validate val;
	
	Office(){
		
	ifstream archivo("Consultorio.txt"); 
     if (!archivo)
    {
   ofstream archivo ("Consultorio.txt");
   if(archivo.is_open()){
    archivo<<"FirstName:"<<setw(40)<<"Surname:"<<setw(40)<<"No.room:"<<endl;    	
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
               			      
			
               cout<<"\n\nVeterinarian name:\n	First name:  ";
               for(;;){
								fflush(stdin);
								getline(cin,linea);
								if(val.isVacio(linea)==true){
								if(!val.isString( linea ))
								{
								cout << "Enter letters only...\n";
								Sleep(800);
									}
								else{
								archivo<<linea<<setw(40);	
							break;}
							    }			
							}
							
				cout<<"	Surname:  ";
               for(;;){
								fflush(stdin);
								getline(cin,linea);
								if(val.isVacio(linea)==true){
								if(!val.isString( linea ))
								{
								cout << "Enter letters only...\n";
								Sleep(800);
									}
								else{
								archivo<<linea<<setw(40);	
							break;}
							    }			
							}
							
				cout<<"\nNo.room:  ";
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
										     
               cout<<setw(40)<<"Successful"<<endl;          
            
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
     	cout<<"End of file"<<endl;
      
        }
      
      else
      {
          cout<<"ERROR AL ABRIR EL ARCHIVO";
            } 
     }  	

};
#endif


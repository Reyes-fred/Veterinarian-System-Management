#include <iostream>
#include <iomanip>
#include <fstream>
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\Persona.hpp"
#include <string>
#include <windows.h>
#include <sstream>
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\validar.hpp"
#if !defined(_CLIENTE_HPP)
#define _CLIENTE_HPP
using namespace std;

class Cliente : public Persona {
	
private:
	string no_Cliente;
	string mascota;
	validar val;
	
public:
	
	Cliente(string nombre,string direccion,string telefono,string no_Cliente,string mascota):Persona(nombre,direccion,telefono){
		this->no_Cliente=no_Cliente;
		this->mascota=mascota;
	
	ifstream archivo("Clientes.txt"); 
     if (!archivo)
    {
   ofstream archivo ("Clientes.txt");
   }
   
   
   ifstream archivo2("Socios.txt"); 
     if (!archivo2)
    {
   ofstream archivo2 ("Socios.txt");
   
   }
	
	}
	
	
	void nuevocliente(){
		string leer;
	ofstream archivo("Clientes.txt",ios::app);
	if(archivo.is_open()){
	fflush( stdin );
	
	for(;;){
	fflush(stdin);
	system("cls");
	cout<<"Nombre:   ";
	getline(cin, leer);
	if(val.isVacio(leer)==true){
	if(val.isString( leer )==false)
	{
	cout << "Ingresa un nombre valido...\n";
	Sleep(800);
		}
	else{
	archivo<<leer<<setw(10);
	break;
    }}
    }
    	for(;;){
	fflush(stdin);
	cout<<"Apellido Paterno:   ";
	getline(cin, leer);
	if(val.isVacio(leer)==true){
	if(val.isString( leer )==false)
	{
	cout << "Ingresa un apellido valido...\n";
	Sleep(800);
		}
	else{
	archivo<<leer<<setw(15);
	break;
    }}
    }
    
    for(;;){
	fflush(stdin);
	cout<<"Apellido Materno:   ";
	getline(cin, leer);
	if(val.isVacio(leer)==true){
	if(val.isString( leer )==false)
	{
	cout << "Ingresa un apellido valido...\n";
	Sleep(800);
		}
	else{
	archivo<<leer<<setw(15);
	break;
    }}
    }
    
    
	cout<<"Direccion    \nCalle:  ";
    for(;;){
	getline(cin, leer);
	if(val.isVacio(leer)==true){
	archivo<<leer<<setw(10);
	break;}}
	int num;
	 cout<<"No. Casa:  ";
     for(;;){
	fflush(stdin);
	getline(cin, leer);
	num=atoi(leer.c_str());
	if(num>0&&num<2000){
	if(val.isVacio(leer)==true){
	if(val.isInteger( leer )==false)
	{
	cout << "Ingresa un numero valido..\n";
	Sleep(800);
		}
	else{
	archivo<<leer<<setw(15);
	break;
    }	}}
	else{cout << "Ingresa un numero valido...\n";}}
    
    
    cout<<"Ciudad:  ";
     for(;;){
	fflush(stdin);
	getline(cin, leer);
	if(val.isVacio(leer)==true){
	if(val.isCiudad(leer )==false)
	{
	cout << "Ingresa una ciudad valida...\n";
	Sleep(800);
		}
	else{
	archivo<<leer<<setw(10);
	break;
    }	}}


	cout<<"Numero Telefono:   ";
	for(;;){
	getline(cin, leer);
	if(val.isVacio(leer)==true){
        if( !val.isTelef( leer ))
        {
            cout << "Ingresa un numero valido...\n";
			Sleep(800);
        }
        else{
        archivo<<leer<<endl;
		break;	
        }	}
		}
		
		}	archivo.close();
	
	
	
	int x=0;
	string linea;
	ifstream archivo2("Socios.txt");
	if(archivo2.is_open()){
		while(archivo2.good()){
			getline(archivo2,linea);
			x++;
			}
	}
	archivo2.close();
	
	
	ofstream archivo3("Socios.txt",ios::app);
	cout<<endl<<endl<<"Usuario:   "<<(x)<<"    Contrasena:   123"<<endl<<endl;
	Sleep(1000);
	if(archivo3.is_open()){
		archivo3<<(x)<<setw(20)<<"123"<<endl;
	}
	archivo3.close();
	cout<<endl;
	cout<<setw(50)<<"GUARDADO CON EXITO"<<endl;
	
	}
	
int cambiar_contra(int num){
			
     string nombre, cont, aux;
  
    
     ofstream temp("temporal.txt", ios::out);
     ifstream archivo("Socios.txt", ios::in);
     
     fflush( stdin );
     if (archivo.is_open()&&temp.is_open())
     {
        		stringstream stream;
				stream << num;
				aux = stream.str();
                 
               archivo>>nombre;  
      
        while(!archivo.eof())
         {    
              fflush( stdin );                 
              archivo>>cont;
              
              if (nombre.compare(aux) == 0)  //comparo la cedula ingresa con las existentes
              {
              cout<<"\nNueva contrasena: ";
              cin>>cont;    
              cout<<"Successful";
              } 
              temp<<nombre<<setw(20)<<cont<<endl;   
              archivo>>nombre;  
                     
              }  
       
                     
              temp.close();   //datos nuevos
              archivo.close();        //datos viejos
              
              remove("Socios.txt");   // borramos el archivo anterior y renombramos el temp como empleados
              rename("temporal.txt", "Socios.txt");
                 }
      
      else
      {
          cout<<"ERROR AL ABRIR EL ARCHIVO"; 
     }
}
	
	
	
int identificarse(int no_cliente)
	{	string usuario, pass, aux, aux1;
		stringstream stream;
		stream<<no_cliente;
		aux=stream.str();
		
     int bandera=0;
   ifstream archivo5("Socios.txt",ios::in);
     fflush( stdin );
     if (archivo5.is_open())
     {
               system ("cls");
                 
               cout<<"\nConstrasena: ";
                
 
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
                     {  cout<<endl<<setw(30)<<"\nIdentificado"<<endl;
                      Sleep(800);
                        bandera=1;
                        return 1;
                      }
                  } 
             
                 archivo5>>usuario;  
          }  // end while
              
              if (bandera!=1)
              {		cout<<"\nAcceso Denegado";
			  Sleep(1000);
			  system ("cls");
              return 0;
                   
                    
               }            
	      archivo5.close();	
		    }

      else
          cout<<"ERROR AL ABRIR EL ARCHIVO";

	}
	

	

	


};
#endif


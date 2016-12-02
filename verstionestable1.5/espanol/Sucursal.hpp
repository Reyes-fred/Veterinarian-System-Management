#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\validar.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\Horario.hpp"


#if !defined(_SUCURSAL_HPP)
#define _SUCURSAL_HPP
class Sucursal {
private:
	Horario horario(string,string);
	string gerente;
	string direccion;
	string localidad;
	string RFC;
	string lista_precio_servicios;
	string lista_precio_productos;
	string telefono;

public:
	validar val;
    Sucursal(string direccion, string gerente, string localidad, string telefono, string RFC, string lista_precio_servicios,string lista_precio_productos)
    {				Horario horario("xxx","xxx");
					this->direccion=direccion;
                    this->gerente=gerente;
                    this->localidad=localidad;
                    this->telefono=telefono;
                    this->RFC=RFC;
                    this->lista_precio_servicios=lista_precio_servicios;
                    this->lista_precio_productos=lista_precio_productos;
                    
   
    ifstream archivo("Sucursal.txt"); 
     if (!archivo)
    {
   ofstream archivo ("Sucursal.txt");
   if(archivo.is_open()){
   	archivo<<setw(50)<<"Veterinary Medicine El Perrito Cojo"<<endl<<endl;
	archivo<<"Gerente:   "<<gerente<<endl;
	archivo<<"Direccion: "<<direccion<<endl;
	archivo<<"Ciudad: "<<localidad<<endl;
	archivo<<"Telefono:  "<<telefono<<endl;
	archivo<<"Horario:   "<<endl<<setw(15)<<horario.gethoras()<<endl<<setw(15)<<horario.getdias();
	archivo<<endl<<"RFC:       "<<RFC<<endl;
   }archivo.close();
   }
   
   
    ifstream archivo2("ListaServicios.txt"); 
     if (!archivo2)
    {
   ofstream archivo2 ("ListaServicios.txt");
   if(archivo2.is_open()){
   
	
   }archivo2.close();
   }
	
	  } 
				    
		
 
	
	
	void mostrardatos(){
	string linea;
	ifstream archivo("Sucursal.txt");
	if(archivo.is_open()){
		while(archivo.good()){
			getline(archivo,linea);
			cout<<linea<<endl;
			}
	
	}
	archivo.close();
	
	}
	
	
	void editardatos(){
	string temp;
	string linea;
	ofstream archivo ("Sucursal.txt");
   if(archivo.is_open()){
   	archivo<<setw(50)<<"Veterinary Medicine: El Perrito Cojo"<<endl<<endl;
	cout<<"Gerente:  \n   Nombre: ";
   				for(;;){
				fflush(stdin);
				getline(cin, linea);
				if(val.isVacio(linea)==true){
				if(!val.isString( linea ))
				{
				cout << "Ingresa solo letras...\n";
				Sleep(800);
					}
				else{
				temp=linea;
				break;}
			    }}
	cout<<"\n	Apellido: ";
   				for(;;){
				fflush(stdin);
				getline(cin, linea);
				if(val.isVacio(linea)==true){
				if(!val.isString( linea ))
				{
				cout << "Ingresa solo letras...\n";
				Sleep(800);
					}
				else{
				archivo<<"Gerente:   "<<temp<<" "<<linea<<endl;
				break;}
			    }}
	
	cout<<"Direccion:  ";
			   for(;;){
				getline(cin, linea);
				if(val.isVacio(linea)==true){
				archivo<<"Direccion: "<<linea<<endl;
				break;}}
	
	cout<<"Ciudad:  ";
			   	for(;;){
				fflush(stdin);
				getline(cin, linea);
				if(val.isVacio(linea)==true){
				if(val.isCiudad(linea )==false)
				{
				cout << "Ingresa una ciudad valida...\n";
				Sleep(800);
					}
				else{
				archivo<<"City: "<<linea<<endl;
				break;
			    }	}}
	
	cout<<"Telefono:  ";
			   for(;;){
				getline(cin, linea);
				if(val.isVacio(linea)==true){
			        if( !val.isTelef( linea ))
			        {
			            cout << "Ingresa un telefono valido...\n";
						Sleep(800);
			        }
			        else{
			        archivo<<"Telefono:  "<<linea<<endl;
					break;	
			        }	}
					}
   	
	cout<<"Horario";
	cout<<"\nDia: \nDesde:";
			for(;;){
						fflush(stdin);
						getline(cin, linea);
						if(val.isVacio(linea)==true){
						if(val.isDia( linea )==false)
						{
						cout << "Ingresa un dia valido...\n";
						Sleep(800);
							}
						else{
						archivo<<"Horario:"<<endl<<setw(15)<<linea;
						break;
					    }		
						}}
	cout<<"Hasta:";
				for(;;){
				fflush(stdin);
				getline(cin, linea);
				if(val.isVacio(linea)==true){
				if(val.isDia( linea )==false)
				{
				cout << "Ingresa un dia valido...\n";
				Sleep(800);
					}
				else{
				archivo<<"--"<<linea<<endl;
				break;
			    }		
				}}						
	
	cout<<"Hora: \nDesde:";
	
				int hor;
				string tem;
				for(;;){
				fflush(stdin);
				cout<<"\nHr (_ _):   ";
				for(;;){
				getline(cin, linea);
				hor=atoi(linea.c_str());
				if(hor>=0&&hor<=24)break;else cout<<"Ingresa hora valida";}
				tem=linea+":";
				cout<<"Min (_ _):   ";
				for(;;){
				getline(cin, linea);
				hor=atoi(linea.c_str());
				if(hor>=0&&hor<60)break;else cout<<"Ingresa minuto valido";}
				tem=tem+linea;
				if(val.isVacio(tem)==true){
				if(!val.isHora( tem ))
				{
				cout << "Ingresa hora valida...\n";
				Sleep(800);
					}
				else{
				archivo<<setw(15)<<tem;
				break;
			    }	
					}}
	cout<<"To: ";
	for(;;){
				fflush(stdin);
				cout<<"\nHr (_ _):   ";
				for(;;){
				getline(cin, linea);
				hor=atoi(linea.c_str());
				if(hor>=0&&hor<=24)break;else cout<<"Ingresa hora valida";}
				tem=linea+":";
				cout<<"Min (_ _):   ";
				for(;;){
				getline(cin, linea);
				hor=atoi(linea.c_str());
				if(hor>=0&&hor<60)break;else cout<<"Ingresa minuto valido";}
				tem=tem+linea;
				if(val.isVacio(tem)==true){
				if(!val.isHora( tem ))
				{
				cout << "Ingresa hora valida...\n";
				Sleep(800);
					}
				else{
				archivo<<"--"<<tem<<endl;
				break;
			    }	
					}}
	
	cout<<"Ingresa el RFC:  ";
   	getline(cin,linea);
	archivo<<"RFC:       "<<linea<<endl;
	
	
   }
   archivo.close();
		
	}
	
	
	
	
	void agregarservicios(){
		string linea;
		char cadena[40];
		ofstream archivo("ListaServicios.txt",ios::app);
		if(archivo.is_open()){
			fflush(stdin);
			cout<<"No. Servicio:  ";
			for(;;){
				fflush(stdin);
				gets(cadena);
				if(val.isCharVacio(cadena)==true){
				if(val.isCharStr( cadena)==false)
				{
				cout << "Letters only...\n";
				Sleep(800);
					}
				else{
				break;
			    }		
				}}
			
			char*tmp;
			while((tmp=strchr(cadena,32))!=NULL)
			  sprintf(tmp,"%s",tmp+1);		
		  	archivo<<cadena<<setw(20);
		  	
			fflush(stdin);
			cout<<"No.Servicio:  ";
						for(;;){
						fflush(stdin);
						getline(cin, linea);
						if(val.isVacio(linea)==true){
						if(!val.isInteger( linea ))
						{
						cout << "Ingresa solo numeros...\n";
						Sleep(800);
							}
						else{
							
							archivo<<linea<<setw(20);
							break;}
					    }			
					}
			
			cout<<"Precio:  ";
					for(;;){
								fflush(stdin);
								getline(cin, linea);
								if(val.isVacio(linea)==true){
								if(!val.isPrecio( linea ))
								{
								cout << "Ingresa un precio valido...\n";
								Sleep(800);
									}
								else{
									archivo<<linea<<setw(20)<<endl;
									break;}
							    }			
							}
		
		}
		archivo.close();
		
	}
	
	void modificarservicio(){
		
		
     string nombre, num, aux, sueldo;
    
     ofstream temp("temporal.txt", ios::out);
     ifstream archivo("ListaServicios.txt", ios::in);
     
     fflush( stdin );
     if (archivo.is_open()&&temp.is_open())
     {
        
               cout<<"\nNo.Servicio: ";
		              for(;;){
								fflush(stdin);
								getline(cin, aux);
								if(val.isVacio(aux)==true){
								if(!val.isInteger( aux ))
								{
								cout << "Ingresa solo numeros...\n";
								Sleep(800);
									}
								else{
							break;}
							    }			
							}  
               archivo>>nombre;  
      
        while(!archivo.eof())
         {    
              fflush( stdin );                 
              archivo>>num;
              archivo>>sueldo;  
              if (aux.compare(num) == 0)  //comparo la cedula ingresa con las existentes
              {
              cout<<"\nNuevo Precio: ";
		              for(;;){
								fflush(stdin);
								getline(cin, sueldo);
								if(val.isVacio(sueldo)==true){
								if(!val.isPrecio( sueldo ))
								{
								cout << "Ingresa solo numeros...\n";
								Sleep(800);
									}
								else{
									
								
									break;}
							    }			
							}   
              } 
              temp<<nombre<<setw(20)<<num<<setw(20);   
              temp<<sueldo<<endl;                             
              archivo>>nombre;  
                     
              }  
           
                     
              temp.close();   //datos nuevos
              archivo.close();        //datos viejos
              
              remove("ListaServicios.txt");   // borramos el archivo anterior y renombramos el temp como empleados
              rename("temporal.txt", "ListaServicios.txt");
                 }
      
      else
      {
          cout<<"ERROR AL ABRIR EL ARCHIVO"; 
     } 
		
		
	}
	
	
	
	
	void eliminarservicio(){
	string OP;
	int op;
	cout<<"Elimar por \n1)No.Producto 2)Nombre producto";
	cout<<"\nChoose an option:  ";
	for(;;){
	getline(cin,OP);
	if( !val.isInteger( OP ) )
	        {
	            cout << "Ingresa solo numeros...\n";
				Sleep(800);
	        }
	        else{
	        	op=atoi(OP.c_str());
	        	break;
        	}}
	
		string nombre, ced, aux, sueldo;
		int bandera=0;
    
     ofstream temp("temporal.txt", ios::out);
     ifstream archivo("ListaServicios.txt", ios::in);
     
    switch(op) 
		{
			case(1):
				
				fflush( stdin );
     if (archivo.is_open()&&temp.is_open())
     {
                cout<<"\nNo. Producto: ";
               for(;;){
				fflush(stdin);
				getline(cin, aux);
				if(val.isVacio(aux)==true){
				if(!val.isInteger( aux ))
				{
				cout << "Ingresa solo numeros...\n";
				Sleep(800);
					}
				else{
				break;}
			    }}  
               archivo>>nombre;  
      
        while(!archivo.eof())
         {    
              fflush( stdin );        
                       
              archivo>>ced;
              archivo>>sueldo;  
              if (aux.compare(ced) == 0)  //comparo la cedula ingresa con las existentes
                 {
                 cout<<"\nServicio e informacion eliminada ";
                 bandera=1;
                  } 
              else
              {
      
                 temp<<nombre<<setw(20)<<ced<<setw(20);   
                 temp<<sueldo<<endl;                             
                 
                 }
                 archivo>>nombre;  
              }  // end while
              
              if (bandera!=1)
              {
                 
                   cout<<"\nServicio no encontrado ";
                   }            
                             
              temp.close();   //datos nuevos
              archivo.close();        //datos viejos
              
              remove("ListaServicios.txt");   // borramos el archivo anterior y renombramos el temp como empleados
              rename("temporal.txt", "ListaServicios.txt");
                 }
      
      else
      {
          cout<<"ERROR AL ABRIR EL ARCHIVO"; 
     } 
				
				
				
				break;
			case(2):
				
     if (archivo.is_open()&&temp.is_open())
     {
                cout<<"\nNombre servicio: ";
               for(;;){
				fflush(stdin);
				getline(cin, aux);
				if(val.isVacio(aux)==true){
				if(!val.isString( aux ))
				{
				cout << "Ingresa solo letras...\n";
				Sleep(800);
					}
				else{
				break;}
			    }}  
               archivo>>nombre;  
      
        while(!archivo.eof())
         {    
              fflush( stdin );        
                       
              archivo>>ced;
              archivo>>sueldo;  
              if (aux.compare(nombre) == 0)  //comparo la cedula ingresa con las existentes
                 {
                 cout<<"\nServicio e informacion elinada ";
                 bandera=1;
                  } 
              else
              {
      
                 temp<<nombre<<setw(20)<<ced<<setw(20);   
                 temp<<sueldo<<endl;                             
                 
                 }
                 archivo>>nombre;  
              }  // end while
              
              if (bandera!=1)
              {
                 
                   cout<<"\nServicio no encontrado ";
                   }            
                             
              temp.close();   //datos nuevos
              archivo.close();        //datos viejos
              
              remove("ListaServicios.txt");   // borramos el archivo anterior y renombramos el temp como empleados
              rename("temporal.txt", "ListaServicios.txt");
                 }
      
      else
      {
          cout<<"ERROR AL ABRIR EL ARCHIVO"; 
     } 
				
				break;
			default:cout<<"Opcion Incorrecta";
			Sleep(1000);
			system("cls");
				break;
		}
		
		
	}

	
    
	
	void getLista_Servicios(){
		cout<<"Nombre Servicio:"<<setw(20)<<"No.Servicio:"<<setw(20)<<"Precio:"<<endl;
		ifstream archivo("ListaServicios.txt");
		string linea;
		if(archivo.is_open()){
			while(archivo.good()){
				getline(archivo,linea);
				cout<<linea<<endl;
			}
	cout<<endl<<"---------------------------------------------------------------"<<endl;
	cout<<"Fin Archivo"<<endl;
		}
		archivo.close();
	
	}

	
};
#endif


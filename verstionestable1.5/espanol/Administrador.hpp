#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\Empleado.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\Persona.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\validar.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#if !defined(_ADMINISTRADOR_HPP)
#define _ADMINISTRADOR_HPP
using namespace std;

class Administrador : public Empleado{
public:
	Administrador(string nombre,string direccion,string telefono,int no_trabajador,string password,string RFC,string cargo,float sueldo):Empleado(nombre,direccion,telefono,no_trabajador,password,RFC,cargo,sueldo)
	{	}
	validar val;
	
	void mostrardatos(){
	cout<<"Nombre:"<<setw(31)<<"Direccion:"<<setw(20)<<"Telefono"<<setw(25)<<"No. Trabajador"<<setw(20)<<"RFC"<<setw(20)<<"Actividad"<<setw(20)<<"Salario";
		string linea;
		ifstream archivo ("Nomina.txt");
		if(archivo.is_open()){
			while(archivo.good()){
				getline(archivo,linea);
				cout<<linea<<endl;
			
			}
	cout<<endl<<"---------------------------------------------------------------"<<endl;
	cout<<"Fin archivo"<<endl;
		}
		archivo.close();
	}
	
	
	
	void agregar_producto(){
			char cadena[40];
		fflush(stdin);
		string linea;
		ofstream archivo("Almacen.txt",ios::app);
		if(archivo.is_open()){
			fflush(stdin);
		cout<<"Nombre: "<<endl;
		gets(cadena);
			char*tmp;
			while((tmp=strchr(cadena,32))!=NULL)
			  sprintf(tmp,"%s",tmp+1);		
		  	archivo<<cadena<<setw(13);
		
		
		cout<<"Numero producto: "<<endl;
						for(;;){
								fflush(stdin);
								getline(cin,linea);
								if(val.isVacio(linea)==true){
								if(!val.isInteger( linea )) //checar
								{
								cout << "Ingresa solo numeros...\n";
								Sleep(800);
									}
								else{
							archivo<<linea<<setw(15);		
							break;}
							    }			
							} 
	
		cout<<"Precio: "<<endl;
							for(;;){
								fflush(stdin);
								getline(cin,linea);
								if(val.isVacio(linea)==true){
								if(!val.isPrecio( linea ))
								{
								cout << "Ingresa solo numeros...\n";
								Sleep(800);
									}
								else{
							archivo<<"$"<<linea<<setw(20);		
							break;}
							    }			
							}
		
		cout<<"Existencia: "<<endl;
					for(;;){
								fflush(stdin);
								getline(cin,linea);
								if(val.isVacio(linea)==true){
								if(!val.isInteger( linea ))
								{
								cout << "Ingresa solo numeros...\n";
								Sleep(800);
									}
								else{
							archivo<<linea<<endl;		
							break;}
							    }			
							}
		}
		archivo.close();
			
	}
	
	
	void eliminar_producto(){
	string OP;
	int op;
	cout<<"Eliminar por\n 1)No.Producto \n2)Nombre Producto\n";	
	cout<<"Opcion Deseada:  ";
	for(;;){
			fflush(stdin);
			getline(cin,OP);
			if(val.isVacio(OP)==true){
			if(!val.isInteger( OP ))
			{
			cout << "Ingresa solo numeros...\n";
			Sleep(800);
			}
			else{
			op=atoi(OP.c_str());		
			break;}
			   }			
			}
		string nombre,num,aux;
     int exis,bandera=0;
   	string costo;
    
     ofstream temp("temporal.txt", ios::out);
     ifstream archivo("Almacen.txt", ios::in);
	
	switch(op){
		case(1):     
     fflush( stdin );
     if (archivo.is_open()&&temp.is_open())
     {
                cout<<"\nNo.Producto: "; 
               for(;;){
								fflush(stdin);
								getline(cin,aux);
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
              archivo>>costo;
			  archivo>>exis;  
              if (aux.compare(num) == 0)  //comparo la cedula ingresa con las existentes
                 {
                 cout<<"\nServicio e informacion eliminada..\n  ";
                 bandera=1;
                  } 
              else
              {
    
                 temp<<nombre<<setw(13)<<num<<setw(15);   
                 temp<<costo<<setw(20)<<exis<<endl;                             
                 
                 }
                 archivo>>nombre;  
        }  // end while
              
              if (bandera!=1)
              {
                 
                   cout<<"\nServicio no encontrado ";
                   Sleep(800);
                   }            
           
                    
              temp.close();   //datos nuevos
              archivo.close();        //datos viejos
              
              remove("Almacen.txt");   // borramos el archivo anterior y renombramos el temp como empleados
              rename("temporal.txt", "Almacen.txt");
                 }
      
      else
      {
          cout<<"ERROR AL ABRIR EL ARCHIVO";
              } 
				break;


case(2):     
     fflush( stdin );
     if (archivo.is_open()&&temp.is_open())
     {
                cout<<"\nNombre producto: "; 
               for(;;){
								fflush(stdin);
								getline(cin,aux);
								if(val.isVacio(aux)==true){
								if(!val.isString( aux ))
								{
								cout << "Ingresa solo letras...\n";
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
              archivo>>costo;
			  archivo>>exis;  
              if (aux.compare(nombre) == 0)  //comparo la cedula ingresa con las existentes
                 {
                 cout<<"\nServvicio e informacion eliminado..\n  ";
                 bandera=1;
                  } 
              else
              {
    
                 temp<<nombre<<setw(13)<<num<<setw(15);   
                 temp<<costo<<setw(20)<<exis<<endl;                             
                 
                 }
                 archivo>>nombre;  
        }  // end while
              
              if (bandera!=1)
              {
                 
                   cout<<"\nServicio no encontrado ";
                   Sleep(800);
                   }            
           
                    
              temp.close();   //datos nuevos
              archivo.close();        //datos viejos
              
              remove("Almacen.txt");   // borramos el archivo anterior y renombramos el temp como empleados
              rename("temporal.txt", "Almacen.txt");
                 }
      
      else
      {
          cout<<"ERROR AL ABRIR EL ARCHIVO";
              } 
	break;
		
		default: cout<<"Opcion Incorrecta\n";
		Sleep(1000);
		system("cls");
		}
		
	 
		
		
	}
	
	
	void cambiar_precio(){
		
     string nombre, num, aux;
     string  existe;
 string preci;
    
     ofstream temp("temporal.txt", ios::out);
     ifstream archivo("Almacen.txt", ios::in);
     
     fflush( stdin );
     if (archivo.is_open()&&temp.is_open())
     {
        
               cout<<"\nNombre Producto: ";
			   for(;;){
								fflush(stdin);
								getline(cin,aux);
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
              archivo>>preci;
			  archivo>>existe;
              if (aux.compare(num) == 0) 
              {
              cout<<"\nNuevo precio: ";
              for(;;){
								fflush(stdin);
								getline(cin,preci);
								if(val.isVacio(preci)==true){
								if(!val.isPrecio( preci ))
								{
								cout << "Ingresa solo numeros...\n";
								Sleep(800);
									}
								else{
									
							break;}
							    }			
							}   
              } 
              temp<<nombre<<setw(13)<<num<<setw(15);   
              temp<<preci<<setw(20)<<existe<<endl;                             
              archivo>>nombre;  
                     
              }  
       
                     
              temp.close();   //datos nuevos
              archivo.close();        //datos viejos
              
              remove("Almacen.txt");   // borramos el archivo anterior y renombramos el temp como empleados
              rename("temporal.txt", "Almacen.txt");
                 }
      
      else
      {
          cout<<"ERROR AL ABRIR EL ARCHIVO"; 
     } 
		
			
	}
	
	
	
	void cambiar_existencia(){
			
     string nombre, num, aux, existe;
     string preci;
    
     ofstream temp("temporal.txt", ios::out);
     ifstream archivo("Almacen.txt", ios::in);
     
     fflush( stdin );
     if (archivo.is_open()&&temp.is_open())
     {
        
               cout<<"\nNo. Producto: ";
			   for(;;){
								fflush(stdin);
								getline(cin,aux);
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
              archivo>>preci;
			  archivo>>existe;
              if (aux.compare(num) == 0)  //comparo la cedula ingresa con las existentes
              {
              cout<<"\nNueva Existencia: ";
              
			  for(;;){
								fflush(stdin);
								getline(cin,existe);
								if(val.isVacio(existe)==true){
								if(!val.isInteger( existe ))
								{
								cout << "Ingresa solo numeros...\n";
								Sleep(800);
									}
								else{		
							break;}
							    }			
							}
			      
              } 
              temp<<nombre<<setw(13)<<num<<setw(15);   
              temp<<preci<<setw(20)<<existe<<endl;                             
              archivo>>nombre;  
                     
              }  
       
                     
              temp.close();   //datos nuevos
              archivo.close();        //datos viejos
              
              remove("Almacen.txt");   // borramos el archivo anterior y renombramos el temp como empleados
              rename("temporal.txt", "Almacen.txt");
                 }
      
      else
      {
          cout<<"ERROR AL ABRIR EL ARCHIVO"; 
     } 
	
		
	}
	
	
	
	void alta_empleadonomina(){
		string linea;
		char cadena[40];
	ofstream archivo ("Nomina.txt",ios::app);
   if(archivo.is_open()){
   	
		fflush(stdin);
		
		cout<<"Nombre:  ";
			gets(cadena);
			char*tmp;
			while((tmp=strchr(cadena,32))!=NULL)
			sprintf(tmp,"%s",tmp+1);		
		  	archivo<<endl<<cadena<<setw(10);
		
		cout<<"Apellido: ";
		for(;;){getline(cin, linea);
					        if( !val.isString( linea ) )
					        {
					            cout << "Ingresa un apellido valido...\n";
								Sleep(800);
					        }
					        else{
					        	archivo<<linea<<setw(20);
					        	break;
					        }}
	
		
		fflush(stdin);
			
			cout<<"Direccion:  ";
			gets(cadena);
			char*tmp1;
			while((tmp=strchr(cadena,32))!=NULL)
			sprintf(tmp,"%s",tmp+1);		
		  	archivo<<cadena<<setw(20);
		  	
		fflush(stdin);
			
			cout<<"Telefono:  ";
			for(;;){
			getline(cin,linea);
			if(!val.isTelef(linea)){		
		  			cout<<"Ingresa un telefono valido\n";
		  			Sleep(800);
			  }
		  	else{archivo<<linea<<setw(20);
		  	break;
		  	}}
			
		 
		cout<<"No. Trabajador:  ";
		for(;;){getline(cin, linea);
					        if( !val.isInteger( linea ) )
					        {
					            cout << "Ingresa solo numeros...\n";
								Sleep(800);
					        }
					        else{
					        	archivo<<linea<<setw(20);
					        	break;
					        }}
		
		cout<<"RFC:  ";
		getline(cin,linea);
		archivo<<linea<<setw(20);
		
		cout<<"Actividad:  ";
		for(;;){
							getline(cin, linea);
					        if( !val.isString( linea ) )
					        {
					            cout << "Ingresa solo letras...\n";
								Sleep(800);
					        }
					        else{
					        	if(linea.compare("veterinario")==0||linea.compare("Veterinario")==0||linea.compare("Administrador")==0||linea.compare("administrador")==0||
								linea.compare("Asistente")==0||linea.compare("asistente")==0){			        	
					        	archivo<<linea<<setw(20);
					        	break;}
					        else{
					        	cout<<"Ingresa una actividad valida"<<endl;
					        }
					        }}
		
		cout<<"Salario:  ";
		for(;;){getline(cin, linea);
					        if( !val.isPrecio( linea ))
					        {
					            cout << "Ingresa un salario valido...\n";
								Sleep(800);
					        }
					        else{
					        	archivo<<linea<<endl;
					        	break;
					        }}
	
		cout<<setw(30)<<"Creado con Exito"<<endl;
	}
	archivo.close();
					}
	
	
	
	void baja_empleadonomina(){
	
     string nombre, apell,dir,telf, num, rfc, cargo, aux;
     string sueldo;
	 int bandera=0;
    
     ofstream temp("temporal.txt", ios::out);
     ifstream archivo("Nomina.txt", ios::in);
     
     fflush( stdin );
     if (archivo.is_open()&&temp.is_open())
     {
            
               cout<<"\nNombre Trabajador: ";
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
              archivo>>apell;
              archivo>>dir;
              archivo>>telf; 
              archivo>>num;
			  archivo>>rfc;
			  archivo>>cargo;
			  archivo>>sueldo;  
              if (aux.compare(nombre) == 0)  //comparo la cedula ingresa con las existentes
                 {
                 cout<<"\nTrabajador e informacion eliminado ";
                 bandera=1;
				 Sleep(800);
                  } 
              else
              {
      
                 temp<<nombre<<setw(10)<<apell<<setw(10)<<dir<<setw(10)<<telf<<setw(10)<<num<<setw(10); 
                 temp<<rfc<<setw(10)<<cargo<<setw(10)<<sueldo<<endl;                           
                 
                 }
                 archivo>>nombre;  
              }  // end while
              
              if (bandera!=1)
              {
                 
                   cout<<"\nNombre no encontrado ";
                   Sleep(800);
                   }            
                     
              temp.close();   //datos nuevos
              archivo.close();        //datos viejos
              
              remove("Nomina.txt");   // borramos el archivo anterior y renombramos el temp como empleados
              rename("temporal.txt", "Nomina.txt");
                 }
      
      else
      {
          cout<<"ERROR AL ABRIR EL ARCHIVO";
       Sleep(800);
     } 

	}
	
	
	
	
	int validaruser(int id,string user){
		int bandera;
	string  usuario,pass;
	if(id==3){	
   ifstream archivo5("RegistroAdministrador.txt",ios::in);
     fflush( stdin );
     if (archivo5.is_open())
     {
                  
               archivo5>>usuario;  
      
        while(!archivo5.eof())
         {    fflush( stdin );        
                       
              archivo5>>pass;  
                
              
              if (user.compare(usuario) == 0)  //comparo usuario ingresado con los existentes
                 {
                   		bandera=1; 
                        return 1;
                  } 
             
                 archivo5>>usuario;  
          }  // end while
              
              if (bandera!=1)
              {		return 0;
                   }            
	      archivo5.close();	
		    }

      else
          cout<<"ERROR AL ABRIR EL ARCHIVO";
	}
	
	
		if(id==2){	
   ifstream archivo5("RegistroAdministrador.txt",ios::in);
     fflush( stdin );
     if (archivo5.is_open())
     {
                  
               archivo5>>usuario;  
      
        while(!archivo5.eof())
         {    fflush( stdin );        
                       
              archivo5>>pass;  
                
              
              if (user.compare(usuario) == 0)  //comparo usuario ingresado con los existentes
                 {
                   		bandera=1; 
                        return 1;
                  } 
             
                 archivo5>>usuario;  
          }  // end while
              
              if (bandera!=1)
              {		return 0;
                   }            
	      archivo5.close();	
		    }

      else
          cout<<"ERROR AL ABRIR EL ARCHIVO";
	}
	
	
		if(id==1){	
   ifstream archivo5("RegistroVeterinario.txt",ios::in);
     fflush( stdin );
     if (archivo5.is_open())
     {
                  
               archivo5>>usuario;  
      
        while(!archivo5.eof())
         {    fflush( stdin );        
                       
              archivo5>>pass;  
                
              
              if (user.compare(usuario) == 0)  //comparo usuario ingresado con los existentes
                 {
                   		bandera=1; 
                        return 1;
                  } 
             
                 archivo5>>usuario;  
          }  // end while
              
              if (bandera!=1)
              {		return 0;
                   }            
	      archivo5.close();	
		    }

      else
          cout<<"ERROR AL ABRIR EL ARCHIVO";
	}
	
	
	}
	
	
	
	
	
	
	
	
	
	void altaUsuario(){
		int op; string OP;
		cout<<"¿Typo de Trabajor?\n1)Veterinario\n2)Administrador\n3)Asistente\n";
		cout<<"Choose an option:  ";
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
	for(;;){
	if(op==1){//veterinario
	system("cls");
	string linea,us;
	ofstream archivo ("RegistroVeterinario.txt",ios::app);
	if(archivo.is_open()){
		fflush(stdin);
		for(;;){
			system("cls");
		cout<<"Usuario:  ";
		for(;;){
				fflush(stdin);
				getline(cin, us);
				if(val.isVacio(us)==true){	
				break;
			    }}  
		
		cout<<"Constrasena:  ";
		for(;;){
				fflush(stdin);
				getline(cin, linea);
				if(val.isVacio(linea)==true){		
				break;
			    }}
		if(validaruser(op,us)==1){
			cout<<"Usuario existente, Ingreso otro\n";
			Sleep(1000);
		}
		else{
			archivo<<us<<setw(10);
			archivo<<linea<<endl;	
			break;
		}	    
			}
		
	cout<<setw(30)<<"Creado con Exito"<<endl;
	break;}
	archivo.close();
		
	}
	
		
	if(op==2){//adminstrador
		system("cls");
		string linea,us;
	ofstream archivo ("RegistroAdministrador.txt",ios::app);
	if(archivo.is_open()){
		fflush(stdin);
		for(;;){
			system("cls");
		cout<<"Usuario:  ";
			for(;;){
				fflush(stdin);
				getline(cin, us);
				if(val.isVacio(us)==true){		
				break;
			    }}   
		cout<<"Constrasena:  ";
		for(;;){
				fflush(stdin);
				getline(cin, linea);
				if(val.isVacio(linea)==true){	
				break;
			    }}  
			    
	if(validaruser(op,us)==1){
			cout<<"Usuario existe,ingrese otro\n";
			Sleep(1000);
		}
		else{
			archivo<<us<<setw(10);
			archivo<<linea<<endl;	
			break;
		}		    
			    
			}
cout<<setw(30)<<"Creado con Exito"<<endl;
	break;}
	archivo.close();
	}
	if(op==3){//asistente
		system("cls");
		string linea,us;
	ofstream archivo ("RegistroAsistente.txt",ios::app);
	if(archivo.is_open()){
		fflush(stdin);
		for(;;){
			system("cls");
		cout<<"Usuario:  ";
			for(;;){
				fflush(stdin);
				getline(cin, us);
				if(val.isVacio(us)==true){		
				break;
			    }}  
		cout<<"Constrasena:  ";
		for(;;){
				fflush(stdin);
				getline(cin, linea);
				if(val.isVacio(linea)==true){	
				break;
			    }}
				
		if(validaruser(op,us)==1){
			cout<<"Usuario Existente,ingrese otro\n";
			Sleep(1000);
		}
		else{
			archivo<<us<<setw(10);
			archivo<<linea<<endl;	
			break;
		}		
				}  
		
	cout<<setw(30)<<"Creado con Exito"<<endl;
	break;}
	archivo.close();
	}
	else{break;
	}
		
	}}
	
	
	void bajaUsuario(){
		int op; string OP;
		cout<<"¿Tipo Trabajador?\n1)Veterinario\n2)Administrador\n3)Asistente\n";
		cout<<"Choose an option:  ";
		for(;;){getline(cin, OP);
					        if( !val.isInteger( OP ) )
					        {
					            cout << "Ingresa solo numeros...\n";
								Sleep(800);
					        }
					        else{
					        	op=atoi(OP.c_str());
					        	break;
					        }}
	for(;;){
		if(op==1){
		string nombre, pass, aux;
     int bandera=0;
    
     ofstream temp("temporal.txt", ios::out);
     ifstream archivo("RegistroVeterinario.txt", ios::in);
     
     fflush( stdin );
     if (archivo.is_open()&&temp.is_open())
     {
            
               cout<<"\nIntroduzca el usuario a eliminar: ";
			   for(;;){
				fflush(stdin);
				getline(cin, aux);
				if(val.isVacio(aux)==true){
				
				break;
			    }}  
			     
               archivo>>nombre;  
      
        while(!archivo.eof())
         {    
              fflush( stdin );        
                       
              archivo>>pass;
               
              if (aux.compare(nombre) == 0)  //comparo la cedula ingresa con las existentes
                 {
                 cout<<"\nUsuario e informacion eliminado";
                 bandera=1;
                  } 
              else
              {
      
                 temp<<nombre<<setw(20)<<pass<<endl;   
                 
                 }
                 archivo>>nombre;  
              }  // end while
              
              if (bandera!=1)
              {
                 
                   cout<<"\nUsuario no encontrado";
                   }            
                  
              temp.close();   //datos nuevos
              archivo.close();        //datos viejos
              
              remove("RegistroVeterinario.txt");   // borramos el archivo anterior y renombramos el temp como empleados
              rename("temporal.txt", "RegistroVeterinario.txt");
              break;
                 }
      
      else
      {
          cout<<"ERROR AL ABRIR EL ARCHIVO";
            } 
	 
	 }
		if(op==2){
			string nombre, pass, aux;
     int bandera=0;
    
     ofstream temp("temporal.txt", ios::out);
     ifstream archivo("RegistroAdministrador.txt", ios::in);
     
     fflush( stdin );
     if (archivo.is_open()&&temp.is_open())
     {
            
               cout<<"\nUsuario: ";
               for(;;){
				fflush(stdin);
				getline(cin, aux);
				if(val.isVacio(aux)==true){
				
				break;
			    }}    
               archivo>>nombre;  
      
        while(!archivo.eof())
         {    
              fflush( stdin );        
                       
              archivo>>pass;
               
              if (aux.compare(nombre) == 0)  //comparo la cedula ingresa con las existentes
                 {
                 cout<<"\nUseario e informacion eliminada ";
                 bandera=1;
                  } 
              else
              {
      
                 temp<<nombre<<setw(20)<<pass<<endl;   
                 
                 }
                 archivo>>nombre;  
              }  // end while
              
              if (bandera!=1)
              {
                 
                   cout<<"\nUsuario no encontrado ";
                   }            
                  
              temp.close();   //datos nuevos
              archivo.close();        //datos viejos
              
              remove("RegistroAdministrador.txt");   // borramos el archivo anterior y renombramos el temp como empleados
              rename("temporal.txt", "RegistroAdministrador.txt");
              break;
                 }
      
      else
      {
          cout<<"ERROR AL ABRIR EL ARCHIVO";
            } 
		
		}
		if(op==3){
			string nombre, pass, aux;
     int bandera=0;
    
     ofstream temp("temporal.txt", ios::out);
     ifstream archivo("RegistroAsistente.txt", ios::in);
     
     fflush( stdin );
     if (archivo.is_open()&&temp.is_open())
     {
            
               cout<<"\nUsuario: ";
               for(;;){
				fflush(stdin);
				getline(cin, aux);
				if(val.isVacio(aux)==true){
				
				break;
			    }}   
               archivo>>nombre;  
      
        while(!archivo.eof())
         {    
              fflush( stdin );        
                       
              archivo>>pass;
               
              if (aux.compare(nombre) == 0)  //comparo la cedula ingresa con las existentes
                 {
                 cout<<"\nUsuario e informacion eliminada ";
                 bandera=1;
                  } 
              else
              {
      
                 temp<<nombre<<setw(20)<<pass<<endl;   
                 
                 }
                 archivo>>nombre;  
              }  // end while
              
              if (bandera!=1)
              {
                 
                   cout<<"\nUsuario no encontrado ";
                   }            
                  
              temp.close();   //datos nuevos
              archivo.close();        //datos viejos
              
              remove("RegistroAsistente.txt");   // borramos el archivo anterior y renombramos el temp como empleados
              rename("temporal.txt", "RegistroAsistente.txt");
              break;
                 }
      
      else
      {
          cout<<"ERROR AL ABRIR EL ARCHIVO";
            } 
		}
	
	else{break;
	}
	}
		}
		
	
	
	
	void mostrarusuarios(){
		int op; string OP;
		cout<<"¿Tipo Trabajador?\n1)Veterinario\n2)Administrador\n3)Asistente\n";
		cout<<"Choose an option:  ";
		for(;;){getline(cin, OP);
					        if( !val.isInteger( OP ) )
					        {
					            cout << "Ingresa solo numeros...\n";
								Sleep(800);
					        }
					        else{
					        	op=atoi(OP.c_str());
					        	break;
					        }}
	for(;;){
	if(op==1){
		system("cls");
		ifstream archivo("RegistroVeterinario.txt");
		string linea;
		if(archivo.is_open()){
		while(archivo.good()){
			getline(archivo,linea);
			cout<<linea<<endl;
		}
		
		break;
		}
			cout<<endl<<"---------------------------------------------------------------"<<endl;
		cout<<"Fin archivo"<<endl;
		archivo.close();
	}	
	
		if(op==2){
			system("cls");
		ifstream archivo("RegistroAdministrador.txt");
		string linea;
		if(archivo.is_open()){
		while(archivo.good()){
			getline(archivo,linea);
			cout<<linea<<endl;
		
		}
		
		break;
		}
	cout<<endl<<"---------------------------------------------------------------"<<endl;
	cout<<"Fin archivo"<<endl;
		archivo.close();
	}
	
		if(op==3){
			system("cls");
		ifstream archivo("RegistroAsistente.txt");
		string linea;
		if(archivo.is_open()){
		while(archivo.good()){
			getline(archivo,linea);
			cout<<linea<<endl;
			
		}
		break;
		}
			cout<<endl<<"---------------------------------------------------------------"<<endl;
	cout<<"Fin archivo"<<endl;
		archivo.close();
	}
	else{
		break;
	}
}
	}
	
	
	

	void calcular_sueldo(){
		sueldo=sueldo*.90;
		cout<<"Su salario es de: "<<endl;
	}
	
	
	void compra_producto(){
		cout<<"Ingrese No.Producto"<<endl;
		cout<<"Ingrese el total de productos que desee comprar"<<endl;
		
	}
};
#endif


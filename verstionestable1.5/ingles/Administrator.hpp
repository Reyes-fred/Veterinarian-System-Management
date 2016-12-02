#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Employee.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\People.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Validate.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#if !defined(_ADMINISTRATOR_HPP)
#define _ADMINISTRATOR_HPP
using namespace std;

class Administrator : public Employee{
public:
	Administrator(string nombre,string direccion,string telefono,int no_trabajador,string password,string RFC,string cargo,float sueldo):Employee(nombre,direccion,telefono,no_trabajador,password,RFC,cargo,sueldo)
	{	}
	Validate val;
	
	void mostrardatos(){
	cout<<"Name:"<<setw(31)<<"Address:"<<setw(20)<<"Telephone"<<setw(25)<<"Worker number"<<setw(20)<<"RFC"<<setw(20)<<"Task performs"<<setw(20)<<"Salary";
		string linea;
		ifstream archivo ("Nomina.txt");
		if(archivo.is_open()){
			while(archivo.good()){
				getline(archivo,linea);
				cout<<linea<<endl;
			
			}
	cout<<endl<<"---------------------------------------------------------------"<<endl;
	cout<<"End of file"<<endl;
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
		cout<<"Name: "<<endl;
		gets(cadena);
			char*tmp;
			while((tmp=strchr(cadena,32))!=NULL)
			  sprintf(tmp,"%s",tmp+1);		
		  	archivo<<cadena<<setw(13);
		
		
		cout<<"Product number: "<<endl;
						for(;;){
								fflush(stdin);
								getline(cin,linea);
								if(val.isVacio(linea)==true){
								if(!val.isInteger( linea )) //checar
								{
								cout << "Enter Numbers only...\n";
								Sleep(800);
									}
								else{
							archivo<<linea<<setw(15);		
							break;}
							    }			
							} 
	
		cout<<"Price: "<<endl;
							for(;;){
								fflush(stdin);
								getline(cin,linea);
								if(val.isVacio(linea)==true){
								if(!val.isPrecio( linea ))
								{
								cout << "Enter Numbers only...\n";
								Sleep(800);
									}
								else{
							archivo<<"$"<<linea<<setw(20);		
							break;}
							    }			
							}
		
		cout<<"Existence: "<<endl;
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
		}
		archivo.close();
			
	}
	
	
	void eliminar_producto(){
	string OP;
	int op;
	cout<<"Erase by\n 1)No.Product \n2)Product Name\n";	
	cout<<"Choose an option:  ";
	for(;;){
			fflush(stdin);
			getline(cin,OP);
			if(val.isVacio(OP)==true){
			if(!val.isInteger( OP ))
			{
			cout << "Enter Numbers only...\n";
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
                cout<<"\nNo.Product: "; 
               for(;;){
								fflush(stdin);
								getline(cin,aux);
								if(val.isVacio(aux)==true){
								if(!val.isInteger( aux ))
								{
								cout << "Enter numers only...\n";
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
                 cout<<"\nService and data Delete..\n  ";
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
                 
                   cout<<"\nService not found ";
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
                cout<<"\nProduct name: "; 
               for(;;){
								fflush(stdin);
								getline(cin,aux);
								if(val.isVacio(aux)==true){
								if(!val.isString( aux ))
								{
								cout << "Enter letters only...\n";
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
                 cout<<"\nService and data Delete..\n  ";
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
                 
                   cout<<"\nService not found ";
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
		
		default: cout<<"Incorrect option\n";
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
        
               cout<<"\nProduct number: ";
			   for(;;){
								fflush(stdin);
								getline(cin,aux);
								if(val.isVacio(aux)==true){
								if(!val.isInteger( aux ))
								{
								cout << "Enter Numbers only...\n";
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
              cout<<"\nNew price: ";
              for(;;){
								fflush(stdin);
								getline(cin,preci);
								if(val.isVacio(preci)==true){
								if(!val.isPrecio( preci ))
								{
								cout << "Enter Numbers only...\n";
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
        
               cout<<"\nProduct number: ";
			   for(;;){
								fflush(stdin);
								getline(cin,aux);
								if(val.isVacio(aux)==true){
								if(!val.isInteger( aux ))
								{
								cout << "Enter Numbers only...\n";
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
              cout<<"\nNew Existence: ";
              
			  for(;;){
								fflush(stdin);
								getline(cin,existe);
								if(val.isVacio(existe)==true){
								if(!val.isInteger( existe ))
								{
								cout << "Enter Numbers only...\n";
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
		
		cout<<"First name:  ";
			gets(cadena);
			char*tmp;
			while((tmp=strchr(cadena,32))!=NULL)
			sprintf(tmp,"%s",tmp+1);		
		  	archivo<<endl<<cadena<<setw(10);
		
		cout<<"Surname: ";
		for(;;){getline(cin, linea);
					        if( !val.isString( linea ) )
					        {
					            cout << "Enter a correct surname...\n";
								Sleep(800);
					        }
					        else{
					        	archivo<<linea<<setw(20);
					        	break;
					        }}
	
		
		fflush(stdin);
			
			cout<<"Address:  ";
			gets(cadena);
			char*tmp1;
			while((tmp=strchr(cadena,32))!=NULL)
			sprintf(tmp,"%s",tmp+1);		
		  	archivo<<cadena<<setw(20);
		  	
		fflush(stdin);
			
			cout<<"Telephone:  ";
			for(;;){
			getline(cin,linea);
			if(!val.isTelef(linea)){		
		  			cout<<"Enter a valid phone number\n";
		  			Sleep(800);
			  }
		  	else{archivo<<linea<<setw(20);
		  	break;
		  	}}
			
		 
		cout<<"Worker number:  ";
		for(;;){getline(cin, linea);
					        if( !val.isInteger( linea ) )
					        {
					            cout << "Enter Numbers only...\n";
								Sleep(800);
					        }
					        else{
					        	archivo<<linea<<setw(20);
					        	break;
					        }}
		
		cout<<"RFC:  ";
		getline(cin,linea);
		archivo<<linea<<setw(20);
		
		cout<<"Task performs:  ";
		for(;;){
							getline(cin, linea);
					        if( !val.isString( linea ) )
					        {
					            cout << "Enter letters only...\n";
								Sleep(800);
					        }
					        else{
					        	if(linea.compare("veterinarian")==0||linea.compare("Veterinarian")==0||linea.compare("Administrator")==0||linea.compare("administrator")==0||
								linea.compare("Assistan")==0||linea.compare("assistan")==0){			        	
					        	archivo<<linea<<setw(20);
					        	break;}
					        else{
					        	cout<<"Enter a valid task perform"<<endl;
					        }
					        }}
		
		cout<<"Salary:  ";
		for(;;){getline(cin, linea);
					        if( !val.isPrecio( linea ))
					        {
					            cout << "Enter a correct price...\n";
								Sleep(800);
					        }
					        else{
					        	archivo<<linea<<endl;
					        	break;
					        }}
	
		cout<<setw(30)<<"Successful"<<endl;
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
            
               cout<<"\nWorker name: ";
              	for(;;){
				fflush(stdin);
				getline(cin, aux);
				if(val.isVacio(aux)==true){
				if(!val.isString( aux ))
				{
				cout << "Enter Letter only...\n";
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
                 cout<<"\nWorker and Data Delete ";
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
                 
                   cout<<"\nName not found ";
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
		cout<<"¿Type of Worker?\n1)Veterinarian\n2)Administrator\n3)Assistant\n";
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
		cout<<"User:  ";
		for(;;){
				fflush(stdin);
				getline(cin, us);
				if(val.isVacio(us)==true){	
				break;
			    }}  
		
		cout<<"Password:  ";
		for(;;){
				fflush(stdin);
				getline(cin, linea);
				if(val.isVacio(linea)==true){		
				break;
			    }}
		if(validaruser(op,us)==1){
			cout<<"already existing user\n";
			Sleep(1000);
		}
		else{
			archivo<<us<<setw(10);
			archivo<<linea<<endl;	
			break;
		}	    
			}
		
	cout<<setw(30)<<"Successful"<<endl;
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
		cout<<"User:  ";
			for(;;){
				fflush(stdin);
				getline(cin, us);
				if(val.isVacio(us)==true){		
				break;
			    }}   
		cout<<"Password:  ";
		for(;;){
				fflush(stdin);
				getline(cin, linea);
				if(val.isVacio(linea)==true){	
				break;
			    }}  
			    
	if(validaruser(op,us)==1){
			cout<<"already existing user\n";
			Sleep(1000);
		}
		else{
			archivo<<us<<setw(10);
			archivo<<linea<<endl;	
			break;
		}		    
			    
			}
cout<<setw(30)<<"Succesful"<<endl;
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
		cout<<"User:  ";
			for(;;){
				fflush(stdin);
				getline(cin, us);
				if(val.isVacio(us)==true){		
				break;
			    }}  
		cout<<"Password:  ";
		for(;;){
				fflush(stdin);
				getline(cin, linea);
				if(val.isVacio(linea)==true){	
				break;
			    }}
				
		if(validaruser(op,us)==1){
			cout<<"already existing user\n";
			Sleep(1000);
		}
		else{
			archivo<<us<<setw(10);
			archivo<<linea<<endl;	
			break;
		}		
				}  
		
	cout<<setw(30)<<"Successful"<<endl;
	break;}
	archivo.close();
	}
	else{break;
	}
		
	}}
	
	
	void bajaUsuario(){
		int op; string OP;
		cout<<"¿Type of Worker?\n1)Veterinarian\n2)Administrator\n3)Assistant\n";
		cout<<"Choose an option:  ";
		for(;;){getline(cin, OP);
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
		if(op==1){
		string nombre, pass, aux;
     int bandera=0;
    
     ofstream temp("temporal.txt", ios::out);
     ifstream archivo("RegistroVeterinario.txt", ios::in);
     
     fflush( stdin );
     if (archivo.is_open()&&temp.is_open())
     {
            
               cout<<"\nDelete User: ";
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
                 cout<<"\nUser and data Delete";
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
                 
                   cout<<"\nUser not found ";
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
            
               cout<<"\nUser: ";
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
                 cout<<"\nUser and data Delete ";
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
                 
                   cout<<"\nUser not found ";
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
            
               cout<<"\nUser: ";
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
                 cout<<"\nUser and data delete ";
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
                 
                   cout<<"\nUser not found ";
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
		cout<<"¿Type of Worker?\n1)Veterinarian\n2)Administrator\n3)Assistant\n";
		cout<<"Choose an option:  ";
		for(;;){getline(cin, OP);
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
		cout<<"End of file"<<endl;
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
	cout<<"End of file"<<endl;
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
	cout<<"End of file"<<endl;
		archivo.close();
	}
	else{
		break;
	}
}
	}
	
	
	

	void calcular_sueldo(){
		sueldo=sueldo*.90;
		cout<<"Your salary is: "<<endl;
	}
	
	
	void compra_producto(){
		cout<<"Ingrese No.Producto"<<endl;
		cout<<"Ingrese el total de productos que desee comprar"<<endl;
		
	}
};
#endif


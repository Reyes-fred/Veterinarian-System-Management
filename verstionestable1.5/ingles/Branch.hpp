#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Validate.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Schedule.hpp"


#if !defined(_BRANCH_HPP)
#define _BRANCH_HPP
class Branch {
private:
	Schedule schedule(string,string);
	string gerente;
	string direccion;
	string localidad;
	string RFC;
	string lista_precio_servicios;
	string lista_precio_productos;
	string telefono;

public:
	Validate val;
    Branch(string direccion, string gerente, string localidad, string telefono, string RFC, string lista_precio_servicios,string lista_precio_productos)
    {				Schedule schedule("xxx","xxx");
					this->direccion=direccion;
                    this->gerente=gerente;
                    this->localidad=localidad;
                    this->telefono=telefono;
                    this->RFC=RFC;
                    this->lista_precio_servicios=lista_precio_servicios;
                    this->lista_precio_productos=lista_precio_productos;
                    
   
    ifstream archivo("Sucursaling.txt"); 
     if (!archivo)
    {
   ofstream archivo ("Sucursaling.txt");
   if(archivo.is_open()){
   	archivo<<setw(50)<<"Veterinary Medicine El Perrito Cojo"<<endl<<endl;
	archivo<<"Manager:   "<<gerente<<endl;
	archivo<<"Address: "<<direccion<<endl;
	archivo<<"City: "<<localidad<<endl;
	archivo<<"Telephone:  "<<telefono<<endl;
	archivo<<"Schedule:   "<<endl<<setw(15)<<schedule.gethoras()<<endl<<setw(15)<<schedule.getdias();
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
	ifstream archivo("Sucursaling.txt");
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
	ofstream archivo ("Sucursaling.txt");
   if(archivo.is_open()){
   	archivo<<setw(50)<<"Veterinary Medicine: El Perrito Cojo"<<endl<<endl;
	cout<<"Manager:  \n   First Name: ";
   				for(;;){
				fflush(stdin);
				getline(cin, linea);
				if(val.isVacio(linea)==true){
				if(!val.isString( linea ))
				{
				cout << "Enter Letter only...\n";
				Sleep(800);
					}
				else{
				temp=linea;
				break;}
			    }}
	cout<<"\n	Surname: ";
   				for(;;){
				fflush(stdin);
				getline(cin, linea);
				if(val.isVacio(linea)==true){
				if(!val.isString( linea ))
				{
				cout << "Enter Letter only...\n";
				Sleep(800);
					}
				else{
				archivo<<"Manager:   "<<temp<<" "<<linea<<endl;
				break;}
			    }}
	
	cout<<"Address:  ";
			   for(;;){
				getline(cin, linea);
				if(val.isVacio(linea)==true){
				archivo<<"Address: "<<linea<<endl;
				break;}}
	
	cout<<"City:  ";
			   	for(;;){
				fflush(stdin);
				getline(cin, linea);
				if(val.isVacio(linea)==true){
				if(val.isCiudad(linea )==false)
				{
				cout << "Enter a correct city...\n";
				Sleep(800);
					}
				else{
				archivo<<"City: "<<linea<<endl;
				break;
			    }	}}
	
	cout<<"Telephone:  ";
			   for(;;){
				getline(cin, linea);
				if(val.isVacio(linea)==true){
			        if( !val.isTelef( linea ))
			        {
			            cout << "Enter a correct Telefone...\n";
						Sleep(800);
			        }
			        else{
			        archivo<<"Telephone:  "<<linea<<endl;
					break;	
			        }	}
					}
   	
	cout<<"Shcedule";
	cout<<"\nDay: \nFrom:";
			for(;;){
						fflush(stdin);
						getline(cin, linea);
						if(val.isVacio(linea)==true){
						if(val.isDia( linea )==false)
						{
						cout << "Enter a correct Day only...\n";
						Sleep(800);
							}
						else{
						archivo<<"Schedule:"<<endl<<setw(15)<<linea;
						break;
					    }		
						}}
	cout<<"To:";
				for(;;){
				fflush(stdin);
				getline(cin, linea);
				if(val.isVacio(linea)==true){
				if(val.isDia( linea )==false)
				{
				cout << "Enter a correct Day only...\n";
				Sleep(800);
					}
				else{
				archivo<<"--"<<linea<<endl;
				break;
			    }		
				}}						
	
	cout<<"Houre: \nFrom:";
	
				int hor;
				string tem;
				for(;;){
				fflush(stdin);
				cout<<"\nHr (_ _):   ";
				for(;;){
				getline(cin, linea);
				hor=atoi(linea.c_str());
				if(hor>=0&&hor<=24)break;else cout<<"Enter a valid hour";}
				tem=linea+":";
				cout<<"Min (_ _):   ";
				for(;;){
				getline(cin, linea);
				hor=atoi(linea.c_str());
				if(hor>=0&&hor<60)break;else cout<<"Enter a valid minute";}
				tem=tem+linea;
				if(val.isVacio(tem)==true){
				if(!val.isHora( tem ))
				{
				cout << "Enter Hour only...\n";
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
				if(hor>=0&&hor<=24)break;else cout<<"Enter a valid hour";}
				tem=linea+":";
				cout<<"Min (_ _):   ";
				for(;;){
				getline(cin, linea);
				hor=atoi(linea.c_str());
				if(hor>=0&&hor<60)break;else cout<<"Enter a valid minute";}
				tem=tem+linea;
				if(val.isVacio(tem)==true){
				if(!val.isHora( tem ))
				{
				cout << "Enter Hour only...\n";
				Sleep(800);
					}
				else{
				archivo<<"--"<<tem<<endl;
				break;
			    }	
					}}
	
	cout<<"RFC:  ";
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
			cout<<"Service Name:  ";
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
			cout<<"No.Service:  ";
						for(;;){
						fflush(stdin);
						getline(cin, linea);
						if(val.isVacio(linea)==true){
						if(!val.isInteger( linea ))
						{
						cout << "Enter Numbers only...\n";
						Sleep(800);
							}
						else{
							
							archivo<<linea<<setw(20);
							break;}
					    }			
					}
			
			cout<<"Price:  ";
					for(;;){
								fflush(stdin);
								getline(cin, linea);
								if(val.isVacio(linea)==true){
								if(!val.isPrecio( linea ))
								{
								cout << "Enter a correct price...\n";
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
        
               cout<<"\nNo.Service: ";
		              for(;;){
								fflush(stdin);
								getline(cin, aux);
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
              archivo>>sueldo;  
              if (aux.compare(num) == 0)  //comparo la cedula ingresa con las existentes
              {
              cout<<"\nNew Price: ";
		              for(;;){
								fflush(stdin);
								getline(cin, sueldo);
								if(val.isVacio(sueldo)==true){
								if(!val.isPrecio( sueldo ))
								{
								cout << "Enter Numbers only...\n";
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
	cout<<"Erase by \n1)No.Product 2)Product Name";
	cout<<"\nChoose an option:  ";
	for(;;){
	getline(cin,OP);
	if( !val.isInteger( OP ) )
	        {
	            cout << "Enter Numbers only...\n";
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
                cout<<"\nNo. Product: ";
               for(;;){
				fflush(stdin);
				getline(cin, aux);
				if(val.isVacio(aux)==true){
				if(!val.isInteger( aux ))
				{
				cout << "Enter numbers only...\n";
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
                 cout<<"\nService and Data Delete ";
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
                 
                   cout<<"\nService not found ";
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
                cout<<"\nName Service: ";
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
                       
              archivo>>ced;
              archivo>>sueldo;  
              if (aux.compare(nombre) == 0)  //comparo la cedula ingresa con las existentes
                 {
                 cout<<"\nService and Data Delete ";
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
                 
                   cout<<"\nService not found ";
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
			default:cout<<"Incorrect option";
			Sleep(1000);
			system("cls");
				break;
		}
		
		
	}

	
    
	
	void getLista_Servicios(){
		cout<<"Service Name:"<<setw(20)<<"No.Service:"<<setw(20)<<"Price:"<<endl;
		ifstream archivo("ListaServicios.txt");
		string linea;
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

	
};
#endif


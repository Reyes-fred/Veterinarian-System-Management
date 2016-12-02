#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <ctime>
#include <sstream>
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Employee.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Validate.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Customer.hpp"
#if !defined(_ASSISTANT_HPP)
#define _ASSISTANT_HPP
using namespace std;

class Assistant : public Employee {
public:
	
	Validate val;
	Assistant(string nombre,string direccion,string telefono,int no_trabajador,string password,string RFC,string cargo,float sueldo):Employee(nombre,direccion,telefono,no_trabajador,password,RFC,cargo,sueldo)
	{
	
   ofstream archivo ("Citas.txt",ios::app);
   
	}
	
	
	
	
	int validarvete(string nomvete,string apevete){
	int bandera;
	string  usuario,cuarto,nom;
		
   ifstream archivo5("Consultorio.txt",ios::in);
     fflush( stdin );
     if (archivo5.is_open())
     {
                  
               archivo5>>usuario;  
      
        while(!archivo5.eof())
         {    fflush( stdin );        
                       
              archivo5>>nom;  
              archivo5>>cuarto;  
                
              
              if (nomvete.compare(usuario) == 0)  //comparo usuario ingresado con los existentes
                 {
                  
				  if (apevete.compare(nom) == 0)       // compara la contraseña con la del usuario si el usuario existe
                     {  
                        bandera=1; 
                        return 1;
                      }
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

	
	
	
	
	

	void crear_cita(int op2){
		string tem;
			int cont=1;
		char nom[7][30]={"No.Member: ","Day: ","Day #: ","Time: ","Month: ", " ","Veterinarian: "};
		fflush (stdin);
		string linea,nomember,day,daynum,mes;
		ofstream archivo("Citas.txt",ios::app);
		if(archivo.is_open()){
			int i=0;
			while(i<8){
			if(i==6){
			for(;;){	
			string nombre,apellido;
			cout<<nom[i];
			cout<<"\n	First Name:  ";	
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
				nombre=linea;
				break;}
			    }}
				
			cout<<"	Surname:  ";	
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
				apellido=linea;
				break;}
			    }}	
		
		if(validarvete(nombre,apellido)==0){
			cont++;
			cout<<"No such veterinary...\n"<<cont;
			
			}	
			else{
					archivo<<nomember<<setw(10)<<day<<setw(10)<<daynum<<setw(10)<<tem<<setw(10)<<mes<<setw(10)<<nombre<<setw(15)<<apellido;
					cout<<setw(50)<<"Successful"<<endl;  
					Sleep(800);
					break;
			} 
			
			if(cont>2){
				cout<<"Number of attempts exceeded...";
				Sleep(800);
				break;
			}
			}
				
				}
			    
			    if(i==4){
			cout<<nom[i];	
			for(;;){
				fflush(stdin);
				getline(cin, linea);
				if(val.isVacio(linea)==true){
				if(!val.isMes( linea ))
				{
				cout << "Enter a correct month...\n";
				Sleep(800);
					}
				else{
				mes=linea;
				break;}
			    }}}
			    
			if(i==1){
				cout<<nom[i];
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
				day=linea;
				break;
			    }		
				}}}			
				
					
			if(i==3){
				int hor;
				
				cout<<nom[i];
				for(;;){
				fflush(stdin);
				cout<<"\nHr (_ _):  ";
				for(;;){
				getline(cin, linea);
				hor=atoi(linea.c_str());
				if(hor>=0&&hor<24)break;else cout<<"Enter a valid hour\n";}
				tem=linea+":";
				cout<<"Min (_ _):  ";
				linea="";
				for(;;){
				getline(cin, linea);
				hor=atoi(linea.c_str());
				if(hor>=0&&hor<60)break;else cout<<"Enter a valid minute\n";}
				tem=tem+linea;
				if(val.isVacio(tem)==true){
				if(!val.isHora( tem ))
				{
				cout << "Enter Hour only...\n";
				Sleep(800);
					}
				else{
				break;
			    }	
					}}}
			
			if(i==0){
				int num;
				cout<<nom[i];
				cout<<op2<<endl;
				stringstream stream;
				stream << op2;
				linea = stream.str();
				nomember=linea;
				
			    }			
			
			
			if(i==2){
				int num;
				cout<<nom[i];
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
					num=atoi(linea.c_str());
					if(num>=1&&num<=31){
					daynum=linea;
					break;}
					else {cout<<"Enter a valid day..\n";}
			    }			
			}}}	
			
			i++; 
			if(cont>2){
				break;
			}
			
			}//fin while
				archivo<<endl<<endl;
				}
			archivo.close();
		   }
		
		
		
		
		


	void crear_cita(){
		int cont=1;
		char nom[7][30]={"No.Member: ","Day: ","Day #: ","Time: ","Month: ", " ","Veterinarian: "};
		fflush (stdin);
		string linea;
		string nomember,day,daynum,mes,tem;
		ofstream archivo("Citas.txt",ios::app);
		if(archivo.is_open()){
			int i=0;
			while(i<7){
			if(i==6){
		string nombre,apellido;
			
		for(;;){		
			cout<<nom[i];
			cout<<"\n	First Name:  ";	
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
				nombre=linea;
				break;}
			    }}
				
			cout<<"		Surname:  ";	
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
				apellido=linea;
				break;}
			    }}
			
			if(validarvete(nombre,apellido)==0){
				cont++;
			cout<<"No such veterinary...\n";
			}	
			else{
					archivo<<nomember<<setw(10)<<day<<setw(10)<<daynum<<setw(10)<<tem<<setw(10)<<mes<<setw(10)<<nombre<<setw(15)<<apellido;
					cout<<setw(50)<<"Successful"<<endl;  
					Sleep(800);
					break;
			}
			
			if(cont>2){
				cout<<"Number of attempts exceeded...";
				Sleep(800);
				break;
			}
		}
		}
		
			    
			    if(i==4){
			cout<<nom[i];	
			for(;;){
				fflush(stdin);
				getline(cin, linea);
				if(val.isVacio(linea)==true){
				if(!val.isMes( linea ))
				{
				cout << "Enter a correct month...\n";
				Sleep(800);
					}
				else{
				mes=linea;
				break;}
			    }}}
			    
			if(i==1){
				cout<<nom[i];
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
				day=linea;
				break;
			    }		
				}}}			
				
					
		if(i==3){
				int hor;
				cout<<nom[i];
				for(;;){
				fflush(stdin);
				cout<<"\nHr: (_ _) ";
				for(;;){
				getline(cin, linea);
				hor=atoi(linea.c_str());
				if(hor>=0&&hor<=24)break;else cout<<"Enter a valid hour\n";}
				tem=linea+":";
				cout<<"Min: (_ _)";
				for(;;){
				getline(cin, linea);
				hor=atoi(linea.c_str());
				if(hor>=0&&hor<60)break;else cout<<"Enter a valid minute\n";}
				tem=tem+linea;
				if(val.isVacio(tem)==true){
				if(!val.isHora( tem ))
				{
				cout << "Enter Hour only...\n";
				Sleep(800);
					}
				else{
				break;
			    }	
					}}}
						
			if(i==0){
				cout<<nom[i];
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
				nomember=linea;
				break;
			    }			
			}}}	
						
			
			
			if(i==2){
				int num;
				cout<<nom[i];
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
					num=atoi(linea.c_str());
					if(num>=1&&num<=31){
				daynum=linea;
					break;}
					else{
						cout<<"Enter a valid day...\n";
					}
			    }			
			}}}	
			
			
			
			i++;
			if(cont>2){
				break;
			}
			 }//fin while
				archivo<<endl<<endl;
				}
			archivo.close();}

	
	
	
	
	
	void cancelar_cita(int op2){
     string num,dia,hora,nomvete,aux,dianum,mes,apevete;
     int bandera=0;
    
     ofstream temp("temporal.txt", ios::out);
     ifstream archivo("Citas.txt", ios::in);
     
     fflush( stdin );
     if (archivo.is_open()&&temp.is_open())
     {
                stringstream stream;
				stream << op2;
				aux = stream.str();
             	archivo>>num; 	
					       
      
        while(!archivo.eof())
         {    
              fflush( stdin );        
                       
              archivo>>dia;
              archivo>>dianum;
              archivo>>hora; 
              archivo>>mes;
              archivo>>nomvete;
			  archivo>>apevete;  
              if (aux.compare(num) == 0)  //comparo la cedula ingresa con las existentes
                 {
                 cout<<"\nAppointment Delete ";
                 Sleep(800);
                 bandera=1;
                  } 
              else
              {
      
                 temp<<num<<setw(15)<<dia<<setw(15)<<dianum<<setw(15)<<hora<<setw(15);  
                 temp<<mes<<setw(15)<<nomvete<<setw(15)<<apevete<<endl;                             
                 
                 }
                 archivo>>num;  
              }  // end while
              
              if (bandera!=1)
              {
                 
                   cout<<"\nNo.Member not found";
                   Sleep(800);
                   }            
              
              temp.close();   //datos nuevos
              archivo.close();        //datos viejos
              
              remove("Citas.txt");   // borramos el archivo anterior y renombramos el temp como empleados
              rename("temporal.txt", "Citas.txt");
                 }
      
      else
      {
          cout<<"ERROR AL ABRIR EL ARCHIVO";
           Sleep(800);
     
     } 
	}
	
void cancelar_cita(){
     string num,dia,hora,vete,aux,dianum,mes;
     int bandera=0;
    
     ofstream temp("temporal.txt", ios::out);
     ifstream archivo("Citas.txt", ios::in);
     
     fflush( stdin );
     if (archivo.is_open()&&temp.is_open())
     {
                cout<<"\nNo.Member:  ";
               	getline(cin,aux);   
             	archivo>>num; 	
					       
      
        while(!archivo.eof())
         {    
              fflush( stdin );        
                       
              archivo>>dia;
              archivo>>dianum;
              archivo>>hora; 
              archivo>>mes;
              archivo>>vete;  
              if (aux.compare(num) == 0)  //comparo la cedula ingresa con las existentes
                 {
                 cout<<"\nAppointment delete ";
                 Sleep(800);
                 bandera=1;
                  } 
              else
              {
      
                 temp<<num<<setw(15)<<dia<<setw(15)<<dianum<<setw(15)<<hora<<setw(15);  
                 temp<<mes<<setw(15)<<vete<<setw(15)<<endl;                             
                 
                 }
                 archivo>>num;  
              }  // end while
              
              if (bandera!=1)
              {
                 
                   cout<<"\nNo.Member not found ";
                   Sleep(800);
                   }            
              
              temp.close();   //datos nuevos
              archivo.close();        //datos viejos
              
              remove("Citas.txt");   // borramos el archivo anterior y renombramos el temp como empleados
              rename("temporal.txt", "Citas.txt");
                 }
      
      else
      {
          cout<<"ERROR AL ABRIR EL ARCHIVO";
           Sleep(800);
     
     } 
	
	}	
	
	

};
#endif


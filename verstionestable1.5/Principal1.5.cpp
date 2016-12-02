#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\Administrador.hpp" 
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\Almacen.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\Asistente.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\Cliente.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\Consultorio.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\Empleado.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\Historia Clinica.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\Persona.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\Registro_Diario.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\Sucursal.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\Sueldo.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\Veterinario.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\validar.hpp"

#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Administrator.hpp" 
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Assistant.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Branch.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Customer.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Employee.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Journal.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\MedicalHistory.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Office.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\People.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Salary.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Storage.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Validate.hpp"
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Veterinarian.hpp"


using namespace std;
static HWND  hConWnd;
HWND BCX_Bitmap(char*,HWND=0,int=0,int=0,int=0,int=0,int=0,int=0,int=0,int=0);
HWND GetConsoleWndHandle(void);

bool SetWindow(int Width, int Height) 
    { 
    _COORD coord; 
    coord.X = Width; 
    coord.Y = Height; 

    _SMALL_RECT Rect; 
    Rect.Top = 0; 
    Rect.Left = 0; 
    Rect.Bottom = Height - 1; 
    Rect.Right = Width - 1; 

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE); 
    if (Handle == NULL) 
        { 
        cout<<"Failure in getting the handle\n"<<GetLastError(); 
        return FALSE; 
        } 
     
   if(!SetConsoleScreenBufferSize(Handle, coord)) 
        { 
        cout<<"Failure in setting buffer size\n"<<GetLastError(); 
        return FALSE; 
        } 

    if(!SetConsoleWindowInfo(Handle, TRUE, &Rect)) 
        { 
        cout<<"Failure in setting window size\n"<<GetLastError(); 
        return FALSE; 
        } 

    return TRUE; 
    } 


int main(){
	SetWindow(140,50);
	system("color F0");
	int op,ido;
	string OP,IDO;
	int num;
	//Español
	validar val;
	Consultorio cons;
	Veterinario vet("xxx","xxx","xxx",0,"xxx","xxx","xxx",0.0,0,"xxx");
	Asistente asi("xxx","xxx","xxx",0,"xxx","xxx","xxx",0.0);
	Sueldo sue(0,0,0);
	Historia_Clinica his("xxx","xxx","xxx","xxx","xxx","xxx");
	Sucursal suc("xxx","xxx","xxx","xxx","xxx","xxx","xxx");
	Cliente cli("xxx","xxx","xxx","xxx","xxx");
	Empleado emp("xxx","xxx","xxx",000,"xxx","xxx","xxx",0.0);
	Almacen alm;
	Administrador adm("xxx","xxx","xxx",0,"xxx","xxx","xxx",0.0);
	Registro_Diario reg(0,0);
	//Ingles
	Validate val2;
	Office cons2;
	Veterinarian vet2("xxx","xxx","xxx",0,"xxx","xxx","xxx",0.0,0,"xxx");
	Assistant asi2("xxx","xxx","xxx",0,"xxx","xxx","xxx",0.0);
	Salary sue2(0,0,0);
	MedicalHistory his2("xxx","xxx","xxx","xxx","xxx","xxx");
	Branch suc2("xxx","xxx","xxx","xxx","xxx","xxx","xxx");
	Customer cli2("xxx","xxx","xxx","xxx","xxx");
	Employee emp2("xxx","xxx","xxx",000,"xxx","xxx","xxx",0.0);
	Storage alm2;
	Administrator adm2("xxx","xxx","xxx",0,"xxx","xxx","xxx",0.0);
	Journal reg2(0,0);
	
	hConWnd = GetConsoleWndHandle();
	Inicio:
	for(;;){
	system("cls");
	cout<<"Choose a Language/Escoge un Idioma\n1)Espanol\n2)English\n3)Salir/Exit"<<endl;
	cout<<endl<<"Opcion:  ";
	getline(cin, IDO);
        if( !val.isInteger( IDO) )
        {
            cout << "Enter Numbers only/Solo Numeros...\n";
			Sleep(800);
        }
        else{
        	ido=atoi(IDO.c_str());
        	break;
        }}
	
	switch(ido){
//-----------------------------------------------------------------------Español----------------------------------------------------------		
		case(1):
			SetConsoleTitle("Sistema Clinica Veterinaria");
	
	suc.mostrardatos();          
                                //muestra los datos de la sucursal veterinaria

	
  if (hConWnd)
  {
    // select a bitmap file you have or use one of the files in the Windows folder
    // filename, handle, ID, ulcX, ulcY, width, height   0,0 auto-adjusts
	  BCX_Bitmap("C:\\Windows\\G.bmp",hConWnd,123,830,460,280,140);

    
  
	
	int no;
	 do   // mantenerse en el menu hasta q el usuario quera salir salir
    {
	Menu:    
                                                      //MENU 1
	system("cls");
	suc.mostrardatos();
	cout<<endl<<endl;
	cout<<"MENU USUARIO"<<endl;
	cout<<"1)Cliente\n2)Empleado\n3)Salir"<<endl;
	cout<<endl<<"Opcion deseda:  ";
	op=0;
	getline(cin, OP);
        if( !val.isInteger( OP ) )
        {
            cout << "Ingresa solo Numeros...\n";
			Sleep(800);
        }
        else{
        	op=atoi(OP.c_str());
        }
        	
	cout<<endl<<endl;
	switch(op){
	   case(1)://cliente
	   Cliente:
	   	system("cls");
		cout<<setw(50)<<"MENU USUARIO: \n"<<endl;		
		cout<<endl<<endl<<"1)Nuevo Cliente\n2)Cliente Existente\n3)Regresar"<<endl;
		cout<<endl<<"Opcion deseada:  ";
		getline(cin, OP);
	      op=0;  
		  if( !val.isInteger( OP ) )
	        {
	            cout << "Ingresa solo numeros...\n";
				Sleep(800);
	        }
	        else{
	        	op=atoi(OP.c_str());
	        }
			switch(op){
				case(1):
					system("cls");
					cli.nuevocliente();
					Sleep(1000);
					goto Cliente;
					break;
				case(2):
				system("cls");
					for(;;){
					cout<<endl<<"Ingresa tu numero de Cliente:  ";
					int num;
					op=0;
					getline(cin,OP);
					if( !val.isInteger( OP ) )
				        {
				            cout << "Ingresa solo numeros...\n";
							system("cls");
							Sleep(800);
							
							
				        }
				        else{
				        	op=atoi(OP.c_str());
				        	num=op;
				        	break;
				        }}
					
					if(cli.identificarse(op)==1){
					
						int op2=op;
						Socio:
							
						system("cls");
						cout<<setw(40)<<"Cliente No."<<op2<<endl;
						num=op2;
						cout<<endl<<"1)Revizar Historial Medico"<<endl<<"2)Solicitar Cita"<<endl<<"3)Cancelar Cita"<<endl<<"4)Consultar Consultorios"<<endl<<"5)Cambiar contrasena"<<endl<<"6)Regresar"<<endl;
						cout<<"Opcion deseada:  ";
							op=0;
							getline(cin, OP);
					        if( !val.isInteger( OP ) )
					        {
					            cout << "Ingresa solo numeros...\n";
								Sleep(800);
					        }
					        else{
					        	op=atoi(OP.c_str());
					        }
						switch(op){
							case(1):
							system("cls");
									his.consultarhistorial(num);
									fflush(stdin);
									char c;
									c = getchar();
									while(c != '\n'){
									c = getchar();
									goto Socio;
								break;
								} 
								goto Socio;
								break;
							case(2):
								system("cls");
								asi.crear_cita(num);
								goto Socio;
								break;
							case(3):
								system("cls");
							asi.cancelar_cita(num);
								Sleep(800);
								goto Socio;
								break;
							case(4):
								system("cls");
								cons.mostrarDatos();
								fflush(stdin);
									char c2;
									c2 = getchar();
									while(c2 != '\n'){
									c2 = getchar();
									goto Socio;
								break;
								} 
								goto Socio;
								
								case(5):
									system("cls");
								cli.cambiar_contra(num);
								goto Socio;
								break;
								
								case(6):
								goto Cliente;
								break;
							default:
									cout<<"Opcion Incorrecta";
									Sleep(1000);
									goto Socio;
									break;
						}
						
					}
					else{
					cout<<"No se encuentra registrado"<<endl;
					Sleep(1000);	
					goto Cliente;
					}
										
					goto Cliente;
					break;
					
				case(3):goto Menu;
				break;
				default: cout<<"Opcion Incorrecta"<<endl;
				Sleep(1000);
				goto Cliente; break;	
		}
	break;                                                         // final opcion CLIENTE
		
		
	
	case(2):                                                       //opcion TRABAJADOR
	Trabajador:	
	system("cls");
	cout<<"Tipo de Trabajador:\n\n1)Veterinario\n2)Administrador\n3)Asistente\n4)Regresar"<<endl<<endl;
	cout<<"Opcion deseada:  ";
	 op=0;
	      getline(cin, OP);
	        if( !val.isInteger( OP ) )
	        {
	            cout << "Ingresa solo numeros...\n";
				Sleep(800);
	        }
	        else{
	        	op=atoi(OP.c_str());
        	}
			switch(op){
				case(1):			//Veterinario
				if(emp.identificarse(op)==1){
					
					MenuVet:
						for(;;){
							system("cls");
						cout<<setw(40)<<"Veterinario"<<endl<<endl;
					cout<<endl<<"1)Historial Medico"<<endl<<"2)Revisar Citas"<<endl<<"3)Registro Diario"<<endl<<"4)Generar Salario "<<endl<<"5)Crear Receta"<<endl<<"6)Regresar"<<endl;
					cout<<"Opcion deseada:  ";
					op=0;
						getline(cin, OP);
				        if( !val.isInteger( OP ) )
				        {
				            cout << "Ingresa solo numeros...\n";
							Sleep(800);
				        }
				        else{
				        	op=atoi(OP.c_str());
				        	break;
				        }}
					switch(op){
					case(1):
					Histo:
					system("cls");
					cout<<setw(40)<<"Historial Medico"<<endl<<endl;
					
						
						cout<<endl<<endl<<"1)Crear Historial Medico"<<endl<<"2Mostrar Historial Medico"<<endl<<"3)Actualizar Historial Medico"<<endl<<"4)Regresar"<<endl;
							cout<<"Opcion desead:  ";
								op=0;
								getline(cin, OP);
						        if( !val.isInteger( OP ) )
						        {
						            cout << "Ingresa solo numeros...\n";
									Sleep(800);
						        }
						        else{
						        	op=atoi(OP.c_str());
						        }
							switch(op){
								case(1):
									system("cls");
									his.crearHistoria();
									Sleep(1000);
									goto Histo;
									break;
								case(2):
									system("cls");
									his.consultarhistorial();
									fflush(stdin);
									char c;
									c = getchar();
									while(c != '\n'){
									c = getchar();
									goto Histo;
								break;
								} 
								goto Histo;
								
								
								case(3):
									system("cls");
									his.capturadatos();
									goto Histo;
									break;
								case(4):
									system("cls");
									goto MenuVet;
									break;
								default: cout<<"Opcion no disponible"<<endl;
								Sleep(1000);
								goto Histo;	
									}
							break;
					case(2):
						system("cls");
						cout<<setw(40)<<"Citas"<<endl<<endl;
						
						vet.revisar_cita();
								fflush(stdin);
									char c;
									c = getchar();
									while(c != '\n'){
									c = getchar();
									goto MenuVet;
								break;
								} 
								goto MenuVet;
						break;
					case(3):
						
						cout<<setw(40)<<"Registro Diario"<<endl<<endl;
						Registro:
						system("cls");
						cout<<"1)Crear Registro Diariol\n2)Actualizar Registro Diario\n3)Regresar"<<endl;
						cout<<"Opcion Desead:  ";
							op=0;
							getline(cin, OP);
					        if( !val.isInteger( OP ) )
					        {
					            cout << "Ingresa solo numeros...\n";
								Sleep(800);
					        }
					        else{
					        	op=atoi(OP.c_str());
					        }
						switch(op){
							case(1):
								system("cls");
								reg.crearRegistro();
								Sleep(1000);
								goto Registro;
								break;
							case(2):
								system("cls");
								reg.agregarRegistro();
								Sleep(1000);
								goto Registro;
								break;
							case(3):
								system("cls");
								goto MenuVet;
								break;
							default:
								cout<<"Opcion no disponible"<<endl;
								Sleep(1000);
								goto Registro;
								break;
						}
						goto MenuVet;
						break;
						
					case(4):
								system("cls");
								cout<<"Su salario es: "<<sue.generarpago(1);
								Sleep(1000);
								goto MenuVet;
								break;	
						
						
					case(5):
								system("cls");
								vet.crear_receta();
								Sleep(1000);
								goto MenuVet;
								break;	
						
						
					case(6):
						goto Trabajador;
					break;	
					default: cout<<"Opcion no disponible"<<endl;
					Sleep(1000);
					goto MenuVet;
					break;
					}
				
				break;
			}
			else {goto Trabajador; 
			}
				
				
			    case(2):			//Administrador
			    if(emp.identificarse(op)==1){
			      
				Menu2:
				
					
						for(;;){
							system("cls");
				cout<<setw(40)<<"Administrador"<<endl;
				cout<<"1)Sucursal"<<endl<<"2)Lista Servicios"<<endl<<"3)Almacen"<<endl<<"4)Empleados"<<endl<<"5)Salario"<<endl<<"6)Consultorios"<<endl<<"7)Regresar"<<endl;
				cout<<"Opcion deseada:  ";
					op=0;
						getline(cin, OP);
				        if( !val.isInteger( OP ) )
				        {
				            cout << "Ingresa solo numeros...\n";
							Sleep(800);
				        }
				        else{
				        	op=atoi(OP.c_str());
				        	break;
				        }}
			    switch(op){
			    	case (1):
			    		Tienda:
			    		system("cls");
						cout<<setw(40)<<"Sucursal"<<endl<<endl;
						cout<<"1)Mostrar Informacion"<<endl<<"2)Modificar Informacion"<<endl<<"3)Regresar"<<endl;
						cout<<"Opcion deseada:  ";
							op=0;
							getline(cin, OP);
					        if( !val.isInteger( OP ) )
					        {
					            cout << "Ingresa solo numeros...\n";
								Sleep(800);
					        }
					        else{
					        	op=atoi(OP.c_str());
					        }
					    	
							switch(op){
					    			case(1):
					    			system("cls");
									suc.mostrardatos();
									fflush(stdin);
									char c;
									c = getchar();
									while(c != '\n'){
									c = getchar();
									goto Tienda;
								break;
								} 
								goto Tienda;
									
					    			case(2):
									system("cls");
									suc.editardatos();
									goto Tienda;
									break;
									case(3):
									goto Menu2;
									default:
										goto Tienda;
										break;
					    		}
					break;
					
			    	case (2):
			    		Servicios:
						system("cls");
						cout<<setw(40)<<"Lista de Servicios"<<endl;						 		
			    		cout<<"1)Mostar Lista"<<endl<<"2)Agregar nuevo producto"<<endl<<"3)Modificar Servicios"<<endl<<"4)Eliminar Servicios"<<endl<<"5)Regresar"<<endl;
			    		cout<<"Opcion deseada:  ";
							op=0;
							getline(cin, OP);
					        if( !val.isInteger( OP ) )
					        {
					            cout << "Ingresa solo numeros...\n";
								Sleep(800);
					        }
					        else{
					        	op=atoi(OP.c_str());
					        }
					        
					    	switch(op){
					    			case(1):
					    				system("cls");
									suc.getLista_Servicios();
									
									fflush(stdin);
									char c;
									c = getchar();
									while(c != '\n'){
									c = getchar();
									goto Servicios;
								break;
								} 
								goto Servicios;
									
					    			case(2):
					    				system("cls");
									suc.agregarservicios();
									goto Servicios;
									break;
									
					    			case(3):
					    				system("cls");
									suc.modificarservicio();
									goto Servicios;
									Sleep(1000);break;
									
									case(4):
										system("cls");
										suc.eliminarservicio();
										goto Servicios;
										Sleep(1000);
										break;
									
									case(5):
									goto Menu2;
									
									default:
									goto Servicios;
					    		}
					break;
					
					
			    	case (3):
			    		Almacen:
			    		system("cls");
						cout<<setw(40)<<"Almacen"<<endl;
						cout<<"1)Mostar Datos"<<endl<<"2)Agregar Producto"<<endl<<"3)Borrar Producto"<<endl<<"4)Modificar Producto"<<endl<<"5)Regresar"<<endl;
						cout<<"Opcion deseada:  ";
							op=0;
							getline(cin, OP);
					        if( !val.isInteger( OP ) )
					        {
					            cout << "Enter Numbers only...\n";
								Sleep(800);
					        }
					        else{
					        	op=atoi(OP.c_str());
					        }
			    		switch(op){
			    				case(1):
			    					system("cls");
								alm.mostrardatos();
								
									fflush(stdin);
									char c;
									c = getchar();
									while(c != '\n'){
									c = getchar();
									goto Almacen;
								break;
								} 
								goto Almacen;
								break;
			    				
								case(2):
			    					system("cls");
								adm.agregar_producto();
								goto Almacen;
								break;
			    				case(3):
			    					system("cls");
								adm.eliminar_producto();
								goto Almacen;
								break;
								case(4):
									op=0;
									MenuAlm:system("cls");
									
									cout<<"Modificar\n1)Precio\n2)Existencia\n3)Regresar"<<endl;
									cout<<"Opcion Deseada:  ";
										op=0;
										getline(cin, OP);
								        if( !val.isInteger( OP ) )
								        {
								            cout << "Ingresa solo numeros...\n";
											Sleep(800);
								        }
								        else{
								        	op=atoi(OP.c_str());
								        }
									switch(op){
										case(1):
											system("cls");
											adm.cambiar_precio();
											goto MenuAlm;
											break;
										case(2):
											system("cls");
											adm.cambiar_existencia();
											goto MenuAlm;
											break;
										case(3):
										goto Almacen;
											break;
										default:
										system("cls");
										goto MenuAlm;	
									}
								
								case(5):
								goto Menu2;
								default:
								cout<<"Opcion Incorrecta";
								goto Almacen;
								break;
			    		}
			    	break;               
			    	case (4):
			    		Empleado:
			    			system("cls");
			    		cout<<setw(40)<<"Empleados"<<endl;	
						cout<<"1)Mostar nomina"<<endl<<"2)Mostar Usuarios Sistema"<<endl<<"3)Elimiar Usuario Nomina"<<endl<<"4)Crear Usuario Nomina"<<endl<<"5)Crear Usuario Sistema"<<endl<<"6)Eliminar Usuario Sistema"<<endl<<"7)Regresar\n";
						cout<<"Opcion Deseada:  ";
							op=0;
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
						switch(op){
							case(1):
							system("cls");
							adm.mostrardatos();
							fflush(stdin);
									char c1;
									c1 = getchar();
									while(c1 != '\n'){
									c1 = getchar();
									goto Empleado;
								break;
								} 
								goto Empleado;
							
							break;
							case(2):
								system("cls");
							adm.mostrarusuarios();
							fflush(stdin);
									char c2;
									c2 = getchar();
									while(c2 != '\n'){
									c2 = getchar();
									goto Empleado;
								break;
								} 
								goto Empleado;
							
								break;
							case(3):
								system("cls");
							adm.baja_empleadonomina();
							Sleep(1000);
							goto Empleado;
							break;
							case(4):
								system("cls");
							adm.alta_empleadonomina();
							Sleep(1000);
							goto Empleado;
							break;
							case(5):
								system("cls");
							adm.altaUsuario();
							Sleep(1000);
							goto Empleado;
								break;
							case(6):
								system("cls");
								adm.bajaUsuario();
								Sleep(1000);
								goto Empleado;			
								
								break;
							case(7):
								goto Menu2;
								
							default:
								goto Empleado;
								
						}
					break;
					
					case(5):	system("cls");
								cout<<"Su salario es: "<<sue.generarpago(2);
								Sleep(1000);
								goto Menu2;
								break;
					
					case(6):
						
						
						Cons:
						system("cls");
						cout<<"1)Consultar Consultorios\n2)Nuevo Consultorio\n3)Regresar"<<endl;
						cout<<"Opcion deseada:  ";
							op=0;
							getline(cin, OP);
					        if( !val.isInteger( OP ) )
					        {
					            cout << "Ingresa solo numeros...\n";
								Sleep(800);
					        }
					        else{
					        	op=atoi(OP.c_str());
					        }
						switch(op){
							case(1):
								system("cls");
								cons.mostrarDatos();
								fflush(stdin);
									char c2;
									c2 = getchar();
									while(c2 != '\n'){
									c2 = getchar();
									goto Cons;
								break;
								} 
								goto Cons;
						
									break;
									
							case(2):
								cons.setDatos();
								system("cls");
								goto Cons;
							break;
						    case(3):
						    	system("cls");
						    	goto Menu2;
						    	break;
							default:
								cout<<"Opcion incorrecta";
								Sleep(1000);
								goto Cons;
								break;
						}
						break;
					
					
					case(7): goto Menu;
						break;
					
					default:
						cout<<"Opcion incorrecta";
						Sleep(1000);
						goto Menu2;
						break;
			    }
			
				break;
			}
			else{ goto Trabajador;
			}
				
			    case(3)://Asistente
			    
			    if(emp.identificarse(op)==1){
			    
			    cout<<setw(40)<<"Asistente"<<endl;	
			    Asistente:
					
						cout<<setw(40)<<"Asistente"<<endl;		
						for(;;){system("cls");
			    cout<<"1)Crear Cita\n2)Cancelar Cita\n3)Mostar Cita\n4)Salario\n5)Regresar"<<endl;
			    cout<<"Opcion Deseada:  ";
					op=0;
						getline(cin, OP);
				        if( !val.isInteger( OP ) )
				        {
				            cout << "Ingresa solo numeros...\n";
							Sleep(800);
				        }
				        else{
				        	op=atoi(OP.c_str());
				        	break;
				        }}
						switch(op){
							case(1):
								 system("cls");
								asi.crear_cita();
								goto Asistente;
								break;
							case(2):
								 system("cls");
								asi.cancelar_cita();
								goto Asistente;
								break;
								
							case(3):
								 system("cls");
								vet.revisar_cita();
								fflush(stdin);
									char c;
									c = getchar();
									while(c != '\n'){
									c = getchar();
									goto Asistente;
								break;
								} 
							goto Asistente;
							break;
							case(4):
								system("cls");
								cout<<"Su salario es: "<<sue.generarpago(3);
								Sleep(1000);
								goto Asistente;
								break;
								
							case(5):
								goto Menu;
								break;
								
							default:cout<<"Opcion incorrecta"<<endl;
							Sleep(1000);
							goto Asistente;
						}
				
				
				
	break;			}
			    else{ goto Trabajador;
			    }
			    
			    case(4):
			    	goto Menu;
			    default: cout<<endl<<"Opcion incorrecta";
			    Sleep(1000);
			   goto Trabajador;
			    
			}
		//Acceso Denegado	
			
	break;
	
case(3):
      	break;
default:
	cout<<"Opcion Incorrecta"<<endl;
			Sleep(800);
			break;
			
}
} while (op!=3);	
	
}
			
			break;//Fin español




//---------------------------------------------------------------Ingles------------------------------------------------------------------
case(2):

SetConsoleTitle("Veterinary Clinic System");
	
	suc.mostrardatos();          
                                //muestra los datos de la sucursal veterinaria

	
  if (hConWnd)
  {
    // select a bitmap file you have or use one of the files in the Windows folder
    // filename, handle, ID, ulcX, ulcY, width, height   0,0 auto-adjusts
	  BCX_Bitmap("C:\\Windows\\G.bmp",hConWnd,123,830,460,280,140);

    
  
	
	int no;
	 do   // mantenerse en el menu hasta q el usuario quera salir salir
    {
	Menu22:    
                                                      //MENU 1
	system("cls");
	suc2.mostrardatos();
	cout<<endl<<endl;
	cout<<"USER MENU"<<endl;
	cout<<"1) Customer\n2) Employee\n3) Exit"<<endl;
	cout<<endl<<"Choose an option:  ";
	op=0;
	getline(cin, OP);
        if( !val2.isInteger( OP ) )
        {
            cout << "Enter Numbers only...\n";
			Sleep(800);
        }
        else{
        	op=atoi(OP.c_str());
        }
        	
	cout<<endl<<endl;
	switch(op){
	   case(1)://cliente
	   Cliente2:
	   	system("cls");
		cout<<setw(50)<<"CUSTOMER MENU: \n"<<endl;		
		cout<<endl<<endl<<"1)New Customer\n2)Existing Customer\n3)Return"<<endl;
		cout<<endl<<"Enter a type of member  ";
		getline(cin, OP);
	      op=0;  
		  if( !val2.isInteger( OP ) )
	        {
	            cout << "Enter Numbers only...\n";
				Sleep(800);
	        }
	        else{
	        	op=atoi(OP.c_str());
	        }
			switch(op){
				case(1):
					system("cls");
					cli2.nuevocliente();
					Sleep(1000);
					goto Cliente2;
					break;
				case(2):
				system("cls");
					for(;;){
					cout<<endl<<"Enter your Customer number:  ";
					int num;
					op=0;
					getline(cin,OP);
					if( !val2.isInteger( OP ) )
				        {
				            cout << "Enter Numbers only...\n";
							system("cls");
							Sleep(800);
							
							
				        }
				        else{
				        	op=atoi(OP.c_str());
				        	num=op;
				        	break;
				        }}
					
					if(cli2.identificarse(op)==1){
					
						int op2=op;
						Socio2:
							
						system("cls");
						cout<<setw(40)<<"Customer No."<<op2<<endl;
						num=op2;
						cout<<endl<<"1)Check Medical History"<<endl<<"2)Appointment Request"<<endl<<"3)Cancel Appointment"<<endl<<"4)Consulting offices"<<endl<<"5)Change password"<<endl<<"6)Return"<<endl;
						cout<<"Choose an option:  ";
							op=0;
							getline(cin, OP);
					        if( !val2.isInteger( OP ) )
					        {
					            cout << "Enter Numbers only...\n";
								Sleep(800);
					        }
					        else{
					        	op=atoi(OP.c_str());
					        }
						switch(op){
							case(1):
							system("cls");
									his2.consultarhistorial(num);
									fflush(stdin);
									char c;
									c = getchar();
									while(c != '\n'){
									c = getchar();
									goto Socio2;
								break;
								} 
								goto Socio2;
								break;
							case(2):
								system("cls");
								asi2.crear_cita(num);
								goto Socio2;
								break;
							case(3):
								system("cls");
							asi2.cancelar_cita(num);
								Sleep(800);
								goto Socio2;
								break;
							case(4):
								system("cls");
								cons2.mostrarDatos();
								fflush(stdin);
									char c2;
									c2 = getchar();
									while(c2 != '\n'){
									c2 = getchar();
									goto Socio2;
								break;
								} 
								goto Socio2;
								
								case(5):
									system("cls");
								cli2.cambiar_contra(num);
								goto Socio2;
								break;
								
								case(6):
								goto Cliente2;
								break;
							default:
									cout<<"Incorrect Option";
									Sleep(1000);
									goto Socio2;
									break;
						}
						
					}
					else{
					cout<<"You are not registered"<<endl;
					Sleep(1000);	
					goto Cliente2;
					}
										
					goto Cliente2;
					break;
					
				case(3):goto Menu22;
				break;
				default: cout<<"Incorrect Option"<<endl;
				Sleep(1000);
				goto Cliente2; break;	
		}
	break;                                                         // final opcion CLIENTE
		
		
	
	case(2):                                                       //opcion TRABAJADOR
	Trabajador2:	
	system("cls");
	cout<<"Type of worker:\n\n1)Veterinarian\n2)Administrator\n3)Assistant\n4)Return"<<endl<<endl;
	cout<<"Choose an option:  ";
	 op=0;
	      getline(cin, OP);
	        if( !val2.isInteger( OP ) )
	        {
	            cout << "Enter Numbers only...\n";
				Sleep(800);
	        }
	        else{
	        	op=atoi(OP.c_str());
        	}
			switch(op){
				case(1):			//Veterinario
				if(emp2.identificarse(op)==1){
					
					MenuVet2:
						
						
						for(;;){
							system("cls");
						cout<<setw(40)<<"Veterinarian"<<endl<<endl;
					cout<<endl<<"1)Medical History"<<endl<<"2)Check Appointments"<<endl<<"3)Journal"<<endl<<"4)Check salary "<<endl<<"5)Prescription"<<endl<<"6)Return"<<endl;
					cout<<"Choose an option:  ";
					op=0;
						getline(cin, OP);
				        if( !val2.isInteger( OP ) )
				        {
				            cout << "Enter Numbers only...\n";
							Sleep(800);
				        }
				        else{
				        	op=atoi(OP.c_str());
				        	break;
				        }}
					switch(op){
					case(1):
					Histo2:
					system("cls");
					cout<<setw(40)<<"Medical History"<<endl<<endl;
					
						
						cout<<endl<<endl<<"1)Create Medical History"<<endl<<"2)Display Medical History"<<endl<<"3)Update Medical History"<<endl<<"4)Return"<<endl;
							cout<<"Choose an option:  ";
								op=0;
								getline(cin, OP);
						        if( !val2.isInteger( OP ) )
						        {
						            cout << "Enter Numbers only...\n";
									Sleep(800);
						        }
						        else{
						        	op=atoi(OP.c_str());
						        }
							switch(op){
								case(1):
									system("cls");
									his2.crearHistoria();
									Sleep(1000);
									goto Histo2;
									break;
								case(2):
									system("cls");
									his2.consultarhistorial();
									fflush(stdin);
									char c;
									c = getchar();
									while(c != '\n'){
									c = getchar();
									goto Histo2;
								break;
								} 
								goto Histo2;
								
								
								case(3):
									system("cls");
									his2.capturadatos();
									goto Histo2;
									break;
								case(4):
									system("cls");
									goto MenuVet2;
									break;
								default: cout<<"Option not available"<<endl;
								Sleep(1000);
								goto Histo2;	
									}
							break;
					case(2):
						system("cls");
						cout<<setw(40)<<"Appointments"<<endl<<endl;
						
						vet2.revisar_cita();
								fflush(stdin);
									char c;
									c = getchar();
									while(c != '\n'){
									c = getchar();
									goto MenuVet2;
								break;
								} 
								goto MenuVet2;
						break;
					case(3):
						
						cout<<setw(40)<<"Journal"<<endl<<endl;
						Registro2:
						system("cls");
						cout<<"1)Create Journal\n2)Make Journal\n3)Return"<<endl;
						cout<<"Choose an option:  ";
							op=0;
							getline(cin, OP);
					        if( !val2.isInteger( OP ) )
					        {
					            cout << "Enter Numbers only...\n";
								Sleep(800);
					        }
					        else{
					        	op=atoi(OP.c_str());
					        }
						switch(op){
							case(1):
								system("cls");
								reg2.crearRegistro();
								Sleep(1000);
								goto Registro2;
								break;
							case(2):
								system("cls");
								reg2.agregarRegistro();
								Sleep(1000);
								goto Registro2;
								break;
							case(3):
								system("cls");
								goto MenuVet2;
								break;
							default:
								cout<<"Option not available"<<endl;
								Sleep(1000);
								goto Registro2;
								break;
						}
						goto MenuVet2;
						break;
						
					case(4):
								system("cls");
								cout<<"Your salary is: "<<sue2.generarpago(1);
								Sleep(1000);
								goto MenuVet2;
								break;	
						
					case(5):
								vet2.crear_receta();
								Sleep(1000);
								goto MenuVet2;
								break;		
						
					case(6):
						goto Trabajador2;
					break;	
					default: cout<<"Option not available"<<endl;
					Sleep(1000);
					goto MenuVet2;
					break;
					}
				
				break;
			}
			else {goto Trabajador2; 
			}
				
				
			    case(2):			//Administrador
			    if(emp2.identificarse(op)==1){
			      
				Menu222:
				
					
						for(;;){
							system("cls");
				cout<<setw(40)<<"Administrator"<<endl;
				cout<<"1)Store data"<<endl<<"2)Services list"<<endl<<"3)Stock"<<endl<<"4)Staff"<<endl<<"5)Salary"<<endl<<"6)Offices"<<endl<<"7)Return"<<endl;
				cout<<"Choose an option:  ";
					op=0;
						getline(cin, OP);
				        if( !val2.isInteger( OP ) )
				        {
				            cout << "Enter Numbers only...\n";
							Sleep(800);
				        }
				        else{
				        	op=atoi(OP.c_str());
				        	break;
				        }}
			    switch(op){
			    	case (1):
			    		Tienda2:
			    		system("cls");
						cout<<setw(40)<<"Store data"<<endl<<endl;
						cout<<"1)Show data"<<endl<<"2)Modify data"<<endl<<"3)Return"<<endl;
						cout<<"Choose an option:  ";
							op=0;
							getline(cin, OP);
					        if( !val2.isInteger( OP ) )
					        {
					            cout << "Enter Numbers only...\n";
								Sleep(800);
					        }
					        else{
					        	op=atoi(OP.c_str());
					        }
					    	
							switch(op){
					    			case(1):
					    			system("cls");
									suc2.mostrardatos();
									fflush(stdin);
									char c;
									c = getchar();
									while(c != '\n'){
									c = getchar();
									goto Tienda2;
								break;
								} 
								goto Tienda2;
									
					    			case(2):
									system("cls");
									suc2.editardatos();
									goto Tienda2;
									break;
									case(3):
									goto Menu222;
									default:
										goto Tienda2;
										break;
					    		}
					break;
					
			    	case (2):
			    		Servicios2:
						system("cls");
						cout<<setw(40)<<"Services list"<<endl;						 		
			    		cout<<"1)Show list"<<endl<<"2)Add service"<<endl<<"3)Modify service"<<endl<<"4)Erase service"<<endl<<"5)Return"<<endl;
			    		cout<<"Choose an option:  ";
							op=0;
							getline(cin, OP);
					        if( !val2.isInteger( OP ) )
					        {
					            cout << "Enter Numbers only...\n";
								Sleep(800);
					        }
					        else{
					        	op=atoi(OP.c_str());
					        }
					        
					    	switch(op){
					    			case(1):
					    				system("cls");
									suc2.getLista_Servicios();
									
									fflush(stdin);
									char c;
									c = getchar();
									while(c != '\n'){
									c = getchar();
									goto Servicios2;
								break;
								} 
								goto Servicios2;
									
					    			case(2):
					    				system("cls");
									suc2.agregarservicios();
									goto Servicios2;
									break;
									
					    			case(3):
					    				system("cls");
									suc2.modificarservicio();
									goto Servicios2;
									Sleep(1000);break;
									
									case(4):
										system("cls");
										suc2.eliminarservicio();
										goto Servicios2;
										Sleep(1000);
										break;
									
									case(5):
									goto Menu222;
									
									default:
									goto Servicios2;
					    		}
					break;
					
					
			    	case (3):
			    		Almacen2:
			    		system("cls");
						cout<<setw(40)<<"Stock"<<endl;
						cout<<"1)Show stock"<<endl<<"2)Add product"<<endl<<"3)Erase product"<<endl<<"4)Modify product"<<endl<<"5)Return"<<endl;
						cout<<"Choose an option:  ";
							op=0;
							getline(cin, OP);
					        if( !val2.isInteger( OP ) )
					        {
					            cout << "Enter Numbers only...\n";
								Sleep(800);
					        }
					        else{
					        	op=atoi(OP.c_str());
					        }
			    		switch(op){
			    				case(1):
			    					system("cls");
								alm2.mostrardatos();
								
									fflush(stdin);
									char c;
									c = getchar();
									while(c != '\n'){
									c = getchar();
									goto Almacen2;
								break;
								} 
								goto Almacen2;
								break;
			    				
								case(2):
			    					system("cls");
								adm2.agregar_producto();
								goto Almacen2;
								break;
			    				case(3):
			    					system("cls");
								adm2.eliminar_producto();
								goto Almacen2;
								break;
								case(4):
									op=0;
									MenuAlm2:system("cls");
									
									cout<<"Modify\n1)Price\n2)Existence\n3)Return"<<endl;
									cout<<"Choose an option:  ";
										op=0;
										getline(cin, OP);
								        if( !val2.isInteger( OP ) )
								        {
								            cout << "Enter Numbers only...\n";
											Sleep(800);
								        }
								        else{
								        	op=atoi(OP.c_str());
								        }
									switch(op){
										case(1):
											system("cls");
											adm2.cambiar_precio();
											goto MenuAlm2;
											break;
										case(2):
											system("cls");
											adm2.cambiar_existencia();
											goto MenuAlm2;
											break;
										case(3):
										goto Almacen2;
											break;
										default:
										system("cls");
										goto MenuAlm2;	
									}
								
								case(5):
								goto Menu222;
								default:
								cout<<"Incorrect Option";
								goto Almacen2;
								break;
			    		}
			    		
			    		
					break;
			    	case (4):
			    		Empleado2:
			    			system("cls");
			    		cout<<setw(40)<<"Staff"<<endl;	
						cout<<"1)Show Payroll"<<endl<<"2)Show Users"<<endl<<"3)Erase employee in Payroll"<<endl<<"4)Create employee in Payroll"<<endl<<"5)Create User"<<endl<<"6)Erase user"<<endl<<"7)Return\n";
						cout<<"Choose an option:  ";
							op=0;
							for(;;){getline(cin, OP);
					        if( !val2.isInteger( OP ) )
					        {
					            cout << "Enter Numbers only...\n";
								Sleep(800);
					        }
					        else{
					        	op=atoi(OP.c_str());
					        	break;
					        }}
						switch(op){
							case(1):
							system("cls");
							adm2.mostrardatos();
							fflush(stdin);
									char c1;
									c1 = getchar();
									while(c1 != '\n'){
									c1 = getchar();
									goto Empleado2;
								break;
								} 
								goto Empleado2;
							
							break;
							case(2):
								system("cls");
							adm2.mostrarusuarios();
							fflush(stdin);
									char c2;
									c2 = getchar();
									while(c2 != '\n'){
									c2 = getchar();
									goto Empleado2;
								break;
								} 
								goto Empleado2;
							
								break;
							case(3):
								system("cls");
							adm2.baja_empleadonomina();
							Sleep(1000);
							goto Empleado2;
							break;
							case(4):
								system("cls");
							adm2.alta_empleadonomina();
							Sleep(1000);
							goto Empleado2;
							break;
							case(5):
								system("cls");
							adm2.altaUsuario();
							Sleep(1000);
							goto Empleado2;
								break;
							case(6):
								system("cls");
								adm2.bajaUsuario();
								Sleep(1000);
								goto Empleado2;			
								
								break;
							case(7):
								goto Menu222;
								
							default:
								goto Empleado2;
								
						}
					break;
					
					case(5):	system("cls");
								cout<<"Your salary is: "<<sue2.generarpago(2);
								Sleep(1000);
								goto Menu222;
								break;
					
					case(6):
						
						
						Cons2:
						system("cls");
						cout<<"1)Consult BD\n2)New office\n3)Return"<<endl;
						cout<<"Choose an option:  ";
							op=0;
							getline(cin, OP);
					        if( !val2.isInteger( OP ) )
					        {
					            cout << "Enter Numbers only...\n";
								Sleep(800);
					        }
					        else{
					        	op=atoi(OP.c_str());
					        }
						switch(op){
							case(1):
								system("cls");
								cons2.mostrarDatos();
								fflush(stdin);
									char c2;
									c2 = getchar();
									while(c2 != '\n'){
									c2 = getchar();
									goto Cons2;
								break;
								} 
								goto Cons2;
						
									break;
									
							case(2):
								cons2.setDatos();
								system("cls");
								goto Cons2;
							break;
						    case(3):
						    	system("cls");
						    	goto Menu222;
						    	break;
							default:
								cout<<"Incorrect option";
								Sleep(1000);
								goto Cons2;
								break;
						}
						break;
					
					
					case(7): goto Menu22;
						break;
					
					default:
						cout<<"Incorrecto option";
						Sleep(1000);
						goto Menu222;
						break;
			    }
			
				break;
			}
			else{ goto Trabajador2;
			}
				
			    case(3)://Asistente
			    
			    if(emp2.identificarse(op)==1){
			    
			    cout<<setw(40)<<"Assistant"<<endl;	
			    Asistente2:
					
						cout<<setw(40)<<"Assistant"<<endl;		
						for(;;){system("cls");
			    cout<<"1)Create appointment\n2)Cancel appointment\n3)Show appointment\n4)Salary\n5)Return"<<endl;
			    cout<<"Choose an option:  ";
					op=0;
						getline(cin, OP);
				        if( !val2.isInteger( OP ) )
				        {
				            cout << "Enter Numbers only...\n";
							Sleep(800);
				        }
				        else{
				        	op=atoi(OP.c_str());
				        	break;
				        }}
						switch(op){
							case(1):
								 system("cls");
								asi2.crear_cita();
								goto Asistente2;
								break;
							case(2):
								 system("cls");
								asi2.cancelar_cita();
								goto Asistente2;
								break;
								
							case(3):
								 system("cls");
								vet2.revisar_cita();
								fflush(stdin);
									char c;
									c = getchar();
									while(c != '\n'){
									c = getchar();
									goto Asistente2;
								break;
								} 
							goto Asistente2;
							break;
							case(4):
								system("cls");
								cout<<"Your salary is: "<<sue2.generarpago(3);
								Sleep(1000);
								goto Asistente2;
								break;
								
							case(5):
								goto Menu22;
								break;
								
							default:cout<<"Incorrect option"<<endl;
							Sleep(1000);
							goto Asistente2;
						}
				
				
				
	break;			}
			    else{ goto Trabajador2;
			    }
			    
			    case(4):
			    	goto Menu22;
			    default: cout<<endl<<"Incorrect option";
			    Sleep(1000);
			   goto Trabajador2;
			    
			}
		//Acceso Denegado	
			
	break;//Fin Ingles
	
//-------------------------------------------------------------------Salir------------------------------------------------------------------------------------	
case(3):
      	break;
default:
	cout<<"Incorrect option"<<endl;
			Sleep(800);
			break;
			
}
} while (op!=3);	
	
}		
		
		
		
			break;
		case(3):
			cout<<"Hasta Luego/Good Bye"<<endl;
			break;
		default:
			cout<<"Opcion no disponible\nNo such option";
			break;
		goto Inicio;
	}


	
}







HWND BCX_Bitmap(char* Text,HWND hWnd,int id,int X,int Y,int W,int H,int Res,int Style,int Exstyle)
{
  HWND A;
  HBITMAP hBitmap;
  
  // set default style
  if (!Style) Style = WS_CLIPSIBLINGS|WS_CHILD|WS_VISIBLE|SS_BITMAP|WS_TABSTOP;
  
  // form for the image
  A = CreateWindowEx(Exstyle,"static",NULL,Style,X,Y,0,0,hWnd,(HMENU)id,GetModuleHandle(0),NULL);
                      
  // Text contains filename
  hBitmap=(HBITMAP)LoadImage(0,Text,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
  // auto-adjust width and height
  if (W || H) hBitmap = (HBITMAP)CopyImage(hBitmap,IMAGE_BITMAP,W,H,LR_COPYRETURNORG);
  SendMessage(A,(UINT)STM_SETIMAGE,(WPARAM)IMAGE_BITMAP,(LPARAM)hBitmap);
  if (W || H) SetWindowPos(A,HWND_TOP,X,Y,W,H,SWP_DRAWFRAME);
  return A;
}
// tricking Windows just a little ...
HWND GetConsoleWndHandle(void)
{
  HWND hConWnd;
  OSVERSIONINFO os;
  char szTempTitle[64], szClassName[128], szOriginalTitle[1024];
  os.dwOSVersionInfoSize = sizeof( OSVERSIONINFO );
  GetVersionEx( &os );
  // may not work on WIN9x
  if ( os.dwPlatformId == VER_PLATFORM_WIN32s ) return 0;
  GetConsoleTitle( szOriginalTitle, sizeof ( szOriginalTitle ) );
  sprintf( szTempTitle,"%u - %u", GetTickCount(), GetCurrentProcessId() );
  SetConsoleTitle( szTempTitle );
  Sleep( 40 );
  // handle for NT and XP
  hConWnd = FindWindow( NULL, szTempTitle );
  SetConsoleTitle( szOriginalTitle );
  // may not work on WIN9x
  if ( os.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS )
  {
    hConWnd = GetWindow( hConWnd, GW_CHILD );
    if ( hConWnd == NULL ) return 0;
    GetClassName( hConWnd, szClassName, sizeof ( szClassName ) );
    // while ( _stricmp( szClassName, "ttyGrab" ) != 0 )
    while ( strcmp( szClassName, "ttyGrab" ) != 0 )
    {
      hConWnd = GetNextWindow( hConWnd, GW_HWNDNEXT );
      if ( hConWnd == NULL ) return 0;
      GetClassName( hConWnd, szClassName, sizeof( szClassName ) );
    }
  }
  return hConWnd;
}


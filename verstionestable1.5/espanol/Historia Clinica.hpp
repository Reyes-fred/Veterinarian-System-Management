#include<iostream>
#include<fstream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\espanol\validar.hpp"
using namespace std;
class Historia_Clinica {
private:
	string Tipo_enfermedad;
	string Fecha_enfermedad;
	string Tipo_Vacuna;
	string Fecha_Vacuna;
	string Tratamiento;
	string Folio;
	validar val;

public:
	Historia_Clinica(string Tipo_enfermedad,string Fecha_enfermedad,string Tipo_Vacuna,string Fecha_Vacuna,string Tratamiento,string Folio){
		this->Tipo_enfermedad=Tipo_enfermedad;
		this->Fecha_enfermedad=Fecha_enfermedad;
		this->Tipo_Vacuna=Tipo_Vacuna;
		this->Fecha_Vacuna=Fecha_Vacuna;
		this->Tratamiento=Tratamiento;
		this->Folio=Folio;
	}
	
	void crearHistoria(){
		
		char nom[6][30]={"Nombre","Raza","Sexo(F/M)","Peso(Kg)","Especie","Edad"};
		char no[30];
		for(;;){
		cout<<"No.Cliente: "<<endl;
		cin>>no;
		if( !val.isCharnum( no ) )
				        {
				            cout << "Ingresa solo numeros...\n";
							Sleep(800);system("cls");
				        }
				        else{
				        	strcat(no,"-His.txt");
				        	break;
				        }
	}
		int i=0;
		string linea;
		ifstream archivo(no); 
     if (!archivo)
    {
		ofstream archivo(no);
		if(archivo.is_open()){
			archivo<<"Nombre"<<setw(10)<<"Raza"<<setw(10)<<"Sexo"<<setw(10)<<"Peso"<<setw(10)<<"Especie"<<setw(10)<<"Edad"<<endl;
			fflush(stdin);
			while(i<6){
				fflush(stdin);
				if(i==0||i==1||i==4){	
				cout<<nom[i]<<" Mascota:  ";
				for(;;){
				getline(cin, linea);
				if(val.isVacio(linea)==true){
				if(!val.isString( linea ))
				{
				cout << "Ingresa solo letras...\n";
				Sleep(800);
					}
				else{
				archivo<<linea<<setw(10);
				break;
			    }}}}
			    
			    if(i==2){
								
				cout<<nom[i]<<" Mascota:  ";
					for(;;){
				getline(cin, linea);
				if(val.isVacio(linea)==true){
				if(!val.isString( linea ))
				{
				cout << "Ingresa solo letras...\n";
				Sleep(800);
					}
				else{
					if(linea.compare("M")==0||linea.compare("F")==0){
				archivo<<linea<<setw(10);
					break;}
				else{cout<<"Ingresa un sexo valido...\n";
				}
			
			    }}	
			    }}
			    
			    if(i==3){
			    cout<<nom[i]<<" Mascota:  ";
			    	for(;;){
				getline(cin, linea);
				int num;
				num=atoi(linea.c_str());
				if(val.isVacio(linea)==true){
				if(!val.isInteger( linea ))
				{
				cout << "Ingresa solo numeros...\n";
				Sleep(800);
					}
				else{
					if(num>0&&num<300){
				archivo<<linea<<setw(10);break;}
				else cout<<"Ingresa un peso valido\n";
				
			    }}
				
			    }}
			    
			     if(i==5){
			    cout<<nom[i]<<" Mascota:  ";
			    	for(;;){
				getline(cin, linea);
				int num;
				num=atoi(linea.c_str());
				if(val.isVacio(linea)==true){
				if(!val.isInteger( linea ))
				{
				cout << "Ingresa solo numeros...\n";
				Sleep(800);
					}
				else{
					if(num>1&&num<90){
				archivo<<linea<<endl;	break;}
				else cout<<"Ingresa una edad valida\n";
			
			    }}
			}
			    }
			       
				
				
				i++;
				cout<<endl;
				}
			    		
			cout<<setw(40)<<"Creado con Exito"<<endl;
					}
		archivo.close();
	}
	else{
	cout<<"Historial Medico ya Existente";}
	
	}
	
	
	
	
	
	void capturadatos(){
		int i=0;
		string linea;
		char no[30];
		char nom[5][30]={"Tipo de Enfermedad: ","Fecha Enfermedad: ","Tipo de Vacuna: ","Fecha Vacuan aplicada: ","Tratamiento: "};
		for(;;){
		cout<<"No.Cliente"<<endl;
		cin>>no;
		if( !val.isCharnum( no ) )
				        {
				            cout << "Ingresa solo numeros...\n";
							system("cls");
							Sleep(800);
				        }
				        else{
				             	break;}
				}
		strcat(no,"-His.txt");
		ifstream archivo(no); 
     if (!archivo)
    {
		cout<<"Ningun Historial Medico";
		Sleep(800);}
		

else{
ofstream archivo(no,ios::app);
		fflush(stdin);
		if(archivo.is_open()){
		while(i<5){
			if(i==0||i==2){
			for(;;){
				fflush(stdin);
				
				cout<<nom[i];
				getline(cin, linea);
				if(val.isVacio(linea)==true){
				if(!val.isString( linea ))
				{
				cout << "Solo letras...\n";
				Sleep(800);
					}
				else{
				archivo<<nom[i]<<endl<<setw(10)<<linea<<endl;
				break;
			    }}				
					}
					}
					
		if(i==4){
			
			cout<<nom[i];
			for(;;){	
				getline(cin, linea);
				if(val.isVacio(linea)==true){
				archivo<<nom[i]<<endl<<setw(10)<<linea<<endl;
				break;
			    }
				}				
					
			
		}			
					
		if(i==1||i==3) { 
		int op;
		for(;;){
				fflush(stdin);
				cout<<nom[i]<<"\nDia #: ";
				getline(cin, linea);
				if(val.isVacio(linea)==true){
				if(!val.isInteger( linea ))
				{
				cout << "Ingresa un dia correcto...\n";
				Sleep(800);
					}
				else{
				op=atoi(linea.c_str());
					if(op>0&&op<=31){
				archivo<<nom[i]<<endl<<setw(10)<<linea<<"/";
				break;}
				else{
					cout<<"Ingresa un dia correcto...\n";
				}
			    }}	  }
					
			for(;;){
				fflush(stdin);
				cout<<"\nMes: ";
				getline(cin, linea);
				if(val.isVacio(linea)==true){
				if(!val.isMes( linea ))
				{
				cout << "Ingresa un mes valido...\n";
				Sleep(800);
					}
				else{
				archivo<<linea<<"/";
				break;
			    }}		
					}
					
			for(;;){
				int ano;
				fflush(stdin);
				cout<<"\nAno: ";
				getline(cin, linea);
				ano=atoi(linea.c_str());
				if(val.isVacio(linea)==true){
				if(!val.isInteger( linea ))
				{
				cout << "Ingresa un año valido...\n";
				Sleep(800);
					}
				else{
					if(ano>=2012&&ano<3000){
				archivo<<linea<<endl;
				break;}
				else cout<<"Ingresa un año valido\n";
			    }}	
					}		
					
					}	
				i++;
					
				cout<<endl;
		}
		
		
		archivo<<endl<<"---------------------------------------------------------------------"<<endl;
		archivo.close();
		}
		}

	}
	
		
	void consultarhistorial(int num)
	{
		string linea;
		char no[30];
		itoa(num,no,10);
		strcat(no,"-His.txt");
		ifstream archivo(no);
		if(archivo.is_open()){
		cout<<endl<<setw(50)<<"Historial Medico "<<no<<endl<<endl;	
			while(archivo.good()){
				getline(archivo,linea);
				cout<<linea<<endl;
			}
			cout<<endl<<"-----------------------------------------------------------------------"<<endl;
			cout<<"Fin del archivo"<<endl;
		archivo.close();
		}
		else{
			cout<<"Ningun Historia Medico";
		}
		
	}
	
	
		void consultarhistorial()
	{
		string linea;
		char no[30];
		cout<<"No.Cliente:   ";
	
		for(;;){
				fflush(stdin);
				cin>>no;
				if(val.isCharVacio(no)==true){
				if(!val.isCharnum( no ))
				{
				cout << "Ingresa solo numeros...\n";
				Sleep(800);
					}
				else{
				break;}
			    }}
		strcat(no,"-His.txt");
		ifstream archivo(no);
		if(archivo.is_open()){
		cout<<endl<<setw(50)<<"Historial Medico"<<no<<endl<<endl;	
			while(archivo.good()){
				getline(archivo,linea);
				cout<<linea<<endl;
			}
		archivo.close();
		}
		else{
			cout<<"Ningun Historial Medico";
		}
		
	}
	

};


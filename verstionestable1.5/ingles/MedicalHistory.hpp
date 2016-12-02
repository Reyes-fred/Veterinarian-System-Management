#include<iostream>
#include<fstream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Validate.hpp"
using namespace std;
class MedicalHistory {
private:
	string Tipo_enfermedad;
	string Fecha_enfermedad;
	string Tipo_Vacuna;
	string Fecha_Vacuna;
	string Tratamiento;
	string Folio;
	Validate val;

public:
	MedicalHistory(string Tipo_enfermedad,string Fecha_enfermedad,string Tipo_Vacuna,string Fecha_Vacuna,string Tratamiento,string Folio){
		this->Tipo_enfermedad=Tipo_enfermedad;
		this->Fecha_enfermedad=Fecha_enfermedad;
		this->Tipo_Vacuna=Tipo_Vacuna;
		this->Fecha_Vacuna=Fecha_Vacuna;
		this->Tratamiento=Tratamiento;
		this->Folio=Folio;
	}
	
	void crearHistoria(){
		
		char nom[6][30]={"Name","Breed","Sex(F/M)","Weight(Kg)","Species","Years"};
		char no[30];
		for(;;){
		cout<<"No.Member: "<<endl;
		cin>>no;
		if( !val.isCharnum( no ) )
				        {
				            cout << "Enter Numbers only...\n";
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
			archivo<<"Name"<<setw(10)<<"Breed"<<setw(10)<<"Sex"<<setw(10)<<"Weight"<<setw(10)<<"Species"<<setw(10)<<"Years"<<endl;
			fflush(stdin);
			while(i<6){
				fflush(stdin);
				if(i==0||i==1||i==4){	
				cout<<nom[i]<<" Pet:  ";
				for(;;){
				getline(cin, linea);
				if(val.isVacio(linea)==true){
				if(!val.isString( linea ))
				{
				cout << "Enter Letter only...\n";
				Sleep(800);
					}
				else{
				archivo<<linea<<setw(10);
				break;
			    }}}}
			    
			    if(i==2){
								
				cout<<nom[i]<<" Pet:  ";
					for(;;){
				getline(cin, linea);
				if(val.isVacio(linea)==true){
				if(!val.isString( linea ))
				{
				cout << "Enter Letter only...\n";
				Sleep(800);
					}
				else{
					if(linea.compare("M")==0||linea.compare("F")==0){
				archivo<<linea<<setw(10);
					break;}
				else{cout<<"Enter a correct gender...\n";
				}
			
			    }}	
			    }}
			    
			    if(i==3){
			    cout<<nom[i]<<" Pet:  ";
			    	for(;;){
				getline(cin, linea);
				int num;
				num=atoi(linea.c_str());
				if(val.isVacio(linea)==true){
				if(!val.isInteger( linea ))
				{
				cout << "Enter numbers only...\n";
				Sleep(800);
					}
				else{
					if(num>0&&num<300){
				archivo<<linea<<setw(10);break;}
				else cout<<"Enter a correct weight\n";
				
			    }}
				
			    }}
			    
			     if(i==5){
			    cout<<nom[i]<<" Pet:  ";
			    	for(;;){
				getline(cin, linea);
				int num;
				num=atoi(linea.c_str());
				if(val.isVacio(linea)==true){
				if(!val.isInteger( linea ))
				{
				cout << "Enter numbers only...\n";
				Sleep(800);
					}
				else{
					if(num>0&&num<90){
				archivo<<linea<<endl;	break;}
				else cout<<"Enter a correct age\n";
			
			    }}
			}
			    }
			       
				
				
				i++;
				cout<<endl;
				}
			    		
			cout<<setw(40)<<"Medical history Successful"<<endl;
					}
		archivo.close();
	}
	else{
	cout<<"Medical History already exist";}
	
	}
	
	
	
	
	
	void capturadatos(){
		int i=0;
		string linea;
		char no[30];
		char nom[5][30]={"Type sickness: ","Date sickness: ","Type Vaccine: ","Applied vaccine Date: ","Treatment: "};
		for(;;){
		cout<<"No.Member"<<endl;
		cin>>no;
		if( !val.isCharnum( no ) )
				        {
				            cout << "Enter Numbers only...\n";
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
		cout<<"No medical history";
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
				cout << "Enter Letter only...\n";
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
				cout<<nom[i]<<"\nDay #: ";
				getline(cin, linea);
				if(val.isVacio(linea)==true){
				if(!val.isInteger( linea ))
				{
				cout << "Enter a correct day...\n";
				Sleep(800);
					}
				else{
				op=atoi(linea.c_str());
					if(op>0&&op<=31){
				archivo<<nom[i]<<endl<<setw(10)<<linea<<"/";
				break;}
				else{
					cout<<"Enter a correct day...\n";
				}
			    }}	  }
					
			for(;;){
				fflush(stdin);
				cout<<"\nMonth: ";
				getline(cin, linea);
				if(val.isVacio(linea)==true){
				if(!val.isMes( linea ))
				{
				cout << "Enter a correct month...\n";
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
				cout<<"\nYear: ";
				getline(cin, linea);
				ano=atoi(linea.c_str());
				if(val.isVacio(linea)==true){
				if(!val.isInteger( linea ))
				{
				cout << "Enter a correct year...\n";
				Sleep(800);
					}
				else{
					if(ano>=2012&&ano<3000){
				archivo<<linea<<endl;
				break;}
				else cout<<"Enter a correct year\n";
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
		cout<<endl<<setw(50)<<"Medical history "<<no<<endl<<endl;	
			while(archivo.good()){
				getline(archivo,linea);
				cout<<linea<<endl;
			}
			cout<<endl<<"-----------------------------------------------------------------------"<<endl;
			cout<<"End of file"<<endl;
		archivo.close();
		}
		else{
			cout<<"No medical history";
		}
		
	}
	
	
		void consultarhistorial()
	{
		string linea;
		char no[30];
		cout<<"No.Member:   ";
	
		for(;;){
				fflush(stdin);
				cin>>no;
				if(val.isCharVacio(no)==true){
				if(!val.isCharnum( no ))
				{
				cout << "Enter Numbers only...\n";
				Sleep(800);
					}
				else{
				break;}
			    }}
		strcat(no,"-His.txt");
		ifstream archivo(no);
		if(archivo.is_open()){
		cout<<endl<<setw(50)<<"Medical History "<<no<<endl<<endl;	
			while(archivo.good()){
				getline(archivo,linea);
				cout<<linea<<endl;
			}
		archivo.close();
		}
		else{
			cout<<"No Medical history";
		}
		
	}
	

};


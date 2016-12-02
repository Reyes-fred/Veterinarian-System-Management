#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Storage {
private:
	string lista_productos;

public:
	Storage(){
	ifstream archivo("Almacen.txt"); 
     if (!archivo)
    {
   ofstream archivo ("Almacen.txt");
   if(archivo.is_open()){
   	
	
   }
   archivo.close();
   }
	}
	
void mostrardatos(){
	cout<<"Name:"<<setw(20)<<"Product Name:"<<setw(20)<<"Price:"<<setw(20)<<"Existence:"<<endl;
	string linea;
	ifstream archivo("Almacen.txt");
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


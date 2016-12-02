#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Almacen {
private:
	string lista_productos;

public:
	Almacen(){
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
	cout<<"Nombre:"<<setw(20)<<"Nombre Producto:"<<setw(20)<<"Precio:"<<setw(20)<<"Existencia:"<<endl;
	string linea;
	ifstream archivo("Almacen.txt");
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
	

};


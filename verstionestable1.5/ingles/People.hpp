#include <iostream>
#if !defined(_PEOPLE_HPP)
#define _PEOPLE_HPP

using namespace std;

class People {	
private:
	string nombre;
	string direccion;
	string telefono;

public:
	People(string nombre,string direccion,string telefono){
		this->nombre=nombre;
		this->direccion=direccion;
		this->telefono=telefono;
	}
	string getDireccion(){
		return direccion;
	}
	string getNombre(){
		return nombre;
	}
	string getTelefono(){
		return telefono;
	}
	void setDireccion(string dir){
		direccion=dir;
	}
	void setNombre(string nom){
		nombre=nom;
	}
	void setTelefono(string tel){
		telefono=tel;
	}

};
#endif

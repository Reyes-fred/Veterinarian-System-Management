#include <iostream>
#if !defined(_PERSONA_HPP)
#define _PERSONA_HPP

using namespace std;

class Persona {	
private:
	string nombre;
	string direccion;
	string telefono;

public:
	Persona(string nombre,string direccion,string telefono){
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

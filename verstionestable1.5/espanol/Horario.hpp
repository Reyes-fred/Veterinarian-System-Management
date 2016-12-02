#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#if !defined(_HORARIO_HPP)
#define _HORARIO_HPP

using namespace std;

class Horario {
protected:
	string dias;
	string horas;
public:
	Horario(string dias,string horas){
		this->dias=dias;
		this->horas=horas;
	}
	
	void setHorario(string nuevo_Dias, string nueva_Horas)
		{
		dias=nuevo_Dias;
		horas=nueva_Horas;
		}

	
	string getdias(){
	return (dias);
	}
	string gethoras(){
	return (horas);
	}
};
#endif


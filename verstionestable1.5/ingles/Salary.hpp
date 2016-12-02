#include <iostream>
#include "C:\Users\Alfredo\Desktop\Proyectos\Veterinaria\verstionestable1.5\ingles\Validate.hpp"
#if !defined(_SALARY_H)
#define _SALARY_H

using namespace std;
class Salary {
private:
	string HORAS_TRA;
	int tipo_empleado;
	int horas_trabajadas;
	int sueldo;	
	Validate val;
	
public:
	Salary(int tipo_empleado,int horas_trabajadas,int sueldo){
		this->tipo_empleado=tipo_empleado;
		this->horas_trabajadas=horas_trabajadas;
		this->sueldo=sueldo;
	}
	int generarpago(int tipo){
		switch (tipo){
		case 1: //veterinario
		sueldo=100;
		for(;;){
			cout<<"Hours worked:  ";
			getline(cin, HORAS_TRA);
			if( !val.isInteger( HORAS_TRA ) )
			{
			cout << "Enter Numbers only...\n";
			Sleep(800);
			}
			 else{
			horas_trabajadas=atoi(HORAS_TRA.c_str());
			break;
			}}	
			
			return(sueldo*horas_trabajadas);
			break;
		case 2://administrador
		sueldo=100;
			for(;;){
			cout<<"Hours worked:  ";
			getline(cin, HORAS_TRA);
			if( !val.isInteger( HORAS_TRA ) )
			{
			cout << "Enter Numbers only...\n";
			Sleep(800);
			}
			 else{
			horas_trabajadas=atoi(HORAS_TRA.c_str());
			break;
			}}
			
			return(sueldo*horas_trabajadas);
			break;
		case 3://asistente
		return(150);
		 	break;
		default:
			break;
		}
		
	}
};

#endif  

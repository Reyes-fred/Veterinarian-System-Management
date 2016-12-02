#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>

#if !defined(_VALIDATE_HPP)
#define _VALIDATE_HPP
using namespace std;
class Validate{
private:


public:
    
	bool isInteger(string s)
{

    for( unsigned i=0; i<s.length(); ++ i )

    if( s[i] < '0' || s[i] > '9' ) return false;
    // else if reach here ...

    return true;

}

	bool isPrecio(string s)
{

 	 bool valid = true;
    float vf;

    if (s.length() == 0) {
        valid = false;
    } else {
//cannot have alphabet or characters
        for (int i = 0; i < s.length(); i++) {
            if (!isdigit(s[i])) {
                valid = false;
            }
            if(s[i]=='.')
            valid=true;
        }
    }
    vf = atof(s.c_str());

    return valid;

}



	bool isTelef(string s)
{ int ban=0;

    for( int i=0; i<s.length(); ++ i ){
	
    if( (s[i] < '0' || s[i] > '9') ) return false;
    ban++;}

    
   if(ban==7)
   {
   	return true;
   }
}


	bool isTelefChar(char s[])
{ int ban=0;

    for( int i=0; i<strlen(s); ++ i ){
	
    if( (s[i] < '0' || s[i] > '9') ) return false;
    ban++;}

    
   if(ban==7)
   {
   	return true;
   }
}


	bool isString(string s)
{

    for( unsigned i=0; i<s.length(); ++ i )

    if( (s[i] < 'A' || s[i] > 'Z') && (s[i]<'a' || s[i]>'z')) return false;
    // else if reach here ...

    return true;
  
}


	bool isNombre(string s)
{

   for( unsigned i=0; i<s.length(); ++ i )

    if( (s[i] < 'A' || s[i] > 'Z') && (s[i]<'a' || s[i]>'z')&& s[i]!=' ') return false;
    // else if reach here ...

    return true;
  
}

	bool isDia(string s)
{

    if(s.compare("Monday")==0||s.compare("monday")==0||s.compare("Tuesday")==0||s.compare("tuesday")==0||s.compare("Thursday")==0||s.compare("thursday")==0||s.compare("Wednesday")==0||s.compare("wednesday")==0||s.compare("Friday")==0||s.compare("friday")==0||s.compare("Saturday")==0||(s.compare("saturday")==0)
	||(s.compare("Sunday")==0)||(s.compare("sunday")==0)){ 
	 return true;}
    // else if reach here ...

    return false;
  
}

	bool isMes(string s)
{

    if(s.compare("January")==0||s.compare("january")==0||s.compare("February")==0||s.compare("february")==0||s.compare("March")==0||s.compare("march")==0||s.compare("April")==0||s.compare("april")==0||s.compare("May")==0||s.compare("may")==0||s.compare("June")==0||(s.compare("june")==0)
	||s.compare("July")==0||s.compare("july")==0||s.compare("August")==0||s.compare("august")==0||s.compare("September")==0||s.compare("september")==0||s.compare("Octobre")==0||s.compare("octobre")==0||s.compare("November")==0||s.compare("november")==0
	||s.compare("Diciembre")==0||s.compare("diciembre")==0){ 
	 return true;}
    // else if reach here ...

    return false;
  
}


	bool isCiudad(string s)
{

    if(s.compare("Aguascaliente")==0||s.compare("aguascaliente")==0||s.compare("Baja California")==0||s.compare("baja california")==0||s.compare("Baja California Sur")==0||s.compare("baja california sur")==0||s.compare("Campeche")==0||s.compare("campeche")==0||s.compare("Chiapas")==0||s.compare("chiapas")==0||s.compare("Chihuahua")==0||(s.compare("chihuahua")==0)
	||s.compare("Coahuila")==0||s.compare("coahuila")==0||s.compare("Colima")==0||s.compare("colima")==0||s.compare("Distrito Federal")==0||s.compare("distrito federal")==0||s.compare("Durango")==0||s.compare("durango")==0||s.compare("Estado de Mexico")==0||s.compare("estado de mexico")==0||s.compare("Guanajuato")==0||s.compare("guanajuato")==0||s.compare("Guerrero")==0
	||s.compare("guerrero")==0||s.compare("Hidalgo")==0||s.compare("hidalgo")==0||s.compare("Jalisco")==0||s.compare("jalisco")==0||s.compare("Michoacan")==0||s.compare("michoacan")==0||s.compare("Morelos")==0||s.compare("morelos")==0||s.compare("Nayarit")==0||s.compare("Nuevo Leon")==0||s.compare("nuevo leon")==0||s.compare("Oaxaca")==0||s.compare("oaxaca")==0
	||s.compare("Puebla")==0||s.compare("puebla")==0||s.compare("Queretaro")==0||s.compare("queretaro")==0||s.compare("Quintana Roo")==0||s.compare("quintana roo")==0||s.compare("San Luis Potosi")==0||s.compare("san luis potosi")==0||s.compare("Sinaloa")==0||s.compare("sinaloa")==0||s.compare("Sonora")==0||s.compare("sonora")==0
	||s.compare("Sonora")==0||s.compare("sonora")==0||s.compare("Tabasco")==0||s.compare("tabasco")==0||s.compare("Tamaulipas")==0||s.compare("tamaulipas")==0||s.compare("Tlaxcala")==0||s.compare("tlaxcala")==0||s.compare("Veracruz")==0||s.compare("veracruz")==0||s.compare("Yucatan")==0||s.compare("yucatan")==0||s.compare("Zacatecas")==0||s.compare("zacatecas")==0){ 
	 return true;}
    // else if reach here ...

    return false;
  
}


	bool isHora(string s)
{
    for(unsigned i=0; i<5; ++ i )	
    if(( s[i] < '0' || s[i] > '9')&& s[2]!=':') return false;
	
	
	return true;	

}//metodo

	bool isCharnum(char s[])
{

    for( unsigned i=0; i<strlen(s); ++ i )

    if( s[i] < '0' || s[i] > '9') return false;
    // else if reach here ...

    return true;
   

}
	bool isCharStr(char s[])
{

    for( unsigned i=0; i<strlen(s); ++ i )

    if( (s[i] < 'A' || s[i] > 'Z') && (s[i]<'a' || s[i]>'z')) return false;
    // else if reach here ...

    return true;
   

}

	bool isVacio(string s)
{
int ban=0;
    for( unsigned i=0; i<s.length(); ++ i ){

    if( s[i] == ' '){
    	ban++;
    }}
    
    if(ban==s.length()){
    	return false;
    }
	else{
	
    return true;
}

}

	bool isCharVacio(char s[])
{
	int ban=0;
    for( unsigned i=0; i<strlen(s); ++ i ){

    if( s[i] == ' '){
    	ban++;
    }}
    
    if(ban==strlen(s)){
    	return false;
    }
	else{
	
    return true;
}

}
		
};


		

#endif


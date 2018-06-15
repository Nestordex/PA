/** diadelasemana.cpp
 * Implementación de la clase sin secciones privadas (struct) Fecha.
 */
#include <iostream>
//#include <stdlib.h>	/* malloc() */
#include <windows.h>
using namespace std;	/* cout */
#include "Racional.h"

void Rac::simplificar(){
	n=n/mcd;
	d=d/mcd;
}

ostream& operator<<(ostream& ostreamOut,Rac& RacObj){
	ostreamOut<<" "<<RacObj.n<<" "<<endl;
	ostreamOut<<"----"<<endl;
	ostreamOut<<" "<<RacObj.d<<endl;
	return ostreamOut;	
}

Rac::Rac(int intNum,int intDen):n(intNum),d(intDen){
	set_mcd();
}
Rac::Rac(){
}


void Rac::set_mcd(){
	int M,N,tmp;/*si numerador!=0 y denominador!=0, usar Algoritmo de Euclides*/
	if((n!=0)&&(d!=0)){
		if(n>d){
			M=n;N=d;
		}else{
			M=d;N=n;
		}/* ALGORITNMO DE EUCLIDES (300 a.C.) */
		while((tmp=M%N)!=0){ /* M = QN + r */
			M=N;
			N=tmp;
		}/*cuando este while termina, en N se tiene el mcd*/
		mcd=N;
	}else{/*si no, hacer mcd=1*/
		mcd=1;/*Para evitar problemas cuando n=0 o d=0*/
	}
}
Rac& Rac::operator+(Rac& RacObj){
	Rac RacResult;
	RacResult.n=n*RacObj.d+d*RacObj.n;
	RacResult.d=d*RacObj.d;
	RacResult.set_mcd();
	RacResult.simplificar();
	return RacResult;
}
Rac& Rac::operator-(Rac& RacObj){
	Rac RacResult;
	RacResult.n=n*RacObj.d-d*RacObj.n;
	RacResult.d=d*RacObj.d;
	RacResult.set_mcd();
	RacResult.simplificar();
	return RacResult;
}
Rac& Rac::operator*(Rac& RacObj){
	Rac RacResult;
	RacResult.n=n*RacObj.n;
	RacResult.d=d*RacObj.d;
	RacResult.set_mcd();
	RacResult.simplificar();
	return RacResult;
}

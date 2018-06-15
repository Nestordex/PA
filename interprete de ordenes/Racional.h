struct Rac{
	int n;		/* numerador */
	int d;		/* denominador*/
	int mcd;	/* maximo comun divisor*/
	void simplificar();
	void set_mcd();

	Rac& operator+(Rac& RacObj);
	Rac& operator-(Rac& RacObj);
	Rac& operator*(Rac& RacObj);
	Rac& operator/(Rac& RacObj);
	/* constructores */
	Rac(int intNum,int intDen);
	Rac();
friend	ostream& operator<<(ostream& ostreamOut,Rac& RacObj); 
};//end class Rac


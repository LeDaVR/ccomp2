#include <iostream>

using namespace std;

int tamanio(string cadena){
	int cantidad=0;
	while(cadena[cantidad]!='\0'){
		cantidad++;
	}
	return cantidad;
}

int sumaescrita(string u,string a,string d,string c){
	int tu=tamanio(u);
	int ta=tamanio(a);
	int td=tamanio(d);
	int tc=tamanio(c);
	int sumacien=tu+ta+3+((td-3)*10)+(tu*8);
	int suma1000=(sumacien*9)+(99*3*9)+(tu*100)+(tc*900)+11;
	return sumacien+suma1000;
}
int main(){
	string dig="onetwothreefourfivesixseveneightnine";
	string a="eleventwelvethirteenfourteenfifteensixteenseventeeneighteennineteen";
	string decenas="tentwentythirtyfortyfiftysixtyseventyeightyninety";
	string centenas="hundred";
	cout<<sumaescrita(dig,a,decenas,centenas);
}

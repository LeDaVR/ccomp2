#include <iostream>
#include <sstream>
using namespace std;
int tamanio(string cadena){
	int cantidad=0;
	while(cadena[cantidad]!='\0'){
		cantidad++;
	}
	return cantidad;
}
int sumadedig(string num){
	int suma=0;
	for(int i=0;i<tamanio(num);i++){
		int x=static_cast<int>(num[i])-48;
		suma+=x;
	}
	return suma;
}
void invertir(string &cadena){
	int tamano=tamanio(cadena);
	for(int i=0;i<tamano/2;i++){
		char a=cadena[i];
		cadena[i]=cadena[tamano-i-1];
		cadena[tamano-i-1]=a;
	}
}
void multiplicar(string &numero,int mult){
	string newnum="";
	int x=0,acarreo=0;
	for(int i=tamanio(numero)-1;i>=0;i--){
		x=static_cast<int>(numero[i])-48;
		x*=mult;
		x+=acarreo;
		stringstream ss;
		ss << x%10;
		newnum+=ss.str();
		acarreo=x/10;
	}
	while(acarreo>0){
		stringstream ss;
		ss << acarreo%10;
		newnum+=ss.str();
		acarreo/=10;
	}
	invertir(newnum);
	numero=newnum;
}
int main(){
	string numero="2";
	for(int i=1;i<1000;i++){
		multiplicar(numero,2);
	}
	cout<<numero<<endl;
	cout<<sumadedig(numero);
}

#include <iostream>
#include <math.h>
#include <sstream>
using namespace std;
class Arr{
	public:
		int size;
		string *arr;
		Arr(string x){
			size=1;
			arr=new string[size];
			arr[0]=x;
		}
		void resize(int newsize){
			string *temp=new string[newsize];
			int minsize = (newsize>size)?size:newsize;
			for(int i=0;i<minsize;i++)
				temp[i]=arr[i];
			delete[] arr;
			arr=temp;
			size=newsize; 
		}
		void push_back(string x){
			resize(size+1);
			arr[size-1]=x;
		}
		~Arr(){
			delete[] arr;
		}
};

int tamanio(string cadena){
	int cont=0;
	while(cadena[cont]=='\0')
		cont++;
	return cont;
}

void invertir(string &cadena){
	int tamano=tamanio(cadena);
	for(int i=0;i<tamano/2;i++){
		char a=cadena[i];
		cadena[i]=cadena[tamano-i-1];
		cadena[tamano-i-1]=a;
	}
}
string multiplicar(string numero,int mult){
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
	return newnum;
}
string potencia(int numero,int potencia){
	stringstream ss;
	ss << numero;
	string num=ss.str();
	for(int i=1;i<=potencia;i++){
		num=multiplicar(num,numero);
	}
	return num;
}
int main(){
	/*Arr potencias("4");
	for(int i=2;i<=100;i++){
		for(int j=2;j<=100;j++){
			//cout<<i<<" "<<j<<endl;
			for(int k=0;k<potencias.size;k++){
				cout<<potencia(i,j)<<endl;
				if(potencia(i,j)==potencias.arr[k])
					break;
				if(k==potencias.size-1)
					potencias.push_back(potencia(i,j));
			}
		}
	}
	cout<<potencias.size;*/
	cout<<multiplicar("20",2);
}

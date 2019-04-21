#include <iostream>
using namespace std;
bool esprimo(int numero){
	if(numero<=1){
		return false;
	}
	for(int i=2;i<=numero/2;i++){
		if(numero%i==0)
			return false;
	}
	return true;
}
int main(){
	int multiplicacion;
	int mayor=0;
	for(int a=-999;a<1000;a++){
		for(int b=-1000;b<=1000;b++){
			int cont=0;
			while(esprimo((cont*cont)+(a*cont)+b))
				cont++;
			if(cont>mayor){
				cout<<"consecu "<<cont<<" "<<a<<" "<<b<<endl;
				mayor=cont;
				multiplicacion=a*b;
			}
		}
	}
	cout<<multiplicacion<<endl;
	cout<<esprimo(1601);
}

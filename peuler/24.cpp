#include <iostream>
using namespace std;
int len(string n){
	int cont=0;
	while(n[cont]!='\0')
		cont++;
	return cont;
}

int factorial(string numero){
	int tam=len(numero);
	int re=1;
	for(int i=1;i<=tam;i++)
		re*=i;
	return re;
}
int npermutacion(string numero,int pos){
	int tam=len(numero),fact=factorial(numero);
	int lock[tam]={0};
	
	int grupo=fact/tam;
	int i=tam-1;
	int cont;
	while(i>0){
		cont=0;
		while(pos>(grupo*(cont+1)))
			cont++;
		int aux=0;
		for(int j=0;j<tam;j++){
			if(!(lock[j])){
				aux++;
			}
			if(aux==cont+1){
				lock[j]=1;
				cout<<j;
				break;
			}
		}
		pos-=(grupo*cont);
		grupo/=i;
		i--;
	}
	for(int i=0;i<tam;i++)
		if(lock[i]==0)
			cout<<i;
	cout<<endl;
}

int main(){
	string numero="0123456789";
	npermutacion(numero,1000000);
}

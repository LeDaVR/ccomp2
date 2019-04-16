#include <iostream>
using namespace std;
int collatz(unsigned long long int &x){
	if(!(x%2))
		x/=2;
	else
		x=(3*x)+1;
}
int buscar(){
	int contador=0;
	int number=1;
	for(int i=1000000;i>0;i--){
		unsigned long long int numero=i,temp=0;
		while(numero!=1){
			collatz(numero);
			temp++;
		}
		if(temp>contador){
			contador=temp;
			number=i;
		}
	}
	return number;
}
int main(){
	cout<<buscar();
}

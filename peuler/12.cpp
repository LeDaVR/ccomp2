#include <iostream>
#include <math.h>
using namespace std;

int divisores(int num){
	if(num>1){
		int div=1;
		for(int i=2;;i++){
			if(num%i!=0)
				continue;
			int primo=0;
			int cont=0;
			for(int j=1;j<=i;j++){
				if(i%j==0)
					primo++;
			}
			if(primo<=2){	
				while(num%i==0){
					num/=i;
					cont++;
				}
				div*=(cont+1);
			}
			if(num==1)
				break;
		}
		return div;
	}
	return 0;
}

int main(){
	int acum=0;
	for(int i=1;divisores(acum)<500;i++){
		acum+=i;
	}
	cout<<acum;
}

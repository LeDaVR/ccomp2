#include <iostream>
using namespace std;
int ddsemana(){
	int meses[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int cont=0;
	int domingo=2;
	int anio=1901;
	for(int i=anio;i<2001;i++){
		int last=((anio%10)+((anio/10)%10));
		for(int j=0;j<12;j++){
			domingo+=meses[j];			
			if(!(anio%4)&&j==1&&last!=0)
				domingo++;
			if(j==1&&last==0&&!(anio%400))
				domingo++;
			domingo%=7;
			if(domingo==0)
				cont++;
		}
	}
	return cont;
}
int main(){
	cout<<ddsemana()<<endl;
}

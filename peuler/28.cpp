#include <iostream>
using namespace std;
long long int diasum(){
	long long int antnum=1;
	long long int cont=1;
	int i=2;
	for(int j=1;j<=500;j++){
		for(int k=0;k<4;k++){
			antnum+=i;
			cont+=antnum;
		}
		i+=2;
	}
	return cont;
}
int main(){
	cout<<diasum();
}

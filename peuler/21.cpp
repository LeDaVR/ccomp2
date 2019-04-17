#include <iostream>
using namespace std;
int sumdivisores(int num){
	int sum=0;
	for(int i=1;i<=num/2;i++){
		if(!(num%i))
			sum+=i;
	}
	return sum;
}


int main(){
	int cont=0;
	for(int i=1;i<10000;i++){
		if((i==sumdivisores(sumdivisores(i)))&&i!=sumdivisores(i)){
			cont+=i;
			cout<<i<<"  "<<sumdivisores(i)<<endl;
			cout<<sumdivisores(i)<<"   "<<sumdivisores(sumdivisores(i))<<endl;
		}
			
	}
	cout<<cont<<endl;
}

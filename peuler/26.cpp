#include <iostream>
#include <sstream>
using namespace std;

class Arr{
	public:
		int size;
		int *arr;
		Arr(int x){
			size=1;
			arr=new int[size];
			arr[0]=x;
		}
		void resize(int newsize){
			int *temp=new int[newsize];
			int minsize = (newsize>size)?size:newsize;
			for(int i=0;i<minsize;i++)
				temp[i]=arr[i];
			delete[] arr;
			arr=temp;
			size=newsize; 
		}
		void push_back(int x){
			resize(size+1);
			arr[size-1]=x;
		}
		~Arr(){
			delete[] arr;
		}
};

int len(string n){
	int cont=0;
	while(n[cont]!='\0')
		cont++;
	return cont;
}
string purotam(int divisor,int dividendo){
	string respuesta;
	Arr residuos(10);
	divisor*=10;
	while(true){
		int cociente=divisor/dividendo;
		int residuo=(divisor%dividendo)*10;
		divisor=residuo;
		for(int i=0;i<residuos.size;i++){
			if(residuos.arr[i]==residuo){
				for(int j=i;j<residuos.size;j++){
					stringstream ss;
					ss << (residuos.arr[j]/dividendo);
					respuesta+=ss.str();
				}
				return respuesta;
			}
		}
		residuos.push_back(residuo);
		for(int i=0;i<residuos.size;i++){
		}
		if(residuo==0){
			return "0";
		}
	}
}

int main(){
	int respuesta=1;
	for(int i=1;i<1000;i++){
		if(len(purotam(1,i))>len(purotam(1,respuesta)))
			respuesta=i;
	}
	cout<<respuesta;
	
}

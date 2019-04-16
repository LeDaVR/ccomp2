#include <iostream>
using namespace std;
unsigned long long int caminos(unsigned long long int **ptr){
	for(int i=0;i<21;i++){
		for(int j=0;j<21;j++){
			*(*(ptr+i)+j)=0;
			if(i==0||j==0)
				*(*(ptr+i)+j)=1;
		}
	}
	for(int i=1;i<21;i++){
		for(int j=1;j<21;j++){
			*(*(ptr+i)+j)=*(*(ptr+i-1)+j)+*(*(ptr+i)+j-1);
		}
	}
	return *(*(ptr+20)+20);
}

int main(){
	//inicializando matriz
	unsigned long long int **arr=new unsigned long long int*[21];
	for(int i=0;i<21;i++){
		arr[i]=new unsigned long long int[21];
	}
	cout<<caminos(arr)<<endl;
	for(int i=0;i<21;i++){
		for(int j=0;j<21;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int i=0;i<21;i++){
		delete[] arr[i];
	}
	delete[] arr;
}

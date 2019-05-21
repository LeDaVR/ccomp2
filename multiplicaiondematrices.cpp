#include <iostream>


using namespace std;
void multiplicacion(int **m1,int f1,int c1,int **m2,int f2,int c2,int **c){
	if(c1!=f2)
		return;
	for(int i=0;i<f1;i++)
		for(int j=0;j<c2;j++){
			*(*(c+i)+j)=0;
			for(int k=0;k<c1;k++)
				*(*(c+i)+j)+=*(*(m1+i)+k) * (*(*(m2+k)+j));
		}			
}

int main(){
	int **arr=new int*[3];
	for(int i=0;i<3;i++)
		arr[i]=new int[3];
	int cont=1;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			arr[i][j]=cont++;
	}
	int **arr2=new int*[3];
	for(int i=0;i<3;i++)
		arr2[i]=new int[2];
	for(int i=0;i<3;i++){
		for(int j=0;j<2;j++)
			arr2[i][j]=cont++;
	}
	int **result=new int*[3];
	for(int i=0;i<3;i++)
		result[i]=new int[2];
		
	multiplicacion(arr,3,3,arr2,3,2,result);
	
	cout<<"MATRIZ 1"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
	cout<<"MATRIZ 2"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<2;j++)
			cout<<arr2[i][j]<<" ";
		cout<<endl;
	}
	cout<<"MATRIZ 3"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<2;j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	for(int i=0;i<3;i++)
		delete[] arr[i];
	for(int i=0;i<3;i++)
		delete[] arr2[i];
	for(int i=0;i<3;i++)
		delete[] result[i];
	delete[] arr;
	delete[] arr2;
	delete[] result;
}

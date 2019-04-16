#include <iostream >
using namespace std;

void multiplicacion(int m1[20][20],int f1,int c1,int m2[20][20],int f2,int c2,int m3[20][20]){
	if (c1==f2){
		for(int i=0;i<f1;i++){
			for(int j=0;j<c2;j++){
				m3[i][j]=0;
				for(int k=0;k<c1;k++){
					m3[i][j]+=m1[i][k]*m2[k][j];
				}
			}
		}
	}
}

int main()
{
	int arr[20][20]={2,3,4};    // 2  3  4
	arr[1][0]=8;                // 8  9  6
	arr[1][1]=9;
	arr[1][2]=6;	
	
	int arr2[20][20]={2,9};      //  2   9
	arr2[1][0]=6;                //  6   7
	arr2[1][1]=7;                //  5   3
	arr2[2][0]=5;
	arr2[2][1]=3;
	
	int arr3[20][20]={};
	
	multiplicacion(arr,2,3,arr2,3,2,arr3);
	
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cout<<arr3[i][j]<<" ";
		}
		cout<<endl;
	}
}


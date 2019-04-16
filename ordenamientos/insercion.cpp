#include <iostream >
using namespace std;

void insercion(int arr[],int len){
	int pos;
	for(int i=0;i<len;i++){
		pos=i;
		while(pos>0&&arr[pos]<arr[pos-1]){
			int temp=arr[pos];
			arr[pos]=arr[pos-1];
			arr[pos-1]=temp;
			pos--;
		}
	}
}


int main()
{
	int arr[10]={5,3,4,6,9,2,1,8,7,10};
	insercion(arr,10);
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}
	
}

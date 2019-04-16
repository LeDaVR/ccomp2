#include <iostream >
using namespace std;

void burbuja(int arr[],int len){
	for(int i=0;i<len;i++){
		for(int j=0;j<len-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

int main()
{
	int arr[10]={5,3,4,6,9,2,1,8,7,10};
	burbuja(arr,10);
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}
	
}


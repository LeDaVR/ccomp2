#include <iostream >
using namespace std;

void intercambiar(int &x, int &y){
	int temp=x;
	x=y;
	y=temp;
}
void quick(int arr[],int min,int max){
	int pivpos,i,j;
	pivpos=(min+max)/2;
	intercambiar(arr[pivpos],arr[max]);
	int piv=arr[max];
	i=min;
	j=max-1;
	
	while(i<=j){
		while(piv>arr[i]){
			i++;
		}
		while(piv<arr[j]){
			j--;	
		}
		if(i<=j){
			intercambiar(arr[i],arr[j]);
			i++;
		}
	
	}
	if(piv<arr[i]){
		intercambiar(arr[max],arr[i]);
	}
	i++;
	if(min<j){
		quick(arr,min,j);
	}
	if(max>i){
		quick(arr,i,max);
	}
		
}

int main()
{
	int arr[10]={5,3,4,6,9,2,1,8,7,10};
	quick(arr,0,9);
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}
	
}


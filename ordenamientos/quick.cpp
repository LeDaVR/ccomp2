#include <iostream >
using namespace std;

void intercambiar(int &x, int &y){
	int temp=x;
	x=y;
	y=temp;
}
void quick(int *arr,int min,int max){
	int pospivote=(min+max)/2,pivote=arr[pospivote];
	intercambiar(arr[max],arr[pospivote]);
	int i=min,j=max-1;
	while(i<j){
		while(arr[i]<pivote&&i<max-1)
			i++;
		while(arr[j]>pivote&&j>min)
			j--;
		if(i<j){
			intercambiar(arr[i],arr[j]);
			i++;
			j--;
		}
	}
	if(arr[i]>arr[max])
		intercambiar(arr[i],arr[max]);
	if(min<j)
		quick(arr,min,j);
	if(max>i+1)
		quick(arr,i+1,max);
	/*
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
	
	*/
		
}

int main()
{
	int arr[10]={5,3,4,6,10,2,1,8,7,9};
	quick(arr,0,9);
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}
	
}


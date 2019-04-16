#include <iostream >
using namespace std;

void Merge(int arr[],int min, int med,int max){
	int len1=med-min+1;       //tamaño de arr1
	int len2=max-med;         //tamaño de arr2
	int arr1[len1],arr2[len2];
	for(int i=0;i<len1;i++){
		arr1[i]=arr[min+i]; //actualizamos los elementos de arr1
	}
	for(int j=0;j<len2;j++){
		arr2[j]=arr[med+j+1];   //actualizamos los elemantos de arr2
	}
	int i=0;
	int j=0;
	int k=min;
	while (i < len1 && j < len2){ 
        if (arr1[i] <= arr2[j]) { 
            arr[k] = arr1[i]; 
            i++; 
        } 
        else{ 
            arr[k] = arr2[j]; 
            j++; 
        } 
        k++; 
    } 
	while(i<len1){
		arr[k++]=arr1[i++];
	}
	while(j<len2){
		arr[k++]=arr2[j++];
	}
}
void mergesort(int arr[],int min,int max){  
	int med;                                
	if(min<max){                //si min es mayor significa que todavía se puede dividir el arreglo
		med=(min+max)/2;                   
		mergesort(arr,min,med);     //dividimos el arreglo del principio hasta el medio     
		mergesort(arr,med+1,max);   //dividimos el arreglo desde el medio+1 hasta al final
		Merge(arr,min,med,max);     //lo ordenamos y lo juntamos simultáneamente
	}
}

int main()
{
	int arr[10]={5,3,4,6,9,2,1,8,7,10};
	mergesort(arr,0,9);
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}
	
}

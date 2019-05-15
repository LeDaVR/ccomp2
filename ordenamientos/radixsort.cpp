#include <iostream >
using namespace std;

//funci�n para obtener el mayor elemento del arreglo
int getMayor(int *arr, int len){
	int nummayor=*(arr+0);
	for(int i=0;i<len;i++)
		if(*(arr+i)>nummayor)
			nummayor=*(arr+i);
	return nummayor;
	/*int max = arr[0];
	for (int i = 1; i < len; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;*/
}
 
// Count sort of arr[].
void countSort(int *arr, int len, int exp){
	int respuesta[len],digitos[10]={0};
	for(int i=0;i<len;i++)
		digitos[(*(arr+i)/exp)%10]++;
	for(int i=0;i<9;i++)
		digitos[i+1]+=digitos[i];
	for(int i=len-1;i>=0;i--){
		respuesta[digitos[(*(arr+i)/exp)%10]-1]=*(arr+i);
		digitos[(*(arr+i)/exp)%10]--;
	}
	for(int i=0;i<len;i++)
		arr[i]=respuesta[i];
	
/*
	int radix[len], count[10] = {0};
	// cuenta la cantidad de veces que los d�gitos de los n�meros en la misma jerarqu�a 
	for (int i = 0; i < len; i++)
		count[(arr[i] / dig) % 10]++;
	for (int i = 1; i < 10; i++)
		count[i] += count[i-1];
		
	// inserta los valores de acuerdo con los d�gitos
	for (int i = len - 1; i >= 0; i--){
		radix[count[(arr[i] / dig) % 10] - 1] = arr[i];
		count[(arr[i] / dig) % 10]--;
	}
	// actualizar los valores de arr[] pero que ya est�n ordenados en radix[]
	for (int i = 0; i < len; i++)
		arr[i] = radix[i];*/
}


void radixsort(int *arr, int len){
	int exp,mayor;
	mayor=getMayor(arr,len);
	for(exp=1;mayor/exp>0;exp*=10){
		countSort(arr,len,exp);
	}
	
	
	/*int dig, max;
	max = getMayor(arr, len); //variable con el mayor valor del arreglo
	// llama a countSort para que ordene los n�meros dependiendo de la posici�n de los digitos 
	for (dig = 1; max/dig > 0; dig *= 10)
		countSort(arr, len, dig);*/
}

int main()
{
	int arr[10]={5,3,4,6,9,2,1,8,7,10};
	radixsort(arr,10);
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}
	
}

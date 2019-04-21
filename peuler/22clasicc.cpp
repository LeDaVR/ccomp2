#include <iostream>
#include <fstream>
using namespace std;
int tama(string a){
	int b=0;
	while(a[b]!='\0'){
		b++;
	}
	return b;
}
int palabras(string archivo){
	int cantidad=0,iterador=0;
	while(archivo[iterador]!='\0'){
		if(archivo[iterador]==',')
			cantidad++;
		iterador++;
	}
	return cantidad+1;
}
void ordenar(string *b,int tam){
	for(int i=0;i<tam;i++){
		for(int j=i+1;j<tam;j++){
			string fir=*(b+i);
			string sec=*(b+j);
			int cont=0;
			while(fir[cont]==sec[cont]){
				cont++;
			}
			if(fir[cont]>sec[cont]){
			*(b+i)=sec;
			*(b+j)=fir;
			}
		}			
	}
}
int main(){
	ifstream read("names.txt");
	string archivo;
	getline(read,archivo);
	read.close();
	string arreglo[palabras(archivo)];
	int j=0;
	for(int i=0;i<palabras(archivo);i++){

		while(archivo[j]=='"'||archivo[j]==','){
			j++;
		}
		while(archivo[j]!='"'&&archivo[j]!=','&&archivo[j]!='\0'){
			arreglo[i]+=archivo[j];
			j++;
		}
	}
	ordenar(arreglo,palabras(archivo));
	ofstream write("orden.txt");
	string orden;
	for(int i=0;i<palabras(archivo);i++){
		orden+=arreglo[i]+'\n';
	}
	write << orden;
	write.close();
	unsigned long long int suma=0;
	for(int i=0;i<palabras(archivo);i++){
		int sumletras=0;
		string palabra=arreglo[i];
		cout<<palabra<<endl;
		for(int j=0;j<tama(palabra);j++){
			int asd=(static_cast<int>(palabra[j])-64);
			sumletras+=asd;
		}
		cout<<sumletras<<endl;
		suma+=(sumletras*(i+1));
	}
	cout<<suma;
	
}

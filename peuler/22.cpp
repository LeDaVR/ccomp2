#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int cpal(string archivo){
	int cantidad=0,iterador=0;
	while(archivo[iterador]!='\0'){
		if(archivo[iterador]==',')
			cantidad++;
		iterador++;
	}
	return cantidad+1;
}
int tama(string a){
	int b=0;
	while(a[b]!='\0'){
		b++;
	}
	return b;
}
void radix(string &archivo){
	string posciciones="$";
	string resultado;
	int arr[26]={0};
	for(int i=1;i<tama(archivo)-1;){
		if(archivo[i]=='"'&&archivo[i+1]!='\0')
			i+=3;
		if(archivo[i]!='"'&&archivo[i]!=','){
			int letra=static_cast<int>(archivo[i])-97;
			arr[letra]+=1;
			while(archivo[i]!='"')
				i++;
			if(archivo[i+1]!='\0')
				i+=3;
			else
				break;
		}
	}
	for(int i=0;i<25;i++){
		arr[i+1]+=arr[i];
	}
	for(int i=tama(archivo)-2;i>=0;i--){
		if(archivo[i]=='"'&&archivo[i+1]!=','){
			stringstream ss;
			int letra=static_cast<int>(archivo[i+1])-97;
			ss << arr[letra]-1;
			posciciones+=ss.str()+"$";
			arr[letra]-=1;
		}
	}
	/*for(int i=tama(archivo)-2;i>=0;i--){
		if(archivo[i]=='"'&&archivo[i+1]!=','){
			resultado+='"';
			for(int j=i+1;archivo[j]!='"';j++){
				resultado+=archivo[j];
			}
			if(i!=0)
				resultado+='"'+',';
			else{
				resultado+='"';
			}
		}
	}*/
	int i=0;
	while(i<cpal(archivo)){
		cout<<"palabra"<<i<<endl;
		stringstream ss;
		ss << i;
		int cont=0,cont2=1,m=0;
		string num="";
		for(int j=0;num!=ss.str();j++){
			num="";
			if(posciciones[j]=='$'){
				cont++;
				for(int k=j+1;posciciones[k]!='$';k++){
					num+=posciciones[k];
				}
			}cout<<num<<" "<<ss.str()<<endl;
		}
		while(cont2!=cont){
			if(archivo[cont2]==',')
				cont2++;
			m++;
		}
		resultado+='"';
		while(archivo[m]!='"'){
			resultado+=archivo[m];
			m++;
		}
		if(i-1==cpal(archivo))
			resultado+='"';
		else
			resultado+='"'+',';
	}
	archivo=resultado;
}
int main(){
	ifstream read("names.txt");
	string archivo="";
	getline(read,archivo);
	read.close();
		cout<<cpal(archivo);
	radix(archivo);
	ofstream write("orden.txt");
	write << archivo;
	write.close();

}

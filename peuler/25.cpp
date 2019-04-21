#include <iostream>
#include <sstream>
using namespace std;
int len(string n){
	int cont=0;
	while(n[cont]!='\0')
		cont++;
	return cont;
}

string suma(string a,string b){
	string result="";
	int lena=len(a)-1;
	int lenb=len(b)-1;
	int minlen=(lena>lenb)?lenb:lena;
	int acarreo=0;
	while(minlen>=0){
		int num1=static_cast<int>(a[lena])-48;
		int num2=static_cast<int>(b[lenb])-48;
		acarreo+=num1+num2;
		stringstream ss;
		ss << acarreo%10;
		result=ss.str()+result;
		acarreo/=10;
		lena--;lenb--;minlen--;
	}
	if(lena>lenb){
		for(int i=lena;i>=0;i--){
			int num1=static_cast<int>(a[i])-48;
			acarreo+=num1;
			stringstream ss;
			ss << acarreo%10;
			result=ss.str()+result;
			acarreo/=10;
		}
	}else{
		for(int i=lenb;i>=0;i--){
			int num1=static_cast<int>(b[i])-48;
			acarreo+=num1;
			stringstream ss;
			ss << acarreo%10;
			result=ss.str()+result;
			acarreo/=10;
		}
	}
	if(acarreo>0){
		stringstream ss;
		ss << acarreo;
		result=ss.str()+result;
	}
	return result;
}

int fibdig(int digitos){
	string n1="1";
	string n2="1";
	int i;
	for(i=2;len(n2)<digitos;i++){
		string temp=n2;
		n2=suma(n1,n2);
		n1=temp;
	}
	return i;
}

int main(){
	string a="2065";
	string b="952";
	cout<<fibdig(1000);
}

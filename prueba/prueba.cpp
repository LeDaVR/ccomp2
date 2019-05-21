#include <iostream>
#include <fstream>
using namespace std;


template<class T>
struct DinamicArray{
	T *arr;
	int size;
	DinamicArray(){
		size=0;
		arr=new T[size];
	}	
	
	void resize(int newsize){
		int minsize=size>newsize ? newsize : size;
		T *temp=new T[newsize];
		for(int i=0;i<minsize;i++)
			temp[i]=arr[i];
		size=newsize;
		delete[] arr;
		arr=temp;
	}
	
	void push_back(T element){
		resize(size+1);
		arr[size-1]=element;
	}
	
	void clear(){
		resize(0);
	}
	
	int getSize()const{
		return size;
	}
	~DinamicArray(){
		delete[] arr;
	}
};


class Editor{
	private:
		int cuadrante;
		bool **matrix;

	public:
		DinamicArray<float> vertices;
		DinamicArray<unsigned int> indices;
		Editor();
		void draw();
		void addElement();
		~Editor();
	
};

Editor::Editor(){
	int cuadrante=2;
	matrix=new bool*[80];
	for(int i=0;i<80;i++){
		*(matrix+i)=new bool[80];
	}
	for(int i=0;i<80;i++)
		for(int j=0;j<80;j++)
			*(*(matrix+i)+j)=true;
			
	for(int i=0;i<80;i++){
		for(int j=0;j<80;j++){
			vertices.push_back(float(j*cuadrante));
			vertices.push_back(float(i*cuadrante));
			vertices.push_back(0.0f);
		}
	}
	
	float cont=0.0f;
	for(int i=0;i<79;i++){
		for(int j=0;j<79;j++){
			indices.push_back(cont);
			indices.push_back(cont+1);
			indices.push_back(cont+81);
			indices.push_back(cont);
			indices.push_back(cont+80);
			indices.push_back(cont+81);	
			cont++;
		}
	}
}


void Editor::draw(){
	
	stringstream is;
	
	
	for(int i=0;i<indices.getSize();i++){
		if(!(i%3)){
			cout<<") (";
		}
		if(!(i%240)&&i>0)
			cout<<endl;
		cout<<indices.arr[i]<<",";
	}
}



Editor::~Editor(){
	for(int i=0;i<80;i++){
		delete[] *(matrix+i);
	}
	delete[] matrix;
}

int main(){
	Editor editor;
	ofstream write("escritura.txt");
	string  a;
//	cout<<editor.vertices.getSize();
	/*int a=500;
	float b=float(a);
	cout<<b;*/

	editor.draw();
}

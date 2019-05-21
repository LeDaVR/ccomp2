#ifndef DINAMICARRAY_H
#define DINAMICARRAY_H

template<class T>
struct DinamicArray{
	T *arr;
	int size;
	DinamicArray(){
		size=0;
		arr=new T[size];
	}
	void addArray(DinamicArray<T>* o){
		for(int i=0;i<o->getSize();i++)
			push_back(o->arr[i]);
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


#endif

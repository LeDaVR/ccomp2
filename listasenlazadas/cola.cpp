#include <iostream>
using namespace std;


template <class T>
class Nodo;

template <class T>
class Cola;

template<class T>
ostream& operator <<(ostream& o,Nodo<T>& a){
    o << a.data;
    return o;
}

template <class T>
class Nodo{
    private:
        friend class Cola<T>;
        T data;
        Nodo<T>* next;
    public:
        Nodo(){
            next=NULL;
        }
        friend ostream& operator << <>(ostream& o,Nodo<T>& a);
};

template <class T>
class Cola{
    private:
    Nodo<T>* first;
    int size;
    public:
        class iterator{
            Nodo<T>* pos;
            public:
            iterator(Nodo<T>*_pos=NULL) : pos(_pos){}

            T& operator*(){ 
                return pos->data; 
            }
 
			bool operator!=(const iterator& it){ 
                return this->pos != it.pos; 
            }
 
			iterator operator++(int){ 
                pos = pos->next; 
                return *this; 
            }

            iterator& operator=(iterator a){
                this->pos=a.pos;
                return *this;
            }

            iterator operator+(int a){
                iterator temp;
                temp.pos=this->pos;
                for(int i=0;i<a;i++){
                    temp.pos=temp.pos->next;
                }
                return temp;
            }

            iterator& operator+=(int a){
                for(int i=0;i<a;i++){
                    this->pos=this->pos->next;
                }
                return *this;
            }
 
        };

        Cola(){
            first=NULL;
            size=0;
        }

        void push(T value){
            Nodo<T>* temp=new Nodo<T>;
            temp->data=value;
            Nodo<T>* aux1=first;
            if(!aux1){
                first=temp;
                size++;
            }else{
                while(aux1->next){
                    aux1=aux1->next;
                }
                aux1->next=temp;
                size++;
            }
        }

        void pop_front(){
            Nodo<T>* aux1=first;
            if(!first)
                return;
            else if(!(first->next)){
                delete aux1;
            }else{
                first=aux1->next;
                delete aux1;
            }
            size--;
        }

        T front(){
            return first->data;
        }

        const iterator begin(){
            return iterator(first);
        }

        const iterator end(){
            return iterator(NULL);
        }

        bool empty(){
            return (!size);
        }

        int Size(){
            return size;
        }
};

int main(){
    Cola<int> cola;
    cola.push(5);
    cola.push(2);
    cola.push(8);
    for(Cola<int>::iterator i=cola.begin();i!=cola.end();i++)
        cout << *i <<" ";
    cout <<endl;

    cola.pop_front();

    for(Cola<int>::iterator i=cola.begin();i!=cola.end();i++)
        cout << *i <<" ";
    cout<<endl;
    cout << cola.Size()<<endl;
    cout << cola.front()<<endl;
}
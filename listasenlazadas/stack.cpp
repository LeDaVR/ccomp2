#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Nodo;

template <class T>
class Stack;

template<class T>
ostream& operator <<(ostream& o,Nodo<T>& a){
    o << a.data;
    return o;
}

template <class T>
class Nodo{
    private:
        friend class Stack<T>;
        T data;
        Nodo<T>* next;
    public:
        Nodo(){
            next=NULL;
        }
        friend ostream& operator << <>(ostream& o,Nodo<T>& a);
};

template <class T>
class Stack{
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

        Stack(){
            first=NULL;
            size=0;
        }

        void push_back(T value){
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

        void pop_back(){
            Nodo<T>* aux1=first;
            Nodo<T>* aux2=aux1;
            if(!first)
                return;
            else if(!(first->next)){
                delete aux1;
            }else{
                while(aux1->next){
                    aux2=aux1;
                    aux1=aux1->next;
                }
                delete aux1;
                aux2->next=NULL;
            }
            size--;
        }

        T top(){
            return *(iterator(first)+(size-1));
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
    Stack<int> mystack;
    mystack.push_back(9);
    mystack.push_back(8);
    mystack.push_back(3);
    for(Stack<int>::iterator i=mystack.begin();i!=mystack.end();i++)
        cout << *i <<" ";
    cout <<endl;

    mystack.pop_back();

    for(Stack<int>::iterator i=mystack.begin();i!=mystack.end();i++)
        cout << *i <<" ";
    cout<<endl;
    cout << mystack.Size()<<endl;
    cout<< mystack.top() <<endl;
}
#include <iostream>
using namespace std;


template <class T>
class Point;

template <class T>
ostream& operator <<(ostream& o,Point<T> p){
    o<<"("<< p.x <<","<<p.y<<")";
    return o;
}

template <class T>
class Point{
private:
    T x,y;
public:
    Point(){}
    Point(T x,T y) {
        this->x=x;
        this->y=y;
    }
    bool operator <(Point<T>& a){
        return x<a.x;
    }

    bool operator ==(Point<T>& a){
        return (x==a.x && y==a.y);
    }

    bool operator !=(Point<T>& a){
        return (x!=a.x || y!=a.y);
    }
    friend ostream& operator << <>(ostream& o,Point<T> p);
};

template <class T>
class Lista;

template <class T>
class Nodo{
    private:
        friend class Lista<T>;
        T data;
        Nodo<T>* next;
    public:
        Nodo(){
            next=NULL;
        }
};

template <class T>
class Lista{
        Nodo<T>* first;
        int size;
    public:

        Lista(){
            first=NULL;
            size=0;
        }

        void add(T data){
            Nodo<T>* new_nodo=new Nodo<T>;
            new_nodo->data=data;
            Nodo<T>* aux1;
            Nodo<T>* aux2;
            aux1=first;
            while(aux1&&aux1->data<data){
                aux2=aux1;
                aux1=aux1->next;
            }
            if(first==aux1)
                first=new_nodo;
            else
            {
                aux2->next=new_nodo;
            }
            new_nodo->next=aux1;
            size++;
        }

        void search(T data){
            int pos=0;
            Nodo<T>* aux1=first;
            while(aux1->data!=data){
                aux1=aux1->next;
                pos++;
                if(!aux1)
                    break;
            }
            if(!aux1){
                cout<<"No se encontro el elemento"<<endl;
            }
            else{
                cout<<"ELEMENTO ENCONTRADO EN LA POSICION : "<< pos <<endl;
            }
        }

        void remove(T data){
            Nodo<T>* aux1=first;
            Nodo<T>* aux2=NULL;
            while(aux1->data!=data){
                aux2=aux1;
                aux1=aux1->next;
                if(!aux1)
                    break;
            }
            if(!aux2){
                first=aux1->next;
                delete aux1;
                size--;
                return;
            }
                
            if(!aux1)
                cout<<"No se encontro el elemento a eliminar"<<endl;
            else{
                aux2->next=aux1->next;
                delete aux1;
                size--;
            }
        }


        void printlist(){
            Nodo<T>* aux1=first;
            while(aux1){
                cout<<aux1->data<<" ";
                aux1=aux1->next;
            }
            cout<<endl;
        }

        int getSize(){
            return size;
        }

        ~Lista(){
            Nodo<T>* aux1=first;
            Nodo<T>* aux2;
            while(aux1){
                aux2=aux1->next;
                delete aux1;
                aux1=aux2;
            }
        }
};


int main(){
    cout<< "------------LISTA DE NUMEROS-------------"<<endl;
    Lista<int> mylist;
    cout << "AGREGANDO NODOS" << endl;
    mylist.add(10);
    mylist.add(5);
    mylist.add(15);
    mylist.add(13);

    cout<<"IMPRIMIENDO NODOS" << endl;
    mylist.printlist();
    
    mylist.search(10);
    mylist.search(12);
    mylist.remove(5);
    mylist.remove(12);
    mylist.remove(13);
    cout<<"IMPRIMIENDO NODOS" << endl;
    mylist.printlist();

    cout <<"Size : "<< mylist.getSize()<<endl;
    Lista< Point<int> > puntos;
    
    puntos.add( Point<int>(2,3) );
    puntos.add( Point<int>(5,2) );
    puntos.add( Point<int>(1,1) );
    puntos.printlist();

    puntos.search(Point<int> (1,1));

    puntos.remove(Point<int> (1,1));
    puntos.remove(Point<int> (5,6));

    puntos.printlist();
    return 0;
}
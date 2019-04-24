#include <iostream>
using namespace std;
class Point{
	private :
 		int x, y;
	public :
 		Point (int u, int v) : x(u),y(v){}
 		int getX () { return x; }
 		int getY () { return y; }
		void doubleVal (){
		 	x *= 2;
		 	y *= 2;
		}
		void setX (int newX ) const{// no puede modificar x porque la funcion
			x= newX ;               // tiene un const que no deja modificar variables mienbro
		}
		//caso 2
		void setX(int);
};
void setX(int newX){ x = newX; }//no esta en la clase es necesario usar void Point::setX
int main ()
{
	 const Point myPoint (5, 3)  //falta ;
	 myPoint . doubleVal ();    // no se puede modificar porque es constante 
	 cout << myPoint . getX () << " " << myPoint . getY () << "\n";
	 Point p(5, 3);
	 cout << p.x << " " << p.y << "\n";// no puede utilizar las variables x , y porque son privadas
	 
	int size;
 	cin >> size;
 	int *nums = new int[size];
 	for(int i = 0; i < size; ++i){
		cin >> nums[i];
	}
	delete nums; // para borrar correctamente nums es un arreglo es delete[]
	
	
	Point *p=new Point (5,3);
	cout<<p-> getX ()<<’ ’<<p-> getY ();// como estamos usando el operador new es necesario hacer un delete
	return 0;
}

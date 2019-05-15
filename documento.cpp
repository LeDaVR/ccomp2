#include <iostream>
#include <stack>
#include <vector>
template < class T> 
class Stack ;

template < class T>
Stack <T> operator +( const Stack <T> &s1 , const Stack <T> &s2){
	Stack <T> result = s1;
	for ( unsigned i = 0; i < s1. items . size (); ++i) {
	result . items . push_back (s2. items [i]);
	}
	return result ;
}

template < class T>
class Stack {
	friend Stack <T> operator +<>( const Stack <T> &s1 , const Stack <T> &s2);
	std::vector <T> items ;
	public :
		bool empty () const { return items . empty () ;}
		void push ( const T & item ) { items . push_back ( item );}
		T pop () {
			T last = items . back ();
			items . pop_back ();
			return last ;
		}
};
/*template < class T>
Stack <T> operator +( const Stack <T> &s1 , const Stack <T> &s2)
{
Stack <T> result = s1;
for ( unsigned i = 0; i < s1. items . size (); ++i) {
result . items . push_back (s2. items [i]);
}

return result ;*/

int main(){
}

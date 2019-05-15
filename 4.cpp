#include <iostream>
#include <vector>
#include <map>
using namespace std;
template<class T>
class Stack;

template<class T>
Stack<T> operator+(const Stack<T> &a,const Stack<T> &b){
	Stack<T> result= a;
	for(int i=0;i<b.items.size();i++)
		result.items.push_back(b.items[i]);
	return result;
}

template<class T>
class Stack{
		friend Stack<T> operator+<>(const Stack&,const Stack&);
		vector<T> items;
	public:
		bool empty(){
			return items.empty();
		}
		void push(T a){
			items.push_back(a);
		}
		T pop(){
			T last=items.back();
			items.pop_back();
			return last;
		}
};

class Grafo{
	
	public:
		map<int,vector<int> > outgoing;
		Grafo(const vector<int> &start,const vector<int> &end){
			for(int i=0;i<start.size();i++){
				int first=start[i];
				int last=end[i];
				outgoing[first].push_back(last);
				outgoing[last];
			}
		}
		int numoutgoing(int nodeID){
			return adjacent(nodeID).size();
		}
		
		const vector<int> adjacent(int nodeID){
			return outgoing.find(nodeID)->second;
		}
};

int main(){
	int arr[]={2,3,3,5};
	int arr2[]={8,6,9,6};
	vector<int> a;
	vector<int> b;
	a.insert(a.begin(),arr,arr+4);
	b.insert(b.begin(),arr2,arr2+4);
	Grafo ga(a,b);
	vector<int>::iterator ar=a.end();
	map<int,vector<int> >::iterator it=ga.outgoing.begin();
	cout<<a.capacity()<<endl;
	cout<<a.size()<<endl;
	cout<<*ar;
	a.insert(a.end(),b.begin(),b.end());
	for(int i=0;i<a.size();i++)
		cout<<a[i]<<" ";
	return 0;
}

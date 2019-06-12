#include <iostream>
#include <vector>
class Prueba {
protected:
	Prueba() {
		info.push_back(myname);
		x++;
	}
public:
	static std::vector<std::string> info;
	std::string myname;
	static int x;
	static void print();
};
void Prueba::print() {

	std::vector<std::string>::iterator i = info.begin();
	for (int j = 0; j < info.size(); i++, j++)
		std::cout <<"entro"<< i[j] << std::endl;
}
std::vector<std::string> Prueba::info;
int Prueba::x=0;

class Derived : public Prueba {
public:
	Derived() {
		myname = "derivo ";
	}
};
int main() {
	std::vector<int> c;
	c.push_back(5);
	Derived a;
	Derived b;
	Derived d;
	std::cout << Prueba::x<<std::endl;
	/*std::vector<int>::iterator i = c.begin();
	int* ptr = &(i[0]);
	*ptr = 10;
	std::cout << i[0];*/
	Prueba::print();

}
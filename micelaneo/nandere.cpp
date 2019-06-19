#include <iostream>
#include <vector>
using namespace std;

template <int n>
struct fibonacci{
    enum{
        value = fibonacci<n-1>::value + fibonacci<n-2>::value
    };
};

template <>
struct fibonacci<1>{
    enum{
        value=1,
    };
};

template <>
struct fibonacci<0>{
    enum{
        value=0,
    };
};

int main(){
    cout<<fibonacci<10>::value<<endl;
}
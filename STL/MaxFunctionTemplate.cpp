#include<iostream>
using namespace std;

template<class any_data_type>
any_data_type MyMax(any_data_type var1, any_data_type var2)
{
    return var1 > var2 ? var1 : var2;
}

int main()
{

cout<<"MyMax(10, 20) = "<<MyMax(10, 20)<<endl;
cout<<"MyMax(10.1, 20.2) = "<<MyMax(10.1, 20.2)<<endl;
cout<<"MyMax('a', 'b') = "<<MyMax('a', 'b')<<endl;

const char* p="Function";
const char* q="Template";


cout<<&p<<endl;
cout<<&q<<endl;

cout<<"MyMax(p, q) = "<<MyMax(p, q)<<endl;
 
return 0;
}

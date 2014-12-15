#include<iostream>
using namespace std;

const int STACK_SIZE = 100;

template<class any_data_type>
class MyStack
{
public:
    MyStack();
    ~MyStack();
    void Push(const any_data_type& element);
    void Pop();
    bool IsFull();
    bool IsEmpty();
    void Travel();
private:
    int size;
    int stack_size;
    any_data_type* sp;
};

template<class any_data_type>
MyStack<any_data_type>::MyStack()
{
size = 0;
stack_size = STACK_SIZE;
sp = new any_data_type[stack_size];
}

template<class any_data_type>
MyStack<any_data_type>::~MyStack()
{
if (NULL != sp)
{
delete sp;
sp = NULL;
}
}

template<class any_data_type>
void MyStack<any_data_type>::Push(const any_data_type& element)
{
if (!IsFull())
{
sp[size++] = element;
}
else
{
stack_size += STACK_SIZE;

any_data_type* temp = new any_data_type[stack_size]; 
for (int i=0; i<size; ++i)
{
temp[i] = sp[i];
}
temp[size++] = element;
sp = temp;
}
}

template<class any_data_type>
void MyStack<any_data_type>::Pop()
{
if (IsEmpty())
{
cout<<"The Stack is empty, no element pop out!"<<endl;
}
else
{
size--;
}
}

template<class any_data_type>
bool MyStack<any_data_type>::IsFull()
{
return size == stack_size - 1;
}

template<class any_data_type>
bool MyStack<any_data_type>::IsEmpty()
{
return size == 0;
}

template<class any_data_type>
void MyStack<any_data_type>::Travel()
{
while(size != 0)
{
cout<<sp[size - 1]<<" ";
size--;
}
cout<<endl;
}

int main()
{
MyStack<int> s;

for (int i=0; i<300; ++i)
{
s.Push(i);
}

s.Travel();




return 0;
}

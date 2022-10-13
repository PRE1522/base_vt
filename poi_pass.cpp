#include <iostream>

using namespace std;

void fun1(int a) 
{
    a = a + 5;
}

void fun2(int &a) 
{
    a = a + 5;
}

void fun3(int *a) 
{
    *a = *a + 10;
}

int main() 
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int number = num;
    fun1(number);
    cout << "number after use fun1: " << number << endl;
    
    number = num;
    fun2(number);
    cout << "number after use fun2: " << number << endl;

    number = num;
    fun3(&number);
    cout << "number after use fun3: " << number << endl;
    
    return 0;
}
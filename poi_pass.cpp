#include <iostream>

using namespace std;

void sum(int a, int b) 
{
    cout << "sum of a,b is : " << a+b << endl;
}

void inc5(int &a, int &b) 
{
    a += 5;
    b += 5;
}

void swap(int *a, int *b) 
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() 
{
    int number1, number2;
    cout << "Enter number 1: ";
    cin >> number1;
    cout << "Enter number 2: ";
    cin >> number2;

    sum(number1, number2);

    inc5(number1, number2);
    cout << "After inc 5:" << endl;
    cout << "number 1: " << number1 << endl;
    cout << "number 2: " << number2 << endl;

    swap(&number1, &number2);
    cout << "After swap:" << endl;
    cout << "number 1: " << number1 << endl;
    cout << "number 2: " << number2 << endl;
    
    return 0;
}
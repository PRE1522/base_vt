#include <iostream>

using namespace std;

void my_swap(int* x, int* y) 
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void my_sort(int* a, const int &n) 
{
    for (int i = 0; i < n-1; ++i)
    {
        for (int j = i+1; j < n; ++j)
        {
            if (a[i] > a[j]) my_swap(a+i, a+j);
        }
    }
    
    //display
    for (int i = 0; i < n; ++i) 
        cout << a[i] << " ";
    cout << endl;
}

int count_even(const int *a, const int &n) 
{
    int res = 0;
    for (int i = 0; i < n; ++i) 
        if (a[i] % 2 == 0) ++res;
    return res;
}

int main() 
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << "Array a after sort descending: ";
    my_sort(a,n);

    cout << "Total even number in array a: " << count_even(a, n) << endl;

    return 0;
}
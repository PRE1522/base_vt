#include <iostream>

using namespace std;

int main() 
{
    int n = 0, choice = 1;
    while (choice != 4) 
    {
        cout << "OPTION:" << endl;
        cout << "\t1. Input an integer number n." << endl;
        cout << "\t2. Check parity." << endl;
        cout << "\t3. Sum of all numbers <= n." << endl;
        cout << "\t4. Quit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)     
        {
        case 1:
            cout << "Enter n: ";
            cin >> n;
            break;
        case 2:
            if (n % 2 == 0) cout << "n is even number." << endl;
            else cout << "n is odd number." << endl; 

            break;
        case 3: 
        {
            int sum = 0;
            for (int i = 1; i <= n; ++i) 
                sum += i;
            cout << "Sum of all numbers <= n is " << sum << endl;
            break;
        }
        case 4:
            cout << "Bye!" << endl;
            break;
        default:
            cout << "Try again!" << endl;
            break;
        }
    }
    return 0;
}
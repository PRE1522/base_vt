#include <iostream>
#include <bits/stdc++.h>
#define oo 1000

using namespace std;

int n;
string s[oo];

int main() 
{
    string x;
    getline(cin, x);
    n = atoi(x.c_str());    
    for (int  i = 0; i < n; ++i) 
    {
        getline(cin, s[i]);
        for (int j = 0; j < s[i].length(); ++j) 
            s[i][j] = toupper(s[i][j]);
    }
    sort(s,s+n);

    for (int  i = 0; i < n; ++i) 
        cout << s[i] << endl;

    return 0;
}

// input list name, output list name toupper order by ascending 
#include <iostream>
#include <cstring>
#include <string>
 
using namespace std;

void to_lower(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] + 32;
        }
    }
}
 
void to_upper(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 32;
        }
    }
}
 
void to_title(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
        if (str[i - 1] == ' ' || i == 0)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] = str[i] - 32;
        }
    }
}
 
int main()
{
    printf("\nEnter a string : ");
    string x; 
    getline(cin, x);
    char s[100];
    strcpy(s, x.c_str());

    to_lower(s);
    printf("\nString in Lowercase = %s\n", s);

    to_upper(s);
    printf("\nString in Uppercase = %s\n", s);
    
    to_title(s);
    printf("\nString in Titlecase = %s\n", s);
    return 0;
}
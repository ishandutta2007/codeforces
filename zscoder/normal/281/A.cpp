#include <iostream>
#include <cstring>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string a;
    cin >> a;
    if(!isupper(a[0]))
    {
        a[0] = toupper(a[0]);
    }
    cout << a;
    return 0;
}
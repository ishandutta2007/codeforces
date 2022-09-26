#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    bool sol = true;
    for (int i = 0; i < n - 1 - i; i++) 
    {
        if (s[i] == '1') sol = false;
        if (s[i] == '2') sol = false;
        if (s[i] == '3' && s[n - 1 - i] != '3') sol = false;
        if (s[i] == '4' && s[n - 1 - i] != '6') sol = false;
        if (s[i] == '5' && s[n - 1 - i] != '9') sol = false;
        if (s[i] == '6' && s[n - 1 - i] != '4') sol = false;
        if (s[i] == '7' && s[n - 1 - i] != '7') sol = false;
        if (s[i] == '8' && s[n - 1 - i] != '0') sol = false;
        if (s[i] == '9' && s[n - 1 - i] != '5') sol = false;
        if (s[i] == '0' && s[n - 1 - i] != '8') sol = false;
    }
    if (n % 2 == 1)
    {
        int id = n / 2;
        if (s[id] != '3' && s[id] != '7')
        {
            sol = false;
        }
    }
    if (sol)
    {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}
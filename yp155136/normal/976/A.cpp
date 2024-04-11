#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >>n;
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    reverse(s.begin(),s.end());
    if (s.front() == '0') cout <<s << endl;
    else
    {
        cout << 1;
        for (char i:s)
        {
            if (i == '0') cout << i;
        }
        cout <<endl;
    }
}
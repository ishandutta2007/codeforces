#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    int now=0;
    for (int i=0;n>i;i++)
    {
        int s,d;
        cin >>s >>d;
        if (now < s) now = s;
        else
        {
            int delta = (now-s);
            delta /= d;
            now = s + (delta+1)*d;
        }
    }
    cout << now << endl;
}
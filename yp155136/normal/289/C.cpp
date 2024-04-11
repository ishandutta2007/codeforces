#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n,k;
    cin >> n >> k;
    if (k > n)
    {
        cout << -1 << endl;
        return 0;
    }
    if (k == 1 && n == 1)
    {
        cout << "a" << endl;
        return 0;
    }
    if (k == 1 && n != 1)
    {
        cout << "-1" << endl;
        return 0;
    }
    string _ = "ab";
    while (n > k)
    {
        cout << _;
        n -= 2;
    }
    if (n == k)
    {
        for (int i='a';'a'+k-1>=i;i++)
        {
            cout << char(i);
        }
        cout << endl;
    }
    else
    {
        cout << 'a';
        for (int i='c';'a'+k-1>=i;i++)
        {
            cout << char(i);
        }
        cout << endl;
    }
}
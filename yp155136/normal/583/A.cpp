#include <bits/stdc++.h>
using namespace std;
bool a[56],b[56];

int main ()
{
    int n;
    cin >> n;
    n = n*n;
    int id=1;
    while (n--)
    {
        int x,y;
        cin >> x >>y;
        if (!a[x] && !b[y])
        {
            cout << id << ' ';
            a[x] = b[y] = 1;
        }
        ++id;
        //a[x] = b[y] = 1;
    }
}
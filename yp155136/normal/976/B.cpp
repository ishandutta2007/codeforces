#include <bits/stdc++.h>
using namespace std;

int main ()
{
    long long n,m,k;
    cin >> n >> m >> k;
    if (k <= n-1)
    {
        cout << 1 + k << ' ' <<1 << endl;
        return 0;
    }
    k -= (n);
    int len = m-1;
    int x = k / len;
    int y = k % len;
    if (x % 2 == 0)
    {
        cout << n - x << ' ' << 2 + y << endl;
    }
    else
    {
        cout << n - x << ' ' << m - y <<endl;
    }
}
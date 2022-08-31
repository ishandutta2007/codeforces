#include <iostream>
using namespace std;

typedef long long llong;

llong n, k;
llong _n, _k;
char get(llong t)
{
    n = _n, k = _k;
    --t;
    if (k == 0)
        return '.';
    else
    {
        if (n % 2 == 1)
        {
            if (t == n - 1)
            {
                return 'X';
            }
            else
                n--, k--;  
        }
        if (n % 2 == 0)
        {
            t = n - 1 - t;
            if (t % 2 == 0)
                return ((t / 2 < k) ? 'X' : '.');
            else
                return ((t / 2 < k - (n / 2)) ? 'X' : '.');
        }
    }
}

int main()
{
    cin >> _n >> _k;
    int q;
    cin >> q;
    if (q == -1)
    {
        for (int i = 1; i <= _n; i++)
            cout << get(i);
        cout << endl;
        return 0;
    }
    llong t;
    for (int i = 0; i < q; i++)
        cin >> t, cout << get(t);
    cout << endl;
    return 0;
}
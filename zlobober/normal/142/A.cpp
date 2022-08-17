#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    typedef long long llong;
    llong n;
    cin >> n;
    long long mn = 1e18, mx = -1e18;
    for (llong a = 1; a <= min(n, 2000LL); a++)
    {
        if (n % a)
            continue;
        for (llong b = a; b * b <= n / a; b++)
        {
            if ((n / a) % b)
                continue;
            llong c = n / a / b;
            if (c < b)
                continue;
            llong U[] = {a, b, c};
            do
            {
                mn = min(mn, (U[0] + 1) * (U[1] + 2) * (U[2] + 2) - U[0] * U[1] * U[2]);
                mx = max(mx, (U[0] + 1) * (U[1] + 2) * (U[2] + 2) - U[0] * U[1] * U[2]);
            } while (next_permutation(U, U + 3));
        }
    }
    cout << mn << ' ' << mx;
}
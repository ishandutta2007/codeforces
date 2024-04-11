#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long x, long long y) {return (y == 0 ? x : gcd(y, x % y));}

int main()
{
    long long n, k, a, b; cin >> n >> k >> a >> b;

    long long arr[4] = {a + b, a - b, -a + b, -a - b};
    long long x = 1e15, y = -1;
    for(int i = 0; i < 4; ++i)
    {
        long long res = (arr[i] + n * k) % (n * k);
        long long g = gcd(k, res);
        long long _k = k / g;
        long long _n = n, _g;
        while((_g = gcd(_n, _k)) != 1) _n /= _g;

        x = min(x, n * k / (g * _n));
        y = max(y, n * k / g);
    }

    cout << x << ' ' << y;
    return 0;
}
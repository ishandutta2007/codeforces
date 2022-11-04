#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;

ll n, mo;

ll sumi(ll a, ll b);

int main()
{
    cin >> n >> mo;
    cout << ((sumi(3, n) - 1) % mo + mo) % mo << endl;
    return 0;
}

ll sumi(ll a, ll b)
{
    ll i, x = a, ret = 1;
    for (i = 1; i <= b; i <<= 1)
    {
        if (i & b)
            ret *= x, ret %= mo;
        x *= x, x %= mo;
    }
    
    return ret;
}
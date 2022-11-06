#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define ll long long

using namespace std;

int n;

ll mod = 998244353;

ll ans, sum;

vector<int> primes;

ll divs[1234567];

ll div(ll x)
{
    ll xx = x;
    for(auto p : primes)
    {
        int times = 1;
        while(x % p == 0)
        {
            x /= p;
            times++;
        }
        if(times > 1)
        {
            divs[xx] = times*divs[x];
            return divs[xx];
        }
    }
    divs[xx] = 2;
    return 2;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 2; i <= 1000; i++)
    {
        bool p = true;
        for(auto j : primes)
        {
            if(i % j == 0)
            {
                p = false;
                break;
            }
        }
        if(p)
            primes.push_back(i);
    }
    ans = 1;
    sum = 1;
    divs[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        ll x = sum;
        x += div(i);
        sum += x;
        sum %= mod;
        ans = x%mod;
    }
    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector<pair<long long, int> > frac(long long x)
{
    vector<pair<long long, int> > ans;
    for(long long i = 2; i * i <= x; ++i)
    {
        if(!(x % i))
        {
            int k = 0;
            while(!(x % i)){x /= i; ++k;}
            ans.push_back({i, k});
        }
    }
    if(x != 1) ans.push_back({x, 1});
    return ans;
}

int main()
{
    long long n, b; cin >> n >> b;
    auto t = frac(b);
    long long ans = -1;
    for(const auto &i : t)
    {
        long long pow = 0; long long _n = n;
        while(_n)
        {
            _n /= i.first;
            pow += _n;
        }
        if(pow / i.second < ans || ans == -1) ans = pow / i.second;
    }
    cout << ans;
    return 0;
}
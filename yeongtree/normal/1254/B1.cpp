#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss

using namespace std;

int n;
int arr[1010101];
long long sm;
long long ans = 8e18;

void f(long long p)
{
    long long ps = 0;
    long long __ans = 0;
    vector<pll> V;
    int mid = -1;

    for(int i = 0; i < n; ++i)
    {
        if(mid == -1 && ps + arr[i] >= (p + 1 >> 1)) mid = i;
        if(ps + arr[i] >= p)
        {
            V.push_back({i, p - ps});
            for(auto &j : V) __ans += abs(j.ff - mid) * j.ss;
            V.clear();
            ps = (arr[i] + ps) % p;
            V.push_back({i, ps});
            mid = -1;
        }
        else V.push_back({i, arr[i]}), ps += arr[i];
        if(mid == -1 && ps >= (p + 1 >> 1)) mid = i;
    }

    ans = min(ans, __ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i], sm += arr[i];

    long long _sm = sm;
    for(int p = 2; 1ll * p * p <= _sm; ++p)
    {
        if(_sm % p == 0)
        {
            while(_sm % p == 0) _sm /= p;
            f(p);
        }
    }
    if(_sm != 1) f(_sm);

    cout << (ans == (long long)8e18 ? -1 : ans);
}
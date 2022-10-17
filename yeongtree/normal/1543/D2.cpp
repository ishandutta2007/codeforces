#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss
#define DEBUG
const int INF = (int)1e9 + 7;

using namespace std;

int sub(int x, int k)
{
    int ret = 0;
    int a = 1;
    while(x)
    {
        ret += (x % k == 0 ? 0 : a * (k - x % k));
        a *= k;
        x /= k;
    }
    return ret;
}

int sum(int x, int y, int k)
{
    int ret = 0;
    int a = 1;
    while(x || y)
    {
        ret += a * ((x + y) % k);
        a *= k;
        x /= k; y /= k;
    }
    return ret;
}

int main()
{
    int T; cin >> T;
    while(T--)
    {
        int n, k; cin >> n >> k;
        int t = 0;
        for(int i = 0; i < n; ++i)
        {
             int q = (i & 1 ? sum(t, sub(i, k), k) : sum(t, i, k));
             cout << q << endl; cout.flush();
             int r; cin >> r;
             if(r == 1) break;
             t = sum(q, sub(t, k), k);
        }
    }
}
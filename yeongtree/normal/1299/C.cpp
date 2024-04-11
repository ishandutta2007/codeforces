#include <iostream>
#include <vector>
#include <iomanip>
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int arr[n]; for(auto &i : arr) cin >> i;
    vector<pll> Q;
    for(int i = 0; i < n; ++i)
    {
        pll tmp = {arr[i], 1};
        while(Q.size() && Q.back().ff * (Q.back().ss + tmp.ss) >= (Q.back().ff + tmp.ff) * Q.back().ss)
            tmp.ff += Q.back().ff, tmp.ss += Q.back().ss, Q.pop_back();
        Q.push_back(tmp);
    }
    cout << fixed << setprecision(10);
    for(auto &i : Q)
    {
        long double ans = (long double)i.ff / i.ss;
        for(int j = 0; j < i.ss; ++j)
            cout << ans << '\n';
    }
}
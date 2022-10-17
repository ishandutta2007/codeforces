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

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> V;
    for(int i = 1; 2ll * i * i <= (long long)1e9; ++i) V.push_back(2 * i * i);
    for(int i = 1; 4ll * i * i <= (long long)1e9; ++i) V.push_back(4 * i * i);
    sort(V.begin(), V.end());

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        if(*lower_bound(V.begin(), V.end(), n) == n) cout << "YES\n";
        else cout << "NO\n";
    }
}
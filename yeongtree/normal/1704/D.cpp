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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, m; cin >> n >> m;
        vector<long long> V;
        for(int i = 0; i < n; ++i)
        {
            long long t = 0;
            for(int j = 0; j < m; ++j)
            {
                int x; cin >> x;
                t += 1ll * x * (m - j);
            }
            V.push_back(t);
        }
        cout << min_element(V.begin(), V.end()) - V.begin() + 1 << ' '
             << *max_element(V.begin(), V.end()) - *min_element(V.begin(), V.end()) << '\n';
    }
}
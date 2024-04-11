#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <map>
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
        int n, k; cin >> n >> k;
        map<int, int> M;
        for(int i = 0; i < n; ++i)
        {
            int x; cin >> x;
            M[x]++;
        }
        vector<pii> V;
        for(auto i : M) V.push_back(i);
        int N = V.size();

        int cnt = 0, pt = 0, ed = 0;
        for(; ed < n; ++ed)
        {
            if(pt < N && V[pt].ff == ed) ++pt;
            else ++cnt;
            if(cnt > k) break;
        }

        vector<int> W;
        for(int i = pt; i < N; ++i) W.push_back(V[i].ss);
        sort(W.begin(), W.end(), greater<int>());

        while(W.size() && k >= W.back()) k -= W.back(), W.pop_back();
        cout << W.size() << '\n';
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
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

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int A[n]; int cnt[n]{};
        for(auto &i : A) cin >> i, --i, ++cnt[i];
        bool chc[n - 1]{};
        vector<pii> V;
        for(int i = 0; i < n - 1; ++i) if(A[i] != A[i + 1])
        {
            if(cnt[A[i]] >= cnt[A[i + 1]]) V.push_back({A[i], A[i + 1]});
            else V.push_back({A[i + 1], A[i]});
        }
        sort(V.begin(), V.end(), [&cnt](pii x, pii y){ return (cnt[x.ff] == cnt[y.ff] ? cnt[x.ss] > cnt[y.ss] : cnt[x.ff] > cnt[y.ff]); });

        int ind[n << 1];
        for(int i = 0; i < n; ++i) ind[i + n] = cnt[i] << 1;
        for(int i = n - 1; i >= 1; --i) ind[i] = max(ind[i << 1], ind[i << 1 | 1]);
        if(ind[1] > n + 1) cout << "-1\n";

        else
        {
            int m = n;
            for(auto i : V)
            {
                int x;
                x = i.ff + n;
                --ind[x]; while(x >>= 1) ind[x] = max(ind[x << 1], ind[x << 1 | 1]);
                x = i.ss + n;
                --ind[x]; while(x >>= 1) ind[x] = max(ind[x << 1], ind[x << 1 | 1]);
                --m;

                if(ind[1] > m + 1)
                {
                    x = i.ff + n;
                    ++ind[x]; while(x >>= 1) ind[x] = max(ind[x << 1], ind[x << 1 | 1]);
                    x = i.ss + n;
                    ++ind[x]; while(x >>= 1) ind[x] = max(ind[x << 1], ind[x << 1 | 1]);
                    ++m;
                }
            }
            cout << m - 1 << '\n';
        }
    }
}
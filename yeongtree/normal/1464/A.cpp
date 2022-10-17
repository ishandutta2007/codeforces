#include <iostream>
#include <vector>
#include <algorithm>
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

    int T; cin >> T;
    while(T--)
    {
        int n, m; cin >> n >> m;
        pii A[m]; for(auto &i : A) cin >> i.ff >> i.ss, --i.ff, --i.ss;
        int X[n], Y[n]; for(auto &i : X) i = -1; for(auto &i : Y) i = -1;
        for(int i = 0; i < m; ++i) X[A[i].ff] = i, Y[A[i].ss] = i;
        bool vst[m]{}; int ans = m;
        for(int i = 0; i < m; ++i) if(!vst[i])
        {
            if(A[i].ff == A[i].ss) { vst[i] = true; --ans; continue; }
            vst[i] = true;
            int pt = i;
            bool ver = false;
            while(1)
            {
                if(ver) pt = X[A[pt].ss];
                else pt = Y[A[pt].ff];
                if(pt == -1) break;
                if(pt == i) { ++ans; break; }
                vst[pt] = true;
            }
        }
        cout << ans << '\n';
    }
}
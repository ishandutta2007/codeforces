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

long long dst(pii x, pii y)
{
    return 1ll * (x.ff - y.ff) * (x.ff - y.ff) + 1ll * (x.ss - y.ss) * (x.ss - y.ss);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    pii A[n]; for(int i = 0; i < n; ++i) cin >> A[i].ff >> A[i].ss;
    bool vst[n]{};

    cout << "1 ";
    int pr = 0; vst[0] = true;

    for(int i = 1; i < n; ++i)
    {
        int nxt = -1;
        for(int j = 0; j < n; ++j) if(!vst[j])
        {
            if(nxt == -1 || dst(A[pr], A[nxt]) < dst(A[pr], A[j])) nxt = j;
        }

        cout << nxt + 1 << ' ';
        pr = nxt;
        vst[pr] = true;
    }
}
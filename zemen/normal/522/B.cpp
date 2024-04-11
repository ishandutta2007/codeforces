#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    freopen("b.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 300001;

int w[maxn];
int h[maxn];

int solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        scanf("%d%d", w + i, h + i);
    int max1 = 0, max2 = 0;
    for (int i = 0; i < n; ++i)
        if (max1 < h[i])
        {
            max2 = max1;
            max1 = h[i];
        }
        else if (max2 < h[i])
            max2 = h[i];
    ll W = accumulate(w, w + n, 0ll);
    for (int i = 0; i < n; ++i)
    {
        ll H = (max1 == h[i] ? max2 : max1);
        if (i)
            cout << ' ';
        cout << (W - w[i]) * H;
    }
    cout << '\n';
    return 0;
}
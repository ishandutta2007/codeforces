#include <iostream>
#include <string>
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
    int A[n]{}, B[n]{};
    for(int i = 0; i < n; ++i)
    {
        string s; cin >> s;
        for(auto c : s)
        {
            if(c == 'B') ++A[i];
            else ++B[i];
        }
    }

    pii a, b, c; a = b = c = {(int)1e9, -(int)1e9};
    for(int i = 0; i < n; ++i)
    {
        a.ff = min(a.ff, A[i]);
        a.ss = max(a.ss, A[i]);
        b.ff = min(b.ff, B[i]);
        b.ss = max(b.ss, B[i]);
        c.ff = min(c.ff, A[i] - B[i]);
        c.ss = max(c.ss, A[i] - B[i]);
    }

    int ans = (int)1e9;
    int ansa = -1, ansb = -1;
    int MAX = (int)1e6;
    for(int i = 0; i < MAX; ++i)
    {
        int k = max(abs(b.ff - i), abs(b.ss - i));
        int s = min(a.ff, c.ff + i);
        int t = max(a.ss, c.ss + i);
        int d = (s + t) / 2;
        int l = (d < 0 ? -s : t - d);
        if(i == 0) l = (d < 1 ? 1 - s : t - d);
        if(ans > max(k, l))
        {
            ans = max(k, l);
            ansb = i;
            ansa = max(d, 0);
            if(i == 0) ansa = max(d, 1);
        }
    }

    cout << ans << '\n';
    for(int i = 0; i < ansa; ++i) cout << 'B';
    for(int i = 0; i < ansb; ++i) cout << 'N';
}
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 300500, inf = 1e9, mod = 998244353;

int sum(int a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
    return a;
}
int sub(int a, int b){
    a -= b;
    if(a < 0)
        a += mod;
    return a;
}
int mult(int a, int b){
    return 1ll * a * b % mod;
}
int bp(int a, int b){
    int res = 1;
    while(b){
        if(b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}
int inv(int x){
    return bp(x, mod - 2);
}

int n, m, a[N], b[N];
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        a[i]--;
    }
    sort(a, a + m);
    for(int i = 0; i < m; i++)
        b[i] = (a[(i + 1) % m] - a[i] + n - 1) % n;
    sort(b, b + m);
    reverse(b, b + m);
    int ans = m;
    int cur = 0;
    for(int i = 0; i < m; i++) {
        {
            int x = min(b[i], 2 * cur);
            b[i] -= x;
            ans += x;
            cur++;
            b[i] = max(b[i] - 1, 0);
        }
        {
            int x = min(b[i], 1);
            b[i] -= x;
            ans += x;
            cur++;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

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
int mul(int a,int b){
    return 1ll * a * b % mod;
}
int bp(int a, int b){
    int c = 1;
    while(b){
        if(b & 1)
            c = mul(c, a);
        a = mul(a, a);
        b >>= 1;
    }
    return c;
}
int inv(int a){
    return bp(a, mod - 2);
}

int n, k;
ll a[N], b[N];


void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }
    ll ans = 0;
    if(k >= n)
        ans = b[n] + 1ll * k * n - 1ll * n * (n + 1) / 2;
    for(int i = 1; i <= n; i++) {
        int l = i;
        int r = min(n, i + k - 1);
        ans = max(ans, b[r] - b[l - 1] + 1ll * (r - l + 1) * (r - l) / 2);
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    //    freopen("input.txt","r",stdin);
    //    freopen("output.txt","w",stdout);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
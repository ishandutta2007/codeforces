#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e6 + 123, inf = 1e9, mod = 1e9 + 7;
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

int n, a[N];

const int M = 2e6 + 100;

int prv[M];

void flex(ll &l, ll &r, int x, int &k){
    l = max(l, 1ll * (k - 1) * (k - 1) - x);
    r = min(r, 1ll * (k - 1) * k - x);
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        prv[a[i]] = i;
    }

    for(int i = 0; i < a[0]; i++)
        prv[i] = 0;
    for(int i = 1; i < n; i++)
        for(int j = a[i]; j < a[i + 1]; j++)
            prv[j] = i;
    for(int i = a[n]; i < M; i++)
        prv[i] = n;

    for(int i = 2; i < M; i++){

        ll l = 0;
        ll r = INF;

        int k = i;
        int cur = 1;
        while (l <= r && cur <= n){
            while(1ll * (k - 1) * k < l + a[cur])
                k++;
            int nxt = prv[min(M - 1, a[cur] + k - 1)] + 1;
            flex(l, r, a[cur], k);
            flex(l, r, a[nxt - 1], k);
            cur = nxt;
        }
        if(l <= r){
            cout << l << endl;
            return;
        }
    }
    assert(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    //    freopen("input.txt","r",stdin);
    //    freopen("output.txt","w",stdout);
    int t = 1;
//    cin >> t;
    while (t--)
        solve();
}
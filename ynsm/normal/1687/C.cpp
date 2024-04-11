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

vector< int > g[N];
int n, m;
ll a[N];

void solve() {
    cin >> n >> m;
    for(int i = 0; i <= n; i++) {
        a[i] = 0;
        g[i].clear();
    }
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] += x;
    }
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] -= x;
    }
    for(int i = 1; i <= n; i++)
        a[i] += a[i - 1];

    for(int i = 1; i <= m;i++){
        int l, r;
        cin >> l >> r;
        l--;
        g[r].pb(l);
        g[l].pb(r);
    }

    queue< int > q;
    for(int i = 0; i <= n; i++)
        if(a[i] == 0)
            q.push(i);

    set< int > st;
    for(int i = 0; i <= n; i++)
        st.insert(i);
    st.insert(n + 1);

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto u : g[v]){
            if(a[u] != 0)
                continue;
            while(true){
                int w = *st.lower_bound(min(v, u));
                if(w > max(v, u))
                    break;
                st.erase(w);
                a[w] = 0;
                q.push(w);
            }
        }
    }
    bool ok = 1;
    for(int i = 0; i <= n; i++)
        ok &= (a[i] == 0);
    if( ok == 1)
        cout << "Yes" <<endl;
    else
        cout << "No" << endl;
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
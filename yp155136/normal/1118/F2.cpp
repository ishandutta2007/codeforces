#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
const int N = 300006;
const ll mod = 998244353;

#define F first
#define S second

vector<int> G[N];

int a[N];
int par[N];
int d[N];

void no() {
    puts("0");
    exit(0);
}

void dfs(int now,int ppar,int cur_depth) {
    par[now] = ppar;
    d[now] = cur_depth;
    for (int i:G[now]) {
        if (i == ppar) continue;
        dfs(i,now,cur_depth+1);
    }
}

vector<int> v[N];

int used[N]; //i --> par[i]

ll ans=1;

int vis[N], vis_id = 880301;

vector<int> saki;
int root;

ll ppow(ll a,ll n) {
    ll ret=1,now=a;
    while (n) {
        if (n&1) {
            ret *= now;
            ret %= mod;
        }
        now *= now;
        now %= mod;
        n >>= 1;
    }
    return ret;
}

ll rev(ll x) {
    return ppow(x,mod-2);
}

ll pre[N],suf[N];
ll yuuki[N];

pii dpp(int now,int par) {
    //cout << "now = " << now << " , par = "<< par <<" , a[now] = " << a[now] << endl;
    if (a[now] != 0) {
        return make_pair(1,1);
    }
    vector<pii> dps;
    ll all=1;
    for (int i:G[now]) {
        if (i != par && vis[i] == vis_id) {
            pii ret = dpp(i,now);
            if (ret != make_pair(0ll,0ll))dps.push_back(ret);
            //cout << "now = " << now << " , i = " << i << " , ret = " << ret.F << " , " << ret.S << endl;
        }
    }
    int n = (int)dps.size();
    for (int i=0;i<n;++i) {
        yuuki[i+1] = dps[i].S;
    }
    pre[0] = 1;
    for (int i=1;i<=n;++i) {
        pre[i] = pre[i-1] * yuuki[i];
        pre[i] %= mod;
    }
    suf[n+1] = 1;
    for (int i=n;i>=1;--i) {
        suf[i] = suf[i+1] * yuuki[i];
        suf[i] %= mod;
    }
    for (pii p:dps) {
        all *= p.S;
        all %= mod;
    }
    pii ret = make_pair(0,0);
    int gee = 0;
    for (pii p:dps) {
        ++gee;
        ret.F += pre[gee-1] * suf[gee+1] % mod * p.F % mod;
        ret.F %= mod;
    }
    ret.S = all;
    if (now != par) {
        ret.S += ret.F;
        ret.S %= mod;
    }
    if (dps.size() == 0) ret.F = ret.S = 0;
    //cout << "now = " << now << " , ret = " << ret.F << " , " << ret.S << endl;
    return ret;
}

void solve(vector<int> v) {
    //cout << "solveing "; for (int i:v) cout << i << ' '; cout << endl;
    int is0=0;
    for (int i:v) {
        if (a[i] == 0) is0++;
    }
    if ((int)v.size() - is0 == 1 || is0 == 0) return;
    if ((int)v.size() == 2) {
        ans *= 1;
        return;
    }
    ++vis_id;
    for (int i:v) {
        vis[i] = vis_id;
    }
    for (int i:v) {
        if (a[i] == 0) {
            pii ret = dpp(i,i);
            ans *= ret.F;
            ans %= mod;
            break;
        }
    }
    return;
}

void dfs2(int now,int ptr,int ori_col) {
    //cerr << "now = " << now << " , ptr = " << ptr << " , ! = " << ori_col << endl;
    if (a[now] && a[now] != ori_col) {
        //ans *= ptr;
        //ans %= mod;
        saki.push_back(now);
        return;
    }
    saki.push_back(now);
    for (int i:G[now]) {
        int a=now,b = i;
        if (d[a] > d[b]) swap(a,b);
        if (used[b] != -1) continue;
        used[b] = ori_col;
        if (now == root) saki.clear();
        dfs2(i,ptr+1,ori_col);
        if (now == root) saki.push_back(root);
        if (now == root) solve(saki);
    }
}

int main () {
    int n,k; scanf("%d%d",&n,&k);
    //int n; scanf("%d",&n); int k = 2;
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
        if (a[i]) {
            v[ a[i] ].push_back(i);
        }
    }
    for (int i=1;i<n;++i) {
        int x,y; scanf("%d%d",&x,&y);
        G[x].push_back(y); G[y].push_back(x);
    }
    dfs(1,1,1);
    memset(used,-1,sizeof(used));
    for (int i=1;i<=k;++i) {
        set<pii> st;
        for (int j:v[i]) {
            st.insert(make_pair(-d[j],j));
        }
        while (st.size() != 1) {
            pii p = *(st.begin());
            st.erase(st.begin());
            int id = p.S;
            if (a[id] == 0)  a[id] = i;
            if (a[id] != 0 && a[id] != i) {
                no();
            }
            if (used[id] != -1) {
                no();
            }
            used[id] = i;
            st.insert(make_pair(-d[ par[id] ],par[id]));
        }
        int _ = st.begin()->S;
        if (a[_] == 0) a[_] = i;
        if (a[_] != i) no();
    }
    //ll ans = 1;
    //cerr << "haha " << endl;
    for (int i=1;i<=n;++i) {
        if (a[i]) {
            root = i;
            dfs2(i,0,a[i]);
        }
    }
    printf("%lld\n",ans%mod);
}
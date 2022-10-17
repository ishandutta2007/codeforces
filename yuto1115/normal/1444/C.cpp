//@formatter:off
#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); ++i)
#define rrep(i,n) for (int i = int(n)-1; i >= 0; i--)
#define rep2(i,s,n) for (int i = int(s); i < int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vp vector<P>
#define vvp vector<vector<P>>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using LP = pair<ll,ll>;
template<class S,class T> istream& operator>>(istream &is,pair<S,T> &p) { return is >> p.first >> p.second; }
template<class S,class T> ostream& operator<<(ostream &os,const pair<S,T> &p) { return os<<'{'<<p.first<<","<<p.second<<'}'; }
template<class T> istream& operator>>(istream &is,vector<T> &v) { for(T &t:v){is>>t;} return is; }
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) { os<<'[';rep(i,v.size())os<<v[i]<<(i==int(v.size()-1)?"":","); return os<<']'; }
void Yes(bool b) { cout << (b ? "Yes" : "No") << '\n'; }
void YES(bool b) { cout << (b ? "YES" : "NO") << '\n'; }
template<class T> bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;
//@formatter:on

class unionfind {
    int n;
    vector<int> par, rank;
public:
    unionfind(int n) : n(n), par(n, -1), rank(n, 0) {}
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool same(int x, int y) { return root(x) == root(y); };
    
    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) rank[x]++;
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) { return -par[root(x)]; };
    
    bool connected() {
        rep(i, n - 1) if (!same(i, i + 1)) return false;
        return true;
    }
};

template<typename T>
class weight_unionfind {
    vi par, rank;
    vector<T> diff_weight;
public:
    weight_unionfind(int n) : par(n, -1), rank(n, 0), diff_weight(n, 0) {}
    
    int root(int x) {
        if (par[x] < 0) return x;
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }
    
    T weight(int x) {
        root(x);
        return diff_weight[x];
    }
    
    bool same(int x, int y) { return root(x) == root(y); }
    
    bool merge(int x, int y, T w) {
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) rank[x]++;
        par[x] += par[y];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }
    
    T diff(int x, int y) {
        assert(same(x, y));
        return weight(y) - weight(x);
    }
    
    void reset(int x) {
        par[x] = -1;
        rank[x] = 0;
        diff_weight[x] = 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vi c(n);
    rep(i, n) {
        cin >> c[i];
        c[i]--;
    }
    vvi G(n);
    unionfind uf(n);
    map<P, vp > mp;
    rep(_, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (c[a] == c[b]) {
            G[a].pb(b);
            G[b].pb(a);
            uf.merge(a, b);
        } else {
            if (c[a] > c[b]) swap(a, b);
            mp[{c[a], c[b]}].eb(a, b);
        }
    }
    vi ok(k, true);
    int cnt = k;
    vi cl(n, -1);
    auto dfs = [&](auto &self, int v, int p, int nc) -> void {
        cl[v] = nc;
        for (int u : G[v]) {
            if (u == p) continue;
            if (cl[u] != -1) {
                if (cl[u] == nc) {
                    ok[c[v]] = false;
                    return;
                }
            } else {
                self(self, u, v, 1 - nc);
            }
        }
    };
    rep(i, n) {
        if (cl[i] != -1) continue;
        dfs(dfs, i, -1, 0);
    }
    rep(i, k) {
        if (!ok[i]) cnt--;
    }
    vi rt;
    rep(i, n) {
        if (uf.root(i) == i) rt.pb(i);
    }
    int sz = rt.size();
    weight_unionfind<int> wf(sz);
    int ng = 0;
    for (auto[cp, es] : mp) {
        if (!ok[cp.first]) continue;
        if (!ok[cp.second]) continue;
        bool flag = false;
        vi hist;
        for (auto[a, b] : es) {
            int f = (cl[a] == cl[b] ? 1 : 0);
            a = uf.root(a);
            b = uf.root(b);
            a = lower_bound(all(rt), a) - rt.begin();
            b = lower_bound(all(rt), b) - rt.begin();
            if (wf.same(a, b)) {
                if ((wf.diff(a, b) & 1) != f) flag = true;
            } else {
                wf.merge(a, b, f);
            }
            hist.pb(a);
            hist.pb(b);
        }
        if (flag) ng++;
        for (int i : hist) wf.reset(i);
    }
    cout << (ll) cnt * (cnt - 1) / 2 - ng << endl;
}
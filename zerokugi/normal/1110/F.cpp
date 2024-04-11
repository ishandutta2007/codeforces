#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define __builtin_popcount __builtin_popcountll
#define endl '\n'

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
    os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
    os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const map<S, T> &t) {
    os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first-t.first, s.second-t.second);}

const ll INF = 1ll<<50;
const double EPS = 1e-8;
const int MOD = 1000000007;

struct handler{
    typedef ll val_t;
    typedef ll opr_t;
    handler(){}
    val_t def_val(){ return INF; }
    opr_t def_lazy(){ return 0; }
    static val_t resolve(const val_t &x, const opr_t &y, int l, int r){
        return x + y;
    }
    static opr_t push(const opr_t &x, const opr_t &y){
        return x + y;
    }
    static val_t merge(const val_t &x, const val_t &y){
        return min(x, y);
    }
};

template<typename Handler>
struct SegTreeLazy{
    typedef typename Handler::val_t val_t;
    typedef typename Handler::opr_t opr_t;
    vector<val_t> val;
    vector<opr_t> lazy;
    Handler hdl;
    int n;

    SegTreeLazy(int size):hdl(){
        n=1;
        while(n<size) n<<=1;
        val=vector<val_t>(2*n, hdl.def_val());
        lazy=vector<opr_t>(2*n, hdl.def_lazy());
    }

    SegTreeLazy(const vector<val_t> &in):hdl(){
        n=1;
        while(n<in.size()) n<<=1;
        val=vector<val_t>(2*n, hdl.def_val());
        lazy=vector<opr_t>(2*n, hdl.def_lazy());
        for(int i=n-1 + in.size()-1;i>=0;i--){
            if(n-1 <= i) val[i] = in[i - (n-1)];
            else val[i] = hdl.merge(val[i*2+1],val[i*2+2]);
        }
    }
    val_t update(int a,int b,opr_t x, int k,int l,int r){
        if(r<=a||b<=l) return hdl.resolve(val[k], lazy[k], l, r);
        if(a<=l&&r<=b){
            lazy[k] = hdl.push(lazy[k], x);
            return hdl.resolve(val[k], lazy[k], l, r);
        }
        lazy[k*2+1] = hdl.push(lazy[k*2+1], lazy[k]);
        lazy[k*2+2] = hdl.push(lazy[k*2+2], lazy[k]);
        lazy[k] = hdl.def_lazy();
        return val[k] = hdl.merge(update(a, b, x, k*2+1, l, (l+r)/2),
                                  update(a, b, x, k*2+2, (l+r)/2, r));
    }
    val_t query(int a,int b,int k,int l,int r){
        if(r<=a||b<=l) return hdl.def_val();
        if(a<=l&&r<=b) return hdl.resolve(val[k], lazy[k], l, r);
        val[k] = hdl.resolve(val[k], lazy[k], l, r);
        lazy[k*2+1] = hdl.push(lazy[k*2+1], lazy[k]);
        lazy[k*2+2] = hdl.push(lazy[k*2+2], lazy[k]);
        lazy[k] = hdl.def_lazy();
        return hdl.merge(query(a, b, k*2+1, l, (l+r)/2),
                         query(a, b, k*2+2, (l+r)/2, r));
    }
    val_t update(int a, int b, opr_t x){return update(a, b, x, 0, 0, n);}
    val_t query(int a, int b){return query(a, b, 0, 0, n);}
    val_t operator[](size_t i){return query(i, i+1);}
    friend ostream& operator<<(ostream &os, SegTreeLazy<Handler> &t){
        REP(i, t.n) os << (i ? ", " : "[") << t.query(i, i+1);
        return os << "]";
    }
};


int T, n, m;
vector<vector<pii>> g;
vector<vector<tuple<int, int, int>>> qs;
SegTreeLazy<handler> seg(0);
vector<ll> seg_in;
vector<ll> ans;
vector<int> cnt;

void fill_seg_in(int u, ll d) {
    if (g[u].empty()) seg_in[u] = d;
    cnt[u] = 1;
    for (auto e : g[u]) {
        int v, w; tie(v, w) = e;
        fill_seg_in(v, d + w);
        cnt[u] += cnt[v];
    }
}

void dfs(int u) {
    for (auto t : qs[u]) {
        int i, l, r; tie(i, l, r) = t;
        ans[i] = seg.query(l, r);
    }
    for (auto e : g[u]) {
        int v, w; tie(v, w) = e;
        seg.update(0, n, w);
        seg.update(v, v + cnt[v], -2 * w);
        dfs(v);
        seg.update(0, n, -w);
        seg.update(v, v + cnt[v], 2 * w);
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n >> m){
        g.resize(n);
        qs.resize(n);
        ans.resize(m);
        seg_in.resize(n, INF);
        cnt.resize(n);
        REPS(u, n - 1) {
            int v, w;
            cin >> v >> w; v--;
            g[v].emplace_back(u, w);
        }
        REP(i, m) {
            int u, l, r;
            cin >> u >> l >> r; u--; l--;
            qs[u].emplace_back(i, l, r);
        }
        fill_seg_in(0, 0);
        seg = SegTreeLazy<handler>(seg_in);
        dfs(0);
        REP(i, m) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
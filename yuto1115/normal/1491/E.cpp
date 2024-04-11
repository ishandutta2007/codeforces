//@formatter:off
#include<bits/stdc++.h>
#define overload4(_1,_2,_3,_4,name,...) name
#define rep1(i,n) for (ll i = 0; i < ll(n); ++i)
#define rep2(i,s,n) for (ll i = ll(s); i < ll(n); ++i)
#define rep3(i,s,n,d) for(ll i = ll(s); i < ll(n); i+=d)
#define rep(...) overload4(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep1(i,n) for (ll i = ll(n)-1; i >= 0; i--)
#define rrep2(i,n,t) for (ll i = ll(n)-1; i >= (ll)t; i--)
#define rrep3(i,n,t,d) for (ll i = ll(n)-1; i >= (ll)t; i-=d)
#define rrep(...) overload4(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define popcount(x) __builtin_popcount(x)
#define pb push_back
#define eb emplace_back
#ifdef __LOCAL
#define debug(...) { cout << #__VA_ARGS__; cout << ": "; print(__VA_ARGS__); cout << flush; }
#else
#define debug(...) void(0)
#endif
#define INT(...) int __VA_ARGS__;scan(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;scan(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;scan(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;scan(__VA_ARGS__)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,int>;
using LP = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using vs = vector<string>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vp = vector<P>;
using vvp = vector<vector<P>>;
template<class S,class T> istream& operator>>(istream &is,pair<S,T> &p) { return is >> p.first >> p.second; }
template<class S,class T> ostream& operator<<(ostream &os,const pair<S,T> &p) { return os<<'{'<<p.first<<","<<p.second<<'}'; }
template<class T> istream& operator>>(istream &is,vector<T> &v) { for(T &t:v){is>>t;} return is; }
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) { os<<'[';rep(i,v.size())os<<v[i]<<(i==int(v.size()-1)?"":","); return os<<']'; }
template<class T> void vecout(const vector<T> &v,char div='\n') { rep(i,v.size()) cout<<v[i]<<(i==int(v.size()-1)?'\n':div);}
template<class T> bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
void scan(){}
template <class Head, class... Tail> void scan(Head& head, Tail&... tail){ cin >> head; scan(tail...); }
template<class T> void print(const T& t){ cout << t << '\n'; }
template <class Head, class... Tail> void print(const Head& head, const Tail&... tail){ cout<<head<<' '; print(tail...); }
template<class... T> void fin(const T&... a) { print(a...); exit(0); }
const string yes[] = {"no","yes"};
const string Yes[] = {"No","Yes"};
const string YES[] = {"NO","YES"};
const int inf = 1001001001;
const ll linf = 1001001001001001001;
//@formatter:on

template<typename T>
class BIT {
    int n;
    vector<T> val;
public:
    BIT(int n) : n(n), val(n + 1, 0) {}
    
    void add(int i, T x = 1) {
        i++;
        while (i <= n) {
            val[i] += x;
            i += i & -i;
        }
    }
    
    T sum(int i) {
        T ret = 0;
        i++;
        while (i > 0) {
            ret += val[i];
            i -= i & -i;
        }
        return ret;
    }
    
    // [l,r)
    T sum(int l, int r) { return sum(r - 1) - sum(l - 1); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vi fibo(30, 1);
    rep(i, 2, 30) fibo[i] = fibo[i - 1] + fibo[i - 2];
    map<int, int> mp;
    rep(i, 1, 30) mp[fibo[i]] = i;
    INT(n);
    vvi G(n);
    rep(i, n - 1) {
        INT(u, v);
        u--, v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    if (!mp.count(n)) fin(YES[0]);
    vi in(n), out(n);
    int k = 0;
    auto dfs = [&](auto &dfs, int u, int p) -> void {
        in[u] = k++;
        for (int v : G[u]) {
            if (v == p) continue;
            dfs(dfs, v, u);
        }
        out[u] = k++;
    };
    dfs(dfs, 0, -1);
    BIT<int> bt(k);
    rep(i, n) bt.add(in[i]);
    vi cnt(n);
    auto f = [&](auto &f, int u, int p) -> void {
        debug(u, p);
        int sz = bt.sum(in[u], out[u]);
        debug(sz);
        if (sz == 1) {
            bt.add(in[u], -1);
            return;
        }
        int ind = mp[sz];
        int nd = fibo[ind - 1];
        int pos = -1, pre;
        auto g = [&](auto &g, int nu, int np) -> void {
            cnt[nu]++;
            assert(cnt[nu] <= 30);
            debug(nu, np);
            int now = bt.sum(in[nu], out[nu]);
            if (now == nd or now == sz - nd) {
                pos = nu, pre = np;
                return;
            }
            for (int nv : G[nu]) {
                if (nv == np) continue;
                if(bt.sum(in[nv],out[nv]) == 0) continue;
                g(g, nv, nu);
            }
        };
        g(g, u, p);
        if (pos == -1) fin(YES[0]);
        f(f, pos, pre);
        f(f, u, p);
    };
    f(f, 0, -1);
    print(YES[1]);
}
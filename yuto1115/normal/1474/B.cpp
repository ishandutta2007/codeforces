//@formatter:off
#include<bits/stdc++.h>
#define overload4(_1,_2,_3,_4,name,...) name
#define rep1(i,n) for (ll i = 0; i < ll(n); ++i)
#define rep2(i,s,n) for (ll i = ll(s); i < ll(n); ++i)
#define rep3(i,s,n,d) for(ll i = ll(s); i < ll(n); i+=d)
#define rep(...) overload4(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep(i,n) for (ll i = ll(n)-1; i >= 0; i--)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
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
template<class T> bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
void scan(){}
template <class Head, class... Tail> void scan(Head& head, Tail&... tail){ cin >> head; scan(tail...); }
template<class T> void print(const T& t){ cout << t << '\n'; }
template <class Head, class... Tail> void print(const Head& head, const Tail&... tail){ cout<<head<<' '; print(tail...); }
//const string yes = {"no","yes"};
//const string Yes = {"No","Yes"};
//const string YES = {"NO","YES"};
const int inf = 1001001001;
const ll linf = 1001001001001001001;
//@formatter:on

class sieve {
    int n;
    vi val;
    
    void init() {
        rep(i, n + 1) val[i] = i;
        for (int i = 2; i * i <= n; i++) {
            if (val[i] != i) continue;
            for (int j = i * 2; j <= n; j += i) {
                if (val[j] == j) val[j] = i;
            }
        }
    }

public:
    sieve(int n) : n(n), val(n + 1) {
        init();
    }
    
    map<int, int> factorlist(int x) {
        if (n < 2) return {};
        map<int, int> ret;
        int now = x;
        while (now > 1) {
            ret[val[now]]++;
            now /= val[now];
        }
        return ret;
    }
    
    vi unique_factor(int x) {
        map<int, int> m = factorlist(x);
        vi ret;
        for (P p : m) ret.pb(p.first);
        return ret;
    };
    
    bool isPrime(int x) {
        return x >= 2 and val[x] == x;
    }
    
    int count_divisor(int x) {
        int ret = 1;
        map<int, int> fl = factorlist(x);
        for (auto p : fl) ret *= p.second + 1;
        return ret;
    };
} sv(30010);

vi ls;

void solve() {
    INT(d);
    ll ans = 1;
    ans *= *lower_bound(all(ls), 1 + d);
    ans *= *lower_bound(all(ls), ans + d);
    print(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    rep(i, 2, 30010) if (sv.isPrime(i)) ls.pb(i);
    int t;
    cin >> t;
    rep(i, t) solve();
}
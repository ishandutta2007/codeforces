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

template<class Monoid>
class segtree {
    using T = typename Monoid::value_type;
    
    int n;
    vector<T> val;

public:
    constexpr segtree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        val = vector<T>(2 * n, Monoid::identity);
    }
    
    constexpr segtree(const vector<T> &init) {
        int _n = init.size();
        n = 1;
        while (n < _n) n *= 2;
        val = vector<T>(2 * n, Monoid::identity);
        rep(i, _n) val[i + n] = init[i];
        rrep(i, n) val[i] = Monoid::operate(val[i * 2], val[i * 2 + 1]);
    }
    
    // segment [l,r)
    T fold(int l, int r) {
        l += n, r += n;
        T fold_l = Monoid::identity;
        T fold_r = Monoid::identity;
        while (l < r) {
            if (l & 1) fold_l = Monoid::operate(fold_l, val[l++]);
            if (r & 1) fold_r = Monoid::operate(val[--r], fold_r);
            l >>= 1, r >>= 1;
        }
        return Monoid::operate(fold_l, fold_r);
    }
    
    template<class F>
    void update(int i, const F &f) {
        i += n;
        val[i] = f(val[i]);
        while (i > 1) {
            i >>= 1;
            val[i] = Monoid::operate(val[i * 2], val[i * 2 + 1]);
        }
    }
    
    T get(int i) {
        return val[i + n];
    }
};

class Node {
public:
    using value_type = int;
    
    value_type value;
    
    Node(value_type value) : value(value) {}
    
    static constexpr value_type identity = -inf;
    
    static constexpr value_type operate(const value_type &l, const value_type &r) {
        return max(l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    INT(n);
    vi a(n);
    cin >> a;
    segtree<Node> st(n + 1);
    st.update(0, [](auto) { return 1; });
    int add = 0;
    rep(i, 1, n) {
        int now = st.fold(0, a[i]) + 1;
        chmax(now, st.fold(a[i] + 1, n + 1) + 1);
        chmax(now, st.get(a[i]));
        if (a[i - 1] != a[i]) {
            add++;
            now--;
        }
        st.update(a[i - 1], [&](int val) { return max(val, now); });
    }
    print(st.fold(0, n + 1) + add);
}
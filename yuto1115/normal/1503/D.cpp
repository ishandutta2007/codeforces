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
#define popcount(x) __builtin_popcountll(x)
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
struct Init_io {
    Init_io() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cout << boolalpha << fixed << setprecision(15);
    }
} init_io;
const string yes[] = {"no","yes"};
const string Yes[] = {"No","Yes"};
const string YES[] = {"NO","YES"};
const int inf = 1001001001;
const ll linf = 1001001001001001001;
//@formatter:on

template<class Node>
class lazy_segtree {
    using V = typename Node::value_structure;
    using VT = typename V::value_type;
    using O = typename Node::operate_structure;
    using OT = typename O::value_type;
    
    int n;
    vector<Node> tree;
    
    void propagate(int k, int l, int r) {
//        if (tree[k].op.value == O::identity) return;
        if (k < n) {
            tree[k * 2].op.value = O::operate(tree[k * 2].op.value, tree[k].op.value);
            tree[k * 2 + 1].op.value = O::operate(tree[k * 2 + 1].op.value, tree[k].op.value);
        }
        OT ot = O::duplicate(tree[k].op.value, r - l);
        tree[k].value.value = Node::operate(tree[k].value.value, ot);
        tree[k].op.value = O::identity;
    }

public:
    VT get(int i) { return Node::operate(tree[i].value.value, tree[i].op.value); }
    
    lazy_segtree(int _n, const vector<VT> &init = vector<VT>()) {
        n = 1;
        while (n < _n) n *= 2;
        tree.assign(n * 2, Node{V::identity, O::identity});
        if (init.size()) rep(i, _n) tree[i + n].value.value = init[i];
        rrep(i, n) tree[i].value.value = V::operate(tree[i * 2].value.value, tree[i * 2 + 1].value.value);
    }
    
    void update(int a, int b, OT x, int k = 1, int l = 0, int r = -1) {
        if (r == -1) r = n;
        propagate(k, l, r);
        if (a <= l && r <= b) {
            tree[k].op.value = O::operate(tree[k].op.value, x);
            propagate(k, l, r);
        } else if (a < r && l < b) {
            update(a, b, x, k * 2, l, (l + r) / 2);
            update(a, b, x, k * 2 + 1, (l + r) / 2, r);
            tree[k].value.value = V::operate(tree[k * 2].value.value, tree[k * 2 + 1].value.value);
        }
    }
    
    // segment [a,b)
    VT fold(int a, int b, int k = 1, int l = 0, int r = -1) {
        if (r == -1) r = n;
        propagate(k, l, r);
        if (b <= l || r <= a) return V::identity;
        if (a <= l && r <= b) return tree[k].value.value;
        VT lt = fold(a, b, k * 2, l, (l + r) / 2);
        VT rt = fold(a, b, k * 2 + 1, (l + r) / 2, r);
        return V::operate(lt, rt);
    }
};

class Value_structure {
public:
    using value_type = ll;
    
    value_type value;
    
    Value_structure(value_type value) : value(value) {}
    
    static constexpr value_type identity = inf;
    
    static constexpr value_type operate(const value_type &l, const value_type &r) {
        if (l == identity) return r;
        if (r == identity) return l;
        return min(l, r);
    }
};

class Operate_structure {
public:
    using value_type = ll;
    
    value_type value;
    
    Operate_structure(value_type value) : value(value) {}
    
    static constexpr value_type identity = 0;
    
    static constexpr value_type operate(const value_type &l, const value_type &r) {
        return l + r;
    }
    
    static constexpr value_type duplicate(const value_type &v, int len) {
        return v;
    }
};

class Node {
public:
    using value_structure = Value_structure;
    using operate_structure = Operate_structure;
    
    value_structure value;
    operate_structure op;

private:
    using V = value_structure::value_type;
    using O = operate_structure::value_type;

public:
    Node(V value, O op) : value(value), op(op) {}
    
    static constexpr V operate(const V &l, const O &r) {
        return l + r;
    }
};


int main() {
    INT(n);
    vi a(n), b(n), t(n);
    int ans = 0;
    rep(i, n) {
        scan(a[i], b[i]);
        a[i]--, b[i]--;
        if (min(a[i], b[i]) >= n) fin(-1);
        if (a[i] < b[i]) {
            t[i] = 1;
        } else {
            ans++;
            swap(a[i], b[i]);
            t[i] = -1;
        }
        b[i] -= n;
    }
    vi ord(n);
    rep(i, n) ord[a[i]] = i;
    debug(a);
    debug(b);
    debug(t);
    debug(ord);
    vector<lazy_segtree<Node>> st(2, lazy_segtree<Node>(n + 1));
    st[0].update(n, n + 1, -inf + t[ord[0]]);
    st[1].update(n, n + 1, -inf);
    rep(i, 1, n) {
        int now = ord[i];
        int bf = ord[i - 1];
        ll nx0, nx1;
        nx0 = st[1].fold(b[now] + 1, n + 1) + t[now];
        nx1 = st[0].fold(b[now] + 1, n + 1);
        debug(nx0, nx1);
        if (b[bf] > b[now]) {
            st[0].update(0, n + 1, t[now]);
        } else {
            st[0].update(0, n + 1, inf);
            st[1].update(0, n + 1, inf);
        }
        ll pre = st[0].fold(b[bf], b[bf] + 1);
        st[0].update(b[bf], b[bf] + 1, nx0 - pre);
        pre = st[1].fold(b[bf], b[bf] + 1);
        st[1].update(b[bf], b[bf] + 1, nx1 - pre);
        debug(st[0].fold(b[bf], b[bf] + 1));
        debug(st[1].fold(b[bf], b[bf] + 1));
    }
    ll mn = min(st[0].fold(0, n + 1), st[1].fold(0, n + 1));
    if (mn > n) fin(-1);
    assert(ans + mn >= 0 and ans + mn <= n);
    fin(ans + mn);
}
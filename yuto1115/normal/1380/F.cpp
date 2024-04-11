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
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define vp vector<P>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using LP = pair<ll,ll>;
template<class S,class T> istream& operator>>(istream &is,pair<S,T> &p) { return is >> p.first >> p.second; }
template<class S,class T> ostream& operator<<(ostream &os,const pair<S,T> &p) { return os<<'{'<<p.first<<","<<p.second<<'}'; }
template<class T> istream& operator>>(istream &is,vector<T> &v) { for(T &t:v){is>>t;} return is; }
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) { os<<'[';rep(i,v.size())os<<v[i]<<(i==int(v.size()-1)?']':','); return os; }
void Yes(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YES(bool b) { cout << (b ? "YES" : "NO") << endl; }
template<class T> bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;

//const int mod = 1000000007;
const int mod = 998244353;
struct mint {
    ll x;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint& a) { if ((x += a.x) >= mod) x -= mod; return *this;}
    mint& operator++() { return *this += mint(1); }
    mint& operator-=(const mint& a) { if ((x += mod-a.x) >= mod) x -= mod; return *this; }
    mint& operator--() { return *this -= mint(1); }
    mint& operator*=(const mint& a) { (x *= a.x) %= mod; return *this; }
    mint operator+(const mint& a) const { mint res(*this); return res+=a; }
    mint operator-(const mint& a) const { mint res(*this); return res-=a; }
    mint operator*(const mint& a) const { mint res(*this); return res*=a; }
    mint pow(ll t) const {
        mint res = mint(1),a(*this);
        while(t > 0) {
            if(t&1) res *= a;
            t >>= 1;
            a *= a;
        }
        return res;
    }
    // for prime mod
    mint inv() const { return pow(mod-2); }
    mint& operator/=(const mint& a) { return *this *= a.inv(); }
    mint operator/(const mint& a) const { mint res(*this); return res/=a; }
};
ostream& operator<<(ostream& os,const mint& m) { return os << m.x; }

template<typename T,typename MERGE,typename UPDATE>
class segtree {
    int n;
    vector<T> val;
    T identity;
    MERGE merge;
    UPDATE _update;

public:
    segtree(int _n,vector<T> init,T identity,
            MERGE merge,UPDATE update)
            :identity(identity),merge(merge),_update(update) {
        n = 1;
        while(n < _n) n *= 2;
        val = vector<T>(2*n-1,identity);
        rep(i,_n) val[i+n-1] = init[i];
        rrep(i,n-1) val[i] = merge(val[i*2+1],val[i*2+2]);
    }
    void update(int i,T x) {
        i += n-1;
        val[i] = _update(val[i],x);
        while(i > 0) {
            i = (i-1)/2;
            val[i] = merge(val[i*2+1],val[i*2+2]);
        }
    }
    T operator[](int i) const { return val[i]; }
};

struct node {
    int l,r;
    mint a,b,c,d;
    node(int l,int r,mint a,mint b,mint c,mint d):l(l),r(r),a(a),b(b),c(c),d(d) {}
    node(int n=0):l(n),r(n) {
        a = n+1;
        b = c = 1;
        d = 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n,m;
    cin >> n >> m;
    auto f = [](node x,node y){
        if(y.l == -1) return x;
        int l = x.l,r = y.r;
        mint a,b,c,d;
        a = x.a*y.a;
        if(x.r == 1) a += x.b*y.c*(9-y.l);
        b = x.a*y.b;
        if(x.r == 1) b += x.b*y.d*(9-y.l);
        c = x.c*y.a;
        if(x.r == 1) c += x.d*y.c*(9-y.l);
        d = x.c*y.b;
        if(x.r == 1) d += x.d*y.d*(9-y.l);
        return node(l,r,a,b,c,d);
    };
    auto g = [](node a,node b) { return b; };
    vector<node> init(n);
    rep(i,n) {
        char c;
        cin >> c;
        init[i] = node(c-'0');
    }
    segtree<node,decltype(f),decltype(g)> st(n,init,node(-1),f,g);
    while(m--) {
        int x,d;
        cin >> x >> d;
        x--;
        st.update(x,node(d));
        cout << st[0].a << '\n';
    }
}
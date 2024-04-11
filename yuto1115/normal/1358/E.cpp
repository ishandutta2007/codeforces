#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n)-1; i >= 0; i--)
#define rep2(i,s,n) for (int i = (s); i < (n); ++i)
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
template<class T> istream& operator>>(istream& is,vector<T>& v) { for(T& t:v){is>>t;} return is; }
template<class T> ostream& operator<<(ostream& os,const vector<T>& v) { rep(i,v.size())os<<v[i]<<(i==v.size()-1?"\n":" "); return os; }
void Yes(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YES(bool b) { cout << (b ? "YES" : "NO") << endl; }
template<class T> inline bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001*4;

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
    // segment [a,b)
    T query(int a,int b,int k = 0,int l = 0,int r = -1) {
        if(r == -1) r = n;
        if(b <= l || r <= a) return identity;
        if(a <= l && r <= b) return val[k];
        T t1 = query(a,b,2*k+1,l,(l+r)/2);
        T t2 = query(a,b,2*k+2,(l+r)/2,r);
        return merge(t1,t2);
    }
    T operator[](int i) const { return val[i]; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vl a((n+1)/2);
    cin >> a;
    ll x;
    cin >> x;
    rep(i,n/2) a.pb(x);
    vl sum(n+1,0);
    rep(i,n) sum[i+1] = sum[i]+a[i];
    if(sum[n] > 0) {
        cout << n << endl;
        return 0;
    }
    int sz = (n+1)/2;
    auto f = [](ll a,ll b){ return min(a,b); };
    auto g = [](ll a,ll b){ return a; };
    vl init(sz+1);
    rep(i,sz+1) init[i] = x*i-sum[i];
    segtree<ll, decltype(f), decltype(g)> st(sz+1,init,linf,f,g);
    rep2(k,sz,n) {
        if(n-k > sz && x <= 0) continue;
        ll mn = st.query(0,n-k+1);
        mn += sum[k];
        if(mn > 0) {
            cout << k << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
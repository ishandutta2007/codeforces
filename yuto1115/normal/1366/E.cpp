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
template<class S,class T> istream& operator>>(istream &is,pair<S,T> &p) { return is >> p.first >> p.second; }
template<class S,class T> ostream& operator<<(ostream &os,const pair<S,T> &p) { return os<<'{'<<p.first<<","<<p.second<<'}'; }
template<class T> istream& operator>>(istream &is,vector<T> &v) { for(T &t:v){is>>t;} return is; }
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) { os<<'[';rep(i,v.size())os<<v[i]<<(i==v.size()-1?']':','); return os; }
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vi a(n),b(m);
    cin >> a >> b;
    reverse(all(a));
    vvi v(m);
    int now = m-1;
    rep(i,n) {
        if(a[i] >= b[now]) {
            v[now].pb(a[i]);
        } else {
            now--;
            if(now < 0 or i == 0) {
                cout << 0 << endl;
                return 0;
            }
            if(a[i] < b[now]) {
                cout << 0 << endl;
                return 0;
            }
            v[now].pb(a[i]);
        }
    }
    mint ans = 1;
    rep(i,m) {
        int fi = -1;
        rep(j,v[i].size()) if(v[i][j] == b[i]) {
            fi = j;
            break;
        }
        if(fi == -1) {
            cout << 0 << endl;
            return 0;
        }
        if(i) ans *= v[i].size()-fi;
    }
    cout << ans << endl;
}
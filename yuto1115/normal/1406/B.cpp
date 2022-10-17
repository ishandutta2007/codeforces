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

void solve() {
    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    vi pl, mi;
    rep(i, n) {
        if (a[i] >= 0) pl.pb(a[i]);
        else mi.pb(-a[i]);
    }
    sort(rall(pl));
    sort(rall(mi));
    ll ans = -linf;
    if (pl.size() >= 5) {
        ll l = 1;
        rep(i, 5) l *= pl[i];
        chmax(ans, l);
    }
    if (pl.size() >= 3 and mi.size() >= 2) {
        ll l = 1;
        rep(i, 3) l *= pl[i];
        rep(i, 2) l *= mi[i];
        chmax(ans, l);
    }
    if (pl.size() >= 1 and mi.size() >= 4) {
        ll l = pl[0];
        rep(i, 4) l *= mi[i];
        chmax(ans, l);
    }
    if (ans == -linf) {
        sort(all(a), [](int x, int y) { return abs(x) < abs(y); });
        ans = 1;
        rep(i, 5) ans *= a[i];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    rep(i, t) solve();
}
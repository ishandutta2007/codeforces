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
template<class T> void fin(T a) { cout << a << endl; exit(0); }
template<class T> bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;
//@formatter:on

int dp[2][110][20010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vi a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, 2) rep(j, 110) rep(k, 20010) dp[i][j][k] = -1;
    dp[0][0][0] = 0;
    rep(k, n) {
        rep(i, 110) rep(j, 20010) {
                if (dp[0][i][j] < 0) continue;
                int now = dp[0][i][j];
                chmax(dp[1][i][j], now + b[k]);
                chmax(dp[1][i + 1][j + a[k] * 2], now + b[k] * 2);
                dp[0][i][j] = -1;
            }
        swap(dp[0], dp[1]);
    }
    rep2(i, 1, n + 1) {
        int ans = 0;
        rep(j, 20010) chmax(ans, min(j, dp[0][i][j]));
        cout << fixed << setprecision(15) << (double) ans / 2.0 << (i == n ? '\n' : ' ');
    }
}
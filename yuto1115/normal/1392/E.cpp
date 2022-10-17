
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    rep(i, n) rep(j, n) {
            cout << (1LL << (i + j)) * (j & 1);
            if(j == n-1) cout << endl;
            else cout << ' ';
        }
    int q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;
        int now = 0;
        rep(i, 2 * n - 1) {
            int nk = k & 1;
            if (i > 0) {
                if ((now & 1) != nk) now++;
            }
            cout << i - now + 1 << ' ' << now + 1 << endl;
            k >>= 1;
        }
        assert(k == 0 and now == n - 1);
    }
}
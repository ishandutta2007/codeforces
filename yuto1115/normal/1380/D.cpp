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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n,m,x,k,y;
    cin >> n >> m >> x >> k >> y;
    vi a(n),b(m);
    cin >> a >> b;
    ll ans = 0;
    auto f = [&](int len,bool flag) {
        if(!len) return;
        if(len < k and !flag) {
            cout << -1 << endl;
            exit(0);
        }
        if((ll)y*k >= x) {
            ans += ll(len/k)*x+ll(len%k)*y;
        } else {
            if(flag) {
                ans += (ll)len*y;
            } else {
                ans += ll(len-k)*y+x;
            }
        }
    };
    int now = 0;
    vb v(n);
    rep(i,n) {
        if(a[i] == b[now]) {
            v[i] = true;
            now++;
            if(now == m) break;
        }
    }
    if(now < m) {
        cout << -1 << endl;
        return 0;
    }
    int cnt = 0;
    int mx = 0,last = 0;
    rep(i,n) {
        if(v[i]) {
            f(cnt,mx < max(last,a[i]));
            cnt = 0;
            mx = 0;
            last = a[i];
        } else {
            cnt++;
            chmax(mx,a[i]);
        }
    }
    f(cnt,mx < last);
    cout << ans << endl;
}
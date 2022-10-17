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
template<class T> ostream& operator<<(ostream& os,const vector<T>& v) { for(T t:v){os<<t<<" ";} os<<"\n"; return os; }
void Yes(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YES(bool b) { cout << (b ? "YES" : "NO") << endl; }
template<class T> inline bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n,a,r,m;
    cin >> n >> a >> r >> m;
    vi h(n);
    cin >> h;
    sort(all(h));
    ll L = h[0],R = h[n-1];
    auto f = [&](ll x) {
        ll u = 0,d = 0,ch = 0;
        rep(i,n) {
            if(h[i] < x) u += x-h[i];
            else if(h[i] > x) d += h[i]-x;
        }
        if(a+r > m) {
            ch += min(u,d);
            u = u-ch;
            d = d-ch;
        }
        return u*a+d*r+ch*m;
    };
    while(R-L > 2) {
        ll m1 = (L*2+R)/3,m2 = (L+R*2)/3;
        if(f(m1) >= f(m2)) L = m1;
        else R = m2;
    }
    ll ans = linf;
    for(ll i = L; i <= R; i++) chmin(ans,f(i));
    cout << ans << endl;
}
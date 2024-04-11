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

void solve() {
    int n,k;
    cin >> n >> k;
    int l1,r1,l2,r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if(l1 > l2) {
        swap(l1,l2);
        swap(r1,r2);
    }
    ll ans = 0;
    if(r1 < l2) {
        int c = l2-r1;
        int g = r2-l1;
        if(c+g >= 2*g and k > g) {
            cout << ll(k-g)*2+g+c << '\n';
            return;
        }
        int r = min(k/g,n);
        ans += (ll)r*(g+c);
        k -= r*g;
        if(k > 0) {
            if(r == n) {
                ans += 2*k;
            } else {
                if(r > 0) ans += min(c+k,k*2);
                else ans += c+k;
            }
        }
    } else {
        int ori = min(r1,r2)-max(l1,l2);
        if((ll)ori*n >= k) {
            cout << 0 << '\n';
            return;
        }
        k -= ori*n;
        int g = max(r1,r2)-min(l1,l2)-ori;
        if(g == 0) {
            cout << k*2 << '\n';
            return;
        }
        int r = min(k/g,n);
        ans += (ll)r*g;
        k -= r*g;
        if(k > 0) {
            if(r == n) {
                ans += 2*k;
            } else {
                ans += k;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    rep(i,t) solve();
}
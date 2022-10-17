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
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    ll ans = 0;
    auto f = [](int a,int b) {
        int n = a-b+1;
        return (ll)(a+b)*n/2;
    };
    rep2(z,c,d+1) {
        int mn = z-c+1;
        int mx = z-b+1;
        if(mn < a) {
            if(mn+c-b < a) ans += (ll)(b-a+1)*(c-b+1);
            else {
                ans += (ll)(b-a+1)*(a-mn);
                int l = max(0,b-mx+1);
                ans += f(b-a+1,l);
            }
        } else if(mn <= b) {
            int r = b-mn+1;
            int l = max(0,b-mx+1);
            ans += f(r,l);
        }
    }
    cout << ans << endl;
}
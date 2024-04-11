#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rrep(i,n) for (int i = n-1; i >= 0; i--)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define tmax(a,b,c) max(a,max(b,c))
#define tmin(a,b,c) min(a,min(b,c))
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using LP = pair<ll,ll>;
inline void Yes(bool b) { cout << (b ? "Yes" : "No") << endl; }
template<class T> inline bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
template<class T> inline void operator>>(istream& is,vector<T>& v) { for(int& i : v){ is>>i; } }
template<class T> inline void operator<<(ostream& os,const vector<T>& v) { for(int i : v){ os<<i<<" "; } os<<endl; }
const int inf = 1001001001;
const ll linf = 1001001001001001001;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    rep(_,t) {
        int n;
        cin >> n;
        vi a(n);
        rep(i,n) cin >> a[i];
        sort(all(a));
        vi ans;
        int l,r;
        if(n%2 == 0) l = n/2-1,r = n/2;
        else l = n/2,r = n/2+1;
        while(true) {
            if(l < 0) break;
            ans.pb(a[l]);
            l--;
            if(r >= n) break;
            ans.pb(a[r]);
            r++;
        }
        rep(i,n) cout << ans[i] << " ";
        cout << endl;
    }
}
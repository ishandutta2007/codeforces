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
const ll linf = 1001001001001001001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n,x;
    cin >> n >> x;
    vl d(n);
    cin >> d;
    vl sum_day(n,0);
    sum_day[0] = d[0];
    rep(i,n-1) sum_day[i+1] = sum_day[i]+d[i+1];
    vl sum_hag(n,0);
    sum_hag[0] = d[0]*(d[0]+1)/2;
    rep(i,n-1) sum_hag[i+1] = sum_hag[i]+d[i+1]*(d[i+1]+1)/2;
    ll ans = 0;
    // last day -> last day of i-th month
    rep(i,n) {
        ll nans = 0;
        if(sum_day[i] >= x) {
            auto it = lower_bound(all(sum_day),sum_day[i]-x);
            int fi = it-sum_day.begin();
            nans += sum_hag[i]-sum_hag[fi];
            ll rem = x-(sum_day[i]-sum_day[fi]);
            nans += (d[fi]+d[fi]-rem+1)*rem/2;
        } else {
            nans += sum_hag[i];
            ll rem = x-sum_day[i];
            auto it = lower_bound(all(sum_day),sum_day[n-1]-rem);
            int fi = it-sum_day.begin();
            nans += sum_hag[n-1]-sum_hag[fi];
            rem -= sum_day[n-1]-sum_day[fi];
            nans += (d[fi]+d[fi]-rem+1)*rem/2;
        }
        chmax(ans,nans);
//        cout << nans << endl;
    }
    cout << ans << endl;
//    cout << sum_day;
//    cout << sum_hag;
}
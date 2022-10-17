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

void solve() {
    int n,k;
    cin >> n >> k;
    if(n%2 == 1 && k%2 == 0) {
        cout << "NO" << "\n";
        return;
    }
    vi v(k);
    if(n%2 == 0 && k%2 == 1) v.assign(k,2);
    else v.assign(k,1);
    int sum = 0;
    rep(i,k) sum += v[i];
    if(sum > n) {
        cout << "NO" << "\n";
        return;
    }
    v[0] += n-sum;
    cout << "YES" << "\n";
    cout << v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    rep(i,t) solve();
}
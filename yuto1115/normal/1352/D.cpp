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
    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    if(n == 1) {
        cout << "1 " << a[0] << " 0" << "\n";
        return;
    }
    vi b = a;
    reverse(all(b));
    vi suma(n+1,0),sumb(n+1,0);
    rep(i,n) suma[i+1] = suma[i]+a[i];
    rep(i,n) sumb[i+1] = sumb[i]+b[i];
    int cnt = 1;
    int turn = 1;
    int nowa = 0,nowb = -1;
    int last = a[0];
    while(true) {
        cnt++;
        if(turn == 0) {
            auto it = upper_bound(all(suma),last+suma[nowa+1]);
            if(it-suma.begin()+nowb+1 >= n) {
                nowa = n-nowb-2;
                break;
            }
            last = *it-suma[nowa+1];
            nowa = it-suma.begin()-1;
            turn = 1-turn;
        } else {
            auto it = upper_bound(all(sumb),last+sumb[nowb+1]);
            if(it-sumb.begin()+nowa+1 >= n) {
                nowb = n-nowa-2;
                break;
            }
            last = *it-sumb[nowb+1];
            nowb = it-sumb.begin()-1;
            turn = 1-turn;
        }
    }
    cout << cnt << " " << suma[nowa+1] << " " << sumb[nowb+1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    rep(i,t) solve();
}
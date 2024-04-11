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

const bitset<7> nums[10] = {bitset<7>("1110111"),
                      bitset<7>("0010010"),
                      bitset<7>("1011101"),
                      bitset<7>("1011011"),
                      bitset<7>("0111010"),
                      bitset<7>("1101011"),
                      bitset<7>("1101111"),
                      bitset<7>("1010010"),
                      bitset<7>("1111111"),
                      bitset<7>("1111011")};

int dp[2010][2010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n,K;
    cin >> n >> K;
    vector<bitset<7>> v(n);
    rep(i,n) {
        string s;
        cin >> s;
        v[i] = bitset<7>(s);
    }
    reverse(all(v));
    rep(i,2010) rep(j,2010) dp[i][j] = -1;
    dp[0][0] = 0;
    rep(i,n) rep(j,K+1) {
        auto now = v[i];
        rep(k,10) {
            int cnt = 0;
            rep(l,7) {
                if(now[l] && !nums[k][l]) cnt = -inf;
                if(!now[l] && nums[k][l]) cnt++;
            }
            if(cnt < 0) continue;
            if(cnt > j) continue;
            if(dp[i][j-cnt] == -1) continue;
            chmax(dp[i+1][j],k);
        }
    }
    if(dp[n][K] == -1) {
        cout << -1 << endl;
        return 0;
    }
    rrep(i,n) {
        cout << dp[i+1][K];
        int cnt = 0;
        rep(j,7) if(!v[i][j] && nums[dp[i+1][K]][j]) cnt++;
        K -= cnt;
    }
}
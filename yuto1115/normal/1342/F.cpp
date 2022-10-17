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
template<class S,class T> istream& operator>>(istream &is,pair<S,T> &p) { return is >> p.first >> p.second; }
template<class S,class T> ostream& operator<<(ostream &os,const pair<S,T> &p) { return os<<'{'<<p.first<<","<<p.second<<'}'; }
template<class T> istream& operator>>(istream &is,vector<T> &v) { for(T &t:v){is>>t;} return is; }
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) { os<<'[';rep(i,v.size())os<<v[i]<<(i==v.size()-1?']':','); return os; }
void Yes(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YES(bool b) { cout << (b ? "YES" : "NO") << endl; }
template<class T> bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;

int ind[(1<<14)+1];

int dp[16][1<<15][16];
P bf[16][1<<15][16];
int SUM[1<<15];

void solve() {
    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    rep(bit,1<<n) {
        int sum = 0;
        rep(i,n) if(bit>>i&1) sum += a[i];
        SUM[bit] = sum;
    }
    rep(i,n+1) rep(j,1<<n) rep(k,n+1) dp[i][j][k] = inf;
    dp[0][0][0] = 0;
    rep(i,n+1) rep(bit,(1<<n)-1) rep(pos,n+1) {
        if(dp[i][bit][pos] == inf) continue;
//        cout << i << ' ' << bit << ' ' << pos << endl;
        int sub = ~bit&((1<<n)-1);
        int add = sub;
        do {
            int sum = SUM[add];
            int now = add&(~((1<<pos)-1));
            if(sum <= dp[i][bit][pos] or now == 0) {
                add--;
                add &= sub;
                continue;
            }
            if(chmin(dp[i+1][bit+add][ind[now&(~(now-1))]],sum)) {
                bf[i+1][bit+add][ind[now&(~(now-1))]] = make_pair(bit,pos);
            };
            add--;
            add &= sub;
        } while(add > 0);
//        cout << i << ' ' << bit << ' ' << pos << endl;
    }
    vp ans;
    int now = (1<<n)-1;
    auto op = [&](int i,int j) {
        int cnt = 0;
        int a,b;
        rep(k,n) if(now>>k&1) {
            cnt++;
            if(k == i) a = cnt;
            else if(k == j) b = cnt;
        }
        ans.eb(a,b);
        now &= ~(1<<i);
    };
    auto er = [&](int bit, int pos) {
        rep(i,n) if(bit>>i&1 and i != pos-1) op(i,pos-1);
    };
    rrep(i,n+1) rep(j,n+1) {
        if(dp[i][(1<<n)-1][j] == inf) continue;
        int ni = i,bit = (1<<n)-1,pos = j;
        while(ni > 0) {
            er(bit-bf[ni][bit][pos].first,pos);
            tie(bit,pos) = bf[ni][bit][pos];
            ni--;
        }
        cout << ans.size() << '\n';
        for(auto p : ans) cout << p.first << ' ' << p.second << '\n';
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    rep(i,15) ind[1<<i] = i+1;
    rep(i,t) solve();
}
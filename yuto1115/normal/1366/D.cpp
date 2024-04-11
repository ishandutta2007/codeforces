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

class sieve {
    int n;
    vi val;

    void init() {
        rep(i,n+1) val[i] = i;
        rep(i,n+1) {
            if(i < 2) continue;
            if(val[i] != i) continue;
            for(int j = i*2; j <= n; j += i) {
                if(val[j] == j) val[j] = i;
            }
        }
    }

public:
    sieve(int n):n(n),val(n+1) {
        init();
    }
    map<int,int> factorlist(int x) {
        if(n < 2) return {};
        map<int,int> ret;
        int now = x;
        while(now > 1) {
            ret[val[now]]++;
            now /= val[now];
        }
        return ret;
    }
    vi unique_factor(int x) {
        map<int,int> m = factorlist(x);
        vi ret;
        for(P p : m) ret.pb(p.first);
        return ret;
    };
    bool isprime(int x) {
        return x >= 2 and val[x] == x;
    }
    int count_divisor(int x) {
        int ret = 1;
        map<int,int> fl = factorlist(x);
        for(auto p : fl) ret *= p.second+1;
        return ret;
    };
} sv(1e7);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vvi ans(2,vi(n));
    rep(i,n) {
        int a;
        cin >> a;
        auto m = sv.factorlist(a);
        if(m.size() == 1) {
            ans[0][i] = ans[1][i] = -1;
            continue;
        }
        ans[0][i] = m.begin()->first;
        ans[1][i] = 1;
        auto it = m.begin();
        while(++it != m.end()) {
            ans[1][i] *= it->first;
        }
    }
    rep(i,2) {
        rep(j,n) cout << ans[i][j] << (j == n-1 ? "\n" : " ");
    }
}
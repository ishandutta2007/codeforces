//@formatter:off
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
#define vvd vector<vector<double>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vp vector<P>
#define vvp vector<vector<P>>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using LP = pair<ll,ll>;
template<class S,class T> istream& operator>>(istream &is,pair<S,T> &p) { return is >> p.first >> p.second; }
template<class S,class T> ostream& operator<<(ostream &os,const pair<S,T> &p) { return os<<'{'<<p.first<<","<<p.second<<'}'; }
template<class T> istream& operator>>(istream &is,vector<T> &v) { for(T &t:v){is>>t;} return is; }
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) { os<<'[';rep(i,v.size())os<<v[i]<<(i==int(v.size()-1)?"":","); return os<<']'; }
void Yes(bool b) { cout << (b ? "Yes" : "No") << '\n'; }
void YES(bool b) { cout << (b ? "YES" : "NO") << '\n'; }
template<class T> bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;
//@formatter:on

template<typename T>
class prime {
    T n;
public:
    prime(T n) : n(n) {}
    
    map<int, int> factorlist() {
        if (n == 1) return {};
        T nn = n;
        map<int, int> ret;
        for (int i = 2; (ll) i * i <= n; i++) {
            if (nn % i != 0) continue;
            int cnt = 0;
            while (nn % i == 0) {
                cnt++;
                nn /= i;
            }
            ret[i] = cnt;
        }
        if (nn != 1) ret[nn]++;
        return ret;
    }
    
    vi unique_factor() {
        map<int, int> m = factorlist();
        vi ret;
        for (P p : m) ret.pb(p.first);
        return ret;
    };
    
    bool isPrime() {
        auto v = factorlist();
        return v.size() == 1 && v[0].second == 1;
    }
    
    int count_divisor() {
        int ret = 1;
        map<int, int> fl = factorlist(n);
        for (auto p : fl) ret *= p.second + 1;
        return ret;
    };
    
    vector<T> enum_divisors() {
        vector<T> res;
        for (T i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                res.pb(i);
                if (n / i != i) res.pb(n / i);
            }
        }
        sort(all(res));
        return res;
    }
};

void solve() {
    ll p, q;
    cin >> p >> q;
    if (p % q != 0) {
        cout << p << '\n';
        return;
    }
    auto ls = prime<int>(q).factorlist();
    auto cnt = [&](int i) {
        int res = 0;
        ll np = p;
        while (np % i == 0) {
            np /= i;
            res++;
        }
        return res;
    };
    auto pow = [](int i, int j) {
        ll res = 1;
        rep(_, j) res *= i;
        return res;
    };
    ll mn = linf;
    for (auto[f, s] : ls) {
        int c = cnt(f);
        assert(c >= s);
        chmin(mn, pow(f, c - s + 1));
    }
    cout << p / mn << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    rep(i, t) solve();
}
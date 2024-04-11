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

template<typename T>
class prime {
    T n;
public:
    prime(T n):n(n) {}
    map<int,int> factorlist() {
        if(n == 1) return {};
        T nn = n;
        map<int,int> ret;
        for(int i = 2; (ll)i*i <= n; i++) {
            if(nn%i != 0) continue;
            int cnt = 0;
            while(nn%i == 0) {
                cnt++;
                nn /= i;
            }
            ret[i] = cnt;
        }
        if(nn != 1) ret[nn]++;
        return ret;
    }
    vi unique_factor() {
        map<int,int> m = factorlist();
        vi ret;
        for(P p : m) ret.pb(p.first);
        return ret;
    };
    bool isprime() {
        auto v = factorlist();
        return v.size() == 1 && v[0].second == 1;
    }
    int count_divisor() {
        int ret = 1;
        map<int,int> fl = factorlist(n);
        for(auto p : fl) ret *= p.second+1;
        return ret;
    };
    vector<T> enum_divisors() {
        vector<T> res;
        for(T i = 1; i*i <= n; i++) {
            if(n%i == 0) {
                res.pb(i);
                if(n/i != i) res.pb(n/i);
            }
        }
        sort(all(res));
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    vi p(n),c(n);
    cin >> p >> c;
    rep(i,n) p[i]--;
    auto f = [&](vi v) {
        int sz = v.size();
        prime<int> pr(sz);
        vi can = pr.enum_divisors();
        int ret = inf;
        for(int i : can) {
            vi cl(i,-1);
            rep(j,sz) {
                if(cl[j%i] == -1) cl[j%i] = c[v[j]];
                else {
                    if(cl[j%i] != c[v[j]]) {
                        cl[j%i] = inf;
                    }
                }
            }
            rep(j,i) if(cl[j] != inf) chmin(ret,i);
        }
        return ret;
    };
    int ans = inf;
    vb seen(n);
    auto lsup = [&](int s) {
        int now = s;
        vi ret;
        ret.pb(s);
        seen[s] = true;
        while(p[now] != s) {
            now = p[now];
            ret.pb(now);
            seen[now] = true;
        }
        return ret;
    };
    rep(i,n) if(!seen[i]) {
        chmin(ans,f(lsup(i)));
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
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

template<typename T>
class prime {
    T n;
public:
    explicit prime(T n):n(n) { assert(n > 0); }
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
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    map<int,vector<int>> m;
    rep(i,n) {
        int a;
        cin >> a;
        map<int,int> nm = prime<int>(a).factorlist();
        for(auto p : nm) m[p.first].pb(p.second);
    }
    ll ans = 1;
    for(auto p : m) {
        sort(all(p.second));
        int num;
        if(p.second.size() == n) num = p.second[1];
        else if(p.second.size() == n-1) num = p.second[0];
        else num = 0;
        rep(_,num) ans *= p.first;
    }
    cout << ans << endl;
}
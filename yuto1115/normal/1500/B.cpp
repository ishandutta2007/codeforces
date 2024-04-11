//@formatter:off
#include<bits/stdc++.h>
#define overload4(_1,_2,_3,_4,name,...) name
#define rep1(i,n) for (ll i = 0; i < ll(n); ++i)
#define rep2(i,s,n) for (ll i = ll(s); i < ll(n); ++i)
#define rep3(i,s,n,d) for(ll i = ll(s); i < ll(n); i+=d)
#define rep(...) overload4(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep1(i,n) for (ll i = ll(n)-1; i >= 0; i--)
#define rrep2(i,n,t) for (ll i = ll(n)-1; i >= (ll)t; i--)
#define rrep3(i,n,t,d) for (ll i = ll(n)-1; i >= (ll)t; i-=d)
#define rrep(...) overload4(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define popcount(x) __builtin_popcount(x)
#define pb push_back
#define eb emplace_back
#ifdef __LOCAL
#define debug(...) { cout << #__VA_ARGS__; cout << ": "; print(__VA_ARGS__); cout << flush; }
#else
#define debug(...) void(0)
#endif
#define INT(...) int __VA_ARGS__;scan(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;scan(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;scan(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;scan(__VA_ARGS__)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,int>;
using LP = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using vs = vector<string>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vp = vector<P>;
using vvp = vector<vector<P>>;
template<class S,class T> istream& operator>>(istream &is,pair<S,T> &p) { return is >> p.first >> p.second; }
template<class S,class T> ostream& operator<<(ostream &os,const pair<S,T> &p) { return os<<'{'<<p.first<<","<<p.second<<'}'; }
template<class T> istream& operator>>(istream &is,vector<T> &v) { for(T &t:v){is>>t;} return is; }
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) { os<<'[';rep(i,v.size())os<<v[i]<<(i==int(v.size()-1)?"":","); return os<<']'; }
template<class T> void vecout(const vector<T> &v,char div='\n') { rep(i,v.size()) cout<<v[i]<<(i==int(v.size()-1)?'\n':div);}
template<class T> bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
void scan(){}
template <class Head, class... Tail> void scan(Head& head, Tail&... tail){ cin >> head; scan(tail...); }
template<class T> void print(const T& t){ cout << t << '\n'; }
template <class Head, class... Tail> void print(const Head& head, const Tail&... tail){ cout<<head<<' '; print(tail...); }
template<class... T> void fin(const T&... a) { print(a...); exit(0); }
const string yes[] = {"no","yes"};
const string Yes[] = {"No","Yes"};
const string YES[] = {"NO","YES"};
const int inf = 1001001001;
const ll linf = 1001001001001001001;
//@formatter:on

// return gcd(a, b)
// solve  ax + by = gcd(a, b)
// |x| <= b, |y| <= a (if a*b != 0)
ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

// solve x = r[i] (mod m[i])
// return (R, M), when the answer is x = R (mod M)
// return (0, 0), when there is no answer
// condition: lcm(m[i]) <= LLONG_MAX
LP crt(const vl &r, const vl &m) {
    assert(r.size() == m.size());
    int n = r.size();
    ll R = 0, M = 1;
    rep(i, n) {
        assert(m[i] >= 1);
        ll p, q;
        ll g = extGCD(M, m[i], p, q); // p is inv of M/d (mod. m[i]/d)
        if ((r[i] - R) % g != 0) return P(0, 0);
        ll tmp = (r[i] - R) / g * p % (m[i] / g);
        R += M * tmp;
        M *= m[i] / g;
        R = (R % M + M) % M;
    }
    return {R, M};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL(n, m, k);
    vi a(n), b(m);
    cin >> a >> b;
    int sz = 2 * max(n, m) + 1;
    vi pos(sz, -1);
    rep(i, m) pos[b[i]] = i;
    ll ok = linf, ng = 0;
    vl R(n), M(n);
    rep(i, n) {
        int j = pos[a[i]];
        if (j == -1) continue;
        auto now = crt({i, j}, {n, m});
        tie(R[i], M[i]) = now;
    }
    auto f = [&](ll x) -> bool {
        ll dif = x;
        rep(i, n) {
            if (M[i] == 0 or R[i] >= x) continue;
            dif -= 1 + (x - R[i] - 1) / M[i];
        }
        return dif >= k;
    };
    assert(f(ok));
    while (abs(ok - ng) > 1) {
        ll mid = (ng + ok) / 2;
        if (f(mid)) ok = mid;
        else ng = mid;
    }
    print(ok);
}
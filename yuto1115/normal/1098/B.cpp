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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s = "AGCT";
    map<char, int> mp = {{'A', 0},
                         {'G', 1},
                         {'C', 2},
                         {'T', 3}};
    INT(n, m);
    vvi v(n, vi(m));
    rep(i, n) rep(j, m) {
            CHR(c);
            v[i][j] = mp[c];
        }
    auto row = [&](int i, int a, int b) -> int {
        int res = 0;
        rep(j, m) {
            if (j & 1) res += v[i][j] != a;
            else res += v[i][j] != b;
        }
        return res;
    };
    auto col = [&](int j, int a, int b) -> int {
        int res = 0;
        rep(i, n) {
            if (i & 1) res += v[i][j] != a;
            else res += v[i][j] != b;
        }
        return res;
    };
    int mn = inf;
    bool is_row;
    int ma, mb;
    // row alter
    {
        rep(a, 3) rep(b, a + 1, 4) {
                vi rem;
                rep(i, 4) if (i != a and i != b) rem.pb(i);
                int c = rem[0], d = rem[1];
                int now = 0;
                rep(i, n) {
                    if (i & 1) {
                        now += min(row(i, a, b), row(i, b, a));
                    } else {
                        now += min(row(i, c, d), row(i, d, c));
                    }
                }
                if (chmin(mn, now)) {
                    is_row = true;
                    ma = a, mb = b;
                }
            }
    }
    // column alter
    {
        rep(a, 3) rep(b, a + 1, 4) {
                vi rem;
                rep(i, 4) if (i != a and i != b) rem.pb(i);
                int c = rem[0], d = rem[1];
                int now = 0;
                rep(i, m) {
                    if (i & 1) {
                        now += min(col(i, a, b), col(i, b, a));
                    } else {
                        now += min(col(i, c, d), col(i, d, c));
                    }
                }
                if (chmin(mn, now)) {
                    is_row = false;
                    ma = a, mb = b;
                }
            }
    }
    vvi ans(n, vi(m));
    auto[a, b] = P{ma, mb};
    vi rem;
    rep(i, 4) if (i != a and i != b) rem.pb(i);
    int c = rem[0], d = rem[1];
    if (is_row) {
        rep(i, n) {
            if (i & 1) {
                if (row(i, a, b) < row(i, b, a)) {
                    rep(j, m) {
                        if (j & 1) ans[i][j] = a;
                        else ans[i][j] = b;
                    }
                } else {
                    rep(j, m) {
                        if (j & 1) ans[i][j] = b;
                        else ans[i][j] = a;
                    }
                }
            } else {
                if (row(i, c, d) < row(i, d, c)) {
                    rep(j, m) {
                        if (j & 1) ans[i][j] = c;
                        else ans[i][j] = d;
                    }
                } else {
                    rep(j, m) {
                        if (j & 1) ans[i][j] = d;
                        else ans[i][j] = c;
                    }
                }
            }
        }
    } else {
        rep(j, m) {
            if (j & 1) {
                if (col(j, a, b) < col(j, b, a)) {
                    rep(i, n) {
                        if (i & 1) ans[i][j] = a;
                        else ans[i][j] = b;
                    }
                } else {
                    rep(i, n) {
                        if (i & 1) ans[i][j] = b;
                        else ans[i][j] = a;
                    }
                }
            } else {
                if (col(j, c, d) < col(j, d, c)) {
                    rep(i, n) {
                        if (i & 1) ans[i][j] = c;
                        else ans[i][j] = d;
                    }
                } else {
                    rep(i, n) {
                        if (i & 1) ans[i][j] = d;
                        else ans[i][j] = c;
                    }
                }
            }
        }
    }
    rep(i, n) {
        string t;
        rep(j, m) t.pb(s[ans[i][j]]);
        print(t);
    }
}
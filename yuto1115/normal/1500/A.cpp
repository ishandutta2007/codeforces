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
    INT(n);
    vi a(n);
    cin >> a;
    int sz = 3000000;
    vi cnt(sz);
    rep(i, n) cnt[a[i]]++;
    rep(i, sz) if (cnt[i] >= 4) {
            vi ls;
            rep(j, n) if (a[j] == i) ls.pb(j + 1);
            print("YES");
            fin(ls[0], ls[1], ls[2], ls[3]);
        }
    vi o2;
    rep(i, sz) if (cnt[i] >= 2) o2.pb(i);
    if (o2.size() >= 2) {
        int i = o2[0], j = o2[1];
        vi la, lb;
        rep(k, n) {
            if (a[k] == i) la.pb(k + 1);
            if (a[k] == j) lb.pb(k + 1);
        }
        print("YES");
        fin(la[0], lb[0], la[1], lb[1]);
    }
    vp v;
    vi pos(sz, -1);
    map<int, P> db;
    rep(i, n) {
        if (pos[a[i]] != -1) {
            db[a[i] * 2] = {pos[a[i]], i + 1};
        } else {
            v.eb(a[i], i + 1);
            pos[a[i]] = i + 1;
        }
    }
    sort(all(v));
    map<int, P> mp;
    rep(i, v.size()) rep(j, i) {
            int now = v[i].first + v[j].first;
            if (mp.count(now)) {
                auto[f, s] = mp[now];
                print("YES");
                assert(f != v[i].second and f != v[j].second);
                assert(s != v[i].second and s != v[j].second);
                fin(f, s, v[i].second, v[j].second);
            } else {
                mp[now] = {v[i].second, v[j].second};
                if (db.count(now)) {
                    auto[f, s] = db[now];
                    print("YES");
                    assert(f != v[i].second and f != v[j].second);
                    assert(s != v[i].second and s != v[j].second);
                    fin(f, s, v[i].second, v[j].second);
                }
            }
        }
    fin("NO");
}
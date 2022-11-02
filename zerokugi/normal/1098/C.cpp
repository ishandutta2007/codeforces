#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define __builtin_popcount __builtin_popcountll

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
    os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
    os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const map<S, T> &t) {
    os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first-t.first, s.second-t.second);}

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;


ll T, n, m, coef;

int check_coef(int n, ll m) {
    if (m > (ll)n * (n + 1) / 2) {
        return -1;
    }
    REPS(i, n - 1) {
        ll c = n, w = 1;
        ll sum = 0;
        for (ll j = 1;c > 0; j++) {
            sum += j * min(c, w);
            c -= min(c, w);
            w *= i;
        }
        if (sum <= m) {
            return i;
        }
    }
    return -1;
}

int dfs(vi &v, ll w, ll i, ll rest, ll restx) {
    if (rest == 0 && restx == 0) return 0;
    if (rest == 0) return restx ? restx / abs(restx) : 0;
    if (restx < (ll)i * rest) return -1;
    ll l = 1, r = min<ll>(rest, w) + 1;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;

        ll x = restx - mid * i;
        ll rest2 = (rest - mid);
        ll maximum = (ll)i * rest + rest2 * (rest2 + 1) / 2;
        if (maximum < restx) r = mid;
        else l = mid;
    }
    v.push_back(l);
    return dfs(v, l * coef, i + 1, rest - l, restx - l * i);
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    while(cin >> n >> m){
        coef = check_coef(n, m);
//        cerr << coef << endl;
        if (coef == -1) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            vi cnts(1, 1);
            int res = dfs(cnts, coef, 2, n - 1, m - 1);
//            cerr << cnts << endl;
            assert(res == 0);
            vector<vi> v(n + 1);
            v[0].push_back(1);
            int cur = 2;
            ll sum = 1;
            REPS(i, cnts.size() - 1) {
                int x = cnts[i];
                for(int u : v[i - 1]) {
                    int rest = coef;
                    while(x > 0 && rest > 0) {
                        cout << u << " ";
                        x --; rest --;
                        v[i].push_back(cur ++);
                        sum += i + 1;
                    }
                }
            }
            assert(sum == m);
            cout << endl;
        }
    }
    return 0;
}
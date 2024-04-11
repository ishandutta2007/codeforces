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

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
    os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
    os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first-t.first, s.second-t.second);}
template<class S, class T> pair<S,T> operator*(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first*t.first, s.second*t.second);}
template<class S, class T> pair<S,T> operator%(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first%t.first, s.second%t.second);}

const int MOD = 998244353;
int T, n, m;
string s;
int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    vector<ll> dp(n + 1);
    ll ans = 0;
    REP(_, n) {
        int x;
        cin >> x;
        vector<ll> nxt = dp;
        ans += dp[1];
        REPS(i, n) {
            (nxt[i - 1] += dp[i]) %= MOD;
        }
        if (0 < x && x <= n) {
            (nxt[x] += dp[0] + 1) %= MOD;
        }
        swap(dp, nxt);
    }
    cout << ans % MOD << endl;
    return 0;
}
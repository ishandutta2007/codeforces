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

vector<int> calcModInv(int N,int P){
    vector<int> inv(N+1);
    inv[1]=1;
    for(int i=2;i<=N;i++) inv[i] = (P+((long long)-inv[P%i]*(P/i))%P)%P;
    return inv;
}

ll sum = 0;
vi inv = calcModInv(100000, MOD);

int solve(int n, int k, int m) {
    vector<ll> dp(k + 1);
    dp[0] = 1;
    REP(i, k) {
        dp[i + 1] = dp[i] * n % MOD;
    }
    REP(_, m) {
        vector<ll> nxt(k + 1);
        ll sum = 0;
        REP(i, k + 1) {
            sum = (sum + dp[i]) % MOD;
            nxt[i] = sum * inv[i + 1] % MOD;
        }
        swap(dp, nxt);
    }
    return dp[k];
}

ll T, n, m;
int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    while(cin >> n >> m){
        ll ans = 1;
        for (ll i = 2; i * i <= n; i ++) {
            int c = 0;
            while (n % i == 0) {
                n /= i;
                c ++;
            }
            if (c) {
                ans = ans * solve(i, c, m) % MOD;
            }
        }
        if (n > 1) ans = ans * solve(n % MOD, 1, m) % MOD;
        cout << ans << endl;
    }
    return 0;
}
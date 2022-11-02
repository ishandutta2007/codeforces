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
const int N = 7000;
int T, n, m, y, b, r;

int main(int argc, char *argv[]){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    while(cin >> n >> m){
        vi moes(N + 1, 1);
        for (int i=2;i*i<=N;i++) {
            for (int j=i*i;j<=N;j+=i*i) {
                moes[j] = 0;
            }
        }
        vector<bitset<N + 1>> divs(N + 1);
        vector<bitset<N + 1>> tbls(N + 1);
        REPS(i, N) {
            REPS(j, i) {
                if (i % j == 0) {
                    divs[i].set(j);
                }
            }
            for(int j=1;j*i<=N;j++) {
                if (moes[j]) {
                    tbls[i].set(i * j);
                }
            }
        }
        vector<bitset<N + 1>> bits(n);
        REP(_, m) {
            int t, x, y, z, v;
            cin >> t;
            if (t == 1) {
                cin >> x >> v; x--;
                bits[x] = divs[v];
            } else if (t == 2) {
                cin >> x >> y >> z; x--; y--; z--;
                bits[x] = bits[y] ^ bits[z];
            } else if (t == 3) {
                cin >> x >> y >> z; x--; y--; z--;
                bits[x] = bits[y] & bits[z];
            } else if (t == 4) {
                cin >> x >> v; x--;
                putchar('0' + ((bits[x] & tbls[v]).count() % 2));
            }
        }
        puts("");
    }
    return 0;
}
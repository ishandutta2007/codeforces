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


int T, n, m;
int umekomi[25][2] =
        {
                {1,        -1},
                {3,        1},
                {7,        1},
                {15,       5},
                {31,       1},
                {63,       21},
                {127,      1},
                {255,      85},
                {511,      73},
                {1023,     341},
                {2047,     89},
                {4095,     1365},
                {8191,     1},
                {16383,    5461},
                {32767,    4681},
                {65535,    21845},
                {131071,   1},
                {262143,   87381},
                {524287,   1},
                {1048575,  349525},
                {2097151,  299593},
                {4194303,  1398101},
                {8388607,  178481},
                {16777215, 5592405},
                {33554431, 1082401}
        };
int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    map<int, int> memo;
    REPS(i, 24) {
        memo[umekomi[i][0]] = umekomi[i][1];
    }
    while(cin >> n){
        REP(i, n) {
            int a;
            cin >> a;
            int x = 1;
            while(x < a) x = x * 2 + 1;
            if (a < x) {
                cout << x << endl;
            } else if (memo.count(a)) {
                cout << memo[a] << endl;
            } else {
                pii ans(-1, -1);
                REPS(b, a - 1) {
                    chmax(ans, pii(__gcd(a & b, a ^ b), b));
                }
                cout << (memo[a] = ans.first) << endl;
            }
        }
    }
    return 0;
}
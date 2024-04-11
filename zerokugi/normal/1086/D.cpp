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

class BIT {
    int n;
    vector<int> vs;
public:
    BIT(int size) {
        n = size;
        vs = vector<int>(n);
    }
    //O(log n)
    void add(int k, int a) {
        for(int i = k; i < n; i |= i + 1) vs[i] += a;
    }
    //[s,t)	O(log n)
    int sum(int s, int t) {
        if (t <= s) return 0;
        if(s > 0) return sum(0, t) - sum(0, s);
        int res = 0;
        for(int i = t - 1; i >= 0; i = (i & (i + 1)) - 1) res += vs[i];
        return res;
    }
};

int toInt(char c) {
    if (c == 'R') return 0;
    if (c == 'P') return 1;
    if (c == 'S') return 2;
}

int n, q;
string s;
int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> q >> s;
    vector<set<int>> lpos(3);
    vector<set<int>> rpos(3);
    REP(i, 3) {
        lpos[i].insert(n);
        rpos[i].insert(-1);
    }
    vi d(n);
    vector<BIT> bit(3, BIT(n));
    REP(i, n) {
        d[i] = toInt(s[i]);
        bit[d[i]].add(i, 1);
        lpos[d[i]].insert(i);
        rpos[d[i]].insert(i);
    }
    auto calc = [&]() {
        int sum = 0;
        REP(i, 3) {
            if (lpos[(i + 1) % 3].size() > 1 && lpos[(i + 2) % 3].size() == 1) {
                sum += bit[i].sum(0, n);
            } else {
                int left_lose = *lpos[(i + 1) % 3].begin();
                int left_win = *lpos[(i + 2) % 3].begin();
                int right_lose = *rpos[(i + 1) % 3].rbegin();
                int right_win = *rpos[(i + 2) % 3].rbegin();
                if (right_win <= left_win) {
                    left_win = right_win;
                }
                sum += bit[i].sum(left_lose, left_win);
                sum += bit[i].sum(right_win, right_lose);
            }
        }
        cout << n - sum << endl;
    };
    calc();
    REP(_, q) {
        int p; char c;
        cin >> p >> c; p--;
        int x = toInt(c);
        REP(i, 3) {
            if (lpos[i].count(p)) {
                lpos[i].erase(p);
                rpos[i].erase(p);
                bit[i].add(p, -1);
            }
        }
        rpos[x].insert(p);
        lpos[x].insert(p);
        bit[x].add(p, 1);
        calc();
    }
    return 0;
}
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
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first-t.first, s.second-t.second);}

const ll INF = 1ll<<60;
const double EPS = 1e-8;
const int MOD = 1000000007;

int T, n, m;
vector<ll> dp;

struct Trie {
    Trie *p[2];
    int c;
    Trie() {
        p[0] = p[1] = 0;
        c = 0;
    }
    void add(const int &x, const int &i) {
        c ++;
        if (i < 0){
                return;
        }
        int b = 1 & (x >> i);
        if (!p[b]) p[b] = new Trie();
        p[b]->add(x, i - 1);
    }
    int get(const int &x, const int &i) {
        c --;
        if (i < 0) {
            return 0;
        }
        int b = 1 & (x >> i);
        int t;
        if (p[b] && p[b]->c != 0) {
            return p[b]->get(x, i - 1);
        } else {
            return p[!b]->get(x, i - 1) + (1 << i);
        }
    }
} trie;

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    vi a(n), p(n);
    REP(i, n) {
        cin >> a[i];
    }
    REP(i, n) {
        cin >> p[i];
        trie.add(p[i], 30);
    }
    REP(i, n) {
        cout << trie.get(a[i], 30) << endl;
    }
    return 0;
}
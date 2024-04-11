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

int solve2(vector<string> &o, char c1, char c2) {
    vector<string> vs = o;
    int ans = 0;
    REP(i, vs.size()) {
        int mi = MOD;
        REP(k, 2) {
            int sum = 0;
            REP(j, vs[i].size()) {
                sum += vs[i][j] != ((1 & (j ^ k)) ? c1 : c2);
            }
            if(chmin(mi, sum)) {
                REP(j, vs[i].size()) {
                    o[i][j] = ((1 & (j ^ k)) ? c1 : c2);
                }
            }
        }
        ans += mi;
    }
    return ans;
}

vector<string> alls({"ACGT", "AGCT", "ATGC", "CGAT", "CTAG", "GTAC"});

int solve(vector<string> &vs) {
    vector<string> vs1, vs2;
    REP(i, vs.size()) {
        (i % 2 ? vs1 : vs2).push_back(vs[i]);
    }
    int mi = MOD;
    for (string s : alls) {
        vector<string> t1 = vs1, t2 = vs2;
        if (chmin(mi, solve2(t1, s[0], s[1]) + solve2(t2, s[2], s[3]))) {
            REP(i, vs.size()) {
                vs[i] = (i % 2 ? t1 : t2)[i / 2];
            }
        }
    }
    return mi;
}


int T, n, m, y, b, r;

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    while(cin >> n >> m){
        vector<string> vs1(n, string(m, '.')), vs2(m, string(n, '.'));
        REP(i, n) {
            REP(j, m) {
                char c;
                cin >> c;
                vs1[i][j] = vs2[j][i] = c;
            }
        }
        int res1 = solve(vs1);
        int res2 = solve(vs2);
        REP(i, n) {
            REP(j, m) {
                if (res1 < res2) {
                    cout << vs1[i][j];
                } else {
                    cout << vs2[j][i];
                }
            }
            cout << '\n';
        }
    }
    return 0;
}
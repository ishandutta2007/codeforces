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

vector<int> solve(const string &s, const string &sa, const string &sb, int f) {
    int n = s.size();
    vi ans(m, -1);
    vi used(m, 0);
    int gtA = 0;
    int ltB = 0;
    REP(i, n) {
        int x = s[i] - 'a';
        int a = sa[i] - 'a';
        int b = sb[i] - 'a';
        if (ans[x] != -1) {
            if ((!gtA && ans[x] < a) || (!ltB && b < ans[x])) {
                ans.clear();
                return ans;
            }
            if (a < ans[x]) {
                gtA = 1;
            }
            if (ans[x] < b) {
                ltB = 1;
            }
        } else if (gtA) {
            for (int j = 0; j < b; j ++) {
                if (!used[j]) {
                    ans[x] = j;
                    return ans;
                }
            }
            if (used[b]) {
                ans.clear();
                return ans;
            } else {
                ans[x] = b;
                used[b] = 1;
            }
        }  else if (ltB) {
            for (int j = a + 1; j < m; j ++) {
                if (!used[j]) {
                    ans[x] = j;
                    return ans;
                }
            }
            if (used[a]) {
                ans.clear();
                return ans;
            } else {
                ans[x] = a;
                used[a] = 1;
            }
        } else if (a == b) {
            if (used[a]) {
                ans.clear();
                return ans;
            }
            ans[x] = a;
            used[a] = 1;
        } else {
            for (int j = a + 1; j < b; j ++) {
                if (!used[j]) {
                    ans[x] = j;
                    return ans;
                }
            }
            int done = 0;
            REP(k, 2) {
                int p = k ^ f;
                if (p == 0) {
                    if (used[b] == 0) {
                        ans[x] = b;
                        used[b] = 1;
                        gtA = 1;
                        done = 1;
                    }
                } else {
                    if (used[a] == 0) {
                        ans[x] = a;
                        used[a] = 1;
                        ltB = 1;
                        done = 1;
                    }
                }
                if (done) break;
            }
            if (!done) {
                ans.clear();
                return ans;
            }
        }
        if (gtA && ltB) {
            return ans;
        }
    }
    return ans;
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> T;
    while (T --) {
        string s, sa, sb;
        cin >> m >> s >> sa >> sb;
        n = s.size();
        vi ans = solve(s, sa, sb, 0);
        if (ans.empty()) {
            ans = solve(s, sa, sb, 1);
        }
        if (ans.size() == 0) {
            puts("NO");
        } else {
            puts("YES");
            set<int> s;
            REP(i, m) s.insert(i);
            REP(i, m) if (ans[i] != -1) s.erase(ans[i]);
            REP(i, m) {
                if (ans[i] == -1) {
                    ans[i] = *s.begin();
                    s.erase(s.begin());
                }
                putchar('a' + ans[i]);
            }
            puts("");
        }
    }
    return 0;
}
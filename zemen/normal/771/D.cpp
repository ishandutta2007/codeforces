#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 80;
int n;
string s;
vector<int> pos[3];
int d[maxn][maxn][maxn][2];

void uin(int &a, int b) {
    a = min(a, b);
}

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    cin >> n >> s;
    forn (i, n) {
        if (s[i] == 'V')
            pos[0].push_back(i);
        else if (s[i] == 'K')
            pos[1].push_back(i);
        else
            pos[2].push_back(i);
    }
    int A = sz(pos[0]);
    int B = sz(pos[1]);
    int C = sz(pos[2]);
    forn (i, A + 1)
        forn (j, B + 1)
            forn (k, C + 1)
                forn (f, 2)
                    d[i][j][k][f] = inf;
    d[0][0][0][false] = 0;

    forn (i, A + 1)
        forn (j, B + 1)
            forn (k, C + 1)
                forn (flag, 2) {
                    int to = i + j + k;

                    if (i < A) {
                        int p = pos[0][i];
                        int orig = p;
                        forn (t, j)
                            if (pos[1][t] > orig)
                                ++p;
                        forn (t, k)
                            if (pos[2][t] > orig)
                                ++p;
                        uin(d[i + 1][j][k][true], d[i][j][k][flag] + abs(to - p));
                    }

                    if (j < B && !flag) {
                        int p = pos[1][j];
                        int orig = p;
                        forn (t, i)
                            if (pos[0][t] > orig)
                                ++p;
                        forn (t, k)
                            if (pos[2][t] > orig)
                                ++p;
                        uin(d[i][j + 1][k][false], d[i][j][k][flag] + abs(to - p));
                    }

                    if (k < C) {
                        int p = pos[2][k];
                        int orig = p;
                        forn (t, i)
                            if (pos[0][t] > orig)
                                ++p;
                        forn (t, j)
                            if (pos[1][t] > orig)
                                ++p;
                        uin(d[i][j][k + 1][false], d[i][j][k][flag] + abs(to - p));
                    }

                }
    int res = inf;
    uin(res, d[A][B][C][true]);
    uin(res, d[A][B][C][false]);
    cout << res << '\n';
}
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>
#include <cassert>

using namespace std;

#define INF 1000000001
#define INFL 1000000000000000001ll
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef complex <double> point;

#define NAME "b"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

char s1[10001];
char s2[10001];
char t[10001];

int d[101][101][101];
int p[101][101][101];
int pk[101][101][101];
int pi[1001];
char res[1001];

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    gets(s1);
    gets(s2);
    gets(t);
    int n = strlen(s1);
    int m = strlen(s2);
    int len = strlen(t);
    for (int i = 0; i < n; ++i)
        for (int j = i; j >= 0; --j) {
            char good = 1;
            for (int k = 0; k < j; ++k)
                if (t[k] != t[i - j + k + 1]) {
                    good = 0;
                    break;
                }
            if (good) {
                pi[i] = j;
                break;
            }
        }
    //~ for (int i = 0; i < len; ++i)
        //~ cerr << pi[i] << ' ';
    //~ cerr << '\n';
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            for (int k = 0; k < len; ++k)
                d[i][j][k] = -INF;
    d[0][0][0] = 0;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            for (int k = 0; k < len; ++k) {
                if (d[i][j][k] < 0)
                    continue;
                if (i < n) {
                    if (d[i + 1][j][k] < d[i][j][k]) {
                        d[i + 1][j][k] = d[i][j][k];
                        p[i + 1][j][k] = 0;
                    }
                }
                if (j < m) {
                    if (d[i][j + 1][k] < d[i][j][k]) {
                        d[i][j + 1][k] = d[i][j][k];
                        p[i][j + 1][k] = 1;
                    }
                }
                if (i < n && j < m && s1[i] == s2[j]) {
                    int nk = k - 1;
                    while (nk >= 0 && t[nk + 1] != s1[i])
                        nk = pi[nk] - 1;
                    if (t[nk + 1] == s1[i])
                        ++nk;
                    if (nk < len - 1 && d[i + 1][j + 1][nk + 1] < d[i][j][k] + 1) {
                        d[i + 1][j + 1][nk + 1] = d[i][j][k] + 1;
                        p[i + 1][j + 1][nk + 1] = 2;
                        pk[i + 1][j + 1][nk + 1] = k;
                    }
                }
            }
    int cx = n, cy = m, ck = 0;
    for (int i = 0; i < len; ++i)
        if (d[n][m][i] > d[n][m][ck])
            ck = i;
    //~ cerr << d[n][m][ck] << '\n';
    int rc = 0;
    while (cx || cy) {
        //~ cerr << cx << ' ' << cy << '\n';
        if (p[cx][cy][ck] == 0)
            --cx;
        else if (p[cx][cy][ck] == 1)
            --cy;
        else {
            ck = pk[cx][cy][ck];
            --cx, --cy;
            res[rc++] = s1[cx];
        }
    }
    //~ cerr << rc << '\n';
    reverse(res, res + rc);
    if (!rc)
        cout << 0 << '\n';
    else
        puts(res);
}
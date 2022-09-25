#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>

#include <algorithm>
#include <numeric>

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define foreach(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define len(a) ((int) (a).size())

#ifdef CUTEBMAING
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef long long int64;
typedef long double ld;
typedef unsigned long long lint;

const int inf = (1 << 30) - 1;
const int64 linf = (1ll << 62) - 1;
const int N = 1e3 + 100;
const int q = 33333;

int n, m;
char buf[N][N];

char newbuf[N][N];

int main() {
#ifdef XCODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%s", buf[i]);
    }
    map<int64, vector<int>> a;
    for (int i = 0; i < n; i++) {
        int64 h = 0;
        for (int j = 0; j < m; j++) {
            h = (h * q + (buf[i][j] == '#') * (j + 1));
        }
        a[h].pb(i);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            newbuf[i][j] = '.';
        }
    }
    vector<pair<vector<int>, vector<int>>> b;
    for (auto i : a) {
        auto indices = i.sc;
        vector<int> result;
        for (int j = 0; j < m; j++) {
            if (buf[indices.front()][j] == '#') {
                result.pb(j);
            }
        }
        b.push_back(mp(indices, result));
    }
    for (auto& i : b) {
        vector<int> a = i.fs, b = i.sc;
        for (int x : a) {
            for (int y : b) {
                if (newbuf[x][y] == '#') {
                    puts("No");
                    return 0;
                }
                newbuf[x][y] = '#';
            }
        }
    }
    multiset<int> x, y;
    for (auto& i : b) {
        for (int j : i.fs) {
            if (x.find(j) != x.end()) {
                puts("No");
                return 0;
            }
            x.insert(j);
        }
        for (int j : i.sc) {
            if (y.find(j) != y.end()) {
                puts("No");
                return 0;
            }
            y.insert(j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (buf[i][j] != newbuf[i][j]) {
                puts("No");
                return 0;
            }
        }
    }
    puts("Yes");
    return 0;
}
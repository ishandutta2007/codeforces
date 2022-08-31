#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;
typedef long long ll;

typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const int MN = 100010;
int n;
vector<int> g[MN];
int d1[MN], d2[MN];
int b[MN] = {};
int used[MN] = {};
int solve(int i, int f1, int f2) {
    if (used[i]) return 0;
    used[i] = true;
    if (f1) d1[i] = 1-d1[i];
    int r = 0;
    if (d1[i] != d2[i]) {
        r++;
        b[i] = 1;
        f1 = 1-f1;
    }
    for (int d: g[i]) {
        r += solve(d, f2, f1);
    }
    return r;
}

int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", d1+i);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", d2+i);
    }
    cout << solve(0, 0, 0) << endl;
    for (int i = 0; i < n; i++) {
        if (b[i]) {
            printf("%d\n", i+1);
        }
    }
    return 0;
}
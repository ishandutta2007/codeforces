#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const int MN = 101000;
vector<int> g[MN];
int c[MN];
vector<int> tr[MN];
bool used[MN];

int dfs(int i) {
    int cc = c[i];
    for (int d: g[i]) {
        if (used[d]) continue;
        used[d] = true;
        tr[i].push_back(d);
        cc += dfs(d);
    }
    return cc;
}

vector<int> res;
bool sol(int i) {
    int cc = 1;
    res.push_back(i);
    for (int d: tr[i]) {
        if (tr[d].size() || c[d]) {
            if (sol(d)) {
                res.push_back(i);
                res.push_back(d);
                cc++;
            }
            res.push_back(i);
            cc++;
        }
    }
    return ((cc % 2) != c[i]);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; 
        scanf("%d %d", &a, &b); a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", c+i);
        s += c[i];
    }
    if (!s) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            int cc = dfs(i);
            if (cc) {
                if (cc != s) {
                    printf("-1\n");
                    return 0;
                }
                bool f = sol(i);
                printf("%ld\n", res.size() - (f ? 1 : 0));
                for (int j = (f ? 1 : 0); j < res.size()-1; j++) {
                    printf("%d ", res[j]+1);
                }
                printf("%d\n", res[res.size()-1]+1);
                return 0;
            }
        }
    }
    return 0;
}
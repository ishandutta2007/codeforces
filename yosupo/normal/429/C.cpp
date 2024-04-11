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
const int MN = 11;
int n, m;
vector<int> d;
int cou[1<<MN], num[1<<MN], ma[1<<MN];

bool dp[1<<MN][1<<MN][15];
bool used[1<<MN][1<<MN][15];
bool solve(int r, int l, int c) {
    if (c < 0) return false;
    if (!r && (c||l)) return false;
    if (r && !c && !l) return false;
    if (!r && !l && !c) {
        return true;
    }
    if (used[r][l][c]) {
        return dp[r][l][c];
    }
    dp[r][l][c] = used[r][l][c] = true;
    int u = ma[r];
    int rr = r^(1<<u);
    for (int i = 0; i < 1<<u; i++) {
        if ((l & i) == i && cou[i] <= d[u] && num[i]+(d[u]-cou[i]) >= 2) {
            if (solve(rr|i, l^i, c-(d[u]-cou[i]))) {
                return true;
            }
        }
    }
    dp[r][l][c] = false;
    return false;
} 

int main() {
    int u;
    cin >> u;
    for (int i = 0; i < u; i++) {
        int a; cin >> a;
        if (a > 1) {
            d.push_back(a);
            n++;
        } else {
            m++;
        }
    }
    if (u == 1 && m == 1) {
        cout << "YES" << endl;
        return 0;
    }
    if (n >= m) {
        cout << "NO" << endl;
        return 0;
    }
    sort(d.begin(), d.end());
    for (int i = 0; i < 1<<n; i++) {
        for (int k = 0; k < n; k++) {
            if (i & (1<<k)) {
                cou[i] += d[k];
                num[i]++;
                ma[i] = k;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        d[i]--;
    }
    if (solve(1<<(n-1), (1<<(n-1))-1, m)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
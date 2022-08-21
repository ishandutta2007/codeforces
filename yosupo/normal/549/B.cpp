#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MN = 110;
bool g[MN][MN];
int deg[MN], out[MN];
bool used[MN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            g[i][j] = s[j] == '1';
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> out[i];
    }
    fill_n(deg, MN, 0);
    while (true) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (deg[i] == out[i]) {
                u = i;
            }
        }
        if (u == -1) break;
        used[u] = true;
        for (int i = 0; i < n; i++) {
            deg[i] += g[u][i];
        }
    }

    vector<int> v;
    for (int i = 0; i < n; i++) {
        if (!used[i]) continue;
        v.push_back(i);
    }
    cout << v.size() << endl;
    for (int d: v) {
        cout << d+1 << " ";
    } cout << endl;
    return 0;
}
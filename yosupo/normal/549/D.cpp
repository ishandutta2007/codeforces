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

const int MN = 110;

bool g[MN][MN];
int v[MN][MN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            g[i][j] = (s[j] == 'W');
        }
    }
    int s = 0;
    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            int k;
            if (g[i][j]) k = 1;
            else k = -1;
            k -= v[i][j];
            if (!k) continue;
            s++;
            for (int x = i; x >= 0; x--) {
                for (int y = j; y >= 0; y--) {
                    v[x][y] += k;
                }
            }
        }
    }
    cout << s << endl;
    return 0;
}
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

const int MN = 100;

char g[MN][MN];

int main() {
    string base = "face";
    sort(base.begin(), base.end());
    for (int i = 0; i < MN; i++) {
        for (int j = 0; j < MN; j++) {
            g[i][j] = 'x';
        }
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            g[i][j] = s[j];
        }
    }
    int u = 0;
    for (int i = 0; i < MN-1; i++) {
        for (int j = 0; j < MN-1; j++) {
            string s = "";
            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 2; y++) {
                    s += g[i+x][j+y];
                }
            }
            sort(s.begin(), s.end());
            if (base == s) u++;
        }
    }
    cout << u << endl;
    return 0;
}
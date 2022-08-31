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
    int n, k;
    cin >> n >> k;
    int ch = n-k+n-1;
    for (int i = 0; i < k; i++) {
        int m;
        cin >> m;
        vector<int> v;
        for (int j = 0; j < m; j++) {
            int u;
            cin >> u;
            v.push_back(u);
        }
        if (v[0] == 1) {
            bool f = false;
            for (int j = 0; j < m-1; j++) {
                if (v[j]+1 != v[j+1]) {
                    ch -= 2*j;
                    f = true;
                    break;
                }
            }
            if (!f) {
                ch -= 2*(m-1);
            }
        }
    }
    cout << ch << endl;
    return 0;
}
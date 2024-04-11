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

using namespace std;
typedef long long ll;
typedef pair<int, int> P;


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        bool f[30][30] = {};
        int n, p;
        cin >> n >> p;
        f[0][n-1] = true;
        for (int j = 1; j < n; j++) {
            f[j-1][j] = true;
        }
        int c = n+p;
        for (int j = 0; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if (c && !f[j][k]) {
                    c--;
                    f[j][k] = true;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if (f[j][k]) {
                    printf("%d %d\n", j+1, k+1);
                }
            }
        }
    }
    return 0;
}
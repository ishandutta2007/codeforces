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
#include <valarray>
#include <list>
#include <array>

using namespace std;

typedef long long ll;
ll b[8][3];
ll d[8][3];
int mp[6][3] = {
    {0, 1, 2},
    {0, 2, 1},
    {1, 0, 2},
    {1, 2, 0},
    {2, 0, 1},
    {2, 1, 0}
};

bool check() {
    vector<ll> v, v2;
    for (int i = 0; i < 8; i++) {
        for (int j = i+1; j < 8; j++) {
            ll r = 0;
            for (int k = 0; k < 3; k++) {
                r += (d[i][k]-d[j][k])*(d[i][k]-d[j][k]);
            }
            v.push_back(r);
        }
    }
    sort(v.begin(), v.end());
    v2 = v;
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    if (v2.size() != 3) {
        return false;
    }
    if (v2[0]*2 != v2[1] || v2[0]*3 != v2[2]) {
        return false;
    }
    int k = 0;
    while (v[k] == v2[0]) k++;
    if (k != 12) return false;
    while (v[k] == v2[1]) k++;
    if (k != 24) return false;
    return true;
}


bool dfs(int k) {
    if (k == 8) {
        return check();
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            d[k][j] = b[k][mp[i][j]];
        }
        if (dfs(k+1)) {
            return true;
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> b[i][j];
            d[i][j] = b[i][j];
        }
    }
    if (dfs(1)) {
        printf("YES\n");
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 3; j++) {
                cout << d[i][j] << " ";
            }
            printf("\n");
        }
    } else {
        printf("NO\n");
    }
    return 0;
}
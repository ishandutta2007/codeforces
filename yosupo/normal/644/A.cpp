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
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}


int main() {
    int n, a, b;
    cin >> n >> a >> b;
    if (n > a*b) {
        cout << "-1" << endl;
        return 0;
    }
    int g[a][b];
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            g[i][j] = 0;
        }
    }
    int c = 1;
    for (int i = 0; i < a; i++) {
        for (int j = ((i % 2 == 0) ? 0 : 1); j < b; j += 2) {
            if (c <= n) {
                g[i][j] = c;
                c += 2;
            }
        }
    }
    c = 2;
    for (int i = 0; i < a; i++) {
        for (int j = ((i % 2 == 1) ? 0 : 1); j < b; j += 2) {
            if (c <= n) {
                g[i][j] = c;
                c += 2;
            }
        }
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
    return 0;
}
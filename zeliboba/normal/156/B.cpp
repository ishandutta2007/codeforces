#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int n, m, allgood = 0;
    cin >> n >> m;
    vi bad(n), good(n), a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] > 0)
            ++bad[a[i] - 1];
        else {
            ++good[-a[i] - 1];
            ++allgood;
        }
    }
    vi p(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) if (bad[i] + allgood - good[i] == m) {
        p[i] = 1;
        ++cnt;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            if (p[a[i] - 1]) {
                if (cnt == 1)
                    printf("Truth\n");
                else printf("Not defined\n");
            } else {
                printf("Lie\n");
            }
        } else {
            if (p[-a[i] - 1]) {
                if (cnt == 1)
                    printf("Lie\n");
                else printf("Not defined\n");
            } else {
                printf("Truth\n");
            }
        }
    }
    return 0;
}
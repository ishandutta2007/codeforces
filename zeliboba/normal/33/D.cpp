#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;

char a[1000][1000];

int main() {
    int n,m,k;
    scanf("%d%d%d", &n, &m, &k);
    int x[1000], y[1000], kx[1000], ky[1000], r[1000];
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &r[i], &kx[i], &ky[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (r[j] * (long long)r[j] > (x[i] - kx[j]) * (long long)(x[i] - kx[j]) + (y[i] - ky[j]) * (long long)(y[i] - ky[j]))
                a[i][j] = 0;
            else
                a[i][j] = 1;
        }
    }
/*    vector<pii> query(k);
    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &query[i].first, &query[i].second);
        --query[i].first;
        --query[i].second;
        if (query[i].first > query[i].second)
            swap(query[i].first, query[i].second);
    }
    sort(query.begin(), query.end());
    for (int i = 0; i < k; ++i) {
        int res = 0;
        for (int j = 0; j < m; ++j)
            res += a[query[i].first][j] ^ a[query[i].second][j];
        printf("%d\n", res);
    }*/
    for (int i = 0; i < k; ++i) {
        int d, b;
        scanf("%d%d", &d, &b);
        --d; --b;
        int res = 0;
        for (int j = 0; j < m; ++j)
            res += (a[b][j] ^ a[d][j]);
        printf("%d\n", res);
    }
    return 0;
}
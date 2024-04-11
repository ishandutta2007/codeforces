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
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int n;
    cin >> n;
    vector<vi> a(n, vi(n));
    vector<vi> ord(n, vi(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        scanf("%d", &a[i][j]);
        --a[i][j];
        ord[i][a[i][j]] = j;
    }
    vi v(n), ordv(n), cur(n), cur1(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        --v[i];
        ordv[v[i]] = i;
    }
    cur[0] = 0, cur1[0] = n;
    for (int i = 1; i < n; ++i) {
        cur[i] = cur[i - 1];
        cur1[i] = cur1[i - 1];
        if (ordv[i] < ordv[cur[i]]) {
            cur1[i] = cur[i];
            cur[i] = i;
        } else if (cur1[i] == n || ordv[i] < ordv[cur1[i]])
            cur1[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        int best = 0, mi = n;
        for (int j = 0; j < n; ++j) {
            if (i != cur[j]) {
                if (mi > ord[i][cur[j]]) {
                    mi = ord[i][cur[j]];
                    best = j;
                }
            } else if (cur1[j] < n && mi > ord[i][cur1[j]]) {
                mi = ord[i][cur1[j]];
                best = j;
            }
        }
        cout << best + 1 << " ";
    }
    return 0;
}
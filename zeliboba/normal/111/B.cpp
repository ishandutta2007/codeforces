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

void out (vi & v) {
    for (int i = 0; i < v.size(); ++i)
        cerr << v[i] << " ";
    cerr << endl;
}

int main() {
    int n;
    cin >> n;
    vi was(100003, -1);
    for (int i = 0; i < n; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        int cnt = 0;
        for (int j = 1; j * j <= x; ++j) if (x % j == 0) {
            if (i - y > was[j])
                ++cnt;
            if (i - y > was[x / j] && j * j != x)
                ++cnt;
            was[j] = max(was[j], i);
            was[x / j] = max(was[x / j], i);
        }
        printf("%d\n", cnt);
    }
    return 0;
}
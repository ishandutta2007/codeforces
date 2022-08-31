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

map<int, int> id2d, d2id;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> s;
    set<int, greater<int>> rs;
    for (int i = 0; i < n; i++) {
        int d;
        scanf("%d", &d);
        id2d[i] = d; d2id[d] = i;
        s.insert(d);
        rs.insert(d);
    }
    for (int i = 0; i < m; i++) {
        int x, l;
        scanf("%d %d", &x, &l); x--;
        int d = id2d[x];
//        cout << d << " " << l << endl;
        while (true) {
            int p1 = *rs.lower_bound(d+l);
            int a = p1-d;
            int p2 = *s.lower_bound(p1-(l-a));
            int b = p1-p2;

            l -= a;
            d = p1;
            if (b == 0) break;

            int dv = l / b;
            if (dv % 2 == 0) {
                d = p1;
            } else {
                d = p2;
            }
            l %= b;
        }
        printf("%d\n", d2id[d]+1);
    }
    return 0;
}
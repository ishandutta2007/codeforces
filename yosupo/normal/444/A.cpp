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
#include <map>

using namespace std;
typedef long long ll;

typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
const int MN = 550;
int n;
ll d[MN];
vector<T> e;
int main() {
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c; a--; b--;
        e.push_back(T(a, b, c));
    }
    double r = 0;
    for (T t: e) {
        ll a, b, c;
        tie(a, b, c) = t;
        r = max(r, (double)(d[a]+d[b])/c);
    }
    printf("%.23f\n", r);
    return 0;
}
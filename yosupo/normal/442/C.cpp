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
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const int MN = 500500;
int a[MN];
struct D {
    int l, r;
    int d;
    void setmin() {
        if (MN <= r) return;
        d = min(a[l], a[r]);
    }
};
D d[MN];
int main() {
    int n;
    cin >> n;
    priority_queue<P, vector<P>, greater<P>> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        d[i].l = i-1; d[i].r = i+1;
        q.push(P(a[i], i));
    }
    for (int i = 1; i < n-1; i++) {
        d[i].setmin();
    }
    ll r = 0;
    while (q.size() > 2) {
        P p = q.top(); q.pop();
        D dd = d[p.second];
        if (dd.l < 0 || n <= dd.r) {
            r += a[p.second];
            if (dd.l < 0) {
                d[dd.r].l = -1;
            } else {
                d[dd.l].r = n;
            }
        } else {
            r += dd.d;
            d[dd.l].r = dd.r;
            d[dd.l].setmin();
            d[dd.r].l = dd.l;
            d[dd.r].setmin();
        }
    }
    cout << r << endl;
    return 0;
}
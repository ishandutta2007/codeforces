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
const int MN = 101000;
int a[MN], b[MN];
int n, d;
ll x;
ll getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    for(int i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

P a2[MN];
int res[MN] = {};
bool ok[MN] = {};
vector<int> v;
int main() {
    cin >> n >> d >> x;
    initAB();
    for (int i = 0; i < n; i++) {
        if (b[i]) {
            v.push_back(i);
        }
        a2[i] = P(MN-a[i], i);
    }
    sort(a2, a2+n);
    for (int i = 0; i < min(n, 1000); i++) {
        P p = a2[i];
        int dd, po;
        tie(dd, po) = p; dd = MN-dd;
        for (int j = po; j < n; j++) {
            if (!ok[j] && b[j-po]) {
                ok[j] = true;
                res[j] = dd;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!ok[i]) {
            for (int d: v) {
                if (d > i) break;
                res[i] = max(res[i], a[i-d]);
            }
        }
        printf("%d\n", res[i]);
    }
    return 0;
}
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
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
typedef vector<string> vs;
ll x;
ll nextx() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

void initAB(vi & a, vi & b, int n, int d) {
    for(int i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(a[i], a[nextx() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[nextx() % (i + 1)]);
    }
}

void out(const vi & v) {
    for (int i = 0; i < v.size(); ++i)
        cerr << v[i] << ' ';
    cerr << endl;
}

int main() {
    int n, d;
    cin >> n >> d >> x;
    vi a(n), b(n), pos(n + 1);
    initAB(a,b,n,d);
    
    for (int i = 0; i < n; ++i)
        pos[a[i]] = i;
    vi ones;
    for (int i = 0; i < n; ++i) if (b[i])
        ones.push_back(i);
    //out(a);
    //out(b);
    //out(ones);
    //out(pos);
    vi c(n, -1);
    int i0 = n;
    while (i0 > 1 && (n-i0)*d < 8e7) --i0;
    for (int i = i0; i <= n; ++i) {
        for (int it = 0; it < ones.size() && ones[it] < n - pos[i]; ++it) {
            c[ones[it]+pos[i]] = i;
        }
    }
    for (int i = 0; i < n; ++i) if (c[i] == -1) {
        c[i] = 0;
        for (int it = 0; it < ones.size() && ones[it] <= i; ++it) {
            c[i] = max(c[i], a[i - ones[it]]);
        }
    }
    for (int i = 0; i < c.size(); ++i) printf("%d\n", c[i]);
    return 0;
}
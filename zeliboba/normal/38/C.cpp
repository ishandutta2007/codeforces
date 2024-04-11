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

int main() {
    int n,l;
    cin >> n >> l;
    vi a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int s = 0;
    for (int t = l; t < 101; ++t) {
        int cur = 0;
        for (int i = 0; i < n; ++i)
            cur += t * (a[i] / t);
        s = max(s, cur);
    }
    printf("%d\n", s);
    return 0;
}
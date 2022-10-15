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
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;

int main() {
    int n,a,b;
    cin >> n >> a >> b;
    vector<pii> t(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i].first);
        t[i].second = i;
        if (a < b)
            t[i].first *= -1;
        if (a == b)
            t[i].first = 0;
    }
    sort(t.begin(), t.end());
    vi res(n, 2);
    for (int i = 0; i < a; ++i) {
        res[t[i].second] = 1;
    }
    for (int i = 0; i < res.size(); ++i)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}
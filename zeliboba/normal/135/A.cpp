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
    vi a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    if (a.back() > 1) {
        printf("1");
        for (int i = 1; i < n; ++i) {
            printf(" %d", a[i - 1]);
        }
    } else {
        for (int i = 0; i + 1 < n; ++i)
            printf("1 ");
        printf("2");
    }
    return 0;
}
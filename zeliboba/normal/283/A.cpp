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

int main() {
    int n;
    cin >> n;
    ll sum = 0;
    vi v(1, 0);
    vl add(1, 0);
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int a,x;
            scanf("%d%d",&a,&x);
            a = min(a, (int)v.size());
            sum += a*(ll)x;
            add[a-1] += x;
        } else if (t == 2) {
            int k;
            scanf("%d", &k);
            sum += k;
            v.push_back(k);
            add.push_back(0);
        } else {
            sum -= v.back() + add.back();
            add[add.size() - 2] += add.back();
            v.pop_back();
            add.pop_back();
        }
        printf("%.10lf\n", (double)sum/v.size());
    }
    return 0;
}
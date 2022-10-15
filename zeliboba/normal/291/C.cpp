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
    int n, k;
    cin >> n >> k;
    vl ip(n);
    for (int i = 0; i < n; ++i) {
        int a,b,c,d;
        scanf("%d%*c%d%*c%d%*c%d",&a,&b,&c,&d);
        ip[i] = d + (c<<8) + (b << 16) + (((ll)a << 24));
    }
    ll mask = 0;
    for (int i = 31; i > 0; --i) {
        mask += (1LL << i);
        vl v(n);
        for (int j = 0; j < v.size(); ++j)
            v[j] = (mask & ip[j]);
        sort(v.begin(), v.end());
        if (unique(v.begin(), v.end()) - v.begin() == k) {
            cout << (mask >> 24) << "." << ((mask >> 16)&255) << "." << ((mask >> 8)&255) << "." << (mask&255) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
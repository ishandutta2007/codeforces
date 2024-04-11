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
    vll cnt(21);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        cnt[a + 10]++;
    }
    long long res = ((cnt[10] - 1) * (ll)cnt[10]) / 2;
    for (int i = 0; i < 10; ++i)
        res += cnt[i] * (ll)cnt[20 - i];
    cout << res << endl;
    return 0;
}
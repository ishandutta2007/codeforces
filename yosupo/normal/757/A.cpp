#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
int bsr(int x) { return 31 - __builtin_clz(x); }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    string s;
    cin >> s;
    map<char, int> mp;
    for (char c: s) mp[c]++;
    int ans = TEN(9);
    ans = min(ans, mp['B']);
    ans = min(ans, mp['u']/2);
    ans = min(ans, mp['l']);
    ans = min(ans, mp['b']);
    ans = min(ans, mp['a']/2);
    ans = min(ans, mp['s']);
    ans = min(ans, mp['r']);
    cout << ans << endl;
    return 0;

}
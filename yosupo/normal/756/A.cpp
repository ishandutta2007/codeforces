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
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i]; p[i]--;
    }    
    int co = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        co += x;
    }
    co = 1 - co%2;
    bool used[n]; fill_n(used, n, false);
    int gc = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        gc++;
        int j = i;
        do {
            used[j] = true;
            j = p[j];
        } while (j != i);
    }
    if (gc > 1) co += gc;
    cout << co << endl;
    return 0;
}
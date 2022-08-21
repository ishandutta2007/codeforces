#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    set<int> s;
    bool f = false;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        a += i;
        if (s.count(a)) f = true;
        s.insert(a);
    }
    if (f) {
        cout << ":(" << endl;
        return 0;
    }
    int u = 0;
    for (int d: s) {
        printf("%d ", d - u);
        u++;
    }
    printf("\n");
    return 0;
}
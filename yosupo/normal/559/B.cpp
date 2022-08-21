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


void sort_str(char a[], int sz) {
    if (sz % 2) return;
    sort_str(a, sz/2);
    sort_str(a+sz/2, sz/2);
    bool sw = false;
    for (int i = 0; i < sz/2; i++) {
        if (a[i] > a[i+sz/2]) {
            sw = true;
            break;
        }
        if (a[i] < a[i+sz/2]) break;
    }
    if (!sw) return;
    for (int i = 0; i < sz/2; i++) {
        swap(a[i], a[i+sz/2]);
    }
}

const int MN = 200200;

char a[MN], b[MN];
int main() {
    scanf("%s", a);
    scanf("%s", b);
    int n = strlen(a);
    sort_str(a, n); sort_str(b, n);
    bool f = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            f = false;
            break;
        }
    }
    if (f) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
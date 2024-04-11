#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>
#include <valarray>
#include <list>
#include <array>

using namespace std;

typedef long long ll;

const int MN = 1010;

int d[MN];
int p;

bool next(int n) {
    int i;
    for (i = n-1; i >= 0; i--) {
        d[i]++;
        if (d[i] != p) {
            break;
        }
        d[i] = 0;
    }
    return (i != -1);
}

bool isok(int n) {
    bool f = true;
    for (int i = 0; i < n-1; i++) {
        if (d[i] == d[i+1]) {
            f = false;
            break;
        }
    }
    for (int i = 0; i < n-2; i++) {
        if (d[i] == d[i+2]) {
            f = false;
            break;
        }
    }
    return f;
}

bool solve(int n) {
    if (n <= 4) {
        while (!isok(n)) {
            if (!next(n)) {
                return false;
            }
        }
        return true;
    }
    while (!isok(n)) {
        if (d[n-3] == d[n-2] || d[n-4] == d[n-2]) {
            if (!next(n-1)) return false;
            if (!solve(n-1)) return false;
            d[n-1] = 0;
        }
        if (isok(n)) break;
        if (!next(n)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n >> p;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        d[i] = s[i] - 'a';
    }
    if (!next(n)) {
        printf("NO\n");
        return 0;
    }
    if (!solve(n)) {
        printf("NO\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        s[i] = d[i] + 'a';
    }
    cout << s << endl;
    return 0;
}
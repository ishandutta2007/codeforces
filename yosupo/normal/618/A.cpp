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
using ll = long long;

int main() {
    int n;
    cin >> n;
    deque<int> v;
    for (int i = 0; i < n; i++) {
        v.push_front(1);
        while (v.size() >= 2 && v[0] == v[1]) {
            int d = v[0];
            v.pop_front(); v.pop_front();
            v.push_front(d+1);
        }
    }
    reverse(v.begin(), v.end());
    for (int d: v) {
        cout << d << " ";
    } cout << endl;
    return 0;
}
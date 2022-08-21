#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;


int main() {
    ll c, hr, hb, wr, wb;
    cin >> c >> hr >> hb >> wr >> wb;
    ll u = c / (wr*wb);
    if (u) u--;
    ll res = u * max(hr*wb, hb*wr);
    c -= u*wr*wb;

    // c < wr*wb
    if (wr < wb) {
        swap(wr, wb);
        swap(hr, hb);
    }
    ll res2 = 0;
    ll numwr = 0;
    while (true) {
        if (numwr*wr > c) break;
        ll numwb = (c - numwr*wr) / wb;
        res2 = max(res2, numwr*hr + numwb*hb);
        numwr++;
    }
    cout << res+res2 << endl;
    return 0;
}
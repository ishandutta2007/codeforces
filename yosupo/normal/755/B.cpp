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

    int n, m;
    cin >> n >> m;

    set<string> st;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        st.insert(s);
    }
    int c = 0;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (st.count(s)) c++;
    }
    n -= c; m -= c;
    while (true) {
        //poland
        if (c) c--;
        else if (n) n--;
        else {
            cout << "NO" << endl;
            break;
        }
        //enemy
        if (c) c--;
        else if (m) m--; 
        else {
            cout << "YES" << endl;
            break;
        }
    }
    return 0;
}
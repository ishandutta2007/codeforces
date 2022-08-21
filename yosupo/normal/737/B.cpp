#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }


const int MN = 200200;
int n, a, b, k;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> a >> b >> k;
    cin >> s; s += '1';

    int co = 0;
    int L;

    L = 0;
    while (L < n) {
        if (s[L] == '1') {
            L++;
            continue;
        }
        int R = L;
        while (s[R] == '0') {
            R++;
        }
        co += (R-L)/b;
        L = R;
    }

    vector<int> v;
    L = 0;
    while (L < n) {
        if (s[L] == '1') {
            L++;
            continue;
        }
        int R = L;
        while (s[R] == '0') {
            R++;
        }
        for (int i = L + b-1; i < R; i += b) {
            v.push_back(i);
        }
        L = R;
    }

    cout << co-a+1 << endl;
    for (int i = 0; i < co-a+1; i++) {
        cout << v[i]+1 << " ";
    }
    cout << endl;
    return 0;
}
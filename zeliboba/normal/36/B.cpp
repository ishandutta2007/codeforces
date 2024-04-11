#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,k;
    cin >> n >> k;
    vi pws(k + 1, 1);
    vector<string> v(n);
    for (int i = 1; i <= k; ++i)
        pws[i] = pws[i - 1] * n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    for (int i = 0; i < pws[k]; ++i) {
        for (int j = 0; j < pws[k]; ++j) {
            int i1 = i, j1 = j;
            bool out = true;
            for (int i = 0; i < k; ++i) {
                if (v[i1 % n][j1 % n] == '*') {
                    cout << '*';
                    out = false;
                    break;
                }
                i1 /= n;
                j1 /= n;
            }
            if (out)
                cout << '.';
        }
        cout << endl;
    }
    return 0;
}
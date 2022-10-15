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
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int main() {
    int n;
    cin >> n;
    int cur = 1;
    vector<string> vs(4, string(n, 'a'));
    for (int i = 0; i < n - 1; ++i) {
        int cur1 = (cur + 1) % 26;
        int m = i % 2;
        vs[2 * m][i] = vs[2 * m][i + 1] = cur + 'a';
        vs[2 * m + 1][i] = vs[2 * m + 1][i + 1] = cur1 + 'a';
        cur = (cur + 2) % 26;
    }
    int m = (n - 1) % 2;
    vs[2 * m][n - 1] = vs[2 * m + 1][n - 1] = cur + 'a';
    for (int i = 0; i < 4; ++i)
        cout << vs[i] << endl;
    return 0;
}
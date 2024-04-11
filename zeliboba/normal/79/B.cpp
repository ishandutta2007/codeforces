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
typedef long long i64;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;

int main() {
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    long long a, b;
    vi bad;
    for (int i = 0; i < k; ++i) {
        cin >> a >> b;
        --a; --b;
        bad.push_back(a * m + b);
    }
    sort(bad.begin(), bad.end());
    vector<string> s(4);
    s[0] = "Waste\n";
    s[1] = "Carrots\n";
    s[2] = "Kiwis\n";
    s[3] = "Grapes\n";
    for (int i = 0; i < t; ++i) {
        cin >> a >> b;
        --a; --b;
        long long t = a * m + b;
        int it = lower_bound(bad.begin(), bad.end(), t) - bad.begin();
        if (it < bad.size() && bad[it] == t) {
            cout << s[0];
        } else {
            cout << s[1 + (t - it) % 3];
        }
    }
    return 0;
}
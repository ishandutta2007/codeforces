#include <cstdio>
#include <cstdlib>
#include <cassert>
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
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    vi fac(7, 1);
    for (int i = 2; i < fac.size(); ++i)
        fac[i] = i * fac[i - 1];
    int n;
    string s;
    cin >> s;
    vector<char> v;
    for (int i = 0; i < 6; ++i)
        v.push_back(s[i]);
    sort(v.begin(), v.end());
    vi k(1, 1);
    for (int i = 1; i < 6; ++i) {
        if (v[i] == v[i - 1])
            ++k.back();
        else k.push_back(1);
    }
    sort(k.begin(), k.end());
    if (k[0] == 6) {
        cout << 1 << endl;
        return 0;
    }
    int res = fac[6];
    for (int i = 0; i < k.size(); ++i)
        res /= fac[k[i]];
    int res1 = 0;
    if (k.size() == 2 && k[0] == 3)
        res += 16;
    if (k.size() == 2 && k[0] == 2)
        res += 6 * 3;
    if (k.size() == 3 && (k[0] == 2 && k[1] == 2))
        res += 6 * 6;
    if (k.back() >= 4) {
        if (k.size() == 3) {
            res += 6 * 2;
        } else {
            res += 6;
            if (k.back() == 5)
                res += 6;
        }
    }
    if ((k.back() >= 2 && k[k.size() - 2] >= 2) || k.back() >= 4) {
        if (k.size() == 3 && k[0] == 2) {
            res += 3 * 3 * 2;
        } else {
            if (k.size() == 2 && k[0] == 2) {
                res += 3 * 3;
            } else {
                if (k.back() < 4)
                    res += 3 * 2 * 2;
                else res += 3 * 2;
            }
        }
    }
    cerr << res << endl;
//    assert(res % 24 == 0);
    cout << (res + 12) / 24 << endl;
    return 0;
}
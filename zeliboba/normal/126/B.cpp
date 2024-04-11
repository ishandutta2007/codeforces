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
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1) {
        cout << "Just a legend\n";
        return 0;
    }
    vi z(s.size());
    int e = 0, best = 0;
    vi suf;
    vi mid;
    for (int i = 1; i < s.size(); ++i) {
        if (i >= e) {
            e = i - 1;
            best = i;
            for (int j = i; j < s.size() && s[j] == s[j - i]; ++j) {
                ++e;
                ++z[i];
            }
        } else {
            z[i] = min(z[i - best], e - i + 1);
//            cerr << i << " " << z[i - best] << " " << e << endl;
            if (z[i - best] >= e - i + 1) {
                best = i;
                for (int j = e + 1; j < s.size() && s[j] == s[j - i]; ++j) {
                    ++e;
                    ++z[i];
                }
            }
        }
        if (z[i]) {
            if (i + z[i] - 1 == n - 1) {
                suf.push_back(z[i]);
                if (z[i] > 1)
                    mid.push_back(z[i] - 1);
            } else mid.push_back(z[i]);
        }
//      cerr << z[i] << endl;
    }
    sort(suf.begin(), suf.end());
    sort(mid.begin(), mid.end());
    while (!mid.empty() && !suf.empty() && suf.back() > mid.back())
        suf.pop_back();
    if (!mid.empty() && !suf.empty()) {
        string res(s.begin(), s.begin() + min(mid.back(), suf.back()));
        cout << res << endl;
    } else {
        cout << "Just a legend\n";
    }
    return 0;
}
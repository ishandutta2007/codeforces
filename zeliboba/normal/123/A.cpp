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
    vector<int> primes(1, 1);
    for (int i = 2; i <= s.size(); ++i) {
        bool ok = 1;
        for (int j = 2; j * j <= i; ++j) if (i % j == 0)
            ok = 0;
        if (ok && i * 2 > s.size())
            primes.push_back(i);
    }
    vector<int> alp(26);
    for (int i = 0; i < s.size(); ++i)
        alp[s[i] - 'a']++;
    int ma = 0, best = 0;
    for (int i = 0; i < alp.size(); ++i) if (ma < alp[i]) {
        ma = alp[i];
        best = i;
    }
    if (ma < s.size() - primes.size()) {
        cout << "NO\n";
        return 0;
    } else {
        cout << "YES\n";
        string res(s.size(), best + 'a');
        int it = 0;
        for (int i = 0; i < alp.size(); ++i) if (i != best) {
            for (int cnt = 0; cnt < alp[i]; ++cnt) {
                res[primes[it] - 1] = 'a' + i;
                ++it;
            }
        }
        cout << res << endl;
    }
    return 0;
}
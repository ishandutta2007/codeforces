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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<string> vs(n);
    for (int i = 0; i < n; ++i)
        cin >> vs[i];
    vector<vi> alph(26);
    for (int i = 0; i < k; ++i)
        alph[s[i] - 'a'].push_back(i);
    for (int i = 0; i < n; ++i) {
        i64 res = 0;
        for (int it = 0; it < vs[i].size(); ++it) {
            int t = vs[i][it] - 'a';
            if (alph[t].empty()) {
                res += vs[i].size();
            } else {
                vi::iterator iter = lower_bound(alph[t].begin(), alph[t].end(), it);
                int mi = 10000000;
                if (iter != alph[t].end())
                    mi = min(mi, (*iter) - it);
                if (iter != alph[t].begin()) {
                    --iter;
                    mi = min(mi, it - (*iter));
                }
                res += mi;
            }
        }
        cout << res << endl;
    }
    return 0;
}
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
    int n, life, reg;
    cin >> n >> life >> reg;
    vi pw(n), dmg(n);
    for (int i = 0; i < n; ++i)
        cin >> pw[i] >> dmg[i];
    vector<bool> used(n, false);
    int t = 0;
    int totdmg = 0;
    int remain = life;
    vector<pii> action;
    int ma = -1, best = -1;
    for (int i = 0; i < n; ++i)
        if (!used[i] && remain * 100 <= pw[i] * life)
            if (ma < dmg[i]) {
                ma = dmg[i];
                best = i;
            }
    if (best == -1) {
        cout << "NO\n";
        return 0; 
    } else {
        action.push_back(pii(t, best));
        totdmg += ma;
        used[best] = true;
    }
    while (true) {
        ++t;
        remain -= totdmg;
        remain += reg;
        remain = min (remain, life);
        best = ma = -1;
        if (remain <= 0) {
            cout << "YES\n";
            cout << t << " " << action.size() << endl;
            for (int i = 0; i < action.size(); ++i)
                cout << action[i].first << " " << action[i].second + 1<< endl;
            return 0;
        }
        for (int i = 0; i < n; ++i)
            if (!used[i] && remain * 100 <= pw[i] * life)
                if (ma < dmg[i]) {
                    ma = dmg[i];
                    best = i;
                }
        if (best == -1) {
            if (totdmg <= reg) {
                cout << "NO\n";
                return 0; 
            }
        } else {
            action.push_back(pii(t, best));
            totdmg += ma;
            used[best] = true;
        }
    }
    return 0;
}
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

void out (const vi & p) {
    for (int i = 0; i < p.size(); ++i)
        cerr << p[i] << " ";
    cerr << endl;
}

void kmp (const string & s, int len, vi & badpos) {
    vi p(s.size() + 1);
    p[0] = p[1] = 0;
    for (int i = 2; i <= s.size(); ++i) {
//        cerr << "i=" << i << endl;
        if (s[p[i - 1]] == s[i - 1]) {
            p[i] = p[i - 1] + 1;
        } else {
            int cur = p[p[i - 1]];
            while (cur && s[cur] != s[i - 1]) {
//                cerr << cur << endl;
                cur = p[cur];
            }
//            cerr << cur << endl;
            if (cur)
                p[i] = cur + 1;
            else
                p[i] = s[0] == s[i - 1];
        }
        if (p[i] == len && i > len + 1)
            badpos[i - len - 2] = min(badpos[i - len - 2], len);
    }
    out(p);
}

int main() {
    int n;
    string s;
    cin >> s;
    cin >> n;
    vector<string> vs(n);
    for (int i = 0; i < n; ++i)
        cin >> vs[i];
    vector<int> badpos(s.size(), 1000);
    for (int i = 0; i < n; ++i) {
        string cur = vs[i] + "#" + s;
        kmp(cur, vs[i].size(), badpos);
    }
//    out(badpos);
    pii best(0, 0);
    int near = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (badpos[i] < 1000)
            near = max(near, i - badpos[i] + 2);
        pii newbest(i - near + 1, near);
        if (best.first < newbest.first)
            best = newbest;
    }
    if (best.first)
        cout << best.first << " " << best.second << endl;
    else cout << "0 0\n";
    return 0;
}
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
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

vector<string> msplit(const string & s, char c) {
    vector<string> res(1, "");
    int it = 0;
    while (it < s.size()) {
//        cerr << it << endl;
        while (it < s.size() && s[it] != c) {
            res.back().push_back(s[it]);
            ++it;
        }
        if (it < s.size()) {
            res.push_back("");
            ++it;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<string> cur;
    for (int i = 0; i < n; ++i) {
        string com;
        cin >> com;
        if (com == "pwd") {
            cout << "/";
            for (int i = 0; i < cur.size(); ++i)
                cout << cur[i] << "/";
            cout << endl;
            continue;
        }
        string path;
        cin >> path;
//        cerr << path << endl;
        vector<string> vs = msplit(path, '/');
//        cerr << vs.size() << endl;
        int it = 0;
        if (vs[0] == "") {
            it = 1;
            cur.clear();
        }
        while (it < vs.size()) {
            if (vs[it] == "..") {
                cur.pop_back();
            } else {
                cur.push_back(vs[it]);
            }
            ++it;
        }
    }
    return 0;
}
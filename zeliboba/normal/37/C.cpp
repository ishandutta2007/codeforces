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
typedef vector<char> vc;
typedef vector<double> vd;
typedef pair<int, int> pii;

bool bad(const vc & s) {
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == '0')
            return false;
    return true;
}

vc next(const vc & s) {
    vc res = s;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (res[i] == '0') {
            res[i] = '1';
            break;
        } else
            res[i] = '0';
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<pii> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i].first;
        l[i].second = i;
    }
    sort(l.begin(), l.end());
    vector<vc> words(n);
    vc curword(l.back().first, '0');
    for (int i = l.size() - 1; i >= 0; --i) {
//        cout <<i << endl;
        while (curword.size() > l[i].first)
            curword.pop_back();
        if (i != l.size() - 1) {
            if (bad(curword)) {
                cout << "NO\n";
                return 0;
            } else {
                curword = next(curword);
            }
        }
        int cur = l[i].second;
        words[cur] = curword;
    }
    cout << "YES\n";
    for (int i = 0; i < words.size(); ++i) {
        for (int j = 0; j < words[i].size(); ++j)
            printf("%c", words[i][j]);
        printf("\n");
    }
    return 0;
}
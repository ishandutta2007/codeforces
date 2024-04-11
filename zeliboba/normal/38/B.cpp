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

bool beat(pii x, pii y) {
    for (int i = -1; i < 2; i += 2)
        for (int j = -2; j < 3; j += 4) {
            if (x.first + i == y.first && x.second + j == y.second ||
                    x.first + j == y.first && x.second + i == y.second)
                return true;
        }
    return false;
}

pii in() {
    string s;
    cin >> s;
    return pii(s[0] - 'a', s[1] - '1');
}

int main() {
    pii l = in();
    pii kn = in();
//  cout << l.first << " " << l.second << endl;
//  cout << kn.first << " " << kn.second << endl;
    int count = 0;
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            if (i != l.first && j != l.second)
                if (i != kn.first || j != kn.second)
                    if (!beat(kn, pii(i, j)) && !beat(l, pii(i, j))) {
                        ++count;
//                      cout << i << " " << j << endl;
                    }
    cout << count << endl;
    return 0;
}
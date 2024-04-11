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

int cnt (string s) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            ++res;
    return res;
}

int main() {
    vector<string> vs(3);
    int it = 0;
    char s[1000];
    for (int i = 0; i < 3; ++i) {
        gets(s);
        vs[i] = (string)s;
    }
    if (cnt(vs[0]) == 5 && cnt(vs[1]) == 7 && cnt(vs[2]) == 5)
        cout << "YES\n";
    else cout << "NO\n";
    for (int i = 0; i < vs.size(); ++i)
        cerr << cnt(vs[i]) << endl;
    return 0;
}
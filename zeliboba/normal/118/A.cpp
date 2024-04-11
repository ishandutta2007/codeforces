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
    char t[6] = {'A', 'O', 'Y', 'E', 'U', 'I'};
    int diff = (int)'A' - (int)'a';
    string s;
    cin >> s;
    string s1;
    for (int i = 0; i < s.size(); ++i) {
        bool sogl = 1;
        for (int j = 0; j < 6; ++j) if (s[i] == t[j] || s[i] == t[j] - diff)
            sogl = 0;
        if (sogl) {
            s1 += '.';
            if ('A' <= s[i] && s[i] <= 'Z')
                s1.push_back(s[i] - diff);
            else s1.push_back(s[i]);
        }
    }
    cout << s1 << endl;
    return 0;
}
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
    bool all = 1;
    for (int i = 1; i < s.size(); ++i)
        if (!isupper(s[i]))
            all = 0;
    if (all) {
        for (int i = 0; i < s.size(); ++i) {
            if (isupper(s[i]))
                s[i] = tolower(s[i]);
            else if (islower(s[i]))
                s[i] = toupper(s[i]);
        }
    }
    cout << s << endl;
    return 0;
}
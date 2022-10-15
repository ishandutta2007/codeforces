#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
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

char s[200000];

int main() {
    gets(s);
    int n = strlen(s);
    bool open = 0;
    string cur = "";
    for (int i = 0; i < n; ++i) {
        if (s[i] == '"') {
            if (open) {
                open = false;
                cout << "<" << cur << ">" << endl;
                cur = "";
            } else {
                open = true;
            }
        } else {
            if (s[i] != ' ' || open) {
                cur += s[i];
            } else {
                if (cur == "") {
                    continue;
                } else {
                    cout << "<" << cur << ">" << endl;
                    cur = "";
                }
            }
        }
    }
    if (cur != "")
        cout << "<" << cur << ">" << endl;
    return 0;
}
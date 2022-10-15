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
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int n;
    cin >> n;
    string s;
    while (n % 7) {
        n -= 4;
        if (n < 0) {
            cout << -1;
            return 0;
        }
        s += '4';
    }
    s += string(n / 7, '7');
    cout << s << endl;
    return 0;
}
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

int main() {
    int n;
    cin >> n;
    vector<pair<long long, string> > v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].second;
        int pl, mi, a,b,c,d,e;
        cin >> pl >> mi >> a >> b >> c >> d >> e;
        v[i].first = 100 * pl - 50 * mi + a + b + c + d + e;
    }
    sort(v.begin(), v.end());
    cout << v.back().second << endl;
    return 0;
}
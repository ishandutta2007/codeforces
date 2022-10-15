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

int main() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    int count = 0;
    int h = 1;
    int curh = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            ++curh;
        } else {
            ++count;
            h = max(h, curh);
            curh = 1;
        } 
    }
    ++count;
    h = max(h, curh);
    cout << h << " " << count << endl;
    return 0;
}
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
    set<pii> top;
    vi a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        top.insert(pii(sum, i));
    }
    int diff = (*(top.rbegin())).first;
    int down = 0;
    sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        top.erase(pii(sum, i));
        down = min(down, sum);
        if (!top.empty())
            diff = max(diff, (*(top.rbegin())).first - down);
        else
            diff = max(diff, 0);
    }
    cout << 2 * (long long)diff - sum;
    return 0;
}
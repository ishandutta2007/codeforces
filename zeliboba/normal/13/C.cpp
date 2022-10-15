#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;

typedef vector<long long> vi;
typedef vector<pair<int, int> > vii;

int main() {
    int n;
    cin >> n;
    vi a(n);
    vi res(n, 0), res1(n);
    vi s(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s[i] = a[i];
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < n; ++i) {
        res[i] = abs(a[0] - s[i]);
    }
    for (int i = 1; i < n; ++i) {
        long long mi = res[0];
        for (int j = 0; j < n; ++j) {
            mi = min(mi, res[j]);
            res1[j] = mi + abs(a[i] - s[j]);
        }
        res = res1;
    }
    long long mi = res[0];
    for (int i = 0; i < n; ++i) 
        mi = min(mi, res[i]);
    cout << mi << endl;
    return 0;
}
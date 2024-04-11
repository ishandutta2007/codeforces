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

int main() {
    int a, n;
    cin >> a;
    vi div;
    for (int i = 1; i * i <= a; ++i) if (a%i == 0) {
        div.push_back(i);
        if (i*i != a) div.push_back(a/i);
    }
    sort(div.begin(), div.end());
    string s;
    cin >> s;
    n = s.size();
    vl d(div.size());
    ll cnt0 = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        int it = 0;
        for (int j = i; j < n; ++j) {
            sum += s[j]-'0';
            if (sum == 0) {
                ++cnt0;
            } else if (a && a%sum == 0) {
                while (div[it] < sum) ++it;
                d[it]++;
            }
        }
    }
    if (a == 0) {
        cout << cnt0*n*(n+1)-cnt0*cnt0 << endl;
    } else {
        ll sum = 0;
        for (int i = 0; i < div.size(); ++i) for (int j = i; j < div.size(); ++j) if (div[i]*div[j] == a) {
//            cerr << d[i] << ' ' << d[j] << ' ' << div[i] << ' ' << div[j] << endl;
            if (i!=j) {
                sum += 2*d[i]*d[j];
            } else {
                sum += d[i]*d[i];
            }
        }
        cout << sum << endl;
    }
    return 0;
}
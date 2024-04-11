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

vvi gr;

int main() {
    int n,m;
    cin >> n >> m;
    gr.resize(n);
    for (int i = 0; i < m; ++i) {
        int a,b;
        scanf("%d%d",&a,&b);
        --a;--b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    int cnt1 = 0, cnt2 = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (gr[i].size() == 1)
            ++cnt1;
        if (gr[i].size() == 2)
            ++cnt2;
        if (gr[i].size() == n-1)
            ++cnt;
    }
    if (cnt == 1 && cnt1 == n-1) {
        cout << "star topology\n";
    } else if (cnt2 == n) {
        cout << "ring topology\n";
    } else if (cnt1 == 2 && cnt2 == n-2) {
        cout << "bus topology\n";
    } else {
        cout << "unknown topology\n";
    }
    return 0;
}
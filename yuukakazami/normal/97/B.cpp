/*
 * B. Superset.cpp
 *
 *  Created on: 2011-7-16
 *      Author: mac
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<climits>
#include<string>
#include<algorithm>
#include <utility>
#include <set>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;
typedef pair<int, int> ipair;
set<ipair> Set;
vector<ipair> ps;

void build(int l, int r) {
    if (l + 1 < r) {
        int m = (l + r) >> 1;
        for (int i = l; i < r; ++i) {
            Set.insert(make_pair(ps[m].first, ps[i].second));
        }
        build(l, m);
        build(m, r);
    }
}

int main() {
    int n;
    cin >> n;
    ps.resize(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        ps[i] = make_pair(x, y);
        Set.insert(ps[i]);
    }
    sort(ps.begin(), ps.end());
    build(0, ps.size());
    cout << Set.size() << endl;
    foreach(e,Set)
        printf("%d %d\n", e->first, e->second);
}
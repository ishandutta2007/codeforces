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
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<ll, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

const ll M = 1e9 + 5;

int main() {
    ll n, k, h;
    cin >> n >> k >> h;
    vi m(n), v(n);
    vii lem(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &m[i]);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        lem[i] = pii(M * m[i] + v[i], i);
//        cerr << M * m[i] - v[i] << endl;
    }
    sort(lem.begin(), lem.end());
//    for (int i = 0; i < n; ++i)
//        cerr << lem[i].first << " " << lem[i].second << endl;
    double l = 0, r = k * (double)h + 1;
    double curt = r;
    vi best(k);
    vi newbest(k);
    for (int i = 0; i < 100; ++i) {
        double t = (r + l) / 2;
//        cerr << t << endl;
        int cnt = 0, it = 0;
        while (it < n && cnt < k) {
            while (it < n && t * v[lem[it].second] < (cnt + 1) * h)
                ++it;
            if (it < n) {
                newbest[cnt] = lem[it].second;
                ++it;
                ++cnt;
            }
        }
        if (cnt == k) {
            r = t;
            best.swap(newbest);
//            for (int i = 0; i < k; ++i)
//                cerr << best[i] << " ";
//            cerr << endl;
        } else l = t;
    }
    for (int i = 0; i < best.size(); ++i) {
        if (i)
            printf(" ");
        printf("%d", best[i] + 1);
    }
    printf("\n");
    return 0;
}
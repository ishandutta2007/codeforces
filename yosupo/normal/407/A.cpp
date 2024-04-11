#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const int N = 1010;
int main() {
    int a, b;
    cin >> a >> b;
    vector<P> av, bv;
    for (int i = 1; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (i*i+j*j == a*a) {
                av.push_back(P(i, j));
                av.push_back(P(j, i));
            }
        }
    }
    for (int i = 1; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (i*i+j*j == b*b) {
                bv.push_back(P(i, -j));
                bv.push_back(P(j, -i));
            }
        }
    }
    bool f = false;
    P aa, bb;
    for (P p1: av) {
        for (P p2 : bv) {
            if (p1.first != p2.first) {
                if (p1.first*p2.first + p1.second*p2.second == 0) {
                    f = true;
                    aa = p1; bb = p2;
                    break;
                }
            }
        }
        if (f) break;
    }
    if (!f) {
        printf("NO\n");
    } else {
        printf("YES\n");
        printf("0 0\n");
        printf("%d %d\n", aa.first, aa.second);
        printf("%d %d\n", bb.first, bb.second);
    }
    return 0;
}
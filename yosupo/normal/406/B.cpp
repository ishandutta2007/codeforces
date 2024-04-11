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
const int S = 1000000;
bool u[S] = {};
vector<int> v;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int d;
        scanf("%d", &d);
        u[d-1] = true;
    }
    int c = 0;
    for (int i = 0; i < S/2; i++) {
        if (u[i] && u[S-i-1]) {
            c++;
        } else if (u[i]) {
            v.push_back(S-i-1);
        } else if (u[S-i-1]) {
            v.push_back(i);
        }
    }
    for (int i = 0; i < S/2; i++) {
        if (c && !u[i] && !u[S-i-1]) {
            v.push_back(i);
            v.push_back(S-i-1);
            c--;
        }
    }
    printf("%ld\n", v.size());
    for (int i = 0; i < v.size(); i++) {
        printf("%d", v[i]+1);
        if (i == v.size()-1) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
    return 0;
}
//#define NDEBUG

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <cassert>
#include <numeric>

using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> P;
const int MN = 30300;
int a[MN];
int main() {
    int n, t;
    scanf("%d %d", &n, &t); t--;
    if (t == n-1) {
        printf("YES\n");
        return 0;
    }
    for (int i = 0; i < n-1; i++) {
        scanf("%d", a+i);
    }
    int p = 0;
    bool res = false;
    while (p < n-1) {
        if (p == t) {
            res = true;
            break;
        }
        p += a[p];
    }
    if (res) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<P, int> Q;

int main(int argc, char *argv[]) {
    int n, m;
    cin >> n >> m;
    bool usedx[1001] = {}, usedy[1001] = {};
    usedx[0] = usedx[n-1] = true;
    usedy[0] = usedy[n-1] = true;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        usedx[x-1] = true;
        usedy[y-1] = true;
    }
    if (n % 2 && !usedx[n/2] && !usedy[n/2]) {
        usedx[n/2] = true;
    }
    printf("%ld\n", count(usedx, usedx+n, false) + count(usedy, usedy+n, false));
    return 0;
}
// CUT end
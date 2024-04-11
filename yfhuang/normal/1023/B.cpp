#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

typedef long long LL;

LL n, k;

int main(){
    cin >> n >> k;
    LL l = max(1LL, k - n);
    LL r = (k - 1) / 2;
    LL ans = max(0LL, r - l + 1);
    cout << ans << endl;
    return 0;
}
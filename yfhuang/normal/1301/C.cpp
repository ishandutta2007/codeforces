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

int t;
typedef long long LL;

LL n, m;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        LL l = n - m;
        LL l1 = l / (m + 1);
        LL l2 = l % (m + 1);
        LL l3 = (m + 1) - l2;
        LL l4 = l1 + 1;
        cout << n * (n + 1) / 2 - l2 * (l4 + 1) * l4 / 2 - l3 * (l1 + 1) * l1 / 2 << endl;
    }
    return 0;
}
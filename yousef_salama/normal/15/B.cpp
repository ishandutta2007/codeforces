#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
using namespace std;
int t, X1, Y1, X2, Y2;
long long n, m;
int main(){
    cin >> t;
    while(t--){
        cin >> n >> m >> X1 >> Y1 >> X2 >> Y2;

        long long d1 = n - abs(X1 - X2), d2 = m - abs(Y1 - Y2);
        long long ans = n * m - 2 * d1 * d2 + max(2 * d1 - n, 0LL) * max(2 * d2 - m, 0LL);
        cout << ans << endl;
    }
    return 0;
}
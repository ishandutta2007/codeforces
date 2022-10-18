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
#include <string.h>
#define MOD 100000000
using namespace std;
int n1, n2, k1, k2, d[105][105][15][15];
int solve(int rem1, int rem2, int cur1, int cur2){
    if(rem1 < 0 || rem2 < 0 || cur1 > k1 || cur2 > k2)return 0;
    if(rem1 + rem2 == 0)return 1;
    if(d[rem1][rem2][cur1][cur2] != -1)return d[rem1][rem2][cur1][cur2];
    return d[rem1][rem2][cur1][cur2] = (solve(rem1 - 1, rem2, cur1 + 1, 0) +
            solve(rem1, rem2 - 1, 0, cur2 + 1)) % MOD;
}
int main(){
    cin >> n1 >> n2 >> k1 >> k2;
    memset(d, -1, sizeof d);
    cout << solve(n1, n2, 0, 0) << endl;
    return 0;
}
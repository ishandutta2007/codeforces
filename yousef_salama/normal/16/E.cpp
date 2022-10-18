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
int n;
double p[18][18], dp[1 << 18], pre[1 << 18][18];
double Solve(int lake, int cur, int cnt){
    if(cnt == 1)return 1;
    if(dp[lake] == dp[lake])return dp[lake];
    double ans = 0;
    for(int die = 0; die < n; die++)if(!(lake & (1 << die)) && die != cur)
        ans += pre[lake][die] * Solve(lake | 1 << die, cur, cnt - 1);
    return dp[lake] = ans / (cnt * (cnt - 1) / 2);
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> p[i][j];
    for(int lake = 0; lake < 1 << n; lake++)
        for(int i = 0; i < n; i++)if(!(lake & (1 << i)))
            for(int j = 0; j < n; j++)if(i != j && !(lake & (1 << j)))
                pre[lake][i] += p[j][i];
    for(int i = 0; i < n; i++){
        memset(dp, -1, sizeof dp);
        printf("%.6f ", Solve(0, i, n));
    }
    cout << endl;
    return 0;
}
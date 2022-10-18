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
#define MOD 1000000007
using namespace std;
int dp[5005][5005];
string s, t;
int main(){
    cin >> s >> t;
    for(int i = 1; i <= s.size(); i++)
    for(int j = 1; j <= t.size(); j++)
        dp[i][j] = ((s[i - 1] == t[j - 1]?dp[i - 1][j - 1] + 1:0) + dp[i][j - 1]) % MOD;
    long long ans = 0;
    for(int i = 1; i <= s.size(); i++)
        ans = (ans + dp[i][t.size()]) % MOD;
    cout << ans << endl;
    return 0;
}
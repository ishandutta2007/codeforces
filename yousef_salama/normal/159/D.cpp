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
string s;
int N, dp[2005];
bool isPal[2005][2005];
int main(){
    cin >> s;
    N = s.size();
    for(int len = 0; len <= N; len++)
    for(int L = 0; L + len <= N; L++){
        int R = len + L - 1;
        if(len == 0 || len == 1){
            if(R >= 0)isPal[L][R] = 1;
        }else isPal[L][R] = isPal[L + 1][R - 1] && (s[L] == s[R]);
    }
    dp[0] = 0;
    for(int len = 1; len <= N; len++){
        dp[len] = dp[len - 1];
        for(int L = 0; L < len; L++)
            dp[len] += isPal[L][len - 1];
    }
    long long ans = 0;
    for(int L = 0; L < N; L++)
    for(int R = L; R < N; R++)
        if(isPal[L][R])ans += dp[L];
    cout << ans << endl;
    return 0;
}
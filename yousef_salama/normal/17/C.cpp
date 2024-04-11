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
#define MOD 51123987
using namespace std;
int n, dp[155][55][55][55], f[155][3];
string s, a;
int main(){
    cin >> n >> s;
    a += s[0];
    for(int i = 1; i < s.size(); i++)
        if(s[i] != s[i - 1])a += s[i];
    n = a.size();
    for(int i = 0; i < n; i++){
        f[i][0] = f[i][1] = f[i][2] = s.size();
        for(int j = i; j < n; j++){
            f[i][a[j] - 'a'] = min(f[i][a[j] - 'a'], j);
        }
    }
    for(int a = 0; a <= (s.size() + 5) / 3; a++)
    for(int b = 0; b <= (s.size() + 5) / 3; b++)
    for(int c = 0; c <= (s.size() + 5) / 3; c++)
        if(abs(a - b) <= 1 && abs(b - c) <= 1 && abs(c - a) <= 1 && a + b + c == s.size())
            dp[n][a][b][c] = 1;

    for(int i = n - 1; i >= 0; i--)
    for(int a = (s.size() + 5) / 3; a >= 0; a--)
    for(int b = (s.size() + 5) / 3; b >= 0; b--)
    for(int c = (s.size() + 5) / 3; c >= 0; c--){
        dp[i][a][b][c] = dp[n][a][b][c];
        if(f[i][0] < n)dp[i][a][b][c] += dp[f[i][0]][a + 1][b][c];
        dp[i][a][b][c] %= MOD;
        if(f[i][1] < n)dp[i][a][b][c] += dp[f[i][1]][a][b + 1][c];
        dp[i][a][b][c] %= MOD;
        if(f[i][2] < n)dp[i][a][b][c] += dp[f[i][2]][a][b][c + 1];
        dp[i][a][b][c] %= MOD;
    }
    cout << dp[0][0][0][0] << endl;
    return 0;
}
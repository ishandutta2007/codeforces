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
string s, a;
int N, k, dp[100005][30];
int g[30];
int go(int i, int prev){
    if(i == N)return 0;
    if(dp[i][prev] != -1)return dp[i][prev];
    int cost = 100000000;
    if(g[prev] != s[i] - 'a')
        cost = min(cost, go(i + 1, s[i] - 'a'));
    cost = min(cost, go(i + 1, prev) + 1);
    return dp[i][prev] = cost;
}
int main(){
    cin >> s;
    N = s.size();
    cin >> k;
    memset(g, -1, sizeof g);
    g[26] = 26;
    while(k--){
        cin >> a;
        g[a[0] - 'a'] = a[1] - 'a';
        g[a[1] - 'a'] = a[0] - 'a';
    }
    memset(dp, -1, sizeof dp);
    cout << go(0, 26) << endl;
    return 0;
}
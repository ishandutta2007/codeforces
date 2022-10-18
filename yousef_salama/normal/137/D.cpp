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
//char s[505];
string s;
int K, pal[505][505], N, dp[505][505];
string Pal(string a){
    for(int i = 0; i < a.size() / 2; i++)
        a[i] = a[a.size() - i - 1];
    return a;
}
void PrintPath(int idx, int rem){
    if(idx == N)return;
    if(dp[idx][rem] == pal[idx][N - 1]){
        cout << Pal(s.substr(idx));
        return;
    }
    for(int cut = 1; idx + cut < N; cut++){
        if(dp[idx][rem] == pal[idx][idx + cut - 1] + dp[idx + cut][rem - 1]){
            cout << Pal(s.substr(idx, cut)) << '+';
            PrintPath(idx + cut, rem - 1);
            return;
        }
    }
}
int main(){
//    scanf("%s", &s);
//    scanf("%d", &K);
//    N = strlen(s);
    cin >> s;
    cin >> K;
    N = s.size();
    for(int len = 0; len <= N; len++)
    for(int L = 0; L + len <= N; L++){
        int R = L + len - 1;
        if(len == 1 || len == 0)pal[L][R] = 0;
        else pal[L][R] = pal[L + 1][R - 1] + (s[L] != s[R]);
    }
    memset(dp, 63, sizeof dp);
    for(int i = 0; i <= K; i++)
        dp[N][i] = 0;
    for(int idx = N - 1; idx >= 0; idx--)
    for(int rem = 0; rem <= K; rem++){
        dp[idx][rem] = pal[idx][N - 1];
        for(int cut = 1; cut + idx < N; cut++)
            if(rem > 0)dp[idx][rem] = min(dp[idx][rem], pal[idx][idx + cut - 1] + dp[idx + cut][rem - 1]);
    }
    printf("%d\n", dp[0][K - 1]);
    PrintPath(0, K - 1);
    cout << endl;
    return 0;
}
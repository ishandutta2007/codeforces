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

const int maxn = 205;

int dp[maxn][maxn][maxn * 2];

char s[maxn], t[maxn];

pair<pair<int, int>, pair<int, char> > pre[maxn][maxn][maxn * 2];

const int INF = 0x3f3f3f3f;

int main(){
    scanf("%s", s);
    scanf("%s", t);
    int n = strlen(s);
    int m = strlen(t);
    memset(dp, INF, sizeof(dp));
    dp[0][0][0] = 0;
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= m;j++){
            for(int open = 0;open <= n + m;open++){
                if(dp[i][j][open] == INF)
                    continue;
                int nxti = i + (s[i] == '(');
                int nxtj = j + (t[j] == '(');
                if(open < n + m and dp[nxti][nxtj][open + 1] > dp[i][j][open] + 1){
                    dp[nxti][nxtj][open + 1] = dp[i][j][open] + 1;
                    pre[nxti][nxtj][open + 1] = make_pair(make_pair(i, j), make_pair(open, '('));
                }
                nxti = i + (s[i] == ')');
                nxtj = j + (t[j] == ')');
                if(open > 0 and dp[nxti][nxtj][open - 1] > dp[i][j][open] + 1){
                    dp[nxti][nxtj][open - 1] = dp[i][j][open] + 1;
                    pre[nxti][nxtj][open - 1] = make_pair(make_pair(i, j), make_pair(open, ')'));
                }
            }
        }
    }
    int ans = INF, ansi, ansj, ansopen;
    for(int open = 0;open <= n + m;open++){
        if(open + dp[n][m][open] < ans){
            ans = open + dp[n][m][open];
            ansopen = open;
        }
    }
    string S = string(ansopen, ')');
    ansi = n, ansj = m;
    while(ansi or ansj or ansopen){
        pair<pair<int,int>, pair<int, char> > p = pre[ansi][ansj][ansopen];
        S += p.second.second;
        ansi = p.first.first;
        ansj = p.first.second;
        ansopen = p.second.first;
    }
    reverse(S.begin(), S.end());
    cout << S << endl;
    return 0;
}
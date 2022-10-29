#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> piii;
const int MAX_N = 1e3 + 6;
const int INF = 1e9 +7;

char mp[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >>k;
    for (int i=1;n>=i;i++) {
        string s;
        cin >> s;
        s=" "+s;
        for (int j=1;m>=j;j++) {
            mp[i][j] = (s[j]=='.');
        }
    }
    for (int i=0;MAX_N>i;i++) {
        for (int j=0;MAX_N>j;j++) {
            dp[i][j] = INF;
        }
    }
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >>x2 >> y2;
    dp[x1][y1] = 0;
    #define F first
    #define S second
    priority_queue<piii,vector<piii>,greater<piii> > pq;
    pq.push({0,{x1,y1}});
    while (!pq.empty()) {
        piii p=pq.top();
        pq.pop();
        if (p.F != dp[p.S.F][p.S.S]) continue;
        int x=p.S.F,y=p.S.S;
        int dx[4] ={1,0,-1,0},dy[4]={0,1,0,-1};
        for (int i=0;4>i;i++) {
            for (int j=1;k>=j;j++) {
                int tx=x+dx[i]*j,ty=y+dy[i]*j;
                if (!mp[tx][ty]) break;
                if (dp[tx][ty] <= dp[x][y]) break;
                if (dp[tx][ty] > dp[x][y] + 1) {
                    dp[tx][ty] = dp[x][y] + 1;
                    pq.push({dp[tx][ty],{tx,ty} });
                }
            }
        }
    }
    if (dp[x2][y2] == INF) cout<<-1<<endl;
    else cout<<dp[x2][y2]<<endl;
}
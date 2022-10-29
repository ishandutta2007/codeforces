#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAX_N = 5006;
const LL INF = 1e15 + 6;

LL x[MAX_N],d[MAX_N];
vector<int> edg[MAX_N];

LL n,b;
LL dp[2][MAX_N][MAX_N];   //cost of taking subtree i and j items
LL dp_tmp[2][MAX_N];
int sz[MAX_N];

void dfs(int id) {
    dp[0][id][0] = 0;
    dp[1][id][0] = 0;
    dp[0][id][1] = x[id];
    dp[1][id][1] = x[id]-d[id];
    sz[id]=1;
    for (int i:edg[id]) dfs(i);
    sort(edg[id].begin(),edg[id].end(),[&](const int &a,const int &b) {
         return sz[a] > sz[b];
    });
    for (int i:edg[id]) {
        //deal with dp[0] first
        sz[id] += sz[i];
        for (int ii=0;sz[id]>=ii;ii++) {
            dp_tmp[0][ii] = dp[0][id][ii];
            dp_tmp[1][ii] = dp[1][id][ii];
        }
        for (int a=1;sz[i]>=a;a++) {
            for (int b=a;sz[id]>=b;b++) {
                if (dp[0][id][b-a] == -1) break;
                else if (dp_tmp[0][b] == -1) dp_tmp[0][b] = dp[0][id][b-a] + dp[0][i][a];
                else if (dp[0][id][b-a] == -1) continue;
                else dp_tmp[0][b] = min(dp_tmp[0][b],dp[0][id][b-a] + dp[0][i][a]);
                //cout<<"i = "<<i<<" , id = "<<id<<" , a = "<<a<<" , b = "<<b<<" , val = "<<dp_tmp[0][b]<<", first = "<<dp[0][id][b-a]<<" , second = "<<dp[0][i][a]<<endl;
            }
        }
        //deal with 1 then
        for (int a=1;sz[i]>=a;a++) {
            LL val=min(dp[0][i][a],dp[1][i][a]);
            for (int b=a+1;sz[id]>=b;b++) {
                if (dp[1][id][b-a] == -1) break;
                else if (dp_tmp[1][b] == -1) dp_tmp[1][b] = dp[1][id][b-a] + val;
                else dp_tmp[1][b] = min(dp_tmp[1][b],dp[1][id][b-a] + val);
            }
        }
        for (int ii=0;sz[id]>=ii;ii++) {
            dp[0][id][ii] = dp_tmp[0][ii];
            dp[1][id][ii] = dp_tmp[1][ii];
        }
    }
}

int main () {
    scanf("%lld %lld",&n,&b);
    for (int i=1;n>=i;i++) {
        scanf("%lld %lld",&x[i],&d[i]);
        if (i>1) {
            int c;
            scanf("%d",&c);
            edg[c].push_back(i);
        }
    }
    memset(dp,-1,sizeof(dp));
    dfs(1);
    int ans=0;
    for (int i=1;n>=i;i++) {
        if (min(dp[0][1][i],dp[1][1][i]) <= b) ans=i;
    }
    /*for (int i=0;2>i;i++) {
        cout<<"i = "<<i<<endl;
        for (int j=1;n>=j;j++) {
            for (int k=0;n>=k;k++) {
                cout<<dp[i][j][k]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
    }*/
    printf("%d\n",ans);
}
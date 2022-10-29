#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 2e5 + 6;

vector<int> edg[MAX_N];
int depth[MAX_N];
int dp[MAX_N];
int p[MAX_N];
bool visit[MAX_N];

int dfs(int id,int _depth,int parent) {
    visit[id] = 1;
    depth[id] = _depth;
    p[id] =parent;
    dp[id] = _depth;
    for(int i:edg[id]) {
        if (!visit[i]) {
            dp[id] = max(dp[id],dfs(i,_depth+1,id));
        }
    }
    return dp[id];
}

int main (){
    int n,x;
    scanf("%d %d",&n,&x);
    for (int i=1;n>i;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    dfs(1,1,0);
    int can_up = (depth[x] - depth[1] - 1)/2;
    int ans=2*can_up;
    while (can_up--) {
        x = p[x];
    }
    printf("%d\n",2*dp[x]-2);
}
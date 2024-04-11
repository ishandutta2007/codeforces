//
//  main.cpp
//  D
//
//  Created by  on 15/11/14.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1000+5;
int n,m,k;
int cnt;

char maze[maxn][maxn];
bool vis[maxn][maxn];
int num[maxn][maxn];
int ans[1010101];

int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};

int dfs(int x,int y,int cntr){
    if(vis[x][y]) return 0;
    if(maze[x][y]=='*') return 1;
    vis[x][y]=true;
    num[x][y]=cntr;
    int res=dfs(x+1,y,cntr)+dfs(x-1,y,cntr)+dfs(x,y+1,cntr)+dfs(x,y-1,cntr);
    return res;
}

int main(int argc, const char * argv[]) {
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        scanf("%s",maze[i]);
    }
    int cnt=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j]=='.'){
                int temp=dfs(i,j,cnt);
                if(temp){
                    ans[cnt]=temp;
                    cnt++;
                }
            }
        }
    }
    for(int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        cout<<ans[num[x-1][y-1]]<<endl;
    }
    return 0;
}
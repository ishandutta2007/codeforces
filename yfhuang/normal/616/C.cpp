//
//  main.cpp
//  C
//
//  Created by  on 16/1/12.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int comp;
int cnt;
int n,m;

const int maxn=1005;

int c[maxn][maxn];
int SZ[maxn*maxn];
char str[maxn];

int used[maxn][maxn];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

bool valid(int i,int j){
    return (i>=1 && i<=n && j<=m && j>=1 && c[i][j]==0);
}

void dfs(int x,int y){
    used[x][y]=comp;
    cnt++;
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(valid(nx,ny) && used[nx][ny]==0){
            dfs(nx,ny);
        }
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&m);
    memset(used,0,sizeof(0));
    for(int i = 1;i <= n; i++){
        scanf("%s",str+1);
        for(int j = 1;j <= m;j++){
            if(str[j]=='.') c[i][j] = 0;
            else c[i][j] = 1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(c[i][j]==1)
                continue;
            if(used[i][j])
                continue;
            ++comp;
            cnt=0;
            dfs(i,j);
            SZ[comp]=cnt;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(c[i][j]==0) printf(".");
            else{
                vector<int> v;
                for(int k=0;k<4;k++){
                    int nx=i+dx[k],ny=j+dy[k];
                    if(valid(nx,ny)){
                        v.push_back(used[nx][ny]);
                    }
                }
                sort(v.begin(),v.end());
                int ans=1;
                for(int q=0;q<v.size();q++){
                    if(q==0||v[q]!=v[q-1]){
                        ans+=SZ[v[q]];
                    }
                }
                printf("%d",ans%10);
            }
        }
        printf("\n");
    }
    return 0;
}
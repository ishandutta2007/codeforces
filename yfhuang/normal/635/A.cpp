//
//  main.cpp
//  a
//
//  Created by  on 16/2/29.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int R=12;

int grid[R][R];
int a[R][R];

int r,c,n,m;

int main(int argc, const char * argv[]) {
    scanf("%d%d%d%d",&r,&c,&n,&m);
    memset(grid,0,sizeof(grid));
    int x,y;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        grid[x][y]=1;
    }
    memset(a,0,sizeof(a));
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            a[i][j]=a[i][j-1]+a[i-1][j]-a[i-1][j-1]+grid[i][j];
        }
    }
    long long ans=0;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            for(int k=i;k<=r;k++){
                for(int l=j;l<=c;l++){
                    if(a[k][l]-a[i-1][l]-a[k][j-1]+a[i-1][j-1]>=m) ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
//
//  main.cpp
//  A
//
//  Created by  on 16/2/21.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    char grid[105][105];
    for(int i=1;i<=n;i++){
        scanf("%s",grid[i]+1);
    }
    int row[105],col[105];
    memset(row,0,sizeof(row));
    memset(col,0,sizeof(col));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(grid[i][j]=='C')
                row[i]++;
            if(grid[j][i]=='C')
                col[i]++;
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans+=row[i]*(row[i]-1)/2;
        ans+=col[i]*(col[i]-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}
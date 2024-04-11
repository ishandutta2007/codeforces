//
//  main.cpp
//  D(easy)
//
//  Created by  on 16/7/10.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 105;

int r,c;

char grid[maxn][maxn];

bool vis[maxn];

int d[maxn];

int main(int argc, const char * argv[]) {
    cin >> r >> c;
    for(int i = 1;i <= r;i++){
        scanf("%s",grid[i] + 1);
    }
    memset(vis,false,sizeof(vis));
    for(int i = 1;i <= r;i++){
        for(int j = 1;j <= c;j++){
            if(grid[i][j] == 'B'){
                vis[j] = true;
            }
        }
    }
    d[0] = 0;
    for(int i = 1;i <= c;i++){
        if(vis[i]){
            if(vis[i - 1]) d[i] = d[i - 1];
            else d[i] = d[i - 1] + 1;
        }else{
            d[i] = d[i - 1];
        }
    }
    cout << d[c] << endl;
    return 0;
}
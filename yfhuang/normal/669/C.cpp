//
//  main.cpp
//  C
//
//  Created by  on 16/4/25.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 105;
const int INF = 0x3f3f3f3f;

int maze[maxn][maxn];
int maze1[maxn][maxn];

int n,m,q;

struct opt{
    int type;
    int x;
    int y;
    int r;
}op[10005];

int main(int argc, const char * argv[]) {
    cin >> n >> m >> q;
    memset(maze,INF,sizeof(maze));
    for(int i = 1;i <= q;i++){
        int t;
        scanf("%d",&t);
        op[i].type = t;
        if(t == 1 || t == 2){
            scanf("%d",&op[i].x);
        }else{
            scanf("%d%d%d",&op[i].x,&op[i].y,&op[i].r);
        }
    }
    for(int i = q;i >= 1;i--){
        //cout << op[i].x<< endl;
        if(op[i].type == 1){
            int t = maze[op[i].x][m];
            for(int j = 2;j <= m;j++){
                maze1[op[i].x][j] = maze[op[i].x][j - 1];
                //cout << maze[op[i].x][j] << ' ' << maze[op[i].x][j - 1] << endl;
            }
            maze1[op[i].x][1] = t;
            for(int j = 1;j <= m;j++)
                maze[op[i].x][j] = maze1[op[i].x][j];
        }else if(op[i].type == 2){
            int t = maze[n][op[i].x];
            for(int j = 2;j <= n;j++){
                maze1[j][op[i].x] = maze[j - 1][op[i].x];
            }
            maze1[1][op[i].x] = t;
            for(int j = 1;j <= n;j++)
                maze[j][op[i].x] = maze1[j][op[i].x];
        }else{
            maze[op[i].x][op[i].y] = op[i].r;
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(maze[i][j] == INF) maze[i][j] = 0;
            printf("%d%c",maze[i][j],j == m ? '\n' :' ');
        }
    }
    
    return 0;
}
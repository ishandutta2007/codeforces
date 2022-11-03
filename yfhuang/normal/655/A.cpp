//
//  main.cpp
//  A
//
//  Created by  on 16/3/19.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char grid1[5][5];
char grid2[5][5];

int main(int argc, const char * argv[]) {
    for(int i=0;i<2;i++)
        scanf("%s",grid1[i]);
    for(int i=0;i<2;i++)
        scanf("%s",grid2[i]);
    int x,y;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(grid1[i][j]=='X'){
                x=i,y=j;
            }
        }
    }
    if(x==1&&y==0){
        grid1[1][0]=grid1[0][0];
        grid1[0][0]='X';
    }else if(x==0&&y==1){
        grid1[0][1]=grid1[0][0];
        grid1[0][0]='X';
    }else if(x==1&&y==1){
        grid1[1][1]=grid1[0][1];
        grid1[0][1]=grid1[0][0];
        grid1[0][0]='X';
    }
    
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(grid2[i][j]=='X'){
                x=i,y=j;
            }
        }
    }
    if(x==1&&y==0){
        grid2[1][0]=grid2[0][0];
        grid2[0][0]='X';
    }else if(x==0&&y==1){
        grid2[0][1]=grid2[0][0];
        grid2[0][0]='X';
    }else if(x==1&&y==1){
        grid2[1][1]=grid2[0][1];
        grid2[0][1]=grid2[0][0];
        grid2[0][0]='X';
    }
    //for(int i=0;i<2;i++){
    //    printf("%s\n",grid1[i]);
    //}
    //for(int i=0;i<2;i++){
    //    printf("%s\n",grid2[i]);
    //}
    bool flag=false;
    if(grid1[1][0]==grid2[1][0]&&grid1[0][1]==grid2[0][1]) flag=true;
    if(grid1[1][0]==grid2[1][1]&&grid1[0][1]==grid2[1][0]) flag=true;
    if(grid2[1][0]==grid1[1][1]&&grid2[0][1]==grid1[1][0]) flag=true;
    if(flag) puts("YES");
    else puts("NO");
    return 0;
}
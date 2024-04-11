//
//  main.cpp
//  B
//
//  Created by  on 16/2/14.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

bool dp[201][201][201];

int main(int argc, const char * argv[]) {
    char str[205];
    int n;
    scanf("%d",&n);
    scanf("%s",str+1);
    int x=0,y=0,z=0;
    for(int i=1;i<=n;i++){
        if(str[i]=='R') x++;
        else if(str[i]=='B') y++;
        else if(str[i]=='G') z++;
    }
    if(x>=1&&y>=1&&z>=1) {printf("BGR\n");return 0;}
    if(x==0&&y==0) {printf("G\n");return 0;}
    if(x==0&&z==0) {printf("B\n");return 0;}
    if(y==0&&z==0) {printf("R\n");return 0;}
    if(x==0){
        if(y==1&&z==1) {printf("R\n");}
        else if(y>1&&z==1) {printf("GR\n");}
        else if(z>1&&y==1) {printf("BR\n");}
        else{
            printf("BGR\n");
        }
    }else if(y==0){
        if(x==1&&z==1) printf("B\n");
        else if(x>1&&z==1) printf("BG\n");
        else if(x==1&&z>1) printf("BR\n");
        else printf("BGR\n");
    }else if(z==0){
        if(x==1&&y==1) printf("G\n");
        else if(x>1&&y==1) printf("BG\n");
        else if(x==1&&y>1) printf("GR\n");
        else printf("BGR\n");
    }
    return 0;
}
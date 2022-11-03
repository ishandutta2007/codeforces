//
//  main.cpp
//  C
//
//  Created by  on 16/3/29.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 100000 + 5;

int n, d, h;

int main(int argc, const char * argv[]) {
    scanf("%d%d%d",&n,&d,&h);
    if(d > 2 * h || d < h  || d >= n){
        puts("-1");
    }else if(d == h){
        if(d == 1 && n > 2){puts("-1\n"); return 0;}
        for(int i = 1; i <= h; i++){
            printf("%d %d\n",i,i+1);
        }
        for(int i = 0; i < n - 1 - d; i++){
            printf("2 %d\n",n - i);
        }
    }else{
        int h1 = d - h;
        for(int i = 1; i <= h; i++){
            printf("%d %d\n",i,i+1);
        }
        if(h1){
            printf("1 %d\n",h + 2);
            for(int i = 1; i < h1; i++){
                printf("%d %d\n",h + i + 1, h + i +2);
            }
        }
        if(n - 1 - d){
            for(int i = 0; i < n - 1 - d; i++){
                printf("1 %d\n",n - i);
            }
        }
    }
    return 0;
}
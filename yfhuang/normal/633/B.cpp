//
//  main.cpp
//  B
//
//  Created by  on 16/2/27.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int cnt=0,m;
    scanf("%d",&m);
    int i;
    for( i=5;cnt<m;i+=5){
        int cnt1=0;
        int c=i;
        while(c%5==0){
            cnt1++;
            c/=5;
        }
        cnt+=cnt1;
    }
    if(cnt==m){
        i-=5;
        printf("5\n");
        for(int j=i;j<i+5;j++){
            printf("%d%c",j,j==i+4?'\n':' ');
        }
    }else{
        printf("0\n");
    }
    return 0;
}
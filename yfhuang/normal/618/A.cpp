//
//  main.cpp
//  A
//
//  Created by  on 16/1/30.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    int cnt=1;
    int i;
    for( i=1;i<=n;i*=2,cnt++);
        while(n>0&&i>=1){
            if(n>=i){
            n-=i;
                printf("%d ",cnt);
                }
            cnt--;
            i/=2;
        }
    return 0;
}
//
//  main.cpp
//  B
//
//  Created by  on 15/11/1.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    long long n;
    long long ans;
    while(scanf("%I64d",&n)==1){
        ans=(n-2)*(n-2);
        printf("%I64d\n",ans);
    }
    return 0;
}
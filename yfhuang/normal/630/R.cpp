//
//  main.cpp
//  18
//
//  Created by  on 16/2/18.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, const char * argv[]) {
    long long n;
    scanf("%I64d",&n);
    if(n&1) printf("1\n");
    else printf("2\n");
    return 0;
}
//
//  main.cpp
//  A
//
//  Created by  on 15/12/27.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    if(n&1) printf("0\n");
    else{
    n/=2;
        printf("%d\n",(n-1)/2);}
    return 0;
}
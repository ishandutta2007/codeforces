//
//  main.cpp
//  B
//
//  Created by  on 16/3/26.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int h1,h2,a,b;

int main(int argc, const char * argv[]) {
    cin>>h1>>h2>>a>>b;
    h2-=h1+8*a;
    a=12*(a-b);
    if(h2<=0) printf("0\n");
    else{
        if(a<=0) printf("-1\n");
        else printf("%d\n",(h2+a-1)/a);
    }
    return 0;
}
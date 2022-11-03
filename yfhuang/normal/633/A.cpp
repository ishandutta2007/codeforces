//
//  main.cpp
//  A
//
//  Created by  on 16/2/27.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    bool flag=false;
    for(int i=0;i*a<=c;i++){
        if((c-i*a)%b==0) flag=true;
    }
    if(flag) puts("Yes");
    else puts("No");
    return 0;
}
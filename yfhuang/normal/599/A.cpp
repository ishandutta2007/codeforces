//
//  main.cpp
//  A
//
//  Created by  on 15/11/21.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(int argc, const char * argv[]) {
    int d1,d2,d3;
    while(scanf("%d%d%d",&d1,&d2,&d3)==3){
        int ans=min(d1*2+d2*2,d1+d2+d3);
        ans=min(ans,2*d1+2*d3);
        ans=min(ans,2*d2+2*d3);
        printf("%d\n",ans);
    }
    return 0;
}
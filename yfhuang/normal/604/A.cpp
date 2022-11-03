//
//  main.cpp
//  A
//
//  Created by  on 15/12/1.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int a[6]={0,500,1000,1500,2000,2500};
    int x[6];
    int w[6];
    for(int i=1;i<=5;i++){
        scanf("%d",&x[i]);
    }
    for(int i=1;i<=5;i++){
        scanf("%d",&w[i]);
    }
    int point;
    int sh,fh;
    int ans=0;
    scanf("%d%d",&sh,&fh);
    ans+=100*sh-50*fh;
    for(int i=1;i<=5;i++){
        point=max(3*a[i]/10,a[i]-a[i]/250*x[i]-50*w[i]);
        ans+=point;
    }
    printf("%d\n",ans);
    return 0;
}
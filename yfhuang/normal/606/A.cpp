//
//  main.cpp
//  A
//
//  Created by  on 15/12/10.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a,b,c,x,y,z;

int main(int argc, const char * argv[]) {
    scanf("%d%d%d",&a,&b,&c);
    scanf("%d%d%d",&x,&y,&z);
    //printf("%d%d%d",a,b,c);
    //printf("%d%d%d",x,y,z);
    int d[3];
    memset(d,0,sizeof(d));
    d[0]=a-x;
    d[1]=b-y;
    d[2]=c-z;
    int sum=0;
    for(int i=0;i<3;i++){
        if(d[i]>0) sum+=d[i]/2;
        else  sum+=d[i];
    }
    if(sum<0) printf("No\n");
    else printf("Yes\n");
    return 0;
}
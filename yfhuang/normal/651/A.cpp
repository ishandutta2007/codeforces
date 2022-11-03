//
//  main.cpp
//  A
//
//  Created by  on 16/3/7.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int a,b;

int main(int argc, const char * argv[]) {
    scanf("%d%d",&a,&b);
    int i;
    for(i=1;;i++){
        if(a==0||b==0){i--;break;}
        if(a==1&&b==1){i--;break;}
        if(a<b){a+=1;b-=2;}
        else {a-=2;b+=1;}
    }
    printf("%d\n",i);
    return 0;
}
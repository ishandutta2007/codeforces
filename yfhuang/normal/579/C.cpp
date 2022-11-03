//
//  main.cpp
//  C
//
//  Created by  on 16/1/1.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

#define eps  1e-9

int a,b;

int main(int argc, const char * argv[]) {
    cin>>a>>b;
    if(a<b) {printf("-1\n");return 0;}
    int k1=(int)(((double)a)/b+1.0+eps);
    int k2=(int)(((double)a)/b-1.0+eps);
    if(k1%2==1)  k1--;
    if(k2%2==1) k2--;
    double x1=((double)(a+b)/k1);
    double x2=((double)(a-b)/k2);
    printf("%.12lf",min(x1,x2));
    return 0;
}
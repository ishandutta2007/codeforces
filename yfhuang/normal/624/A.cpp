//
//  main.cpp
//  A
//
//  Created by  on 16/2/5.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int d,L,v1,v2;
double t;

int main(int argc, const char * argv[]) {
    scanf("%d%d%d%d",&d,&L,&v1,&v2);
    t=1.0*(L-d)/(v1+v2);
    printf("%.10lf",t);
    return 0;
}
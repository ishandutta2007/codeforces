//
//  main.cpp
//  14
//
//  Created by  on 16/2/18.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    int a,b,c;
    cin>>a>>b>>c;
    double delt=sqrt(1.0*b*b-a*c*4);
    double r1=(-1.0*b+delt)/2.0/a;
    double r2=(-1.0*b-delt)/2.0/a;
    printf("%.10lf\n",max(r1,r2));
    printf("%.10lf\n",min(r1,r2));
    return 0;
}
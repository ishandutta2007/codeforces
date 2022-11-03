//
//  main.cpp
//  16
//
//  Created by  on 16/2/19.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const double pi=acos(-1.0);

int main(int argc, const char * argv[]) {
    long long n,r;
    cin>>n>>r;
    //long long k=n/2;
    double theta=pi*3/n;
    double s=pi/n*r*r-r*r*sin(pi/n)*cos(pi/n)+r*sin(pi/n)*r*sin(pi/n)/tan(theta/2);
    double ans=pi*r*r-s*n;
    printf("%.10lf\n",ans);
    return 0;
}
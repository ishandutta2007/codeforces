//
//  main.cpp
//  2
//
//  Created by  on 16/2/18.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,t;
    cin>>n>>t;
    double a=log(1.0*n)+t*log(1.000000011);
    double ans=exp(a);
    printf("%.10lf\n",ans);
    return 0;
}
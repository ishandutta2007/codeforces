//
//  main.cpp
//  17
//
//  Created by  on 16/2/19.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double pi=acos(-1);

int main(int argc, const char * argv[]) {
    int l3,l4,l5;
    cin>>l3>>l4>>l5;
    double v=0,v1,v2,v3;
    v1=sqrt(6.0)/3*l3*sqrt(3.0)/4*l3*l3/3;
    v2=1.0*l4*l4*sqrt(2.0)/2*l4/3;
    double r=1.0*l5/2.0/sin(36.0/180*pi);
    double h=sqrt(1.0*l5*l5-r*r);
    v3=h/3.0*l5/2.0*sqrt(r*r-l5*l5/4.0)*5;
    v=v1+v2+v3;
    //cout<<v1<<' '<<v2<<' '<<v3<<' '<<endl;
    printf("%.10lf\n",v);
    return 0;
}
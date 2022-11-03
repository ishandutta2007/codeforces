//
//  main.cpp
//  D
//
//  Created by  on 15/11/9.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const double PI=acos(-1);
const double EPS=1e-9;
int N;
double V,R,S,F;

int main(int argc, const char * argv[]) {
    scanf("%d%lf%lf",&N,&R,&V);
    while(N--){
        scanf("%lf%lf",&S,&F);
        double len=F-S;
        double ans=0.0;
        double remain=fmod(len,2.0*PI*R);
        ans+=len-remain;
        remain*=0.5;
        double l=0.0,r=PI;
        while(remain-(R*l+R*sin(l))>EPS*remain){
            double mid=(l+r)/2.0;
            if(R*mid+R*sin(mid)<=remain) l=mid;
            else r=mid;
        }
        ans+=2.0*(l*R);
        printf("%.9lf\n",ans/V);
    }
    return 0;
}
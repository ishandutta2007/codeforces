//
//  main.cpp
//  E
//
//  Created by  on 16/2/9.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const long double pi=acos(-1.0);
const int rms=(1<<20)-1;
const int hrms=rms/2;

struct mdf{
    long double x,y;
    long double ang;
    
    mdf(long double x_=0.0,long double y_=0.0,long double ang_=0.0):x(x_),y(y_),ang(ang_){}
};

int n,m;
int tp,x,y;

long double sqr(long double x){
    return x*x;
}

mdf operator + (const mdf& a,const mdf& b){
    return mdf(a.x+b.x*cos(a.ang)-b.y*sin(a.ang),a.y+b.y*cos(a.ang)+b.x*sin(a.ang),a.ang+b.ang);
}

mdf rmq[rms+1];

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        rmq[i+1+hrms]=mdf(1.0,0.0,0.0);
    for(int i=hrms;i>0;i--)
        rmq[i].x=rmq[i*2].x+rmq[i*2+1].x;
    
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&tp,&x,&y);
        if(tp==1){
            long double curlen=sqrt(sqr(rmq[hrms+x].x)+sqr(rmq[hrms+x].y));
            rmq[x+hrms].x*=(curlen+y)/curlen;
            rmq[x+hrms].y*=(curlen+y)/curlen;
        }else{
            long double ang=atan2(rmq[x+hrms].y,rmq[x+hrms].x);
            long double curlen=sqrt(sqr(rmq[hrms+x].x)+sqr(rmq[hrms+x].y));
            ang-=y*pi/180.0;
            rmq[hrms+x].x=curlen*cos(ang);
            rmq[hrms+x].y=curlen*sin(ang);
            rmq[hrms+x].ang-=y*pi/180.0;
        }
        int ps=x+hrms;
        while(ps>1){
            ps/=2;
            rmq[ps]=rmq[ps*2]+rmq[ps*2+1];
        }
        printf("%.10lf %.10lf\n",(double)rmq[1].x,(double)rmq[1].y);
    }
    return 0;
}
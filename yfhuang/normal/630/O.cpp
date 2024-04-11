//
//  main.cpp
//  15
//
//  Created by  on 16/2/19.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    long long px,py,vx,vy,a,b,c,d;
    cin>>px>>py>>vx>>vy>>a>>b>>c>>d;
    double len=sqrt(1.0*vx*vx+1.0*vy*vy);
    printf("%.10lf %.10lf\n",1.0*px+vx/len*b,1.0*py+vy/len*b);
    printf("%.10lf %.10lf\n",1.0*px+(-vy)/len*a/2,1.0*py+vx/len*a/2);
    printf("%.10lf %.10lf\n",1.0*px+(-vy)/len*c/2,1.0*py+vx/len*c/2);
    printf("%.10lf %.10lf\n",1.0*px+(-vy)/len*c/2.0+(-vx)/len*d,1.0*py+vx/len*c/2.0+(-vy)/len*d);
    printf("%.10lf %.10lf\n",1.0*px+(vy)/len*c/2.0+(-vx)/len*d,1.0*py+(-vx)/len*c/2.0+(-vy)/len*d);
    printf("%.10lf %.10lf\n",1.0*px+(vy)/len*c/2.0,1.0*py+(-vx)/len*c/2.0);
    printf("%.10lf %.10lf\n",1.0*px+(vy)/len*a/2.0,1.0*py+(-vx)/len*a/2.0);
    
    
    return 0;
}
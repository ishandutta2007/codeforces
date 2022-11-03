//
//  main.cpp
//  H
//
//  Created by  on 16/1/11.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

ll a,b,c,d;

bool ok(double dif){
    double ma1=-1e20,mi1=1e20;
    double ma2=-1e20,mi2=1e20;
    
    ma1=max(ma1,(a+dif)*(d+dif));
    ma1=max(ma1,(a+dif)*(d-dif));
    ma1=max(ma1,(a-dif)*(d+dif));
    ma1=max(ma1,(a-dif)*(d-dif));
    ma2=max(ma2,(b+dif)*(c+dif));
    ma2=max(ma2,(b+dif)*(c-dif));
    ma2=max(ma2,(b-dif)*(c+dif));
    ma2=max(ma2,(b-dif)*(c-dif));
    
    mi1=min(mi1,(a+dif)*(d+dif));
    mi1=min(mi1,(a+dif)*(d-dif));
    mi1=min(mi1,(a-dif)*(d+dif));
    mi1=min(mi1,(a-dif)*(d-dif));
    mi2=min(mi2,(b+dif)*(c+dif));
    mi2=min(mi2,(b+dif)*(c-dif));
    mi2=min(mi2,(b-dif)*(c+dif));
    mi2=min(mi2,(b-dif)*(c-dif));
    
    mi1=max(mi1,mi2);
    ma1=min(ma1,ma2);
    return mi1<=ma1;
}

void solve(){
    double L=0,R=1e10;
    for(int i=1;i<=1000;i++){
        double M=(L+R)/2;
        if(ok(M)) R=M;
        else L=M;
    }
    printf("%.10lf",(L+R)/2);
}

int main(int argc, const char * argv[]) {
    cin>>a>>b;
    cin>>c>>d;
    solve();
    return 0;
}
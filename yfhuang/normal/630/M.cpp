//
//  main.cpp
//  13
//
//  Created by  on 16/2/19.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    long long x;
    cin>>x;
    if(x>0) {
        x=x%360;
        if(x>180) x-=360;
    }else{
        x=-1*(abs(x)%360);
        if(x<=-180) x+=360;
    }
    long long b=0;
    long long ans=abs(x);
    for(int i=1;i<=4;i++){
        x-=90;
        if(x<=-180) x+=360;
        if(abs(x)<ans){
            ans=abs(x);
            b=i;
        }
    }
    cout<<b<<endl;
    return 0;
}
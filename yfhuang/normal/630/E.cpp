//
//  main.cpp
//  5
//
//  Created by  on 16/2/19.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    long long x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    long long ans=0;
    if((y2-y1)&1) ans=(y2-y1+1)/2*(x2-x1+1);
    else ans=(y2-y1+2)/2*(x2-x1+2)/2+(y2-y1)/2*(x2-x1)/2;
    if(ans>0) cout<<ans<<endl;
    else cout<<'0'<<endl;
    return 0;
}
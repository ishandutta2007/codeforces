//
//  main.cpp
//  9
//
//  Created by  on 16/2/19.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    long long n;
    cin>>n;
    long long ans;
    if(n==3) printf("24\n");
    
    else {
        if(n==4) ans=(3*4*2+9)*4;
        else ans=(3*pow(4,n-3)*2+9*pow(4,n-4)*(n-3))*4;
        cout<<ans<<endl;
    }
    return 0;
}
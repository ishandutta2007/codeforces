//
//  main.cpp
//  A
//
//  Created by  on 15/11/13.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    long long k,a,b;
    long long x,y;
    cin>>k>>a>>b;
    if(a%k==0) x=a/k;
    else {
        if(a>0) x=a/k+1;
        else x=a/k;
    }
    if(b%k==0) y=b/k;
    else {
        if(b>0) y=b/k;
        else y=b/k-1;
    }
    cout<<y-x+1<<endl;
    return 0;
}
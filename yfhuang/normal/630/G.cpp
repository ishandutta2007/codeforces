//
//  main.cpp
//  7
//
//  Created by  on 16/2/18.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, const char * argv[]) {
    long long n;
    cin>>n;
    long long ans=(n+4)*(n+3)/2*(n+2)/3*(n+1)/2*n/10*(n+2)/3*(n+1)/2*n;
    cout<<ans<<endl;
    return 0;
}
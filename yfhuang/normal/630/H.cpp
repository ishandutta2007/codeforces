//
//  main.cpp
//  8
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
    long long ans=(n*(n-1)/2*(n-2)/3*(n-3)/4*(n-4)/5)*(n*(n-1)/2*(n-2)/3*(n-3)/4*(n-4)/5)*120;
    cout<<ans<<endl;
    return 0;
}
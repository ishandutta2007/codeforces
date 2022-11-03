//
//  main.cpp
//  4
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
    long long ans=1+n*(n+1)*3;
    cout<<ans<<endl;
    return 0;
}
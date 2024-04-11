//
//  main.cpp
//  3
//
//  Created by  on 16/2/18.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    long long ans=1;
    for(int i=1;i<=n+1;i++)
        ans*=2;
    ans-=2;
    cout<<ans<<endl;
    return 0;
}
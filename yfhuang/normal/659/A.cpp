//
//  main.cpp
//  A
//
//  Created by  on 16/3/30.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,a,b;

int main(int argc, const char * argv[]) {
    cin>>n>>a>>b;
    int ans = (a + b)%n;
    if(ans<0) ans+=n;
    if(ans ==0) ans = n;
    cout<<ans<<endl;
    return 0;
}
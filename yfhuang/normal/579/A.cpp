//
//  main.cpp
//  A
//
//  Created by  on 16/1/1.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int ans=0;
    while(n>0){
        ans+=(n%2);
        n/=2;
    }
    cout<<ans;
    return 0;
}
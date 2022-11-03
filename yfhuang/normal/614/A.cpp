//
//  main.cpp
//  A
//
//  Created by  on 16/1/15.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

int main(int argc, const char * argv[]) {
    bool flag=false;
    ll l,r,k;
    cin>>l>>r>>k;
    ll a=1;
    while(true){
        if(a>=l&&a<=r) {cout<<a<<' ';flag=true;}
        if(r/k<a) break;
        a*=k;
    }
    if(!flag) printf("-1\n");
    return 0;
}
//
//  main.cpp
//  c
//
//  Created by  on 16/2/29.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

ll s,x;

int main(int argc, const char * argv[]) {
    cin>>s>>x;
    ll diff=(s-x)/2;
    if(diff<0||((s-x)&1)||(x&diff)!=0){
        printf("0\n");
        return 0;
    }
    ll num=0;
    while(x>0){
        if(x&1) num++;
        x>>=1;
    }
    ll ans=1LL<<num;
    if(diff==0) ans-=2;
    cout<<ans<<endl;
    return 0;
}
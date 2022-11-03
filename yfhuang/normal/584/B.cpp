//
//  main.cpp
//  B
//
//  Created by  on 15/12/13.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

const int MOD=1e9+7;

int n;

int main(int argc, const char * argv[]) {
    cin>>n;
    long long ans=1;
    long long a=1;
    for(int i=1;i<=n;i++){
        ans*=27;
        ans%=MOD;
    }
    for(int i=1;i<=n;i++){
        a*=7;
        a%=MOD;
    }
    if(ans>a) ans=(ans-a)%MOD;
    else ans=(ans+MOD-a)%MOD;
    cout<<ans<<endl;
    return 0;
}
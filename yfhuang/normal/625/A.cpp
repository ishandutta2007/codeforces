//
//  main.cpp
//  A
//
//  Created by  on 16/2/7.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

long long n;

long long a,b,c;

int main(int argc, const char * argv[]) {
    cin>>n>>a>>b>>c;
    long long ans=0;
    if(b-c>=a){
        ans=n/a;
    }else{
        if(n>=b){
        ans=(n-b)/(b-c);
        n=n-(b-c)*ans;
        ans+=max(1+(n-(b-c))/a,n/a);
        }
        else{
            ans=n/a;
        }
    }
    cout<<ans<<endl;
    return 0;
}
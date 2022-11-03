//
//  main.cpp
//  D
//
//  Created by  on 15/12/2.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const long long A=1e9+7;

int main(int argc, const char * argv[]) {
    long long p,k;
    cin>>p>>k;
    if(k>1){
    long long i;
    long long a=1;
    for(i=1;i<=p-1;i++){
        a=a*k;
        a%=p;
        if(a%p==1) break;
    }
    long long j=(p-1)/i;
    long long ans=1;
    for(int l=1;l<=j;l++){
        ans*=p;
        ans%=A;
    }
    ans%=A;
        cout<<ans<<endl;}
    else if(k==1){
        long long ans=1;
        for(int i=1;i<=p;i++){
            ans*=p;
            ans%=A;
        }
        cout<<ans<<endl;
    }
    else if(k==0){
        long long ans=1;
        for(int i=1;i<=p-1;i++){
            ans*=p;
            ans%=A;
        }
        cout<<ans<<endl;
    }
    return 0;
}
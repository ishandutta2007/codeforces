//
//  main.cpp
//  A
//
//  Created by  on 15/11/13.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
int t;

int main(int argc, const char * argv[]) {
    scanf("%d",&t);
    long long n;
    long long ans;
    for(int j=1;j<=t;j++){
        cin>>n;
        long long m=n;
        long long cnt=0;
        while(m>=1){
            m/=2;cnt++;
        }
        cnt--;
        long long x=1;
        for(int i=1;i<=cnt+2;i++)
            x*=2;
        ans=n*(n+1)/2-x+2;
        cout<<ans<<endl;
    }
    return 0;
}
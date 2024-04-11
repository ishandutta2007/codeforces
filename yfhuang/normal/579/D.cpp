//
//  main.cpp
//  D
//
//  Created by  on 16/1/1.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,k,x;

const int maxn=2e5+5;
long long a[maxn],prefix[maxn],suffix[maxn];

int main(int argc, const char * argv[]) {
    cin>>n>>k>>x;
    long long mul=1;
    while(k--)
        mul*=x;
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]|a[i];
    }
    for(int i=n;i>=1;i--){
        suffix[i]=suffix[i+1]|a[i];
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,prefix[i-1]|(a[i]*mul)|suffix[i+1]);
    cout<<ans<<endl;
    return 0;
}
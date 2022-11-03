//
//  main.cpp
//  A
//
//  Created by  on 16/1/31.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
const int maxn=100005;

long long a[maxn];

int main(int argc, const char * argv[]) {
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%I64d",&a[i]);
        ans+=a[i];
    }
    if(ans&1){
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++){
            if(a[i]&1){
                ans-=a[i];
                break;
            }
        }
    }
    printf("%I64d\n",ans);
    return 0;
}
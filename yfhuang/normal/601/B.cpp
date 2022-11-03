//
//  main.cpp
//  D
//
//  Created by  on 15/11/25.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[100005];
int inqueue[100005];
int n,q;

int main(int argc, const char * argv[]) {
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++){
        a[i]=abs(a[i+1]-a[i]);
    }
    while(q--){
        int l,r;
        int size=1;
        long long ans=0,res=0;
        cin>>l>>r;
        inqueue[0]=l-1;
        for(int i=l;i<r;i++){
            while(size>1&&a[i]>=a[inqueue[size-1]]){//
                size--;
                res+=1LL*(inqueue[size]-inqueue[size-1])*(a[i]-a[inqueue[size]]);
            }
            inqueue[size++]=i;
            res+=a[i];
            ans+=res;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
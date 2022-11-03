//
//  main.cpp
//  D
//
//  Created by  on 16/3/7.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

int n,a,b,T;

const int maxn=5e5+10;

char str[maxn];
int x[maxn];

long long pre[maxn];
long long suf[maxn];

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        x[i]=1;
    }
    scanf("%d%d%d",&a,&b,&T);
    scanf("%s",str+1);
    for(int i=1;i<=n;i++){
        if(str[i]=='w') x[i]+=b;
    }
    memset(pre,0,sizeof(pre));
    memset(suf,0,sizeof(suf));
    for(int i=1;i<=n;i++){
        if(i!=1)
            pre[i]=pre[i-1]+x[i]+a;
        else
            pre[i]=pre[i-1]+x[i];
    }
    for(int i=n;i>=1;i--){
        suf[i]=suf[i+1]+x[i]+a;
    }
    int left=n,right=n+1;
    while(pre[left]>T){
        left--;
        if(left<1) break;
    }
    int ans=0;
    for(;left>=1;left--){
        while(suf[right]+pre[left]+(left-1)*a<=T){
            right--;
            if(right<=left) break;
        }
        right++;
        ans=max(ans,n+1+left-right);
    }
    left=1,right=2;
    while(suf[right]+pre[left]>T){
        right++;
        if(right>n) break;
    }
    for(;right<=n+1;right++){
        while(pre[left]+(n+1-right)*a+suf[right]<=T){
            left++;
            if(right<=left) break;
        }
        left--;
        ans=max(ans,n+left-right+1);
    }
    cout<<ans<<endl;
    return 0;
}
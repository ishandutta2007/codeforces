//
//  main.cpp
//  D
//
//  Created by  on 16/2/14.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;

const int maxn=2005;
const int rng=5005;

int a[maxn];
int cnt[rng],cnt2[rng*2];

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            cnt[a[j]-a[i]]++;
    memset(cnt2,0,sizeof(cnt2));
    for(int i=5000;i>=0;i--)
        cnt2[i]=cnt2[i+1]+cnt[i];
    long long ans=0;
    for(int i=1;i<=5000;i++)
        for(int j=1;j<=5000;j++){
            ans+=(long long)cnt[i]*cnt[j]*cnt2[i+j+1];
        }
    int b=n*(n-1)/2;
    printf("%.10lf\n",1.0*ans/b/b/b);
    return 0;
}
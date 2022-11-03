//
//  main.cpp
//  B
//
//  Created by  on 16/1/31.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n;

const int maxn=200005;

int x[maxn],y[maxn];

long long ans;

long long cnt1[2005],cnt2[2005];
int main(int argc, const char * argv[]) {
    cin>>n;
    ans=0;
    memset(cnt1,0,sizeof(cnt1));
    memset(cnt2,0,sizeof(cnt2));
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x[i],&y[i]);
        cnt1[x[i]+y[i]]++;
        cnt2[x[i]-y[i]+1000]++;
    }
    for(int i=0;i<2005;i++){
        ans+=((long long)cnt1[i])*(cnt1[i]-1)/2;
        ans+=((long long)cnt2[i])*(cnt2[i]-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}
//
//  main.cpp
//  d
//
//  Created by  on 16/3/2.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int maxn=1e6+5;

int cnt[maxn];
ll d[maxn];
int a[maxn];
int n,m;

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&m);
    memset(cnt,0,sizeof(cnt));
    memset(d,0,sizeof(d));
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        if(a[i]<=m) cnt[a[i]]++;
    }
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j+=i){
            d[j]+=(ll)cnt[i];
        }
    }
    int l=1;long long k=0;
    for(int i=1;i<=m;i++){
        if(d[i]>k){
            k=d[i];
            l=i;
        }
    }
    cout<<l<<' '<<k<<endl;
    for(int i=0;i<n;i++){
        if(l%a[i]==0) printf("%d%c",i+1,i==n-1?'\n':' ');
    }
    return 0;
}
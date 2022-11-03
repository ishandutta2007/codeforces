//
//  main.cpp
//  D
//
//  Created by  on 16/1/12.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,k;

const int maxn=5e5+5;
const int maxa=1e6+5;

int a[maxn];
int b[maxa];

int main(int argc, const char * argv[]) {
    cin>>n>>k;
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int l=1,r=1;
    int ans=1;
    int dif=1;
    b[a[1]]=1;
    int begin=1,end=1;
    while(l<=r&&l<=n&&r<=n){
        while(dif<=k){
            if(r-l+1>ans){
                ans=r-l+1;
                begin = l,end = r;
                //printf("%d %d\n",l,r);
            }
            if(r==n) break;
            r++;
            if(b[a[r]]==0) dif++;
            b[a[r]]++;
            //printf("%d %d %d\n",l,r,dif);
        }
        while(dif>k&&l<r){
            b[a[l]]--;
            if(b[a[l]]==0) dif--;
            l++;
            //printf("%d %d %d\n",l,r,dif);
        }
        if(r==n) break;
    }
    cout<<begin<<' '<<end<<endl;
    return 0;
}
//
//  main.cpp
//  C
//
//  Created by  on 16/3/19.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=1e5+5;
int n, k;

char s[maxn];
int sum[maxn];

bool check(int p,int l){
    int left=p-l-1,right=p+l;
    if(p-l-1<1) left=0;
    if(p+l>n) right=n;
    if(sum[right]-sum[left]>k)return true;
    else return false;
}

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    sum[0]=0;
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+(s[i]=='0');
    }
    int ans=0x3f3f3f3f;
    //int id=0;
    for(int i=1;i<=n;i++){
        if(s[i]!='0') continue;
        int l=0,r=n;
        //if(r==0) continue;
        //if(!check(i,r)) continue;
        while(r-l>1){
            int mid=l+(r-l+1)/2;
            if(check(i,mid)) r=mid;
            else l=mid;
        }
        if(r<ans){
            ans=r;
            //id=i;
        }
        
    }
    //if(check(3, 6)) puts("YES");
    printf("%d\n",ans);
    return 0;
}
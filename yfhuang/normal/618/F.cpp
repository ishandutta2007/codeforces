//
//  main.cpp
//  F
//
//  Created by  on 16/1/30.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int maxn=1000010;
int A[maxn],B[maxn];
ll a[maxn],b[maxn],d[maxn];
int c[maxn];
int num[maxn];

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(d,0,sizeof(d));
    memset(c,0,sizeof(c));
    memset(num,0,sizeof(num));
    for(int i=1;i<=n;i++){
        scanf("%d",&A[i]);
        a[i]=a[i-1]+(ll)A[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&B[i]);
        b[i]=b[i-1]+(ll)B[i];
    }
    bool flag=false;
    if(a[n]>b[n]){
        flag=true;
        for(int i=1;i<=n;i++){
            swap(a[i],b[i]);
            swap(A[i],B[i]);
        }
    }
    for(int i=1;i<=n;i++){
        int x=upper_bound(b+1,b+1+n,a[i])-b;
        c[i]=x-1;
        d[i]=a[i]-b[c[i]];
        num[d[i]]++;
    }
    c[0]=0;
    d[0]=0;
    num[0]++;
    int i;
    for( i=0;i<n;i++){
        if(num[i]>1) break;
    }
    int x=-1,y=-1;
    for(int j=0;j<=n;j++){
        if(d[j]==i){
            if(x==-1) x=j;
            else{
                if(y==-1) y=j;
                else break;
            }
        }
    }
    //printf("%d %d",x,y);
    if(!flag){
        printf("%d\n",y-x);
        for(int k=x+1;k<=y;k++){
            printf("%d%c",k,k==y?'\n':' ');
        }
        printf("%d\n",c[y]-c[x]);
        for(int k=c[x]+1;k<=c[y];k++){
            printf("%d%c",k,k==c[y]?'\n':' ');
        }
    }else{
        printf("%d\n",c[y]-c[x]);
        for(int k=c[x]+1;k<=c[y];k++){
            printf("%d%c",k,k==c[y]?'\n':' ');
        }
        printf("%d\n",y-x);
        for(int k=x+1;k<=y;k++){
            printf("%d%c",k,k==y?'\n':' ');
        }
    }
    return 0;
}
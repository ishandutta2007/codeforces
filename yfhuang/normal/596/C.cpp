//
//  main.cpp
//  C
//
//  Created by  on 15/11/16.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxx=100000+16;
int a[maxx],b[maxx];
int c[maxx];
int h[maxx];
int n;
int w[maxx];

int findval(int x,int y,int val){
    while(y>x){
        int mid=(x+y)/2;
        if(a[mid]<=val) y=mid;//val
        else x=mid+1;
    }
    return x;
}

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    int x,y,w0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        w0=y-x;
        b[x]=max(w0,b[x]);
    }
    for(int i=0;i<maxx;i++){
        a[i]=-i;
    }
    int num=0;
    int w1;
    //int z=findval(0,9,3);
    //printf("%d",z);
    //int a[10]={9,8,7,6,5,4,3,2,1,1};
    bool flag=true;
    for(int i=1;i<=n;i++){
        scanf("%d",&w1);
        int z=findval(0,num,w1);
        if(z==num) num++;
        if(a[z]==w1&&w1<=b[z]) {a[z]=w1+1;c[i]=z;}
        else flag=false;
    }
    memset(h,0,sizeof(h));
    
    if(!flag) printf("NO\n");
    else{
        printf("YES\n");
        for(int i=1;i<=n;i++){
            printf("%d %d\n",c[i],h[c[i]]);
            h[c[i]]++;
        }
    }
    return 0;
}
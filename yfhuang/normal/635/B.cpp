//
//  main.cpp
//  b
//
//  Created by  on 16/2/29.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=200005;

int a[N],b[N];

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    int pos=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            pos=i;
            break;
        }
    }
    for(int i=pos;i<=n-1;i++)
        a[i]=a[i+1];
    for(int i=1;i<=n;i++){
        if(b[i]==0){
            pos=i;
            break;
        }
    }
    for(int i=pos;i<=n-1;i++)
        b[i]=b[i+1];
    for(int i=1;i<=n-1;i++){
        if(b[i]==a[1]){
            pos=i;
            break;
        }
    }
    bool flag=true;
    for(int i=pos;i<=n-1;i++){
        if(b[i]!=a[i-pos+1])
            flag=false;
    }
    for(int i=1;i<pos;i++){
        if(b[i]!=a[n-pos+i])
            flag=false;
    }
    if(flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}
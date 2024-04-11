//
//  main.cpp
//  B
//
//  Created by  on 16/1/18.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;

const int maxn=1005;

int a[maxn];

int main(int argc, const char * argv[]) {
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    bool flag=true;
    int cnt=0;
    cnt=(n-a[1])%n;
    for(int i=2;i<=n;i++){
        if(i&1) a[i]=(a[i]+cnt)%n;
        else{
            a[i]=(a[i]-cnt+n)%n;
        }
        if(a[i]!=i-1) flag=false;
    }
    if(flag) printf("Yes\n");
    else printf("No\n");
    return 0;
}
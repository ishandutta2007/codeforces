//
//  main.cpp
//  D
//
//  Created by  on 16/1/7.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5+5;

int n;

int h[maxn];
int Left[maxn],Right[maxn];

int main(int argc, const char * argv[]) {
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    Left[0]=Right[n+1]=0;
    for(int i=1;i<=n;i++)
        Left[i]=min(Left[i-1]+1,h[i]);
    for(int i=n;i>=1;i--)
        Right[i]=min(Right[i+1]+1,h[i]);
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,min(Left[i],Right[i]));
    }
    printf("%d\n",ans);
    return 0;
}
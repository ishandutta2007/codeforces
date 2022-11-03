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
#include <map>
using namespace std;

int n;

const int maxn=150000+5;

int a[maxn];
int x[555555];
int no[555555];

typedef pair<int,int> pii;

map<pii,bool> mp;

int ch(int i){
    if(i<=0||i>=n) return 1;
    if(i&1) return a[i]<a[i+1];
    return a[i]>a[i+1];
}

int cnt;

void check(int i,int j){
    if(i>j) swap(i,j);
    
    int flag=true;
    swap(a[i],a[j]);
    
    for(int i=1;i<=cnt;i++) if(!ch(x[i])) flag=false;
    if(!ch(i)) flag=false;
    if(!ch(j)) flag=false;
    if(!ch(i-1)) flag=false;
    if(!ch(j-1)) flag=false;
    
    swap(a[i],a[j]);
    
    if(flag) mp[make_pair(i, j)]=1;
}

int main(){
    scanf("%d",&n);
    memset(x,0,sizeof(x));
    memset(no,0,sizeof(no));
    mp.clear();
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
        if(!ch(i)) x[++cnt]=i;
    if(cnt>5){
        printf("0\n");
        return 0;
    }
    for(int i=1;i<=cnt;i++) no[x[i]]=no[x[i]+1]=1;
    for(int i=1;i<=n;i++) if(no[i]){
        for(int j=1;j<=n;j++) if(i!=j) check(i, j);
    }
    printf("%d\n",(int)mp.size());
}
//
//  main.cpp
//  D
//
//  Created by  on 16/3/26.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=2e5+5;

struct segment{
    int l,r,id,num;
}s[maxn];

bool cmp1(segment s1,segment s2){
    return s1.l > s2.l;
}

bool cmp2(segment s1, segment s2){
    return s1.id < s2.id;
}

int a[maxn<<1],c[maxn<<1];
int n,m;

int sum(int x){
    int ret = 0;
    while(x > 0){
        ret += c[x];
        x -= x & -x;
    }
    return ret;
}

void update(int x){
    while(x<=m){
        c[x]++;
        x += x & -x;
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    m=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&s[i].l,&s[i].r);
        s[i].id=i;
        s[i].num=0;
        a[++m]=s[i].l;
        a[++m]=s[i].r;
    }
    sort(a+1,a+m+1);
    sort(s+1,s+n+1,cmp1);
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++){
        int r = lower_bound(a+1, a+m+1, s[i].r)-a;
        s[i].num=sum(r);
        update(r);
    }
    sort(s+1,s+1+n,cmp2);
    for(int i=1;i<=n;i++)
        cout<<s[i].num<<endl;
    return 0;
}
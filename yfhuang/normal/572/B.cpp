//
//  main.cpp
//  B
//
//  Created by  on 16/2/4.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxn=1005;
int n,S;

int b[100005],s[100005];

struct stock{
    int p,q;
};

stock b1[maxn],s1[maxn];

bool cmp1(stock a,stock b){
    return a.p>b.p;
}
bool cmp2(stock a,stock b){
    return a.p<b.p;
}

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&S);
    memset(b,0,sizeof(b));
    memset(s,0,sizeof(s));
    char str[3]; int p,q;
    for(int i=1;i<=n;i++){
        scanf("%s",str);
        scanf("%d%d",&p,&q);
        if(str[0]=='B'){
            b[p]+=q;
        }else{
            s[p]+=q;
        }
    }
    int cnt1=0,cnt2=0;
    for(int i=0;i<=100000;i++){
        if(b[i]){
            b1[cnt1].q=b[i];
            b1[cnt1++].p=i;
        }
    }
    for(int i=0;i<=100000;i++){
        if(s[i]){
            s1[cnt2].q=s[i];
            s1[cnt2++].p=i;
        }
    }
    sort(b1,b1+cnt1,cmp1);
    sort(s1,s1+cnt2,cmp2);
    for(int i=min(S-1,cnt2-1);i>=0;i--){
        printf("S %d %d\n",s1[i].p,s1[i].q);
    }
    for(int i=0;i<min(S,cnt1);i++){
        printf("B %d %d\n",b1[i].p,b1[i].q);
    }
    return 0;
}
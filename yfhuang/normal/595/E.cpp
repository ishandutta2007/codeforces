//
//  main.cpp
//  E
//
//  Created by  on 15/11/9.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int maxn=100000+5;
int N,K;
struct node{
    int x,y;
    node(){}
    node(const int &_x,const int &_y) :x(_x),y(_y){}
    bool operator<(const node &o) const{return (x==o.x?y<o.y:x<o.x);}
}p[maxn],q[maxn];
int Y,yy[maxn];
LL ans;

void init(){
    scanf("%d%d",&N,&K);
    Y=0;
    for(int x1,x2,y1,y2, i=1;i<=N;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        p[i]=node(x1+x2,y1+y2);
        yy[++Y]=y1+y2;
    }
    sort(p+1,p+N+1);
    sort(yy+1,yy+N+1);
    ans=(1ULL<<63)-1;
}

LL work(int l,int r){//ylr
    int m=0;
    for(int i=1;i<=N;i++){
        if(p[i].y>=l&&p[i].y<=r) q[++m]=p[i];
    }
    int k=K-(N-m),res=(1ULL<<31)-1;
    k=m-1-k;
    for(int i=1;i+k<=m;i++){
        res=min(res,q[i+k].x-q[i].x);
    }
    if(r<=l) r=l+1;
    if(res<=0) res=1;
    return (LL)((res+1)>>1)*((r-l+1)>>1);
}

int main(int argc, const char * argv[]) {
    init();
    for(int i=1;i<=K+1;i++){
        for(int j=N;i-1+N-j<=K;j--){
            ans=min(ans,work(yy[i],yy[j]));
        }
    }
    cout<<ans<<endl;
    return 0;
}
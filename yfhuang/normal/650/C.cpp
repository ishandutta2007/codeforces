//
//  main.cpp
//  E
//
//  Created by  on 16/3/8.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=1000000+5;

struct Node{
    int x,y,v;
    bool operator < (const Node &rhs)const{
        return v<rhs.v;
    }
}node[maxn];

int p[maxn],ans[maxn],n,m,Rank[maxn],maxx[maxn],maxy[maxn];

int find(int x){
    return x==p[x]?x:p[x]=find(p[x]);
}

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            scanf("%d",&node[(i-1)*m+j].v);
            node[(i-1)*m+j].x=i;
            node[(i-1)*m+j].y=j;
        }
    
    sort(node+1,node+1+n*m);
    
    for(int i=1,j=1;i<=n*m;i=j+1,j=i){
        while(j<n*m&&node[j+1].v==node[i].v)
            j++;
        for(int k=i;k<=j;k++){
            p[node[k].x]=node[k].x;
            p[node[k].y+n]=node[k].y+n;
            Rank[node[k].x]=0;
            Rank[node[k].y+n]=0;
        }
        int px,py,res;
        for(int k=i;k<=j;k++){
            res=max(maxx[node[k].x],maxy[node[k].y]);
            px=find(node[k].x);
            py=find(node[k].y+n);
            if(px==py) {Rank[px]=max(Rank[px],res+1);}
            else {p[py]=px;Rank[px]=max(Rank[px],max(Rank[py],res+1));}
        }
        for(int k=i;k<=j;k++){
            px=find(node[k].x);
            py=find(node[k].y+n);
            res=max(Rank[px],Rank[py]);
            maxx[node[k].x]=res;
            maxy[node[k].y]=res;
            ans[(node[k].x-1)*m+node[k].y]=res;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d%c",ans[(i-1)*m+j],j==m?'\n':' ');
        }
    }
    return 0;
}
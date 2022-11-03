//
//  main.cpp
//  D
//
//  Created by  on 16/1/30.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int maxn=200005;
vector<int>G[maxn];
//bool vis[maxn];
typedef pair<int,int> pi;

long long c;

int dfs(int v,int p){
    long long ans=0;
    for(int i=0;i<G[v].size();i++){
        if(G[v][i]==p) continue;
        ans+=dfs(G[v][i],v);
    }
    if(ans>1){
        c+=2;
        return 0;
    }
    else{
        c+=ans;
        return 1;
    }
}

/*pi bfs(int i){
    queue<pi>q;
    vis[i]=true;
    q.push(make_pair(i,0));
    int maxd=0,v=i;
    while(!q.empty()){
        pi p=q.front();q.pop();
        if(p.second>maxd){
            maxd=p.second;v=p.first;
        }
        for(int i=0;i<G[p.first].size();i++){
            if(!vis[G[p.first][i]]){
                vis[G[p.first][i]]=true;
                q.push(make_pair(G[p.first][i],p.second+1));
            }
        }
    }
    return make_pair(maxd, v);
}

*/

int main(int argc, const char * argv[]) {
    int n,x,y;
    c=0;
    scanf("%d%d%d",&n,&x,&y);
    for(int i=1;i<n;i++){
        int s,t;
        scanf("%d%d",&s,&t);
        G[s].push_back(t);
        G[t].push_back(s);
    }
    //memset(vis,false,sizeof(vis));
    dfs(1,-1);
    //memset(vis,false,sizeof(vis));
    //pi b=bfs(a.second);
    long long ans=0;
    if(x<y) ans=((long long)c)*x+((long long)y)*(n-1-c);
    else{
        bool flag=false;
        for(int i=1;i<=n;i++){
            if(G[i].size()==n-1) flag=true;
        }
        if(flag) ans=(long long)(n-2)*y+x;
        else ans=(long long)(n-1)*y;
    }
    cout<<ans<<endl;
    return 0;
}
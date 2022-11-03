//
//  main.cpp
//  E
//
//  Created by  on 16/2/11.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int maxn=5e5+5;

vector<int>G[maxn];

vector<int> res;

void dfs(int v,int p,int d){
    if(G[v].size()==1)
        res.push_back(d);
    for(int i=0;i<G[v].size();i++){
        int to=G[v][i];
        if(to==p) continue;
        dfs(to,v,d+1);
    }
}

int solve(){
    sort(res.begin(),res.end());
    int a=-1;
    for(int i=0;i<res.size();i++){
        a=max(a+1,res[i]);
    }
    return a;
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    int ans=0;
    
    for(int i=0;i<G[0].size();i++){
        res.clear();
        dfs(G[0][i],0,0);
        ans=max(ans,solve());
    }
    cout<<ans+1<<endl;
    return 0;
}
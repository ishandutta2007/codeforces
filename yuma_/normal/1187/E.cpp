#include <bits/stdc++.h>

using namespace std;

int N;
long long int dp[200001];
long long int dp2[200001];
int ch[200001];
long long int answers[200001];

void dfs(int now,int from,const vector<vector<int>>&edges){
    ch[now]=1;
    dp[now]=0;
    for(auto e:edges[now]){
        if(e!=from){
            dfs(e,now,edges);

            ch[now]+=ch[e];
            dp[now]+=dp[e];
        }
    }
    dp[now]+=ch[now];
}
void dfs2(int now,int from,const vector<vector<int>>&edges){

    if(from==-1){
        answers[now]=dp[now];
        dp2[now]=answers[now];
    }else{
        answers[now]=dp2[from]+N-2*ch[now];
        dp2[now]=answers[now];
    }
    for(auto e:edges[now]){
        if(e!=from){
            dfs2(e,now,edges);
        }
    }
    
}

int main() {
    cin>>N;
    vector<vector<int>>edges(N);
    for(int i=0;i<N-1;++i){
        int u,v;scanf("%d %d",&u,&v);
        u--;v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(0,-1,edges);
    dfs2(0,-1,edges);
    long long int answer=0;
    for(int i=0;i<N;++i)answer=max(answer,answers[i]);
    cout<<answer<<endl;
    return 0;
}
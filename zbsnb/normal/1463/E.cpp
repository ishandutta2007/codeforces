#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
vector<int> e[maxn];
vector<int> e2[maxn];
 
int col[maxn],tot;
int fir[maxn];
 
int to[maxn];
int from[maxn];
int in[maxn]; // col
 
int vis[maxn];
int vis2[maxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    auto b=clock();
    auto f_time=[&]{return (double)(clock()-b)/CLOCKS_PER_SEC;};

    int n,m;cin>>n>>m;
    int rt;
    for(int i=1;i<=n;i++){
        int tmp;cin>>tmp;
        if(tmp) e[tmp].push_back(i);
        else rt=i;
    }
    int flg=0;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        if(to[a]||from[b]) flg=1;
        else to[a]=b,from[b]=a;
    }
    if(flg){
        cout<<0<<endl;
        return 0;
    }

    for(int i=1;i<=n;i++){
        if(vis2[i]) continue;
        int now=to[i];
        while(now){
            if(vis2[now]) break;
            vis2[now]=1;
            if(now==i){
                flg=1;
                break;
            }
            now=to[now];
        }
        if(flg==1) break;
    }
 
    if(flg){
        cout<<0<<endl;
        return 0;
    }
 
    vector<int> vec;
    for(int i=1;i<=n;i++){
        if(from[i]) continue; 
        col[i]=++tot;
        fir[tot]=i;
 
        int now=to[i];
        while(now){
            col[now]=tot;
            now=to[now];
        }
    }
    
 
    // for(int i=1;i<=n;i++) cout<<to[i]<<" "; cout<<endl;
    // for(int i=1;i<=n;i++) cout<<col[i]<<" "; cout<<endl;
 
    for(int i=1;i<=n;i++){
        for(auto &v:e[i]){
            if(col[i]!=col[v]){
                in[col[v]]++;
                e2[col[i]].push_back(col[v]);
                // cout<<col[i]<<" "<<col[v]<<endl;
            }
        }
    }
 
    // for(int i=1;i<=tot;i++) cout<<in[i]<<" ";cout<<endl;
 
    queue<int> q; // p
    vector<int> ans;
 
    // col
    for(int i=1;i<=tot;i++){
        if(in[i]==0){
            ans.push_back(i);
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto &v:e2[u]){
            in[v]--;
            if(in[v]==0){
                ans.push_back(v);
                q.push(v);
            }
        }
    }
 
    vector<int> anss;
    for(auto &it:ans){
        anss.push_back(fir[it]);
        int now=to[fir[it]];
        while(now){
            anss.push_back(now);
            now=to[now];
        }
    }
 
 
    if(anss.size()!=n){
        cout<<0<<endl;
        return 0;
    }
 
    flg=0;
 
    vis[rt]=1;
    for(auto &it:anss){
        if(vis[it]){
            for(auto &it:e[it]){
                vis[it]=1;
            }
        }
        else{
            flg=1;
            break;
        }
    }
 
    if(flg){
        cout<<0<<endl;
        return 0;
    }
 
    for(auto &it:anss) cout<<it<<" ";
    cout<<endl;
 
}
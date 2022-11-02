#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int b[1000010];
vector<int> e[1000010];
int cmp(int x,int y){
    return b[x]<b[y];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);;
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<pair<int,int> > ans;
    for(int i=1;i<=n;i++){
        ans.push_back({a[i],i});
    }
    sort(ans.begin(),ans.end());
    for(auto &it:ans){
        int now=it.second;
        int tmp=1;
        sort(e[now].begin(),e[now].end(),cmp);
        // for(auto &v:e[now]){
        //     cout<<v<<","<<b[v]<<" ";
        // }cout<<endl;
        for(auto &v:e[now]){
            if(!b[v])continue;
            if(b[v]==tmp)tmp++;
            else if(b[v]>tmp) break;
        }
        b[now]=tmp;
    }
    for(int i=1;i<=n;i++){
        // cout<<i<<" "<<b[i]<<endl;
        if(a[i]!=b[i]){
            cout<<-1<<endl;
            return 0;
        }
    }
    for(auto &it:ans){
        cout<<it.second<<" ";
    }
    cout<<endl;
}
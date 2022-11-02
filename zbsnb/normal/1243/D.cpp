#include<iostream>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
#define ll long long 

map<pair<int,int>,bool> mp;
set<int> s;
int n,m;
void dfs(int u,int fa){
    s.erase(u);
    for(auto it=s.begin();it!=s.end();it=s.lower_bound(*it+1)){
        int v=*it;
        if(!mp[{u,v}]){
            dfs(v,u);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        mp[{a,b}]=1;
        mp[{b,a}]=1;
    }
    int ans=-1;
    for(int i=1;i<=n;i++)s.insert(i);
    for(int i=1;i<=n;i++){
        if(s.find(i)!=s.end()){
            ans++;
            dfs(i,0);
        }
    }
    cout<<ans<<endl;
}
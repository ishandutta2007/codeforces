#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000010];
int b[1000010];
int pre[1000010];

struct e{
    int x,y;
    int g;
    bool operator<(const e& tmp) const{
        return g>tmp.g;
    }
};

int find(int x){return pre[x]==x?x:pre[x]=find(pre[x]);}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>m>>n;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=1000000;i++) pre[i]=i;
    vector<e> E;
    for(int i=1;i<=m;i++){
        int tmp;cin>>tmp;
        for(int j=1;j<=tmp;j++){
            int x;cin>>x;
            E.push_back({i,x+100010,a[i]+b[x]});
        }
    }
    sort(E.begin(),E.end());
    int ans=0;
    for(auto &it:E){
        int fx=find(it.x);
        int fy=find(it.y);
        if(fx!=fy){
            pre[fx]=pre[fy];
        }
        else ans+=it.g;

    }
    cout<<ans<<endl;

}
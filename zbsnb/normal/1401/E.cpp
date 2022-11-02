#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> vec[1000010];
vector<int> vec2[1000010];
vector<pair<int,int> > diff[1000010];
int h[1000010];
#define lowb(x) ((x)&(-x))
int N=1000001;
void upd(int x,int y){
    for(int i=x;i<=N;i+=lowb(i))h[i]+=y;
}
int que(int x){
    int ret=0;
    for(int i=x;i>=1;i-=lowb(i))ret+=h[i];
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    ll ans=1;
    for(int i=1;i<=n;i++){
        int x,a,b;cin>>x>>a>>b;
        if(a==0&&b==1000000)ans++,vec[x].push_back(b);
        else if(a==0)vec[x].push_back(b);
        else if(b==1000000)vec2[x].push_back(a);
    }
    
    for(int i=1;i<=m;i++){
        int x,a,b;cin>>x>>a>>b;
        if(a==0&&b==1000000)ans++;
        diff[a].push_back({x,1});
        diff[b+1].push_back({x,-1});
    }
 
    for(int i=0;i<=N;i++){
        for(auto &it:diff[i]){
            upd(it.first,it.second);
            // cout<<"now:"<<i<<endl;
            // for(int i=1;i<=10;i++)cout<<que(i)-que(i-1)<<" ";cout<<endl;
        }
        for(auto &it:vec[i]){
            ans+=que(it);
            // cout<<"?1:"<<it<<" "<<i<<" "<<que(it)<<endl;
        }
        for(auto &it:vec2[i]){
            ans+=que(N)-que(it-1);
            // cout<<"?2:"<<it<<" "<<i<<" "<<que(N)-que(it-1)<<endl;
        }
    }
    cout<<ans<<endl;
}
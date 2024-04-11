#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t[1000010],x[1000010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>t[i]>>x[i];
        }
        int ans=0,px=x[1],now=0;
        for(int i=1;i<=n;i++){
            int dt=i==n?(2e9+10):(t[i+1]-t[i]);
            int dx=abs(px-now);
            int nxt;

            if(dt>=dx){
                // cout<<"case1:"<<endl;
                nxt=px;
                px=x[i+1];
            }
            else{
                // cout<<"case2"<<endl;
                nxt=(now<px)?now+dt:now-dt;
                
            }
            
            int minn=min(now,nxt);
            int maxn=max(now,nxt);
            if(minn<=x[i]&&x[i]<=maxn) ans++;

            // cout<<i<<" "<<now<<" "<<nxt<<endl;

            now=nxt;


        }
        cout<<ans<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,k,z;cin>>n>>k>>z;
        for(int i=1;i<=n;i++)cin>>a[i];
        int ans=0;
        for(int i=0;i<=z;i++){
            int maxn=0;
            int now=k-2*i;
            if(now<=0)break;
            int tmp=a[1];
            for(int i=2;i<=now+1;i++){
                tmp+=a[i];
                maxn=max(maxn,a[i]+a[i-1]);
            }
            // cout<<i<<" "<<now<<" "<<tmp<<" "<<maxn<<endl;
            ans=max(ans,tmp+i*maxn);
        }

        k--;z--;
        for(int i=0;i<=z;i++){
            int maxn=0;
            int now=k-2*i;
            if(now<=0)break;
            int tmp=a[1];
            for(int i=2;i<=now+1;i++){
                tmp+=a[i];
                maxn=max(maxn,a[i]+a[i-1]);
            }
            // cout<<i<<" "<<now<<" "<<tmp<<" "<<maxn<<endl;
            ans=max(ans,tmp+i*maxn+a[now]);
        }

        cout<<ans<<endl;
    }
}
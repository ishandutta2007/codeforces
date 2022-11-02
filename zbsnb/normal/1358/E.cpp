#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000010];
int b[1000010];
int sum[1000010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;int lim=(n+1)/2;
    for(int i=1;i<=lim;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    int k;cin>>k;
    if(k>=0){
        if(sum[lim]+k*(n-lim)>0)cout<<n<<endl;
        else cout<<-1<<endl;
    }
    else{
        for(int i=1;i<=lim;i++){
            int tmp=sum[lim]-sum[i-1];
            if(tmp<=0) b[i]=1e18;
            else b[i]=i+max(0ll,(n-lim)-(tmp-1)/(-k));
            // cout<<i<<" "<<tmp<<" "<<b[i]<<endl;
        }
        int maxn=0,ans=n+2;
        for(int i=1;i<=lim;i++){
            maxn=max(maxn,b[i]);
            if(maxn<=i){
                ans=i;
                break;
            }
        }
        cout<<(n+1-ans)<<endl;
    }
}
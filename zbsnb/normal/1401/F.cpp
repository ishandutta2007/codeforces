#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000010];
ll sum[20][1000010];
int t,n,m;
ll que(int x){
    ll ret=0;int now=0;int yan=1<<n;
    for(int i=n;i>=0;i--,yan|=1<<i){
        if(x&(1<<i)){
            ret+=sum[i][(now^t)&yan];
            now|=1<<i;
        }
    }
    return ret;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<(1<<n);i++)cin>>a[i],sum[0][i]=a[i];
    for(int k=1;k<=n;k++){
        for(int i=0;i<(1<<n);i+=1<<k){
            sum[k][i]=sum[k-1][i]+sum[k-1][i|(1<<(k-1))];
        }
    }
    for(int i=1;i<=m;i++){
        int tag;cin>>tag;
        if(tag==1){
            int x,k;cin>>x>>k;x--;
            int pos=(x^t);
            int now=pos;
            for(int i=0;i<=n;i++){
                sum[i][now]+=k-a[pos];
                if(now&(1<<i))now^=1<<i;
            }
            a[pos]=k;
        }
        else if(tag==2){
            int k;cin>>k;t^=(1<<k)-1;
        }
        else if(tag==3){
            int k;cin>>k;t^=1<<k;
        }
        else if(tag==4){
            int l,r;cin>>l>>r;
            cout<<que(r)-que(l-1)<<endl;
        }
    }
}
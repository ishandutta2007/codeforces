#include <bits/stdc++.h>
using namespace std;
int n, m;
int l[51];
int r[51];
constexpr int base = 998244353;
long long val[100001];
int mu[100001];
int p[100001];
int range[51];
int f[100001];
int g[100001];
void solve(){
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>l[i]>>r[i];
    for(int i=2; i<=m; i++) if(p[i]==0) for(int j=i; j<=m; j+=i) if(p[j]==0) {
        p[j]=i;
    }
    mu[1]=1;
    for(int i=2; i<=m; i++){
        int u=i/p[i];
        if(p[u]==p[i]) mu[i]=0;
        else mu[i]=-mu[u];
    }
    for(int i=1; i<=m; i++) if(mu[i]){
        int mx=m/i;
        val[i]=1;
        int sum=m;
        for(int j=1; j<=n; j++){
            int low = l[j];
            if(low%i) low+=i-low%i;
            int high = r[j]-r[j]%i;
            if(low>high){
                val[i]=0;
                break;
            }
            sum-=low;
            if(sum<0){
                val[i]=0;
                break;
            }
            range[j]=(high-low)/i+1;
        }
        // cerr<<i<<' '<<ranfe
        if(val[i]==0) continue;
        sum/=i;
        for(int j=0; j<=sum; j++) f[j]=0;
        for(int j=0; j<=sum; j++) g[j]=1;
        f[0]=1;
        for(int j=1; j<=n; j++){
            for(int k=sum; k>=0; k--){
                if(k-range[j]>=0){
                    f[k]=g[k]-g[k-range[j]];
                    if(f[k]<0) f[k]+=base;
                }
                else f[k]=g[k];
            }
            g[0]=f[0];
            for(int k=1; k<=sum; k++){
                g[k]=g[k-1]+f[k];
                if(g[k]>=base) g[k]-=base;
            }
        }
        val[i]=g[sum];
        // for(int f=r[1]-r[1]%i; f>=l[1]; f-=i)
        // for(int g=r[2]-r[2]%i; g>=l[2]; g-=i)
        // for(int h=r[3]-r[3]%i; h>=l[3]; h-=i)
        // for(int j=r[4]-r[4]%i; j>=l[4]; j-=i)
        // for(int k=r[5]-r[5]%i; k>=l[5]; k-=i)
        //   if(f+g+h+j+k<=m) val[i]--;
        // cerr<<i<<' '<<val[i]%base<<'\n';
        
    }
    long long ans=0;
    for(int i=1; i<=m; i++){
        ans+=val[i]*mu[i];
    }
    ans%=base;
    (ans+=base)%=base;
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();
}
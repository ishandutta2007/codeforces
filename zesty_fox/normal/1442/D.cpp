#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}


#define rdi read<int>
#define rdl read<ll>
#define pb push_back

const int N=3010;
int n,k;
vector<ll> v[N],sum[N];
ll f[N],w[N],ans;
void solve(int l,int r){
    if(l==r){
        int minx=max(0,(int)(k-sum[l].size()+1));
        for(int i=minx;i<=k;i++) ans=max(ans,f[i]+sum[l][k-i]);
        return;
    }
    int mid=(l+r)>>1;
    ll tmp[N];memcpy(tmp,f,sizeof(ll)*(k+3));
    for(int i=mid+1;i<=r;i++){
        int num=v[i].size()-1;
        for(int j=k;j>=num;j--) f[j]=max(f[j],f[j-num]+w[i]);
    }
    solve(l,mid);
    memcpy(f,tmp,sizeof(ll)*(k+3));
    for(int i=l;i<=mid;i++){
        int num=v[i].size()-1;
        for(int j=k;j>=num;j--) f[j]=max(f[j],f[j-num]+w[i]);
    }
    solve(mid+1,r);
}

int main(){
    n=rdi(),k=rdi();
    for(int i=1;i<=n;i++){
        int tmp=rdi();v[i].pb(0),sum[i].pb(0);
        for(int j=1;j<=tmp;j++) v[i].pb(rdi()),w[i]+=v[i][j],sum[i].pb(w[i]);
    }
    solve(1,n);
    printf("%lld\n",ans);
    return 0;
}
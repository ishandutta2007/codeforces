#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7;
int n,K,a[N];
inline ll calc(int L,int R){
    static int l=1,r=0,cnt[N]={0};
    static ll ans=0;
    while(l<L)ans-=--cnt[a[l++]];
    while(l>L)ans+=cnt[a[--l]]++;
    while(r<R)ans+=cnt[a[++r]]++;
    while(r>R)ans-=--cnt[a[r--]];
    return ans;
}
ll f[N][21];
void solve(int l,int r,int L,int R,int k){
    if(l>r)return;
    int mid=(l+r)>>1,Mid=min(R,mid-1);
    for(int i=Mid;i>=L;i--){
	ll res=f[i][k-1]+calc(i+1,mid);
	if(res<f[mid][k])f[mid][k]=res,Mid=i;
    }
    solve(l,mid-1,L,Mid,k),solve(mid+1,r,Mid,R,k);
}
int main(){
    n=read(),K=read();
    for(int i=1;i<=n;i++)a[i]=read();
    memset(f,0x3f,sizeof(f)),f[0][0]=0;
    for(int i=1;i<=K;i++)solve(i,n,i-1,n-1,i);
    printf("%lld\n",f[n][K]);
    return 0;
}
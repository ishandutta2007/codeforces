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
int n,K,s_p,pr[N],v[N];
ll phi[N];
inline void init(){
    phi[1]=1;
    for(int i=2;i<=n;i++){
	if(!v[i])v[i]=i,pr[++s_p]=i,phi[i]=i-1;
	for(int j=1;j<=s_p && i*pr[j]<=n;j++){
	    v[i*pr[j]]=1;
	    if(i%pr[j]==0){phi[i*pr[j]]=phi[i]*pr[j];break;}
	    phi[i*pr[j]]=phi[i]*phi[pr[j]];
	}
    }
    for(int i=2;i<=n;i++)phi[i]+=phi[i-1];
}
inline ll c(int L,int R){
    ll ans=0;
    for(int l=L,r;l<=R;l=r+1){
	r=R/(R/l);
	ans+=(r-l+1)*phi[R/l];
    }
    return ans;
}
ll f[17][N];
void solve(int l,int r,int L,int R){
    if(l>r)return;
    int mid=(l+r)>>1,Mid=min(mid-1,R);
    ll co=c(Mid+1,mid);f[K][mid]=1e18;
    for(int i=Mid;i>=L;i--){
	ll cost=f[K-1][i]+co;
	if(cost<f[K][mid])f[K][mid]=cost,Mid=i;
	co+=phi[mid/i];
    }
    solve(l,mid-1,L,Mid),solve(mid+1,r,Mid,R);
}
int main(){
    n=1e5,init();
    for(int i=1;i<=n;i++)f[1][i]=1ll*i*(i+1)/2;
    for(K=2;K<=16;K++)solve(K,n,K-1,n-1);
    int test=read();
    while(test--){
	n=read(),K=read();
	printf("%lld\n",K>16 || (1<<K)>n?(ll)n:f[K][n]);
    }
    return 0;
}
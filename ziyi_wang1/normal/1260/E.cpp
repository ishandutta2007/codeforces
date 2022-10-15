#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define F(x,y,z) for(re x=y;x<=z;x++)
typedef long long ll;
#define IN inline ll
const ll INF=1e9+7;
ll n,m,N,sum[50],f[1010000][20],a[1010000];
IN work(ll x,ll s){
	if(f[x][s]!=-1)return f[x][s];
	if(a[x]==-1)return f[x][s]=0;
	if(s>N){
		f[x][s]=0;
		return f[x][s];
	}
	f[x][s]=INF;
	if(s<N)f[x][s]=a[x]+work(x+1,s+1);
	if(sum[s]-x>=0)f[x][s]=min(f[x][s],work(x+1,s));
	return f[x][s];
}
int main(){
	cin>>n;N=1;
	while((1ll<<N)<n)N++;
	F(i,1,n){
		cin>>a[i];
	}
	m=n;
	sum[0]=0ll;
	F(i,1,40){
		m>>=1;
		sum[i]=sum[i-1]+m;
	}
	reverse(a+1,a+1+n);
	memset(f,-1,sizeof(f));
	cout<<work(1ll,0ll);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int U=1e4,N=U+5;
ll T;
ll f[7][N],aa[N];
int i,j,k,xb,lm;
void solve(int d,ll l,ll r){
	ll ol=l;
	xb=0,lm=min(ll(U),l);
	l+=f[d-1][min(ll(U),l)];
	for(i=1;i<=lm && l<=r;++i)aa[++xb]=l,l+=f[d-1][min(l+1,ll(U))]+1;
	printf("%d ",xb);
	for(i=1;i<=xb;++i)printf("%lld%c",aa[i],i==xb?'\n':' ');
	fflush(stdout);
	scanf("%d",&i);
	assert(i!=-2);
	if(i==-1)exit(0);
	assert(d>1);
	solve(d-1,i==0?ol:aa[i]+1,i==xb?r:aa[i+1]-1);
}
int main(){
	for(i=1;i<=U;++i)f[0][i]=0;
	for(i=1;i<=5;++i)for(j=1;j<=(i==5?1:U);++j){
		ll nw=j+f[i-1][j];
		for(k=1;k<=j;++k)nw+=f[i-1][min(nw+1,ll(U))]+1;
		f[i][j]=nw-j;
	}
	solve(5,1,10004205361450474);
}
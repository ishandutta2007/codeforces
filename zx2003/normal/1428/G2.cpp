#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ll;
int F[6],k,q,x,y,i,j,mi[6];
ll f[N];
inline void conv(int w,int v,int c){
	static ll nf[N];static int q[N];int he,ta,i,j;
	memcpy(nf,f,sizeof f);
	for(i=0;i<v;++i){
		q[he=ta=1]=0;
		for(j=1;v*j+i<N;++j){
			for(;q[he]<j-c;++he);nf[v*j+i]=max(nf[v*j+i],f[v*q[he]+i]+1ll*w*(j-q[he]));
			for(;he<=ta && f[v*q[ta]+i]-1ll*w*q[ta]<=f[v*j+i]-1ll*w*j;--ta);q[++ta]=j;
		}
	}
	memcpy(f,nf,sizeof f);
}
int main(){
	for(i=*mi=1;i<6;++i)mi[i]=10*mi[i-1];
	scanf("%d",&k);for(i=0;i<6;++i)scanf("%d",F+i);
	for(i=0;i<N;++i)for(x=i,j=0;j<6;++j)y=x%10,x/=10,f[i]+=y && y%3==0?1ll*y/3*F[j]:0;
	if(k>1)for(i=0;i<6;++i)conv(F[i],mi[i]*3,3*(k-1));
	for(scanf("%d",&q);q--;)scanf("%d",&x),printf("%lld\n",f[x]);
}
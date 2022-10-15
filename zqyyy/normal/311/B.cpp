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
const ll INF=4e18;
int n,m,k,K,hd,tl,q[N],d[N];
ll s[N],t[N],f[N][107];
inline ll Y(int i){return f[i][k-1]+s[i];}
inline double slope(int i,int j){
	return 1.*(Y(j)-Y(i))/(j-i);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(),m=read(),K=min(m,read());
	for(int i=2;i<=n;i++)d[i]=d[i-1]+read();
	for(int i=1,x;i<=m;i++)x=read(),t[i]=read()-d[x];
	sort(t+1,t+m+1);
	for(int i=m;i;i--)t[i]-=t[1];
	for(int i=1;i<=m;i++)s[i]=s[i-1]+t[i];
	for(int i=1;i<=m;i++)f[i][0]=INF;
	for(k=1;k<=K;k++){
		hd=tl=0;
		for(int i=1;i<=m;i++){
			while(hd<tl && slope(q[hd],q[hd+1])<=t[i])hd++;
			f[i][k]=Y(q[hd])+i*t[i]-s[i]-t[i]*q[hd];
			if(k>1){
				while(hd<tl && slope(q[tl-1],q[tl])>=slope(q[tl],i))tl--;
				q[++tl]=i;
			}
		}
	}
	printf("%lld\n",f[m][K]);
	return 0;
}
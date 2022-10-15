#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7,M=7007;
int s_p,pr[M],mu[M],v[M];
bitset<M>a[N],b[M],u[M];
inline void init(int n){
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!v[i])v[i]=i,pr[++s_p]=i,mu[i]=-1;
		for(int j=1;j<=s_p && i*pr[j]<=n;j++){
			v[i*pr[j]]=pr[j];
			if(i%pr[j]==0)break;
			mu[i*pr[j]]=-mu[i];
		}
	}
	for(int x=1;x<=n;x++)
		for(int i=x;i<=n;i+=x)
			b[i][x]=1,u[x][i]=mu[i/x]?1:0;
}
int n,Q;
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(),Q=read(),init(7e3);
	while(Q--){
		int opt=read(),x=read();
		if(opt==1)a[x]=b[read()];
		else if(opt==2)a[x]=a[read()]^a[read()];
		else if(opt==3)a[x]=a[read()]&a[read()];
		else printf("%d",(a[x]&u[read()]).count()&1);
	}
	return 0;
}
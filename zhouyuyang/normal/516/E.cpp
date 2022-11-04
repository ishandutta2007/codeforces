#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define N 200005
int n,m,G,inva,invb,T[N];
vi a[N],b[N];
map<int,ll> f,g;
ll ans;
int power(int x,int y,int mo){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int phi(int x){
	int ans=x;
	for (int i=2;i*i<=x;i++)	
		if (x%i==0){
			ans-=ans/i;
			for (;x%i==0;x/=i);
		}
	if (x!=1) ans-=ans/x;
	return ans;
}
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void work(vi a,vi b,int inv,int n,int m){
	int tot=0;
	f.clear(); g.clear();
	for (int i=0;i<a.size();i++){
		int x=1ll*a[i]/G*inv%n;
		if (g.count(x))
			g[x]=min(g[x],a[i]+0ll);
		else g[x]=a[i];
		f[x]=1;
	}
	for (int i=0;i<b.size();i++){
		int x=1ll*b[i]/G*inv%n;
		if (g.count(x))
			g[x]=min(g[x],b[i]+0ll);
		else g[x]=b[i];
	}
	map<int,ll>::iterator it;
	for (it=g.begin();it!=g.end();it++)
		T[tot++]=it->first;
	for (int i=0,j=-1,k=0;k<2*tot;k++){
		i=(i+1)%tot; j=(j+1)%tot;
		g[T[i]]=min(g[T[i]],g[T[j]]+1ll*(T[i]-T[j]+n)%n*m*G);
	}
	for (int i=0;i<tot;i++){
		int x=(i+1)%tot,t=(T[x]+n-1)%n;
		if (!f.count(t)) ans=max(ans,g[T[i]]+1ll*(t-T[i]+n)%n*m*G);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	G=gcd(n,m); n/=G; m/=G;
	if (G>200000) return puts("-1"),0;
	int inva=power(n,phi(m)-1,m);
	int invb=power(m,phi(n)-1,n);
	int T; scanf("%d",&T);
	while (T--){
		int x;
		scanf("%d",&x);
		a[x%G].push_back(x);
	}
	scanf("%d",&T);
	while (T--){
		int x;
		scanf("%d",&x);
		b[x%G].push_back(x);
	}
	for (int i=0;i<G;i++)
		if (!a[i].size()&&!b[i].size())
			return puts("-1"),0;
	for (int i=0;i<G;i++){
		work(a[i],b[i],invb,n,m);
		work(b[i],a[i],inva,m,n);
	}
	printf("%lld",ans);
}
#include<bits/stdc++.h>
#define N 200005
using namespace std;
vector<int> p[N];
int vis[N],f[N],g[N];
int pri[N],mn[N],phi[N];
int n,m,tot;
void init(){
	phi[1]=1;
	for (int i=2;i<N;i++){
		if (!mn[i]){
			mn[i]=++tot;
			pri[tot]=i;
			phi[i]=i-1;
		}
		for (int j=1;j<=tot&&i*pri[j]<N;j++){
			int k=i*pri[j];
			mn[k]=j;
			if (mn[i]==j){
				phi[k]=phi[i]*pri[j];
				break;
			}
			phi[k]=phi[i]*(pri[j]-1);
		}
	}
}
void upd(int &f,int ff,int &g,int gg){
	if (f<ff)
		f=ff,g=gg;
}
int power(int x,int y,int mo){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s; 
}
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int calc(int a,int b){
	int g=gcd(a,m);
	a/=g; b/=g; g=m/g;
	return 1ll*b*power(a,phi[g]-1,g)%g;
}
void out(int x,int &last){
	if (x>1)
		out(g[x],last);
	if (!p[x].size())
		return;
	if (last==-1)
		printf("%d",p[x][0]);
	else printf(" %d",calc(last,p[x][0]));
	for (int i=1;i<p[x].size();i++)
		printf(" %d",calc(p[x][i-1],p[x][i]));
	last=p[x][p[x].size()-1]; 
}
int main(){
	init();
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		vis[x]=1;
	}
	for (int i=0;i<m;i++)
		if (!vis[i])
			p[gcd(m,i)].push_back(i);
	for (int i=1;i<=m;i++)
		for (int j=2*i;j<=m;j+=i)
			upd(f[j],f[i]+p[i].size(),g[j],i);
	printf("%d\n",f[m]+!vis[0]);
	int last=-1;
	out(m,last);
}
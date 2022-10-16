#include <bits/stdc++.h>
using namespace std;
int p, k;
int r[1000000];
int md[1000001];
int root(int u){
	if(r[u]<0) return u;
	return r[u]=root(r[u]);
}
void unite(int u, int v){
	u=root(u);
	v=root(v);
	if(u==v) return;
	if(r[u]>r[v]) swap(u, v);
	r[u]+=r[v];
	r[v]=u;
}
int main(){
	cin>>p>>k;
	if(k==0){
		long long ans=1;
		for(int i=1; i<p; i++) (ans*=p)%=1000000007;
		cout<<ans<<'\n';
		return 0;
	}
	for(int i=0; i<p; i++) r[i]=-1;
	for(int i=0; i<p; i++) unite(i, (((long long)i)*k)%p);
	md[0]=1;
	for(int i=1; i<=p; i++) md[i]=(((long long)md[i-1])*k)%p;
	long long ans=1;
	for(int i=0; i<p; i++) if(i==root(i))	if(md[-r[i]]==1) (ans*=p)%=1000000007;
	cout<<ans<<'\n';
}
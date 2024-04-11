#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e5+50;
vector<int> v[M];
int s[M*40],L[M*40],R[M*40],w[M];
int d[M];
int rt[M],n,root,tot;
#define mid (l+r>>1)
void update(int &x,int l,int r,int p,int d){
	if (!x) x=++tot; 
	
	if (!s[x]) s[x]=d; else s[x]=min(s[x],d);
	
	if (l==r) return ;
	if (p<=mid) update(L[x],l,mid,p,d);
	else update(R[x],mid+1,r,p,d);
}
int MG(int lx,int rx){
	int x=0;
	if (!lx || !rx) {
		return lx+rx;
	}
	x=++tot;
	s[x]=min(s[lx],s[rx]);
	L[x]=MG(L[lx],L[rx]);
	R[x]=MG(R[lx],R[rx]);
	return x;
}
int qry(int x,int l,int r,int ll,int rr){
	if (l==ll && r==rr) return s[x];
	if (rr<=mid) return qry(L[x],l,mid,ll,rr);
	if (ll>mid) return qry(R[x],mid+1,r,ll,rr);
	return min(qry(L[x],l,mid,ll,mid),qry(R[x],mid+1,r,mid+1,rr));
}
void dfs(int x,int fa,int dep){
	d[x]=dep;
	update(rt[x],0,n,dep,w[x]);
	for (int i=0;i<v[x].size();i++){
		int y=v[x][i];
		if (y==fa) continue;
		dfs(y,x,dep+1);
		rt[x]=MG(rt[x],rt[y]);
	}
}
int main(){
	n=read(); root=read();
	int mi=INT_MAX;
	for (int i=1;i<=n;i++) w[i]=read(),mi=min(mi,w[i]);
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i=0;i<=25*n;i++) s[i]=1e9+10;
	dfs(root,0,0);
	int m=read();
	int lastans=0;
//	s[0]=1e9+100;
//	if (n>100)cout<<mi<<"\n";
//	for (int i=0;i<=25*n;i++) assert(s[i]>=mi);
	while (m--){
		int x=read(),k=read();
//		cout<<d[x]<<" "<<d[x]+k<<"\n";
//		cout<<qry(rt[x],0,n,d[x],min(d[x]+k,n))<<"\n";
		x=((x+lastans)%n)+1; k=(k+lastans)%n;
		cout<<(lastans=qry(rt[x],0,n,d[x],min(d[x]+k,n)))<<"\n";
	}
	return 0;
}
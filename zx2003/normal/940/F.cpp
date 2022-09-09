#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,i,a[N],b[N<<1],c[N],j,c1,c2,p[N],x[N],bel[N],sz,l,r,t,o,xb,lst,ans[N];
pair<int,int*>f[N<<1];
struct query{
	int l,r,t,id;
	bool operator<(const query&rhs)const{
		return bel[l]==bel[rhs.l]?(bel[r]==bel[rhs.r]?t<rhs.t:r<rhs.r):l<rhs.l;
	}
}q[N];
inline void in(int v){--c[b[v]],++c[++b[v]];}
inline void out(int v){--c[b[v]],++c[--b[v]];}
inline void swap(int&a,int&b){int t=a;a=b;b=t;}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;sz=pow(n,2.0/3);
	for(i=1;i<=n;++i)cin>>a[i],bel[i]=i/sz,f[++xb]=make_pair(a[i],a+i);
	for(i=1;i<=m;++i){
		cin>>o>>l>>r;
		if(o==1)++c1,q[c1]=(query){l,r,lst,c1};
			else p[++c2]=l,x[c2]=r,lst=c2,f[++xb]=make_pair(x[c2],x+c2);
	}
	sort(f+1,f+xb+1);
	for(i=1;i<=xb;++i)*f[i].second=j+=f[i].first>f[i-1].first;
	sort(q+1,q+c1+1);in(a[l=r=1]);c[0]=j;
	for(i=1;i<=m;++i){
		while(l>q[i].l)in(a[--l]);
		while(r<q[i].r)in(a[++r]);
		while(l<q[i].l)out(a[l++]);
		while(r>q[i].r)out(a[r--]);
		while(t>q[i].t){
			if(l<=p[t] && p[t]<=r)out(a[p[t]]),in(x[t]);
			swap(x[t],a[p[t]]);--t;
		}
		while(t<q[i].t){
			++t;if(l<=p[t] && p[t]<=r)out(a[p[t]]),in(x[t]);
			swap(x[t],a[p[t]]);
		}
		for(j=0;c[j];++j);ans[q[i].id]=j;
	}
	for(i=1;i<=c1;++i)cout<<ans[i]<<'\n';
	return 0;
}
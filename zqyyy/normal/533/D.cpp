#include <bits/stdc++.h>
using namespace std;
#define pb push_back
inline int read(){
    int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e5+5;
int n,a[N],d[N],f[N],g[N];
int tp,stk[N];
vector<int>v;
struct BIT{
	int c[N];
#define lowbit(x) ((x)&-(x))
	inline void add(int p,int x){
		p=lower_bound(v.begin(),v.end(),p)-v.begin()+1;
		for(;p;p-=lowbit(p))c[p]=max(c[p],x);
	}
	inline int ask(int p){
		p=lower_bound(v.begin(),v.end(),p)-v.begin()+1;
		int maxn=-2147483648;
		for(;p<=n;p+=lowbit(p))maxn=max(maxn,c[p]);
		return maxn;
	}
}t;
int main(){
	n=read();
	for(int i=0;i<=n+1;i++)a[i]=read();
	for(int i=1;i<=n;i++)d[i]=read();
	for(int i=1;i<=n;i++){
		while(tp && a[i]-a[f[stk[tp]]]>2*d[stk[tp]])--tp;
		f[i]=stk[tp];
		while(tp && 2ll*d[stk[tp]]+a[f[stk[tp]]]<=2ll*d[i]+a[f[i]])--tp;
		stk[++tp]=i;
	}
	stk[tp=0]=n+1;
	for(int i=n;i;i--){
		while(tp && a[g[stk[tp]]]-a[i]>2*d[stk[tp]])--tp;
		g[i]=stk[tp];
		while(tp && a[g[stk[tp]]]-2*d[stk[tp]]>=a[g[i]]-2*d[i])--tp;
		stk[++tp]=i;
	}
	for(int i=1;i<=n;i++)
		if(a[g[i]]-a[f[i]]<=2*d[i])
			puts("0"),exit(0);
	int ans=a[n+1];
	for(int i=1;i<=n;i++){
		ans=min(ans,a[g[i]]-a[f[i]]);
		if(a[i]-a[f[i]]<2*d[i])v.push_back(a[f[i]]+2*d[i]);
	}
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	for(int i=1;i<=n;i++){
		if(f[i]<1 && a[g[i]]-a[i]<2*d[i])ans=min(ans,a[i]);
		if(g[i]>n && a[i]-a[f[i]]<2*d[i])ans=min(ans,a[n+1]-a[i]);
		if(a[g[i]]-a[i]<2*d[i])ans=min(ans,a[i]-t.ask(a[g[i]]-2*d[i]));
		if(a[i]-a[f[i]]<2*d[i])t.add(a[f[i]]+2*d[i],a[i]);
	}
	return cout<<0.5*ans,0;
}
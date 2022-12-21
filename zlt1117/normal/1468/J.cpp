#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int fa[N],n,m,k;
struct aa
{
	int u,v,w;
	bool operator <(const aa &b)const{return w<b.w;}
}e[N];
int read()
{
	int res=0,fl=0; char a=getchar();
	while(a<'0'||a>'9') fl|=a=='-',a=getchar();
	while(a>='0'&&a<='9') res=res*10+a-'0',a=getchar();
	return fl? -res:res; 
}
int getf(int x) {return fa[x]==x? x:fa[x]=getf(fa[x]);}
signed main()
{
	int i,j,t=read();
	while(t--)
	{
		n=read(),m=read(),k=read();
		int ans=0,lp=0,lg=0;
		for(i=1;i<=n;i++) fa[i]=i;
		for(i=1;i<=m;i++)
			e[i].u=read(),e[i].v=read(),e[i].w=read();
		sort(e+1,e+m+1);
		for(i=1;i<=m;i++)
			if(getf(e[i].u)!=getf(e[i].v)) fa[getf(e[i].u)]=getf(e[i].v),lp=e[i].w,lg+=max(0ll,e[i].w-k);
		ans=lg;
		if(lp<k)
			for(ans=1e9,i=1;i<=m;i++) if(e[i].u!=e[i].v) ans=min(ans,abs(e[i].w-k));
		cout<<ans<<'\n';
	}
	return 0;
}
/*
1
3 3 1
1 2 2
1 3 3
2 3 4

*/
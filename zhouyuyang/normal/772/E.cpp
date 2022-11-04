#include<bits/stdc++.h>
#define N 2005
using namespace std;
int ls[N],rs[N],fa[N],sz[N],z[N];
int id,n,m,rt,mn,Sz;
char s[10];
void getrt(int x,int F){
	sz[x]=1;
	int mx=0;
	if (ls[x]&&ls[x]!=F&&!z[ls[x]]){
		getrt(ls[x],x);
		sz[x]+=sz[ls[x]];
		if (sz[ls[x]]>mx) mx=sz[ls[x]];
	}
	if (rs[x]&&rs[x]!=F&&!z[rs[x]]){
		getrt(rs[x],x);
		sz[x]+=sz[rs[x]];
		if (sz[rs[x]]>mx) mx=sz[rs[x]];
	}
	if (fa[x]&&fa[x]!=F&&!z[fa[x]]){
		getrt(fa[x],x);
		sz[x]+=sz[fa[x]];
		if (sz[fa[x]]>mx) mx=sz[fa[x]];
	}
	if (Sz-sz[x]>mx)
		mx=Sz-sz[x];
	if (mx<mn||(mx==mn&&x>rt))
		mn=mx,rt=x;
}
int getsz(int x,int F){
	sz[x]=1;
	if (ls[x]&&ls[x]!=F&&!z[ls[x]])
		sz[x]+=getsz(ls[x],x);
	if (rs[x]&&rs[x]!=F&&!z[rs[x]])
		sz[x]+=getsz(rs[x],x);
	if (fa[x]&&fa[x]!=F&&!z[fa[x]])
		sz[x]+=getsz(fa[x],x);
	return sz[x];
}
int getleaf(int x){
	return x<=n?x:getleaf(ls[x]);
}
void dfs(int x){
	z[x]=1;
	if (x<=n){
		m++;
		if (ls[fa[x]]==x) ls[fa[x]]=m;
		else rs[fa[x]]=m;
		fa[m]=fa[x];
		fa[x]=m; fa[id]=m;
		ls[m]=x; rs[m]=id;
		return;
	}
	int a1=getleaf(ls[x]);
	int a2=getleaf(rs[x]);
	printf("%d %d %d\n",a1,a2,id);
	fflush(stdout);
	scanf("%s",s);
	char ch=s[0];
	if (ch=='X'){
		if (z[fa[x]]||!fa[x]){
			m++;
			if (fa[x]){
				if (ls[fa[x]]==x) ls[fa[x]]=m;
				else rs[fa[x]]=m;
				fa[m]=fa[x];
			}
			fa[x]=m; fa[id]=m;
			ls[m]=x; rs[m]=id;
			return;
		}
		Sz=getsz(fa[x],0); mn=1e9;
		getrt(fa[x],0); dfs(rt);
	}
	if (ch=='Y'){
		if (z[rs[x]]){
			m++;
			fa[rs[x]]=fa[id]=m;
			ls[m]=rs[x]; rs[m]=id;
			rs[x]=m; fa[m]=x;
			return;
		}
		Sz=getsz(rs[x],0); mn=1e9;
		getrt(rs[x],0); dfs(rt);
	}
	if (ch=='Z'){
		if (z[ls[x]]){
			m++;
			fa[ls[x]]=fa[id]=m;
			ls[m]=ls[x]; rs[m]=id;
			ls[x]=m; fa[m]=x;
			return;
		}
		Sz=getsz(ls[x],0); mn=1e9;
		getrt(ls[x],0); dfs(rt);
	}
}
int main(){
	scanf("%d",&n);
	m=n; m++;
	ls[m]=1; rs[m]=2;
	fa[1]=fa[2]=m;
	for (id=3;id<=n;id++){
		memset(z,0,sizeof(z));
		Sz=2*id-3; mn=1e9;
		getrt(1,0); dfs(rt);
	}
	puts("-1");
	for (int i=1;i<=m;i++)
		printf("%d ",fa[i]?fa[i]:-1);
}
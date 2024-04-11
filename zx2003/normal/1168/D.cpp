#include<bits/stdc++.h>
using namespace std;
const int N=150005,A=26;
int n,q,i,j,p[N],bel[N],ch[N],chh[N][2],dep[N],v;
char c[N],cc;
inline char gc(){char c=' ';for(;isspace(c);)c=getchar();return c;}
struct info{
int a[A],x;
inline void add(char c,int v){(c=='?'?x:a[c-'a'])+=v;}
inline void out(){int ass=0,i;for(i=0;i<A;++i)ass+=(i+1)*(a[i]+x);printf("Shi %d\n",ass);}
inline info operator+=(const info&rhs){for(int i=0;i<A;++i)a[i]+=rhs.a[i];x+=rhs.x;}
}f[N],a[N];
inline bool merge(const info&a,const info&b,info&ass){
	int i,sa=0,sb=0,z;
	for(i=0;i<A;++i)z=a.a[i]-b.a[i],(z>0?sb:sa)+=abs(z);
	if(sa>a.x || sb>b.x)return 0;
	for(i=0;i<A;++i)ass.a[i]=max(a.a[i],b.a[i]);ass.x=a.x-sa;
	return 1;
}
bool can[N];
inline void upd(int x){
	int lc=chh[x][0],rc=chh[x][1];
	if(x==1 && !rc){if(can[x]=can[lc])f[x]=f[lc],f[x]+=a[lc];return;}
	if(!can[lc] || !can[rc]){can[x]=0;return;}
	info L=f[lc],R=f[rc];L+=a[lc];R+=a[rc];
	can[x]=merge(L,R,f[x]);
}
int main(){
	scanf("%d%d",&n,&q);
	for(i=2;i<=n;++i)scanf("%d",p+i),c[i]=gc(),++ch[p[i]],dep[i]=dep[p[i]]+1;
	set<int>sS;for(i=1;i<=n;++i)if(!ch[i])sS.insert(dep[i]);if(sS.size()>1){for(;q--;)puts("Fou");return 0;}
	for(i=n;i>1;--i)if(!bel[i]){
		bel[i]=i;
		for(j=p[i];j>1 && ch[j]==1;j=p[j])bel[j]=i;p[i]=j;
	}
	memset(ch,0,sizeof ch);
	for(i=2;i<=n;++i){
		a[bel[i]].add(c[i],1);
		if(bel[i]==i)chh[p[i]][ch[p[i]]++]=i;
	}
	for(i=n;i;--i)if(!ch[i])can[i]=1;else upd(i);
	for(;q--;){
		scanf("%d",&v);cc=gc();
		a[bel[v]].add(c[v],-1);a[bel[v]].add(c[v]=cc,1);
		for(v=p[bel[v]];v;v=p[v])upd(v);
		if(!can[1])puts("Fou");else f[1].out();
	}
	return 0;
}
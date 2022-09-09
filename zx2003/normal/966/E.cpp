#include<bits/stdc++.h>
using namespace std;
char ibuf[1<<22],*ih=ibuf,obuf[1<<21],*oh=obuf;
inline void read(int&x){
	int f=1;
	for(;!isdigit(*ih);++ih)if(*ih=='-')f=-1;
	for(x=0;isdigit(*ih);x=x*10+*ih++-48);x*=f;
}
inline void write(int x){
	if(x==0)return void(*oh++='0');
	static int buf[30],xb;
	for(xb=0;x;x/=10)buf[++xb]=x%10;
	for(;xb;)*oh++=buf[xb--]|48;
}
const int N=100005,inf=1<<30;
int n,m,p[N],i,t[N],q;
vector<int>e[N];
int sz[N],dad[N],dep[N],ma[N],top[N],id[N],dfn[N],xb;
void dfs1(int x,int fa){
	sz[x]=1;dep[x]=dep[fa]+1;dad[x]=fa;
	for(int i=0;i<e[x].size();++i)if(e[x][i]!=fa){
		dfs1(e[x][i],x);sz[x]+=sz[e[x][i]];
		if(sz[e[x][i]]>sz[ma[x]])ma[x]=e[x][i];
	}
}
void dfs2(int x,int fa){
	dfn[id[x]=++xb]=x;
	if(ma[x]){top[ma[x]]=top[x];dfs2(ma[x],x);}
	for(int i=0;i<e[x].size();++i)if(e[x][i]!=fa && e[x][i]!=ma[x]){
		top[e[x][i]]=e[x][i];dfs2(e[x][i],x);
	}
}
int szi,bs,num[N];
int Ans;
bool cmp(int x,int y){
	return t[x]<t[y];
}
struct block{
	static const int N=120;
	int v[N],lst[N],nxt[N],u[N],tag,pos,be,en,len;
	inline void ini(){
		int i;
		for(i=be;i<=en;++i)u[i-be+1]=dfn[i];
		sort(u+1,u+len+1,cmp);
		for(i=1;i<=len;++i)v[i]=t[u[i]];
		v[0]=-inf;
		recalc();
	}
	inline void recalc(){
		int i,j;
		j=0;
		for(i=1;i<=len;++i){
			lst[i]=j;
			if(v[i]!=v[i+1])j=i;
		}
		j=len;
		for(i=len;i>=0;--i){
			nxt[i]=j;
			if(v[i]!=v[i+1])j=i;
		}
	}
	inline void mdy(int l,int r,int z){
		Ans-=pos;
		static int u1[N],v1[N],u2[N],v2[N];
		int i,j,xb1=0,xb2=0,xb=0;
		for(i=1;i<=len;++i)
			if(l<=id[u[i]] && id[u[i]]<=r)u1[++xb1]=u[i],v1[xb1]=v[i]+z;
				else u2[++xb2]=u[i],v2[xb2]=v[i];
		for(i=j=1;i<=xb1 && j<=xb2;)
			if(v1[i]<v2[j])u[++xb]=u1[i],v[xb]=v1[i],++i;
				else u[++xb]=u2[j],v[xb]=v2[j],++j;
		for(;i<=xb1;++i)u[++xb]=u1[i],v[xb]=v1[i];
		for(;j<=xb2;++j)u[++xb]=u2[j],v[xb]=v2[j];
		for(pos=1;pos<=len && v[pos]<tag;++pos);
		recalc();
		Ans+=--pos;
	}
	inline void add(int z){
		Ans-=pos;
		tag+=z;
		if(z>0 && v[nxt[pos]]<tag)pos=nxt[pos];
		if(z<0 && v[pos]>=tag)pos=lst[pos];
		Ans+=pos;
	}
}b[1100];
inline void mdy(int l,int r,int v){
	int x=num[l],y=num[r],i;
	if(x==y){
		b[x].mdy(l,r,v);
	}else{
		b[x].mdy(l,b[x].en,v);
		b[y].mdy(b[y].be,r,v);
		for(i=x+1;i<y;++i)b[i].add(-v);
	}
}
inline void add(int x,int v){
	x=dad[x];
	for(;x;x=dad[top[x]])
		mdy(id[top[x]],id[x],v);
}
int main(){
	fread(ibuf,1,1<<22,stdin);
	read(n),read(m);
	for(i=2;i<=n;++i)read(p[i]),e[p[i]].push_back(i);
	top[1]=1;dfs1(1,0);dfs2(1,0);
	szi=sqrt(n)/3;if(szi<1)szi=1;
	for(i=1;i<=n;++i)
		num[i]=(i-1)/szi+1,read(t[i]);
	bs=num[n];
	b[1].be=1,b[1].en=szi;
	for(i=2;i<=bs;++i)b[i].be=b[i-1].be+szi,b[i].en=b[i-1].en+szi;
	b[bs].en=n;
	for(i=1;i<=bs;++i)b[i].len=b[i].en-b[i].be+1,b[i].ini();
	while(m--){
		read(q);
		if(q>0){
			add(q,-1);
			b[num[id[q]]].mdy(id[q],id[q],inf);
		}else{
			add(-q,1);
			b[num[id[-q]]].mdy(id[-q],id[-q],-inf);
		}
		write(Ans);*oh++=' ';
	}
	return fwrite(obuf,1,oh-obuf,stdout),0;
}
#include<bits/stdc++.h>
using namespace std;
char ibuf[1<<25],*ih=ibuf,obuf[1<<25],*oh=obuf;
inline void upi(int&a,const int&b){a>b?a=b:0;}
inline void upa(int&a,const int&b){a<b?a=b:0;}
template<typename T>inline void read(T&x){
	int f=1;
	for(;!isdigit(*ih);++ih)if(*ih=='-')f=-1;
	for(x=0;isdigit(*ih);x=x*10+*ih++-48);x*=f;
}
template<typename T>inline void write(T x){
	if(x<0)*oh++='-',x=-x;
	if(x==0)return void(*oh++='0');
	static int buf[30],xb; 
	for(xb=0;x;x/=10)buf[++xb]=x%10;
	for(;xb;)*oh++=buf[xb--]|48;
}
const int N=300005;
int n,q,x[N],y[N],c[N],co,xi[N],yu[N],yd[N],i,j,a[N],d[N],sz[N],szi[N],f[N],e[N][5],u,v,rt,sum;
int be[N],en[N],o;
vector<int>te[N],qu[N];
bool vi[N];
void dfs(int x,int fa){
	szi[x]=f[x]=sz[x];
	for(int i=0;i<te[x].size();++i)
		if(!vi[te[x][i]] && te[x][i]!=fa)dfs(te[x][i],x),szi[x]+=szi[te[x][i]],upa(f[x],szi[te[x][i]]);
	upa(f[x],sum-szi[x]);if(f[x]<f[rt])rt=x;
}
int t,w,dis[N],h[N],q1[N],w1,q2[N],w2,ti[N],qx[N],qy[N],qid[N],ans[N];
inline bool cmp(int a,int b){return x[a]<x[b] || (x[a]==x[b] && y[a]<y[b]);}
inline bool cmp1(int a,int b){return ti[a]<ti[b];}
map<pair<int,int>,int>mp;
int bi1[N],bi2[N],le;
inline void add(int*a,int x,int v){for(;x<=le;x+=x&-x)upi(a[x],v);}
inline int query(int*a,int x){int ans=1<<30;for(;x;x-=x&-x)upi(ans,a[x]);return ans;}
void solve(int x){
	vi[x]=1;int i=0,j,t=0,w=0,u,v;w1=w2=0;static int q[N];
	for(;i<te[x].size();++i)if(!vi[te[x][i]] && szi[te[x][i]]>szi[x])szi[te[x][i]]=sum-szi[x];
	for(i=be[x];i<=en[x];++i)q[++w]=a[i],dis[a[i]]=0,h[a[i]]=y[a[i]];
	for(;t<w;){
		u=q[++t];
		for(i=0;i<d[u];++i){
			v=e[u][i];
			if(!h[v] && !vi[c[v]])dis[v]=dis[u]+1,h[v]=h[u],q[++w]=v;
		}
	}
	for(i=1;i<=w;++i){
		if(ti[j=q[i]])q1[++w1]=q[i];
		if(!qu[j].empty())memcpy(q2+w2+1,&qu[j][0],qu[j].size()<<2),w2+=qu[j].size();
	}
	sort(q1+1,q1+w1+1,cmp1);sort(q2+1,q2+w2+1);le=yu[x]-yd[x]+1;
	memset(bi1+1,100,le<<2);memset(bi2+1,100,le<<2);
	for(i=j=1;i<=w2;++i){
		for(;j<=w1 && ti[q1[j]]<=q2[i];++j){
			add(bi1,yu[x]+1-h[q1[j]],dis[q1[j]]+h[q1[j]]);
			add(bi2,h[q1[j]]-yd[x]+1,dis[q1[j]]-h[q1[j]]);
		}int z=qid[q2[i]];
		upi(ans[q2[i]],query(bi1,yu[x]+1-h[z])+dis[z]-h[z]);
		upi(ans[q2[i]],query(bi2,h[z]-yd[x]+1)+dis[z]+h[z]);
	}
	for(i=1;i<=w;++i)h[q[i]]=0;
	for(i=0;i<te[x].size();++i)if(!vi[te[x][i]])sum=szi[te[x][i]],dfs(te[x][i],rt=0),solve(rt);
}
int main(){
	//freopen("1.txt","r",stdin);
	fread(ibuf,1,1<<25,stdin);
	read(n);
	for(i=1;i<=n;++i)read(x[i]),read(y[i]),a[i]=i,mp[make_pair(x[i],y[i])]=i;
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;++i){
		for(xi[++co]=x[a[i]],yd[co]=y[a[be[co]=i]];;++i){
			for(;x[a[j+1]]<x[a[i]] && (x[a[j]]<x[a[i]]-1 || y[a[j]]<y[a[i]]);++j);
			if(x[a[i-1]]==x[a[i]] && y[a[i-1]]+1==y[a[i]]){
				u=a[i-1],v=a[i];
				e[u][d[u]++]=v,e[v][d[v]++]=u;
			}
			c[a[i]]=co;
			if(x[a[j]]+1==x[a[i]] && y[a[j]]==y[a[i]]){
				u=a[j],v=a[i];
				if(te[c[v]].empty() || te[c[v]].back()!=c[u])
					te[c[u]].push_back(c[v]),te[c[v]].push_back(c[u]);
				e[u][d[u]++]=v,e[v][d[v]++]=u;
			}
			if(x[a[i+1]]!=x[a[i]] || y[a[i+1]]!=y[a[i]]+1)break;
		}
		yu[co]=y[a[en[co]=i]];sz[co]=yu[co]-yd[co]+1;
	}memset(ans,-1,sizeof ans);read(q);
	for(i=1;i<=q;++i){
		read(o),read(qx[i]),read(qy[i]);qid[i]=j=mp[make_pair(qx[i],qy[i])];
		if(o==1)ti[j]=i;
			else qu[j].push_back(i),ans[i]=1<<30;
	}
	sum=n;f[rt=0]=1<<30;dfs(1,0);
	solve(rt);
	for(i=1;i<=q;++i)if(~ans[i])write(ans[i]>n?-1:ans[i]),*oh++='\n';
	return fwrite(obuf,1,oh-obuf,stdout),0;
}
//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
#define mk make_pair
#define iter set<int>::iterator
//#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
const int maxn=2e5+5;
char s[maxn],t[maxn];
int len[maxn],son[maxn][26],fa[maxn],tot=1,last=1,n,Q,l,r;
int pos[maxn];
inline void insert(int c)
{
	int np=++tot,p=last;
	len[np]=len[p]+1;last=np;
	while(p&&!son[p][c])son[p][c]=np,p=fa[p];
	if(!p)fa[np]=1;
	else
	{
		int q=son[p][c];
		if(len[q]==len[p]+1)fa[np]=q;
		else
		{
			int nq=++tot;len[nq]=len[p]+1;
			fa[nq]=fa[q],fa[q]=fa[np]=nq;
			memcpy(son[nq],son[q],sizeof(son[q]));
			while(p&&son[p][c]==q)son[p][c]=nq,p=fa[p];
		}
	}
}
int rt[maxn];
struct segmentree
{
	static const int maxn=4e6+5;
	int ls[maxn],rs[maxn],sum[maxn],tot;
	inline void pushup(int u){sum[u]=sum[ls[u]]+sum[rs[u]];}
	inline void update(int &u,int l,int r,int x,int v)
	{
		if(!u)u=++tot;
		if(l==r)return sum[u]+=v,void();
		int mid=(l+r)>>1;
		if(x<=mid)update(ls[u],l,mid,x,v);
		else update(rs[u],mid+1,r,x,v);
		pushup(u);
	} 
	inline int merge(int u,int v,int l,int r)
	{
		if(!u||!v)return u+v;
		ls[++tot]=ls[u],rs[tot]=rs[u];u=tot;
		if(l==r)return sum[u]+=sum[v],u;
		int mid=(l+r)>>1;
		ls[u]=merge(ls[u],ls[v],l,mid);
		rs[u]=merge(rs[u],rs[v],mid+1,r);
		pushup(u);return u;
	}
	inline int query(int u,int l,int r,int x,int y)
	{
		if(!u)return 0;
		if(x<=l&&y>=r)return sum[u];
		int mid=(l+r)>>1,ret=0;
		if(x<=mid)ret=query(ls[u],l,mid,x,y);
		if(y>mid)ret+=query(rs[u],mid+1,r,x,y);
		return ret;
	}
}tree; 
inline void input()
{
	scanf("%s",s+1);n=strlen(s+1);
	FOR(i,1,n)insert(s[i]-'a'),pos[i]=last;
	FOR(i,1,n)tree.update(rt[pos[i]],1,n,i,1);
	Q=gi();
}
vector<int>e[maxn];
inline void dfs(int u)
{
	for(int v:e[u])
	{
		dfs(v); 
		rt[u]=tree.merge(rt[u],rt[v],1,n);
	}
}
inline bool check(int u,int l,int r){return u&&l<=r&&tree.query(rt[u],1,n,l,r)>0;}
vector<char>answer;
int lent;
inline bool dfs(int u,int l,int r,int x)
{
	if(x==lent+1)
	{
		FOR(i,0,25)if(check(son[u][i],l+x-1,r))return answer.pb('a'+i),true;
		return false;
	}
	if(!son[u][t[x]-'a'])
	{
		FOR(i,t[x]-'a'+1,25)if(check(son[u][i],l+x-1,r))return answer.pb('a'+i),true;
		return false;
	}
	answer.pb(t[x]);
	if(!dfs(son[u][t[x]-'a'],l,r,x+1))
	{
		answer.pop_back();
		FOR(i,t[x]-'a'+1,25)if(check(son[u][i],l+x-1,r))return answer.pb('a'+i),true;
		return false;
	}
	return true;
}
inline void solve()
{
	FOR(i,2,tot)e[fa[i]].pb(i);
	dfs(1);
	FOR(j,1,Q)
	{
		l=gi(),r=gi();scanf("%s",t+1);
		lent=strlen(t+1);
		answer.clear();
		if(lent!=0&&dfs(1,l,r,1)){for(char c:answer)putchar(c);puts("");}
		else puts("-1");
	}
}
int main()
{
	input();
	solve();
	return 0;
}
/*
aaaaaaaaaa
1
1 10 

*/
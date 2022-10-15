#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=3e6+5;
int n,q;
char s[maxn];
int a[maxn];
int deg[maxn];
struct segment
{
	#define L(u) u<<1
	#define R(u) u<<1|1
	struct node{int mi,num;}t[maxn<<2];
	void update(int u)
	{
		t[u].mi=min(t[L(u)].mi,t[R(u)].mi);t[u].num=0;
		if(t[L(u)].mi==t[u].mi)t[u].num+=t[L(u)].num;
		if(t[R(u)].mi==t[u].mi)t[u].num+=t[R(u)].num;
	}
	void build(int u=1,int l=1,int r=n)
	{
		if(l==r){t[u].mi=a[l];t[u].num=1;return;}
		int mid=(l+r)>>1;
		build(L(u),l,mid);build(R(u),mid+1,r);
		update(u);
	}
	pair<int,int>query(int nl,int nr,int u=1,int l=1,int r=n)
	{
		if(l>=nl&&r<=nr)return {t[u].num,t[u].mi};
		int mid=(l+r)>>1;
		if(mid>=nr)return query(nl,nr,L(u),l,mid);
		if(mid+1<=nl)return query(nl,nr,R(u),mid+1,r);
		pair<int,int>lans=query(nl,nr,L(u),l,mid),rans=query(nl,nr,R(u),mid+1,r);
		if(lans.second!=rans.second)return lans.second<rans.second?lans:rans;
		return {lans.first+rans.first,lans.second};
	}
	void del(int p,int u=1,int l=1,int r=n)
	{
		if(l==r){t[u].mi=1e9;t[u].num=0;return;}
		int mid=(l+r)>>1;
		if(mid>=p)del(p,L(u),l,mid);
		else del(p,R(u),mid+1,r);
		update(u);
	}
	#undef L
	#undef R
}tr1;
struct fenwick
{
	ll b[maxn];
	void change(int p,ll x){for(int i=p;i<=n;i+=i&(-i))b[i]+=x;}
	ll query(int p){ll ret=0;for(int i=p;i;i-=i&(-i))ret+=b[i];return ret;}
}tr2;
int pre[maxn],pa[maxn];
int main()
{
	n=read();q=read();
	scanf("%s",s+1);
	stack<int>sta;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')sta.push(i);
		else
		{
			if(!sta.empty()&&s[sta.top()]=='(')
			{
				tr2.change(i,(ll)deg[sta.top()]*(deg[sta.top()]-1)/2+1);
				pa[i]=sta.top();pa[sta.top()]=i;
				int now=sta.top();
				sta.pop();
				if(!sta.empty())deg[sta.top()]++,pre[now]=sta.top();
			}
			else sta.push(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')a[i]=a[i-1]+1;
		else a[i]=a[i-1]-1;
	}
	tr1.build();
	while(q--)
	{
		int opt=read(),l=read(),r=read();
		if(opt==2)
		{
			int son=tr1.query(l,r).first;
			ll ret=(ll)son*(son-1)/2+tr2.query(r)-tr2.query(l-1);
			printf("%lld\n",ret);
		}
		else
		{
			tr1.del(l);tr1.del(r);
			if(pre[l])
			{
				tr2.change(r,-1);
				if(pa[pre[l]])
				{
					tr2.change(pa[pre[l]],-(ll)deg[pre[l]]*(deg[pre[l]]-1)/2);
					deg[pre[l]]--;
					tr2.change(pa[pre[l]],(ll)deg[pre[l]]*(deg[pre[l]]-1)/2);
				}
			}
		}
	}
	return 0;
}
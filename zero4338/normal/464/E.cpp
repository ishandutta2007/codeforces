#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
bool deb;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e5+5,mod=1e9+7,maxm=2e5+30;
int n,m,s,t;
int pow2[maxm];
struct per_seg
{
	#define L(u) t[u].ls
	#define R(u) t[u].rs
	struct node{int val,tag,ls,rs;}t[maxn*300];int cnt;
	void update(int u){t[u].val=(t[L(u)].val+t[R(u)].val)%mod;}
	int clone(int u){t[++cnt]=t[u];return cnt;}
	void pushdown(int u,int l,int r)
	{
		if(t[u].tag)
		{
			L(u)=clone(L(u));
			R(u)=clone(R(u));
			if(t[u].tag==1)
			{
				t[L(u)].tag=t[R(u)].tag=1;
				t[L(u)].val=t[R(u)].val=0;
			}
			if(t[u].tag==2)
			{
				t[L(u)].tag=t[R(u)].tag=2;
				int mid=(l+r)>>1;
				t[L(u)].val=(pow2[mid+1]-pow2[l]+mod)%mod;
				t[R(u)].val=(pow2[r+1]-pow2[mid+1]+mod)%mod;
			}
			t[u].tag=0;
		}
	}
	int change(int u,int nl,int nr,int x,int l=0,int r=maxm)
	{
		u=clone(u);
		if(l>=nl&&r<=nr)
		{
			if(x==0){t[u].tag=1;t[u].val=0;}
			else{t[u].tag=2;t[u].val=(pow2[r+1]-pow2[l]+mod)%mod;}
			return u;
		}
		pushdown(u,l,r);
		int mid=(l+r)>>1;
		if(mid>=nl)L(u)=change(L(u),nl,nr,x,l,mid);
		if(mid+1<=nr)R(u)=change(R(u),nl,nr,x,mid+1,r);
		update(u);return u;
	}
	int findpre(int u,int pos,int l=0,int r=maxm)
	{
		if(l==r&&r<=pos)return t[u].val>0;
		pushdown(u,l,r);
		int mid=(l+r)>>1;
		if(l>pos)
		{
			if(l==r)return t[u].val>0;
			if(t[L(u)].val==(pow2[mid+1]-pow2[l]+mod)%mod)return mid-l+1+findpre(R(u),pos,mid+1,r);
			return findpre(L(u),pos,l,mid);
		}
		if(pos>mid)return findpre(R(u),pos,mid+1,r);
		int lans=findpre(L(u),pos,l,mid);
		if(lans==mid-pos+1)return lans+findpre(R(u),pos,mid+1,r);
		return lans;
	}
	bool comp(int u1,int u2,int l=0,int r=maxm)
	{
		if(l==r)return t[u1].val<t[u2].val;
		pushdown(u1,l,r);pushdown(u2,l,r);
		int mid=(l+r)>>1;
		if(t[R(u1)].val!=t[R(u2)].val)return comp(R(u1),R(u2),mid+1,r);
		return comp(L(u1),L(u2),l,mid);
	}
	#undef L
	#undef R
}tr;
struct bignum
{
	int rt;
	void assign(int val){rt=tr.change(0,0,maxm,0);}
	bignum add(int pos)
	{
		bignum ret;
		int pre=tr.findpre(rt,pos);
		ret.rt=rt;
		ret.rt=tr.change(ret.rt,pos,pos+pre,0);
		ret.rt=tr.change(ret.rt,pos+pre,pos+pre,1);
		return ret;
	}
	bool operator >(const bignum &x)const
	{
		if(!x.rt)return 0;
		if(!rt)return 1;
		return tr.comp(x.rt,rt);
	}
	int getval(){return tr.t[rt].val;}
};
struct graph
{
	vector<pair<int,int>>e[maxn];
	void add(int x,int y,int z){e[x].push_back({y,z});e[y].push_back({x,z});}
	struct node{int x;bignum d;bool operator >(const node &a)const{return d>a.d;}};
	priority_queue<node,vector<node>,greater<node>>q;
	bignum dis[maxn];int pre[maxn];
	void dijkstra(int u)
	{
		dis[u].assign(0);q.push({u,dis[u]});
		while(!q.empty())
		{
			node now=q.top();q.pop();
			if(now.x==t)return;
			if(now.d>dis[now.x])continue;
			for(auto &i:e[now.x])
			{
				if(dis[now.x]>dis[i.first])continue;
				bignum tmp=now.d.add(i.second);
				if(dis[i.first]>tmp)
				{
					dis[i.first]=tmp;pre[i.first]=now.x;
					q.push({i.first,dis[i.first]});
				}
			}
		}
	}
	vector<int>path;
	void getpath(int u)
	{
		if(pre[u])getpath(pre[u]);path.push_back(u);
	}
}o;
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read(),z=read();
		o.add(x,y,z);
	}
	s=read();t=read();
	pow2[0]=1;
	for(int i=1;i<=2e5+20;i++)pow2[i]=pow2[i-1]*2%mod;
	o.dijkstra(s);
	if(!o.dis[t].rt)puts("-1");
	else
	{
		printf("%d\n",o.dis[t].getval());
		o.getpath(t);
		printf("%lu\n",o.path.size());
		for(int &i:o.path)printf("%d ",i);putchar('\n');
	}
	return 0;
}
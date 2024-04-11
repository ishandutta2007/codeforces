#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define N 800100
using namespace std;

int n,m,num[N],b[N],ans[N],dp[N],cnt[N],bb,cb,mx[N],len;
bool gj[N],ok[N],debug;
struct Que
{
	int u,v,id;
	bool operator < (const Que &t) const
	{
		return u<t.u;
	}
}que[N];
struct Xds
{
	int tt;
	struct Node
	{
		int ls,rs,mx;
	}node[N<<1];
	Xds(){tt=1;}
	void build(int now,int l,int r)
	{
		if(l==r) return;
		int mid=((l+r)>>1);
		node[now].ls=++tt;
		build(tt,l,mid);
		node[now].rs=++tt;
		build(tt,mid+1,r);
	}
	void add(int now,int l,int r,int u,int v)
	{
//		if(debug) cout<<l<<" "<<r<<" "<<u<<" "<<v<<endl;
//		if(debug)
//			debug=1;
		if(l==r)
		{
			node[now].mx=max(node[now].mx,v);
			return;
		}
		int mid=((l+r)>>1);
		if(u<=mid) add(node[now].ls,l,mid,u,v);
		else add(node[now].rs,mid+1,r,u,v);
		node[now].mx=max(node[node[now].ls].mx,node[node[now].rs].mx);
	}
	int ask(int now,int l,int r,int u,int v)
	{
		if(u>v) return 0;
		if(u==l&&v==r) return node[now].mx;
		int res=0,mid=((l+r)>>1);
		if(u<=mid) res=max(res,ask(node[now].ls,l,mid,u,min(v,mid)));
		if(mid<v) res=max(res,ask(node[now].rs,mid+1,r,max(u,mid+1),v));
		return res;
	}
};
Xds A,B;
map<int,int>mm;
vector<int>ask;

int main()
{
//	freopen("2.txt","r",stdin);
//	freopen("3.txt","w",stdout);
	int i,j,t;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		b[++bb]=num[i];
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&que[i].u,&que[i].v);
		que[i].id=i;
		b[++bb]=que[i].v;
	}
	sort(b+1,b+bb+1);
	sort(que+1,que+m+1);
	for(i=1;i<=bb;i++)
	{
		if(i==1||b[i]!=b[i-1])
		{
			b[++cb]=b[i];
			mm[b[i]]=cb;
		}
	}
	for(i=1;i<=n;i++) num[i]=mm[num[i]];
	for(i=1;i<=m;i++) que[i].v=mm[que[i].v];
	A.build(1,1,cb),B.build(1,1,cb);
	
	for(i=j=1;i<=n;i++)
	{
		for(;j<=m&&que[j].u==i;j++)
		{
			ans[que[j].id]=A.ask(1,1,cb,1,que[j].v-1)+1;
			ask.push_back(j);
		}
		dp[i]=t=A.ask(1,1,cb,1,num[i]-1)+1;
		len=max(len,dp[i]);
//		cout<<' '<<num[i]<<" "<<t<<endl;
		A.add(1,1,cb,num[i],t);
//		cerr<<dp[i]<<" ";
	}
	reverse(ask.begin(),ask.end());
	
//	for(i=1;i<=n;i++) cerr<<num[i]<<" ";cerr<<endl;
	for(i=n;i>=1;i--) if(dp[i]==len || cnt[dp[i]+1]&&num[i]<mx[dp[i]+1]) mx[dp[i]]=max(mx[dp[i]],num[i]),cnt[dp[i]]++,ok[i]=1;
	for(i=1;i<=n;i++) if(ok[i]&&cnt[dp[i]]==1) gj[i]=1;
//	cerr<<len<<endl;
//	for(i=1;i<=n;i++) cerr<<gj[i]<<" ";
	
	debug=1;
	for(j=0,i=n;i>=1;i--)
	{
		for(;j<ask.size()&&que[ask[j]].u==i;j++)
		{
			ans[que[ask[j]].id]+=B.ask(1,1,cb,que[ask[j]].v+1,cb);
			ans[que[ask[j]].id]=max(ans[que[ask[j]].id],len-gj[que[ask[j]].u]);
		}
		t=B.ask(1,1,cb,num[i]+1,cb)+1;
//		cout<<"   "<<num[i]+1<<" "<<cb<<" "<<t<<endl;
//		cout<<" "<<num[i]<<" "<<t<<endl;
		B.add(1,1,cb,num[i],t);
	}
	
	for(i=1;i<=m;i++) printf("%d\n",ans[i]);
}
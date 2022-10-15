#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=(1<<12)+1,maxm=2.2e6,maxq=(1<<16)+1;
int n,q;
int a[maxn],ans[maxq];
int cnt;pair<int,int>fr[maxm];
class segment
{
	#define L(u) u<<1
	#define R(u) u<<1|1
	private:
	struct node
	{
		vector<int>exi;
		map<pair<int,int>,int>mem;
	}t[maxn<<2];
	public:
	void build(int u=1,int l=1,int r=n)
	{
		if(l==r)
		{
			t[u].exi={a[l]};
			t[u].mem[{a[l],a[l]}]=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(L(u),l,mid);
		build(R(u),mid+1,r);
		t[u].exi.resize(r-l+1);
		merge(t[L(u)].exi.begin(),t[L(u)].exi.end(),t[R(u)].exi.begin(),t[R(u)].exi.end(),t[u].exi.begin());
	}
	int query(int nl,int nr,int u=1,int l=1,int r=n)
	{
		if(t[u].exi.back()<nl)return 0;
		if(t[u].exi.front()>nr)return 0;
		nl=*lower_bound(t[u].exi.begin(),t[u].exi.end(),nl);
		nr=*(--upper_bound(t[u].exi.begin(),t[u].exi.end(),nr));
		if(t[u].mem.count({nl,nr}))return t[u].mem[{nl,nr}];
		
		int mid=(l+r)>>1;
		int lans=query(nl,nr,L(u),l,mid),rans=query(nl,nr,R(u),mid+1,r);
		if(!lans||!rans)return t[u].mem[{nl,nr}]=lans|rans;
		cnt++;
		fr[cnt]={lans,rans};
		return t[u].mem[{nl,nr}]=cnt;
	}
	#undef L
	#undef R
}tr;
int main()
{
	n=read();q=read();
	for(int i=1;i<=n;i++)a[read()]=i;
	tr.build();cnt=n;
	for(int i=1;i<=q;i++)
	{
		int l=read(),r=read();
		ans[i]=tr.query(l,r);
	}
	printf("%d\n",cnt);
	for(int i=n+1;i<=cnt;i++)printf("%d %d\n",fr[i].first,fr[i].second);
	for(int i=1;i<=q;i++)printf("%d ",ans[i]);putchar('\n');
	return 0;
}
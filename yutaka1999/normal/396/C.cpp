#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 300005
#define BT 512*1024*2
#define MOD 1000000007

using namespace std;
typedef long long int ll;

struct segtree
{
	ll seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		memset(seg,0,sizeof(seg));
	}
	void update(int a,int b,int k,int l,int r,ll v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) seg[k]=(seg[k]+v)%MOD;
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
		}
	}
	void update(int a,int b,ll v)
	{
		update(a,b,0,0,mum,v);
	}
	ll get(int k)
	{
		k+=mum-1;
		ll ret=seg[k];
		while(k>0)
		{
			k=(k-1)/2;
			ret=(ret+seg[k])%MOD;
		}
		return ret;
	}
};
segtree s1,s2;
vector <int> vec[SIZE];
int id[SIZE],ch[SIZE],dep[SIZE];
int nw;

void dfs(int v=0,int d=0)
{
	id[v]=nw++;
	dep[v]=d;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		dfs(to,d+1);
	}
	ch[v]=nw;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int p;
		scanf("%d",&p);p--;
		vec[p].push_back(i);
	}
	dfs();
	s1.init(n+2);
	s2.init(n+2);
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int v,x,k;
			scanf("%d %d %d",&v,&x,&k);v--;
			s2.update(id[v],ch[v],k);
			ll val=(ll) x+(ll) dep[v]*(ll) k;
			s1.update(id[v],ch[v],val%MOD);
		}
		else
		{
			int v;
			scanf("%d",&v);v--;
			ll vl=s1.get(id[v]),vr=s2.get(id[v]);
			vr*=(ll) dep[v];vr%=MOD;
			vl-=vr;
			if(vl<0) vl+=MOD;
			printf("%I64d\n",vl);
		}
	}
	return 0;
}
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005
#define BT 256*1024*2

using namespace std;
typedef long long int ll;

struct edge
{
	int to,cost;
	edge(int to=0,int cost=0):to(to),cost(cost){}
	bool operator<(const edge&l) const
	{
		return to<l.to;
	}
};
struct segtree
{
	ll seg[BT*2];
	ll add[BT*2];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		memset(seg,0,sizeof(seg));
		memset(add,0,sizeof(add));
	}
	void make(int k)
	{
		seg[k]=max(seg[k*2+1]+add[k*2+1],seg[k*2+2]+add[k*2+2]);
	}
	void updata(int a,int b,int k,int l,int r,ll v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) add[k]+=v;
		else
		{
			updata(a,b,k*2+1,l,(l+r)/2,v);
			updata(a,b,k*2+2,(l+r)/2,r,v);
			make(k);
		}
	}
	void updata(int a,int b,ll v)
	{
		updata(a,b,0,0,mum,v);
	}
	ll maximum(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return -1;
		if(a<=l&&r<=b) return seg[k]+add[k];
		else
		{
			ll vl=maximum(a,b,k*2+1,l,(l+r)/2);
			ll vr=maximum(a,b,k*2+2,(l+r)/2,r);
			return max(vl,vr)+add[k];
		}
	}
	ll maximum(int a,int b)
	{
		return maximum(a,b,0,0,mum);
	}
};
segtree seg;
vector <edge> vec[SIZE];
int in[SIZE];
ll dp[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);a--;b--;
		vec[a].push_back(edge(b,c));
	}
	seg.init(n+2);
	dp[n]=0;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<vec[i].size();j++)
		{
			edge e=vec[i][j];
			seg.updata(e.to+1,seg.mum,(ll) e.cost);
		}
		seg.updata(i+1,seg.mum,(ll) -in[i]);
		ll mx=seg.maximum(i+1,seg.mum);
		dp[i]=max(dp[i+1],mx);
		seg.updata(i,i+1,dp[i]);
	}
	printf("%I64d\n",dp[0]);
	return 0;
}
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#define SIZE 500005
#define BT 512*1024*2

using namespace std;

struct seg1
{
	int seg[BT*2];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		memset(seg,-1,sizeof(seg));
	}
	void updata(int a,int b,int k,int l,int r,int t)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b)
		{
			seg[k]=t;
		}
		else
		{
			updata(a,b,k*2+1,l,(l+r)/2,t);
			updata(a,b,k*2+2,(l+r)/2,r,t);
		}
	}
	void updata(int a,int b,int t)
	{
		updata(a,b,0,0,mum,t);
	}
	int get(int k)
	{
		k+=mum-1;
		int ret=seg[k];
		while(k>0)
		{
			k=(k-1)/2;
			ret=max(ret,seg[k]);
		}
		return ret;
	}
};
struct seg2
{
	int seg[BT*2];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		memset(seg,-1,sizeof(seg));
	}
	void add(int k,int x)
	{
		k+=mum-1;
		seg[k]=x;
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
	int maximum(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return -1;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			int vl=maximum(a,b,k*2+1,l,(l+r)/2);
			int vr=maximum(a,b,k*2+2,(l+r)/2,r);
			return max(vl,vr);
		}
	}
	int maximum(int a,int b)
	{
		return maximum(a,b,0,0,mum);
	}
};
seg1 s1;
seg2 s2;
vector <int> vec[SIZE];
int id[SIZE],ch[SIZE];
int nw=0;

void dfs(int v=0,int p=-1)
{
	id[v]=nw++;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p) dfs(to,v);
	}
	ch[v]=nw;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs();
	s1.init(n+2);
	s2.init(n+2);
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int t,v;
		scanf("%d %d",&t,&v);v--;
		if(t==1)
		{
			s1.updata(id[v],ch[v],i);
		}
		else if(t==2)
		{
			s2.add(id[v],i);
		}
		else
		{
			int v1=s1.get(id[v]);
			int v2=s2.maximum(id[v],ch[v]);
			printf("%d\n",v1>v2);
		}
	}
	return 0;
}
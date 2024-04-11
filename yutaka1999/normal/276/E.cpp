#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 128*1024*2

using namespace std;

struct segtree
{
	int seg[SIZE*2],all[SIZE*2];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		memset(seg,0,sizeof(seg));
		memset(all,0,sizeof(all));
	}
	void pass(int k)
	{
		all[k*2+1]+=all[k];
		all[k*2+2]+=all[k];
		all[k]=0;
	}
	void updata(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b)
		{
			all[k]+=v;
			seg[k]+=v;
		}
		else
		{
			pass(k);
			updata(a,b,k*2+1,l,(l+r)/2,v);
			updata(a,b,k*2+2,(l+r)/2,r,v);
		}
	}
	void updata(int a,int b,int v)
	{
		updata(a,b,0,0,mum,v);
	}
	int val(int k,int l,int r,int v)
	{
		if(v<l||r<=v) return 0;
		if(r-l==1) return seg[k];
		if(v<(l+r)/2) return seg[k]+val(k*2+1,l,(l+r)/2,v);
		else return seg[k]+val(k*2+2,(l+r)/2,r,v);
	}
	int val(int k)
	{
		return val(0,0,mum,k);
	}
};
segtree seg,pl;
int id[SIZE],dep[SIZE],md[SIZE];
vector <int> vec[SIZE];
int now=0;

int dfs(int v=0,int p=-1,int d=0)
{
	id[v]=now++;
	dep[v]=d;
	md[v]=0;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			md[v]=dfs(to,v,d+1)+1;
		}
	}
	return md[v];
}
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	seg.init(n+2);
	pl.init(n+2);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs();
	for(int i=0;i<q;i++)
	{
		int t;
		scanf("%d",&t);
		if(t==0)
		{
			int v,x,d;
			scanf("%d %d %d",&v,&x,&d);v--;
			int pos=id[v];
			int nd=dep[v];
			int mx=md[v];
			if(nd>d)
			{
				seg.updata(pos-d,pos+min(mx,d)+1,x);
			}
			else
			{
				int len=d-nd;
				if(v!=0&&pos-(nd-len)<pos+min(mx,d)) seg.updata(pos-(nd-len)+1,pos+min(mx,d)+1,x);
				pl.updata(0,len+1,x);
			}
		}
		else
		{
			int v;
			scanf("%d",&v);v--;
			int pos=id[v];
			int nd=dep[v];
			printf("%d\n",seg.val(pos)+pl.val(nd));
		}
	}
	return 0;
}
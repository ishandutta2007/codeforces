#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define BT 1024*128*2

using namespace std;
typedef pair <int,int> P;

struct segtree
{
	int cnt[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++)
		{
			cnt[i]=0;
		}
	}
	void pl(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) cnt[k]++;
		else
		{
			pl(a,b,k*2+1,l,(l+r)/2);
			pl(a,b,k*2+2,(l+r)/2,r);
		}
	}
	void pl(int a,int b)
	{
		pl(a,b,0,0,mum);
	}
	int get(int k)
	{
		k+=mum-1;
		int c=cnt[k];
		while(k>0)
		{
			k=(k-1)/2;
			c+=cnt[k];
		}
		return c;
	}
};
struct segtree2
{
	int mx[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++)
		{
			mx[i]=0;
		}
	}
	void add(int k,int x)
	{
		k+=mum-1;
		mx[k]=x;
		while(k>0)
		{
			k=(k-1)/2;
			mx[k]=max(mx[k*2+1],mx[k*2+2]);
		}
	}
	int get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return mx[k];
		else
		{
			int vl=get(a,b,k*2+1,l,(l+r)/2);
			int vr=get(a,b,k*2+2,(l+r)/2,r);
			return max(vl,vr);
		}
	}
	int get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
segtree seg;
segtree2 nn;
vector <P> query[SIZE];
int ans[SIZE],nxt[SIZE],bef[SIZE];
int ng[SIZE],diff[SIZE];
int in[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		in[i]--;
	}
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);l--;r--;
		query[l].push_back(P(r,i));
	}
	seg.init(n+2);
	nn.init(n+2);
	memset(bef,-1,sizeof(bef));
	for(int i=n-1;i>=0;i--)
	{
		nxt[i]=bef[in[i]];
		bef[in[i]]=i;
		if(nxt[i]==-1)
		{
			diff[i]=SIZE;
			ng[i]=n;
		}
		else
		{
			nn.add(nxt[i],-1);
			int d=nxt[i]-i;
			if(nxt[nxt[i]]==-1)
			{
				diff[i]=d;
				ng[i]=n;
			}
			else
			{
				diff[i]=d;
				if(diff[nxt[i]]==d) ng[i]=ng[nxt[i]];
				else ng[i]=nxt[nxt[i]];
			}
		}
		nn.add(i,ng[i]);
		if(nxt[i]!=-1) seg.pl(i,nxt[i]);
		else seg.pl(i,n);
		for(int j=0;j<query[i].size();j++)
		{
			P p=query[i][j];
			int to=p.first;
			int cnt=seg.get(to);
			int last=nn.get(i,to+1);
			ans[p.second]=cnt+(to<last?0:1);
		}
	}
	for(int i=0;i<m;i++) printf("%d\n",ans[i]);
	return 0;
}
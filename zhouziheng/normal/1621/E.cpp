#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int n,m;
long long a[200000],k[200000];vector<long long> b[200000];
long long sum[200000];

int fnd_pos(long long x,long long cnt)
{
	int l=0,r=m;
	while(l<r)
	{
		int mid=(l+r+1)>>1;if(a[mid]*cnt>=x)l=mid;else r=mid-1;
	}
	return r;
}

struct SegmentTree
{
	struct nd
{
	int l,r;
	int sum,add;
}t[400000];
void build(int l,int r,int k=1)
{
	t[k].l=l,t[k].r=r,t[k].add=0;
	if(l==r)
	{
		t[k].sum=-l;return;
	}
	int mid=(l+r)/2;build(l,mid,k*2);build(mid+1,r,k*2+1);
	t[k].sum=max(t[k*2].sum,t[k*2+1].sum);
}

void spread(int k)
{
	if(t[k].add)
	{
		t[k*2].sum+=t[k].add;
		t[k*2+1].sum+=t[k].add;
		t[k*2].add+=t[k].add,t[k*2+1].add+=t[k].add;
		t[k].add=0;
	}
}

void add(int l,int r,int v,int k=1)
{
	if(l>t[k].r||r<t[k].l)
	{
		return;
	}
	if(l<=t[k].l&&r>=t[k].r)
	{
		t[k].sum+=v;
		t[k].add+=v;
		return;
	}
	spread(k);
	add(l,r,v,k*2),add(l,r,v,k*2+1);
	t[k].sum=max(t[k*2].sum,t[k*2+1].sum);
}

long long query(int l,int r,int k=1)
{
	if(l>t[k].r||r<t[k].l)
	{
		return 0;
	}
	if(l<=t[k].l&&r>=t[k].r)
	{
		return t[k].sum;
	}
	spread(k);
	return max(query(l,r,k*2),query(l,r,k*2+1));
}
}T;

int main()
{
	int TT=0;scanf("%d",&TT);
	while(TT--)
	{
		scanf("%d%d",&n,&m);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);reverse(a+1,a+n+1);
		for(int i=1;i<=m;i++){scanf("%d",&k[i]);b[i].clear(),sum[i]=0;
			for(int j=0;j<k[i];j++){int x=0;scanf("%d",&x);b[i].push_back(x);sum[i]+=x;}}
		
		T.build(0,m);
		for(int i=1;i<=m;i++)
		{
			int u=fnd_pos(sum[i],k[i]);T.add(u,m,1);
		}
		for(int i=1;i<=m;i++)
		{
			int u=fnd_pos(sum[i],k[i]);T.add(u,m,-1);
			for(int j=0;j<k[i];j++)
			{
				int v=fnd_pos(sum[i]-b[i][j],k[i]-1);T.add(v,m,1);
				if(T.query(0,m)>0)putchar('0');else putchar('1');
				T.add(v,m,-1);
			}
			T.add(u,m,1);
		}
		puts("");
	}
}
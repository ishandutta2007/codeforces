#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#define SIZE 1000005
#define BT 1024*1024*2
#define INF 1000000000

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct BIT
{
	int bit[SIZE];
	int n;
	
	void add(int k,int x)
	{
		while(k<=n)
		{
			bit[k]+=x;
			k+=k&-k;
		}
	}
	int sum(int k)
	{
		int ret=0;
		while(k>0)
		{
			ret+=bit[k];
			k-=k&-k;
		}
		return ret;
	}
	int sum(int a,int b)
	{
		return sum(b)-sum(a-1);
	}
};
struct segtree
{
	int seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		memset(seg,0,sizeof(seg));
	}
	void add(int k,int x)
	{
		k+=mum-1;
		seg[k]=x;
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=min(seg[k*2+1],seg[k*2+2]);
		}
	}
	int right(int pos,int lim)
	{
		int l=0,r=mum,k=0,L,R,K;
		while(l+1<r)
		{
			int med=(l+r)/2;
			if(med<=pos)
			{
				l=med;
				k=k*2+2;
			}
			else
			{
				if(seg[k*2+2]<lim)
				{
					K=k*2+2;
					L=med;
					R=r;
				}
				k=k*2+1;
				r=med;
			}
		}
		while(L+1<R)
		{
			int med=(L+R)/2;
			if(seg[K*2+1]>=lim)
			{
				L=med;
				K=K*2+2;
			}
			else
			{
				R=med;
				K=K*2+1;
			}
		}
		if(seg[K]>=lim) return L;
		return L-1;
	}
	int left(int pos,int lim)
	{
		int l=0,r=mum,k=0,L,R,K=-1;
		while(l+1<r)
		{
			int med=(l+r)/2;
			if(pos<med)
			{
				r=med;
				k=k*2+1;
			}
			else
			{
				if(seg[k*2+1]<lim)
				{
					K=k*2+1;
					L=l;
					R=med;
				}
				k=k*2+2;
				l=med;
			}
		}
		if(K==-1) return 0;
		while(L+1<R)
		{
			int med=(L+R)/2;
			if(seg[K*2+2]>=lim)
			{
				R=med;
				K=K*2+1;
			}
			else
			{
				L=med;
				K=K*2+2;
			}
		}
		if(seg[K]>=lim) return L;
		return L+1;
	}
};
BIT bit;
segtree seg;
bool use[SIZE];
int in[SIZE];
vector <P> vec;

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	seg.init(n+2);
	bit.n=n+2;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		seg.add(i,in[i]);
		bit.add(i+1,1);
	}
	int now=0;
	for(int i=0;i<k;i++)
	{
		int a;
		scanf("%d",&a);
		while(in[now]!=a) now++;
		use[now]=true;
	}
	for(int i=0;i<n;i++) if(!use[i]) vec.push_back(P(in[i],i));
	sort(vec.begin(),vec.end());
	ll ret=0;
	for(int i=0;i<vec.size();i++)
	{
		P p=vec[i];
		int pos=p.second;
		int l=seg.left(pos,in[pos]),r=seg.right(pos,in[pos]);
		ret+=(ll) bit.sum(l+1,r+1);
		seg.add(pos,INF);
		bit.add(pos+1,-1);
	}
	printf("%llld\n",ret);
	return 0;
}
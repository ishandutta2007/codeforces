#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 2005
#define BT 4096

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <int,P> PP;

struct BIT
{
	ll bit[SIZE];
	
	void init()
	{
		memset(bit,0,sizeof(bit));
	}
	void add(int k,ll x)
	{
		k++;
		while(k<SIZE)
		{
			bit[k]+=x;
			k+=k&-k;
		}
	}
	ll get(int k)
	{
		k++;
		ll ret=0;
		while(k>0)
		{
			ret+=bit[k];
			k-=k&-k;
		}
		return ret;
	}
	ll get(int s,int t)
	{
		return get(t)-get(s-1);
	}
};
struct segtree
{
	BIT seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i].init();
	}
	void add(int x,int y,int w)
	{
		x+=mum-1;
		seg[x].add(y,w);
		while(x>0)
		{
			x=(x-1)/2;
			seg[x].add(y,w);
		}
	}
	ll get(int a,int b,int c,int d,int k,int l,int r)//((  [a,b) , [c,d)  ]]
	{
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return seg[k].get(c,d-1);
		else
		{
			ll vl=get(a,b,c,d,k*2+1,l,(l+r)/2);
			ll vr=get(a,b,c,d,k*2+2,(l+r)/2,r);
			return vl+vr;
		}
	}
	ll get(int a,int b,int c,int d)
	{
		return get(a,b,c,d,0,0,mum);
	}
};
segtree seg;
vector <PP> nd[SIZE];
vector <int> query[SIZE];
int A[SIZE],B[SIZE],C[SIZE],D[SIZE];
bool use[SIZE];
ll ans[SIZE];
char str[10];

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<k;i++)
	{
		int c;
		scanf("%d",&c);
		while(c--)
		{
			int x,y,w;
			scanf("%d %d %d",&x,&y,&w);x--;y--;
			nd[i].push_back(PP(w,P(x,y)));
		}
	}
	int q;
	scanf("%d",&q);
	for(int i=0;i<k;i++) use[i]=true;
	int sz=0;
	for(int i=0;i<q;i++)
	{
		scanf("%s",&str);
		if(str[0]=='A')
		{
			scanf("%d %d %d %d",&A[sz],&C[sz],&B[sz],&D[sz]);
			A[sz]--,B[sz]--,C[sz]--,D[sz]--;
			for(int j=0;j<k;j++)
			{
				if(use[j])
				{
					query[j].push_back(sz);
				}
			}
			sz++;
		}
		else
		{
			int v;
			scanf("%d",&v);v--;
			use[v]=!use[v];
		}
	}
	seg.init(n+2);
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<nd[i].size();j++)
		{
			int x=nd[i][j].second.first,y=nd[i][j].second.second;
			int w=nd[i][j].first;
			seg.add(x,y,w);
		}
		for(int j=0;j<query[i].size();j++)
		{
			int v=query[i][j];
			//printf("%d %d : %lld\n",i,v,seg.get(A[v],B[v]+1,C[v],D[v]+1));
			ans[v]+=seg.get(A[v],B[v]+1,C[v],D[v]+1);
		}
		for(int j=0;j<nd[i].size();j++)
		{
			int x=nd[i][j].second.first,y=nd[i][j].second.second;
			int w=nd[i][j].first;
			seg.add(x,y,-w);
		}
	}
	for(int i=0;i<sz;i++) printf("%lld\n",ans[i]);
	return 0;
}
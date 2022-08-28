#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 30005
#define BT 32*1024*2

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll memo[SIZE][5];
struct Q
{
	ll dp[3][3];
	int s,e,L;
	Q(int s=BT,int e=BT,int L=0):s(s),e(e),L(L){clear();}
	void clear()
	{
		memset(dp,-1,sizeof(dp));
	}
	void init0()
	{
		dp[0][0]=0;
	}
	void init1()
	{
		L=1;
		dp[1][0]=dp[0][1]=0;
		dp[0][0]=memo[s][1];
	}
};

Q merge(Q l,Q r)
{
	if(r.s==BT) return l;
	Q ret;
	ret.clear();
	ret.s=l.s;
	ret.e=r.e;
	ret.L=l.L+r.L;
	for(int i=0;i<=2;i++)
	{
		for(int j=0;j<=2;j++)
		{
			for(int a=0;a<=2;a++)
			{
				if(l.dp[i][a]==-1) continue;
				for(int b=0;a+b<=3&&b<=2;b++)
				{
					if(r.dp[b][j]==-1||memo[r.s-a][a+b]==-1) continue;
					ret.dp[i][j]=max(ret.dp[i][j],l.dp[i][a]+r.dp[b][j]+memo[r.s-a][a+b]);
				}
			}
		}
	}
	if(ret.L<=2) ret.dp[ret.L][0]=ret.dp[0][ret.L]=0;
	return ret;
}
struct segtree
{
	Q seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++)
		{
			seg[i]=Q();
			seg[i].init0();
		}
	}
	void ins(int k)
	{
		seg[k+mum-1]=Q(k,k);
		k+=mum-1;
		seg[k].init1();
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=merge(seg[k*2+1],seg[k*2+2]);
		}
	}
	ll get()
	{
		return seg[0].dp[0][0];
	}
};
segtree seg;
int A[SIZE],B[SIZE];
P va[SIZE],vb[SIZE];
int pa[SIZE],pb[SIZE];
int to[SIZE];
int ord[5];
int n,q;

void make(int k)
{
	for(int i=1;i<=3;i++)
	{
		if(k+i-1>=n)
		{
			memo[k][i]=-1;
			break;
		}
		for(int j=0;j<i;j++) ord[j]=k+j;
		memo[k][i]=-1;
		do
		{
			ll sum=0;
			for(int j=0;j<i;j++)
			{
				if(to[k+j]==ord[j])
				{
					sum=-1;
					break;
				}
				sum+=(ll) A[k+j]*(ll) B[ord[j]];
			}
			memo[k][i]=max(memo[k][i],sum);
		}while(next_permutation(ord,ord+i));
	}
}
int main()
{
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		va[i]=P(a,i);
	}
	for(int i=0;i<n;i++)
	{
		int b;
		scanf("%d",&b);
		vb[i]=P(b,i);
	}
	sort(va,va+n);
	sort(vb,vb+n);
	for(int i=0;i<n;i++) A[i]=va[i].first,pa[va[i].second]=i;
	for(int i=0;i<n;i++) B[i]=vb[i].first,pb[vb[i].second]=i;
	for(int i=0;i<n;i++) to[i]=pb[va[i].second];
	for(int i=0;i<n;i++) make(i);
	//for(int i=0;i<n;i++) printf("%lld %lld %lld\n",memo[i][1],memo[i][2],memo[i][3]);
	seg.init(n+2);
	for(int i=0;i<n;i++) seg.ins(i);
	//printf("%lld\n",seg.get());
	for(int i=0;i<q;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		swap(pb[a],pb[b]);
		swap(to[pa[a]],to[pa[b]]);
		for(int j=0;j<3;j++)
		{
			if(pa[a]-j>=0)
			{
				make(pa[a]-j);
				seg.ins(pa[a]-j);
			}
			if(pa[b]-j>=0)
			{
				make(pa[b]-j);
				seg.ins(pa[b]-j);
			}
		}
		printf("%lld\n",seg.get());
	}
	return 0;
}
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#define SIZE 300005
#define BT 512*1024*2
#define INF 1000000000

using namespace std;
typedef pair <int,int> P;
typedef long long int ll;

struct Q
{
	int mn,cnt;
	Q(int mn=INF,int cnt=1):mn(mn),cnt(cnt){}
};
Q merge(Q a,Q b)
{
	if(a.mn>b.mn) return b;
	if(a.mn<b.mn) return a;
	return Q(a.mn,a.cnt+b.cnt);
}
struct segtree
{
	Q seg[BT];
	int add[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++)
		{
			seg[i]=Q(0,1);
			add[i]=0;
		}
	}
	void update(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b)
		{
			seg[k].mn+=v;
			add[k]+=v;
		}
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
			seg[k]=merge(seg[k*2+1],seg[k*2+2]);
			seg[k].mn+=add[k];
		}
	}
	void update(int a,int b,int v)
	{
		update(a,b,0,0,mum,v);
	}
	void ins(int k,int x)
	{
		update(k,k+1,x);
	}
	Q get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return Q(INF,1);
		if(a<=l&&r<=b) return seg[k];
		else
		{
			Q vl=get(a,b,k*2+1,l,(l+r)/2);
			Q vr=get(a,b,k*2+2,(l+r)/2,r);
			Q ret=merge(vl,vr);
			ret.mn+=add[k];
			return ret;
		}
	}
	Q get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
segtree seg;
P up[SIZE],down[SIZE];
int s1,s2;
int A[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		A[a]=b;
	}
	seg.init(n+2);
	s1=s2=0;
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		seg.ins(i,i);
		int last=i;
		while(s1>0&&up[s1-1].first<A[i])
		{
			s1--;
			seg.update(up[s1].second,last,A[i]-up[s1].first);
			last=up[s1].second;
		}
		up[s1++]=P(A[i],last);
		last=i;
		while(s2>0&&down[s2-1].first>A[i])
		{
			s2--;
			seg.update(down[s2].second,last,down[s2].first-A[i]);
			last=down[s2].second;
		}
		down[s2++]=P(A[i],last);
		Q gt=seg.get(0,i+1);
		if(gt.mn-i==0) ret+=gt.cnt;
		//for(int j=0;j<s1;j++) printf("[%d %d] ",up[j].first,up[j].second);puts("");
		//for(int j=0;j<s2;j++) printf("[%d %d] ",down[j].first,down[j].second);puts("");
		//printf("%d %d\n",gt.mn-i,gt.cnt);
	}
	printf("%lld\n",ret);
	return 0;
}
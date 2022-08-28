#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <functional>
#define SIZE 100005
#define INF 1500000000
#define BT 1024*32*2
#define MX 10005

using namespace std;
typedef pair <int,int> P;

struct segtree
{
	int seg[BT];
	int cnt[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=cnt[i]=0;
	}
	void add(int k,int x)
	{
		k+=mum-1;
		seg[k]+=x;
		cnt[k]++;
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=seg[k*2+1]+seg[k*2+2];
			cnt[k]=cnt[k*2+1]+cnt[k*2+2];
		}
	}
	int get(int c)
	{
		if(cnt[0]<c) return INF;
		int l=0,r=mum,k=0;
		int ret=0;
		while(l+1<r)
		{
			int m=(l+r)/2;
			if(cnt[k*2+1]<=c)
			{
				c-=cnt[k*2+1];
				ret+=seg[k*2+1];
				l=m;
				k=k*2+2;
			}
			else
			{
				r=m;
				k=k*2+1;
			}
		}
		ret+=c*l;
		return ret;
	}
};
segtree seg;
vector <int> vec[SIZE];
P pos[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	int sum=0;
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		vec[a].push_back(b);
		if(a!=0) sum+=b;
	}
	for(int i=0;i<SIZE;i++) sort(vec[i].begin(),vec[i].end(),greater <int>());
	for(int i=0;i<SIZE-1;i++) pos[i]=P(vec[i+1].size(),i+1);
	sort(pos,pos+SIZE-1);
	int ret=sum;
	int now=n;
	int sz=0;
	seg.init(MX);
	for(int i=1;i<=n;i++)
	{
		int val=sum;
		bool up=true;
		if(now<i)
		{
			int v=seg.get(i-now);
			if(v==INF) up=false;
			else val+=v;
		}
		if(up) ret=min(ret,val);
		while(sz<SIZE-1&&pos[sz].first<i) sz++;
		for(int j=sz;j<SIZE-1;j++)
		{
			int v=pos[j].second;
			int g=vec[v][i-1];
			seg.add(g,g);
			now--;
			sum-=g;
		}
	}
	printf("%d\n",ret);
	return 0;
}
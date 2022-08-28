#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 500005
#define BT 512*1024*2

using namespace std;
typedef pair <int,int> P;

struct segtree
{
	int seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=BT;
	}
	void add(int k,int x)
	{
		k+=mum-1;
		seg[k]=min(seg[k],x);
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=min(seg[k*2+1],seg[k*2+2]);
		}
	}
	int get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return BT;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			int vl=get(a,b,k*2+1,l,(l+r)/2);
			int vr=get(a,b,k*2+2,(l+r)/2,r);
			return min(vl,vr);
		}
	}
	int get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
segtree seg;
int in[SIZE];
vector <int> vx;
vector <int> id[SIZE];
int bef[SIZE],back[SIZE];
int to[SIZE],ft[SIZE];
int dp[SIZE],last[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		vx.push_back(in[i]);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<n;i++)
	{
		in[i]=lower_bound(vx.begin(),vx.end(),in[i])-vx.begin();
	}
	memset(bef,-1,sizeof(bef));
	memset(back,-1,sizeof(back));
	memset(to,-1,sizeof(to));
	memset(ft,-1,sizeof(ft));
	for(int i=n-1;i>=0;i--)
	{
		if(bef[in[i]]!=-1)
		{
			back[bef[in[i]]]=i;
			ft[i]=bef[in[i]];
		}
		bef[in[i]]=i;
	}
	for(int i=0;i<n;i++)
	{
		int g=ft[i];
		if(g!=-1)
		{
			g=ft[g];
			if(g!=-1&&ft[g]!=-1)
			{
				to[i]=ft[g];
			}
		}
	}
	seg.init(n+2);
	for(int i=n-1;i>=0;i--)
	{
		if(back[i]!=-1)
		{
			int v=seg.get(back[i],i);
			if(v<n&&(to[back[i]]==-1||to[back[i]]>v)) to[back[i]]=v;
		}
		seg.add(back[i],i);
	}
	memset(dp,-1,sizeof(dp));
	memset(last,-1,sizeof(last));
	dp[0]=0;
	for(int i=0;i<n;i++)
	{
		if(dp[i]==-1) continue;
		if(to[i]!=-1&&dp[to[i]+1]<dp[i]+4)
		{
			dp[to[i]+1]=dp[i]+4;
			last[to[i]+1]=i;
		}
		if(dp[i+1]<dp[i])
		{
			dp[i+1]=dp[i];
			last[i+1]=last[i];
		}
	}
	vector <int> ans;
	int now=last[n];
	while(now!=-1)
	{
		int l=vx[in[now]],r=vx[in[to[now]]];
		ans.push_back(r);
		ans.push_back(l);
		ans.push_back(r);
		ans.push_back(l);
		now=last[now];
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[ans.size()-i-1]);
	}puts("");
	return 0;
}
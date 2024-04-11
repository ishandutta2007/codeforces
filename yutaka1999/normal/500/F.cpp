#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 4005
#define MX 20005
#define BT 15

using namespace std;

struct P
{
	int c,h,t;
	P(int c=0,int h=0,int t=0):c(c),h(h),t(t){}
	bool operator<(const P&l) const
	{
		return t<l.t;
	}
};
struct Q
{
	int l,r,id,all;
	Q(int l=0,int r=0,int id=0,int all=0):l(l),r(r),id(id),all(all){}
};
int dp[SIZE][SIZE];
int left[MX],right[MX];
P pos[SIZE];
int ans[MX];

void div_conq(int l,int r,vector <Q> query)
{
	if(query.empty()) return;
	int m=(l+r)/2;
	for(int i=m-1;i>=l;i--)
	{
		for(int j=0;j<SIZE;j++)
		{
			if(i==m-1)
			{
				dp[i][j]=j>=pos[i].c?pos[i].h:0;
			}
			else
			{
				dp[i][j]=dp[i+1][j];
				if(j>=pos[i].c) dp[i][j]=max(dp[i][j],dp[i+1][j-pos[i].c]+pos[i].h);
			}
			if(j>0) dp[i][j]=max(dp[i][j],dp[i][j-1]);
		}
	}
	for(int i=m;i<r;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			if(i==m)
			{
				dp[i][j]=j>=pos[i].c?pos[i].h:0;
			}
			else
			{
				dp[i][j]=dp[i-1][j];
				if(j>=pos[i].c) dp[i][j]=max(dp[i][j],dp[i-1][j-pos[i].c]+pos[i].h);
			}
			if(j>0) dp[i][j]=max(dp[i][j],dp[i][j-1]);
		}
	}
	vector <Q> L,R;
	for(int i=0;i<query.size();i++)
	{
		Q p=query[i];
		if(p.l<m&&m<=p.r)
		{
			ans[p.id]=0;
			for(int j=0;j<=p.all;j++)
			{
				ans[p.id]=max(ans[p.id],dp[p.l][j]+dp[p.r][p.all-j]);
			}
		}
		else if(p.l==m)
		{
			ans[p.id]=dp[p.r][p.all];
		}
		else if(p.r==m-1)
		{
			ans[p.id]=dp[p.l][p.all];
		}
		else
		{
			if(p.r<m) L.push_back(p);
			else R.push_back(p);
		}
	}
	div_conq(l,m,L);
	div_conq(m,r,R);
}
int main()
{
	int n,p;
	scanf("%d %d",&n,&p);
	for(int i=0;i<n;i++)
	{
		int c,h,t;
		scanf("%d %d %d",&c,&h,&t);
		pos[i]=P(c,h,t);
	}
	sort(pos,pos+n);
	int l=0,r=-1;
	for(int i=0;i<MX;i++)
	{
		while(r+1<n&&pos[r+1].t<=i) r++;
		while(l<=r&&pos[l].t+(p-1)<i) l++;
		left[i]=l,right[i]=r;
	}
	int q;
	scanf("%d",&q);
	vector <Q> query;
	for(int i=0;i<q;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(left[a]>right[a]) ans[i]=0;
		else query.push_back(Q(left[a],right[a],i,b));
	}
	div_conq(0,n,query);
	for(int i=0;i<q;i++) printf("%d\n",ans[i]);
	return 0;
}
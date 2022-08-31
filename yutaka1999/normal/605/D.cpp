#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 200050
#define BT 1024*128*2*2
#define INF 1000000005

using namespace std;
typedef pair <int,int> P;

struct segtree
{
	vector <P> vx[SIZE];
	vector <int> ans;
	int pos[SIZE],mn[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) mn[i]=INF;
		for(int i=0;i<mum;i++)
		{
			pos[i]=0;
			vx[i].clear();
		}
	}
	void ins(int x,int y,int id)
	{
		vx[x].push_back(P(y,id));
		mn[x+mum-1]=min(mn[x+mum-1],y);
	}
	void build()
	{
		for(int i=mum-2;i>=0;i--)
		{
			mn[i]=min(mn[i*2+1],mn[i*2+2]);
		}
		for(int i=0;i<mum;i++) sort(vx[i].begin(),vx[i].end());
	}
	void query(int a,int b,int k,int l,int r,int t)//t 
	{
		if(b<=l||r<=a||mn[k]>t) return;
		if(l+1==r)
		{
			while(pos[l]<vx[l].size()&&vx[l][pos[l]].first<=t) ans.push_back(vx[l][pos[l]++].second);
			if(pos[l]<vx[l].size()) mn[k]=vx[l][pos[l]].first;
			else mn[k]=INF;
		}
		else
		{
			query(a,b,k*2+1,l,(l+r)/2,t);
			query(a,b,k*2+2,(l+r)/2,r,t);
			mn[k]=min(mn[k*2+1],mn[k*2+2]);
		}
	}
	vector <int> query(int a,int b,int t)
	{
		ans.clear();
		query(a,b,0,0,mum,t);
		return ans;
	}
};
segtree seg;
int A[SIZE],B[SIZE],C[SIZE],D[SIZE];
int dp[SIZE],back[SIZE];
vector <int> vx;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&A[i],&B[i],&C[i],&D[i]);
		vx.push_back(A[i]);
		vx.push_back(C[i]);
	}
	C[n]=D[n]=0;
	vx.push_back(0);
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	seg.init(vx.size()+2);
	for(int i=0;i<n;i++)
	{
		A[i]=lower_bound(vx.begin(),vx.end(),A[i])-vx.begin();
		C[i]=lower_bound(vx.begin(),vx.end(),C[i])-vx.begin();
		seg.ins(A[i],B[i],i);
	}
	seg.build();
	memset(dp,-1,sizeof(dp));
	memset(back,-1,sizeof(back));
	queue <int> que;
	que.push(n);
	dp[n]=0;
	while(!que.empty())
	{
		int v=que.front();que.pop();
		vector <int> er=seg.query(0,C[v]+1,D[v]);
		for(int i=0;i<er.size();i++)
		{
			int to=er[i];
			dp[to]=dp[v]+1;
			back[to]=v;
			que.push(to);
		}
	}
	if(dp[n-1]==-1) puts("-1");
	else
	{
		printf("%d\n",dp[n-1]);
		vector <int> ans;
		int now=n-1;
		while(now!=n)
		{
			ans.push_back(now);
			now=back[now];
		}
		for(int i=((int) ans.size())-1;i>=0;i--)
		{
			if(i+1!=ans.size()) printf(" ");
			printf("%d",ans[i]+1);
		}puts("");
	}
	return 0;
}
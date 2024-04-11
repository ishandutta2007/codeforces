#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <vector>
#define SIZE 500005
#define INF 1000000005

using namespace std;
typedef pair <int,int> P;

vector <int> query[SIZE];
vector <int> vec[SIZE];
int H[SIZE],cnt[SIZE];
P dp1[SIZE],dp2[SIZE];
int worker[SIZE];
int A[SIZE],B[SIZE];
int n,k;

void dfs(int v=0,int p=-1,P f=P(INF,-1),P s=P(INF,-1))
{
	P gt=P(H[v],v);
	if(f>gt) swap(f,gt);
	if(s>gt) swap(s,gt);
	dp1[v]=f,dp2[v]=s;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p) dfs(to,v,f,s);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&H[i]);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++) scanf("%d",&worker[i]);
	sort(worker,worker+k);
	for(int i=0;i<k;i++) cnt[i]=-1;
	dfs();
	for(int i=0;i<n;i++)
	{
		int pos=upper_bound(worker,worker+k,dp1[i].first)-worker;
		query[dp1[i].second].push_back(dp2[i].first);
		//printf("[%d %d] [%d %d]\n",dp1[i].first,dp1[i].second,dp2[i].first,dp2[i].second);
		if(pos>0) cnt[pos-1]++;
	}
	for(int i=k-2;i>=0;i--) cnt[i]+=cnt[i+1];
	for(int i=0;i<=k;i++)
	{
		A[i]=-1;
		B[i]=INF;
	}
	for(int i=0;i<k;i++)
	{
		//cnt[i]<0A-cnt[i]iu
		//mnmx : Kv
		if(cnt[i]<0)
		{
			A[-cnt[i]]=max(A[-cnt[i]],worker[i]);
			B[-cnt[i]]=min(B[-cnt[i]],worker[i]);
		}
	}
	int mx=0;
	for(int i=0;i<=k;i++) if(A[i]!=-1) mx=i;
	//for(int i=0;i<=k;i++) printf("%d ",dp[i]);puts("");
	int ret=INF;
	for(int i=0;i<n;i++)
	{
		if(query[i].size()<mx) continue;
		sort(query[i].begin(),query[i].end());
		//printf("%d : ",i);
		//for(int j=0;j<query[i].size();j++) printf("%d ",query[i][j]);puts("");
		int now=0;
		for(int j=0;j<=mx;j++)
		{
			//jA[j]
			//jB[j]
			if(A[j]!=-1)
			{
				if(H[i]>=B[j]) {now=-1;break;}
				int nm=query[i].end()-lower_bound(query[i].begin(),query[i].end(),A[j]);//A[j]
				if(nm<j) {now=-1;break;}
				now=max(now,A[j]-H[i]);
			}
		}
		if(now!=-1) ret=min(ret,now);
	}
	printf("%d\n",ret==INF?-1:ret);
	return 0;
}
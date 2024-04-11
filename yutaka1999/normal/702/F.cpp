#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 200005
#define MX 40

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

vector <P> gt[SIZE];
P DM[SIZE];
ll A[SIZE];
ll B[SIZE];
ll sum[SIZE],sum2[SIZE];
int pos[SIZE],cnt[SIZE];
int cnt2[SIZE];
int score[SIZE];
int ans[SIZE];
int n,q;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int c,d;
		scanf("%d %d",&c,&d);
		DM[i]=P(-d,c);
	}
	sort(DM,DM+n);
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf("%lld",&B[i]);
		pos[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		A[i]=DM[i].second;
		ll t=1;
		int now=0;
		while(2*t<=A[i])
		{
			t<<=1;
			now++;
		}
		score[i]=now;
	}
	for(int i=MX-1;i>=0;i--)
	{
		for(int j=0;j<n;j++)
		{
			sum[j]=A[j];
			cnt[j]=A[j]>0?1:0;
			sum2[j]=score[j]!=i?A[j]:0;
			cnt2[j]=score[j]<i?1:0;
			if(j>0)
			{
				sum[j]+=sum[j-1];
				cnt[j]+=cnt[j-1];
				sum2[j]+=sum2[j-1];
				cnt2[j]+=cnt2[j-1];
			}
			gt[j].clear();
		}
		for(int j=0;j<q;j++)
		{
			ll now=pos[j]==0?0:sum[pos[j]-1];
			now+=B[j];
			int to=upper_bound(sum,sum+n,now)-sum-1;
			if(pos[j]<=to)//pos[j]`to
			{
				ans[j]+=cnt[to]-(pos[j]==0?0:cnt[pos[j]-1]);
				B[j]-=sum[to]-(pos[j]==0?0:sum[pos[j]-1]);
				pos[j]=to+1;
			}
			if(pos[j]<n) gt[pos[j]].push_back(P(B[j]+(pos[j]==0?0:sum2[pos[j]-1]),j));
		}
		priority_queue <P> que;
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<gt[j].size();k++) que.push(gt[j][k]);
			if(score[j]==i)
			{
				while(!que.empty()&&que.top().first>=sum2[j]+A[j])
				{
					P p=que.top();que.pop();
					int v=p.second;
					B[v]=p.first-sum2[j]-A[j];
					ans[v]+=cnt2[j]-(pos[v]==0?0:cnt2[pos[v]-1])+1;
					pos[v]=j+1;
				}
				A[j]=0;
			}
		}
	}
	for(int i=0;i<q;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[i]);
	}puts("");
	return 0;
}
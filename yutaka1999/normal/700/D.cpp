#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 100005
#define DV 320
#define SQR 1000

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,int> PP;

PP pos[SIZE];
vector <int> big;
int A[SIZE],all[SIZE];
int cnt[SIZE];
int left[SIZE],right[SIZE];
int nm[SQR],now[SQR];
ll ans[SIZE];
int n,q;

ll solve()
{
	priority_queue <int,vector <int>,greater <int> > que;
	for(int i=1;i<SQR;i++) nm[i]=now[i];
	for(int i=0;i<big.size();i++)
	{
		int c=cnt[big[i]];
		if(c>0)
		{
			if(c<SQR) nm[c]++;
			else que.push(c);
		}
	}
	int bef=-1;
	ll ret=0;
	for(int i=1;i<SQR;i++)
	{
		if(nm[i]==0) continue;
		if(bef>=0)
		{
			ret+=bef+i;
			nm[i]--;
			if(bef+i<SQR) nm[bef+i]++;
			else que.push(bef+i);
		}
		if(nm[i]>=2)
		{
			ret+=(ll) i*2LL*(ll) (nm[i]/2);
			if(i*2<SQR) nm[i*2]+=nm[i]/2;
			else for(int j=0;j<nm[i]/2;j++) que.push(i*2);
			nm[i]%=2;
		}
		if(nm[i]==1) bef=i;
		else bef=-1;
	}
	if(bef!=-1) que.push(bef);
	while(que.size()>=2)
	{
		int f=que.top();que.pop();
		int s=que.top();que.pop();
		ret+=f+s;
		que.push(f+s);
	}
	return ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);A[i]--;
		all[A[i]]++;
	}
	for(int i=0;i<SIZE;i++) if(all[i]>=SQR) big.push_back(i);
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf("%d %d",&left[i],&right[i]);
		left[i]--,right[i]--;
		pos[i]=PP(P(left[i]/DV,right[i]),i);
	}
	sort(pos,pos+q);
	int start=0,end=0;
	for(int i=0;i<q;i++)
	{
		int v=pos[i].second;
		while(end<=right[v])
		{
			int c=A[end++];
			if(all[c]<SQR)
			{
				now[cnt[c]]--;
				cnt[c]++;
				now[cnt[c]]++;
			}
			else cnt[c]++;
		}
		while(start>left[v])
		{
			int c=A[--start];
			if(all[c]<SQR)
			{
				now[cnt[c]]--;
				cnt[c]++;
				now[cnt[c]]++;
			}
			else cnt[c]++;
		}
		//printf("[%d %d]\n",start,end);
		while(start<left[v])
		{
			int c=A[start++];
			if(all[c]<SQR)
			{
				now[cnt[c]]--;
				cnt[c]--;
				now[cnt[c]]++;
			}
			else cnt[c]--;
		}
		while(right[v]<end-1)
		{
			int c=A[--end];
			if(all[c]<SQR)
			{
				now[cnt[c]]--;
				cnt[c]--;
				now[cnt[c]]++;
			}
			else cnt[c]--;
		}
		ans[v]=solve();
	}
	for(int i=0;i<q;i++) printf("%lld\n",ans[i]);
	return 0;
}
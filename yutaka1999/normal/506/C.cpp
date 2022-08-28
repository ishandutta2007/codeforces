#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <map>
#include <functional>
#define SIZE 100005
#define INF 100000000000000LL

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

ll st[SIZE],pl[SIZE];
ll mt[SIZE];
int zan[SIZE];
P pos[SIZE];
int n,m,k,pp;

bool ok(ll x)
{
	priority_queue <P,vector <P>,greater <P> > que;
	for(int i=0;i<n;i++)
	{
		mt[i]=x;
		if(x/pl[i]==0) return false;
		if(x/pl[i]<m)
		{
			que.push(P(x/pl[i],i));
		}
	}
	for(int i=0;i<m;i++) zan[i]=k;
	int now=0;
	ll sum=0;
	while(!que.empty())
	{
		P p=que.top();que.pop();
		int v=p.second;
		ll to=p.first-1;
		if(now>to) return false;
		mt[v]+=pp;
		zan[now]--;
		if(zan[now]==0) now++;
		sum++;
		if(mt[v]/pl[v]<m) que.push(P(mt[v]/pl[v],v));
	}
	for(int i=0;i<n;i++)
	{
		ll ob=st[i]+pl[i]*(ll) m;
		if(mt[i]<ob)
		{
			ll cnt=(ob-mt[i]+pp-1)/pp;
			sum+=cnt;
		}
	}
	return sum<=(ll) m*k;
}
int main()
{
	scanf("%d %d %d %d",&n,&m,&k,&pp);
	for(int i=0;i<n;i++)
	{
		scanf("%I64d %I64d",&st[i],&pl[i]);
	}
	ll s=-1,e=INF;
	while(e-s>1)
	{
		ll med=(s+e)/2;
		if(ok(med)) e=med;
		else s=med;
	}
	printf("%I64d\n",e);
	return 0;
}
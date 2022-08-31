#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 200005
#define FF 1000000005
#define INF 100000000000000005LL

using namespace std;
typedef pair <int,int> P;
typedef long long int ll;

int A[SIZE];
P now[SIZE];
int n,k,b,c;

int main()
{
	scanf("%d %d %d %d",&n,&k,&b,&c);
	b=min(b,5*c);
	int mn=FF;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		mn=min(mn,A[i]);
	}
	for(int i=0;i<n;i++) A[i]-=mn;
	ll ret=INF;
	for(int i=0;i<5;i++)//mod 5
	{
		for(int j=0;j<n;j++)
		{
			int a=A[j];
			while(a%5!=i) a++;
			now[j]=P(a,(a-A[j])*c);
		}
		sort(now,now+n);
		ll sum=0;
		priority_queue <ll> que;
		for(int j=0;j<n;j++)
		{
			P p=now[j];
			ll vl=(ll) p.second-(ll) (p.first/5)*(ll) b;
			sum+=vl;
			que.push(vl);
			while(que.size()>k)
			{
				sum-=que.top();
				que.pop();
			}
			//if(i==0) printf("%d %lld\n",j,sum);
			if(que.size()==k) ret=min(ret,sum+(ll) (p.first/5)*(ll) b*(ll) k);
		}
	}
	printf("%lld\n",ret);
	return 0;
}
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 300005

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;

P pos[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	ll A,DM;
	scanf("%lld %lld",&A,&DM);
	for(int i=1;i<n;i++)
	{
		ll a,b;
		scanf("%lld %lld",&a,&b);
		pos[i-1]=P(a,b-a+1);
	}n--;
	sort(pos,pos+n);
	priority_queue <ll,vector <ll>,greater <ll> > que;
	int to=n-1;
	int ret=n+1;
	while(A>=0)
	{
		while(to>=0&&pos[to].first>A)
		{
			que.push(pos[to].second);
			to--;
		}
		ret=min(ret,(int) que.size()+1);
		if(que.empty()) break;
		A-=que.top();
		que.pop();
	}
	printf("%d\n",ret);
	return 0;
}
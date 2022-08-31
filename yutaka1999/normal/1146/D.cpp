#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#define SIZE 200005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int gcd(int x,int y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}
bool use[SIZE];
int cnt[SIZE];

ll get(int n,int g)
{
	ll ret=n+1;
	ll c=n/g;
	ret+=c*(c-1)/2LL*(ll) g;
	ret+=c*(ll) (n%g+1);
	return ret;
}
int main()
{
	int n,a,b;
	scanf("%d %d %d",&n,&a,&b);
	int g=gcd(a,b);
	int now=0;
	for(int i=0;i<=a+b;i++)
	{
		if(i==0||(i>=a&&use[i-a]))
		{
			queue <int> que;
			que.push(i);
			use[i]=true;
			while(!que.empty())
			{
				int v=que.front();que.pop();
				now++;
				if(v+a<=i&&!use[v+a])
				{
					use[v+a]=true;
					que.push(v+a);
				}
				if(v-b>=0&&!use[v-b])
				{
					use[v-b]=true;
					que.push(v-b);
				}
			}
		}
		cnt[i]=now;
	}
	ll ret=0;
	for(int i=0;i<=a+b;i++)
	{
		if(i<=n)
		{
			ret+=cnt[i];
		}
	}
	if(n>a+b)
	{
		ret+=get(n,g)-get(a+b,g);
	}
	printf("%lld\n",ret);
	return 0;
}
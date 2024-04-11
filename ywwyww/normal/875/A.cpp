#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
int calc(int x)
{
	int s=0;
	while(x)
	{
		s+=x%10;
		x/=10;
	}
	return s;
}
int ans[100010];
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int t=0;
	for(i=max(1,n-100);i<=n;i++)
		if(i+calc(i)==n)
			ans[++t]=i;
	printf("%d\n",t);
	for(i=1;i<=t;i++)
		printf("%d\n",ans[i]);
	return 0;
}
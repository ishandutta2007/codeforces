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
int a[300010];
int main()
{
	int n;
	scanf("%d",&n);
	int i,j,x;
	j=n;
	int ans=1;
	printf("%d ",ans);
	for(i=1;i<=n;i++)
	{
		ans++;
		scanf("%d",&x);
		a[x]=1;
		while(j>=1&&a[j])
		{
			j--;
			ans--;
		}
		printf("%d ",ans);
	}
	return 0;
}
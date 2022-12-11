#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int a[110];
int f[110][110];
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(f,0,sizeof f);
	int j,k;
	f[0][0]=1;
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			if(a[i]&1&&a[j]&1&&(i-j+1)&1)
				for(k=1;k<=n;k++)
					f[i][k]|=f[j-1][k-1];
	int ans=0;
	for(i=1;i<=n;i++)
		if(f[n][i]&&i&1)
			ans=1;
	if(ans)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
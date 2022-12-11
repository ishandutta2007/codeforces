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
ll a[1010];
int b[1010];
int n;
int c[1010][1010];
int d1[1010];
int d2[1010];
int e[1010];
int main()
{
	int i,j,k;
	scanf("%d",&n);
	if(n==1)
	{
		printf("%d\n",0);
		return 0;
	}
	for(i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	int m=0;
	for(i=1;i<=n;i++)
		if(i==1||a[i]!=a[i-1])
		{
			d1[++m]=a[i];
			d2[m]=1;
		}
		else
			d2[m]++;
	for(i=1;i<=m;i++)
		for(j=1;j<=m;j++)
		{
			k=lower_bound(d1+1,d1+m+1,d1[i]+d1[j])-d1;
			if(k>m||d1[k]!=d1[i]+d1[j])
				c[i][j]=0;
			else
				c[i][j]=k;
		}
	int ans=0;
	for(i=1;i<=n;i++)
	{
		d2[i]--;
		for(j=1;j<=n;j++)
			if(d2[j])
			{
				d2[j]--;
				for(k=1;k<=m;k++)
					e[k]=d2[k];
				ll s1=i;
				ll s2=j;
				int num=2;
				while(c[s1][s2]&&e[c[s1][s2]])
				{
					e[c[s1][s2]]--;
					swap(s1,s2);
					s2=c[s1][s2];
					num++;
				}
				ans=max(ans,num);
				d2[j]++;
			}
		d2[i]++;
	}
	printf("%d\n",ans);
	return 0;
}
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int a[1000010];
int b[1000010];
int f[1000010];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(m==1)
	{
		printf("%d\n",n);
		return 0;
	}
	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&b[i]);
	for(i=1;i<n;i++)
		a[i]-=a[i+1];
	for(i=1;i<m;i++)
		b[i]-=b[i+1];
	n--;
	m--;
	int t=0;
	f[1]=0;
	for(i=2;i<=m;i++)
	{
		while(t&&b[t+1]!=b[i])
			t=f[t];
		if(b[t+1]==b[i])
			t++;
		f[i]=t;
	}
	int ans=0;
	int j=0;
	for(i=1;i<=n;i++)
	{
		while(j&&a[i]!=b[j+1])
			j=f[j];
		if(a[i]==b[j+1])
			j++;
		if(j==m)
		{
			ans++;
			j=f[j];
		}
	}
	printf("%d\n",ans);
	return 0;
}
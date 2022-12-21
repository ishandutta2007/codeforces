#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
char c[100005];
int f[100005][5];
int i,j,k,l,r,s,m,n;
int main()
{
	scanf("%s",c);
	n=strlen(c);
	for (i=0;i<n;i++)
	{
		f[i+1][1]=f[i][1];
		f[i+1][2]=f[i][2];
		f[i+1][3]=f[i][3];
		if (c[i]=='x')
		f[i+1][1]++;
		else
		if (c[i]=='y')
		f[i+1][2]++;
		else
		f[i+1][3]++;
	}
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		l--;
		r--;
		if (r-l+1<3)
		printf("YES\n");
		else
		{
			int gt=f[r+1][1]-f[l][1];
			int gtw=f[r+1][2]-f[l][2];
			int gtww=f[r+1][3]-f[l][3];
			if (gt<gtw)
			swap(gt,gtw);
			if (gt<gtww)
			swap(gt,gtww);
			if (gtw<gtww)
			swap(gtw,gtww);
			if (gt-gtww<=1)
			printf("YES\n");
			else
			printf("NO\n");
		}
	}
}
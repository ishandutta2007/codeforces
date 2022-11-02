#include<bits/stdc++.h>
#define maxn 505
using namespace std;

int n,d[maxn];

int pos[maxn];

bool cmp(int i,int j)
{
	return d[i]<d[j];
}

bool judge()
{
	int s1=0,s2=0;
	for (int i=1;i<=n;++i)
		if (d[i]==1)
			++s1;
		else
			s2+=d[i];
	return s1<=s2-2*(n-s1-1);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&d[i]),pos[i]=i;
	sort(pos+1,pos+n+1,cmp);
	if (!judge())
		puts("NO");
	else
	{
		int i;
		for (i=1;d[pos[i]]==1;++i);
		
		printf("YES %d\n",(n-i+1)+min(i-1,2)-1);
		printf("%d\n",n-1);
		
		int k=1;
		
		if (k<i)
			--d[pos[n]],
			printf("%d %d\n",pos[k++],pos[n]);
		for (int j=i;j<=n;++j)
		{
			if (j!=n)
				--d[pos[j]],--d[pos[j+1]],
				printf("%d %d\n",pos[j],pos[j+1]);
			while (k<i&&d[pos[j]]--)
				printf("%d %d\n",pos[j],pos[k++]);
		}
	}
	return 0;
}
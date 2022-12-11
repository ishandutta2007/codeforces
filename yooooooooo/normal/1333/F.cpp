#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,cnt[500005],seq[500005],hd;
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		for(int j=2*i;j<=n;j+=i)if(seq[j]==0)seq[j]=i;
	}
	for(int i=2;i<=n;i++)
	{
		if(!seq[i])seq[i]=i;
		cnt[i/seq[i]]++;
	}
	hd=1;
	for(int i=2;i<=n;i++)
	{
		while(!cnt[hd])hd++;
		printf("%d ",hd);
		cnt[hd]--;
	}
	return 0;
}
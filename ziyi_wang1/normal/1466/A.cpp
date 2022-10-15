#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,a[110],ok[110];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				ok[a[j]-a[i]]=1;
		int cnt=0;
		for(int i=1;i<=50;++i)cnt+=ok[i],ok[i]=0;
		printf("%d\n",cnt);
	}
	return 0;
}
#include<cstdio>

using namespace std;

int a[500000];

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0;scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		bool fl=1;for(int i=1;i<n;i++)if(a[i]>a[i+1])fl=0;puts(fl?"NO":"YES");
	}
}
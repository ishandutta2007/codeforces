//luogu
#include<cstdio>
#include<cstring>
using namespace std;
int a[110000];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;scanf("%d",&n);
		long long ss=0;
		bool bk=false;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<n;i++)
		{
			ss+=a[i];
			if(ss<=0){bk=true;break;}
		}
		ss=0;
		for(int i=n;i>1;i--)
		{
			ss+=a[i];
			if(ss<=0){bk=true;break;}
		}
		puts(bk?"NO":"YES");
	}
	return 0;
}
#include<cstdio>
#include<cstring>
using namespace std;
char s[1100];
bool f[110][55];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,m;scanf("%d%d%s",&n,&m,s+1);
		bool bk=true;
		if(n<m*2+1)
		{
			puts("NO");
		}
		else
		{
			for(int i=1,j=n;i<=m;i++,j--)
			{
				if(s[i]!=s[j]){bk=false;break;}
			}
			puts(bk?"YES":"NO");
		}
	}
	return 0;
}
#include<cstdio>
#include<cstring>
using namespace std;
char s[110];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,q;scanf("%d%d",&n,&q);
		scanf("%s",s+1);
		for(int i=1;i<=q;i++)
		{
			int l,r;scanf("%d%d",&l,&r);
			int k=0;bool bk=false;
			for(int j=l;j<=r;j++)
			{
				k++;
				while(k<=n&&s[k]!=s[j])
				{
					if(j>l)bk=true;
					k++;
				}
			}
			if(bk)puts(k<=n?"YES":"NO");
			else
			{
				k++;
				while(k<=n&&s[k]!=s[r])k++;
				puts(k<=n?"YES":"NO");
			}
		}
	}
	return 0;
}
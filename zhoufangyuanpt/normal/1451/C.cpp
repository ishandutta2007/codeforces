#include<cstdio>
#include<cstring>
using namespace std;
char a[1010000],b[1010000];
int cnta[110],cntb[110];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,k;scanf("%d%d",&n,&k);
		scanf("%s%s",a+1,b+1);
		for(int i=0;i<26;i++)cnta[i]=cntb[i]=0;
		for(int i=1;i<=n;i++)cnta[a[i]-'a']++,cntb[b[i]-'a']++;
		bool bk=true;
		for(int i=0;i<26;i++)
		{
			if(cnta[i]<cntb[i])
			{
				bk=false;break;
			}
			else if(cnta[i]>cntb[i])
			{
				if((cnta[i]-cntb[i])%k!=0){bk=false;break;}
				else
				{
					if(i==25){bk=false;break;}
					cnta[i+1]+=cnta[i]-cntb[i];
				}
			}
		}
		puts(bk?"Yes":"No");
	}
	return 0;
}
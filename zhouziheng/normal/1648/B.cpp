#include<cstdio>
#include<algorithm>

using namespace std;

int cnt[2000000],s[2000000];

int main()
{
	int TT=0;scanf("%d",&TT);
	while(TT--)
	{
		int n=0,c=0;scanf("%d%d",&n,&c);for(int i=1,a=0;i<=n;i++){scanf("%d",&a);cnt[a]=1;}
		for(int i=1;i<=c;i++)s[i]=s[i-1]+cnt[i];bool fl=1;
		for(int i=1;i<=c&&fl;i++)
		{
			if(cnt[i])
			{
				for(int j=1;j*i<=c&&fl;j++)
				{
					if(!cnt[j]&&s[i*j-1]!=s[min(c,i*(j+1)-1)])fl=0;
				}
			}
		}
		puts(fl?"Yes":"No");
		for(int i=1;i<=c;i++)s[i]=cnt[i]=0;
	}
	
}
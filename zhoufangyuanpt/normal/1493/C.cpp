#include<cstdio>
#include<cstring>
using namespace std;
char a[110000];
int cnt[110];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,k;scanf("%d%d%s",&n,&k,a+1);
		if(n%k!=0){puts("-1");continue;}
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)cnt[a[i]-'a']++;
		bool bk=true;
		for(int i=0;i<26;i++)
		{
			if(cnt[i]%k!=0){bk=false;break;}
		}
		if(bk==true)
		{
			puts(a+1);
			continue;
		}
		for(int i=n;i>=1;i--)
		{
			cnt[a[i]-'a']--;
			for(int j=a[i]-'a'+1;j<26;j++)
			{
				cnt[j]++;
				int s=0;
				for(int l=0;l<26;l++)
				{
					if(cnt[l]%k!=0)s+=k-cnt[l]%k;
				}
				if(s<=n-i)
				{
					bk=true;
					for(int z=1;z<i;z++)putchar(a[z]);
					putchar(j+'a');
					for(int z=1;z<=n-i-s;z++)putchar('a');
					for(int z=0;z<26;z++)
					{
						if(cnt[z]%k!=0)
						{
							for(int zz=1;zz<=k-cnt[z]%k;zz++)putchar(z+'a');
						}
					}
					putchar('\n');
					break;
				}
				cnt[j]--;
			}
			if(bk==true)break;
		}
		if(bk==false)puts("-1");
	}
}
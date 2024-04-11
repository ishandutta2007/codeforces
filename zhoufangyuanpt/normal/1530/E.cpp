#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[110000],r[110000];
int ct[210];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		sort(s+1,s+n+1);
		int cnt=0,g=0,gg=0;
		s[0]=0;
		for(int i=0;i<=26;i++)ct[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]!=s[i-1])cnt++;
			if(s[i]==s[1])g++;
			else gg++;
			ct[s[i]-'a']++;
		}
		char tk=0;
		for(int i=0;i<26;i++)if(ct[i]==1){tk=i+'a';break;}
		if(tk!=0)
		{
			r[1]=tk;
			int j=1;
			for(int i=2;i<=n;i++)
			{
				if(s[j]==tk)j++;
				r[i]=s[j++];
			}
			r[n+1]='\0';
			puts(r+1);
			continue;
		}
		if(gg<g-2)
		{
			if(cnt==1)
			{
				puts(s+1);
				continue;
			}
			else if(cnt==2)
			{
				r[1]=s[1];
				for(int i=2;i<=gg+1;i++)r[i]=s[g+1];
				for(int i=gg+2;i<=n;i++)r[i]=s[1];
				r[n+1]='\0';
			}
			else
			{
				swap(s[2],s[g+1]);
				for(int i=g+2;i<=n;i++)
				{
					if(s[i]!=s[2])
					{
						swap(s[g+2],s[i]);
						break;
					}
				}
				puts(s+1);
				continue;
			}
		}
		else
		{
			int j=g+1,k=1;
			for(int i=1;i<=g;i++)
			{
				if(i==1)r[k++]=s[i];
				else if(i==2)r[k++]=s[i];
				else
				{
					r[k++]=s[j++];
					r[k++]=s[i];
				}
			}
			for(;j<=n;j++)r[k++]=s[j];
			r[n+1]='\0';
		}
		puts(r+1);
	}
	return 0;
}
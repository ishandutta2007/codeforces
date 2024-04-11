#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 100005

using namespace std;

char str[SIZE];
int cnt[2][12];
int num=0,one=-1;
int ret=0;
int s1[SIZE],s2[SIZE];

void solve(int pl)
{
	for(int i=1;i<10;i++)
	{
		if(cnt[0][i]>=1&&cnt[1][10-i]>=1)
		{
			int ans=pl+1;
			cnt[0][i]--;cnt[1][10-i]--;
			for(int j=0;j<10;j++) ans+=min(cnt[0][j],cnt[1][9-j]);
			cnt[0][i]++;cnt[1][10-i]++;
			if(ans>ret)
			{
				ret=ans;
				num=pl;
				one=i;
			}
		}
	}
	if(ret<pl)
	{
		ret=pl;
		num=pl;
		one=-1;
	}
}
int main()
{
	scanf("%s",&str);
	int sz=strlen(str);
	for(int i=0;i<sz;i++)
	{
		cnt[0][str[i]-'0']++;
		cnt[1][str[i]-'0']++;
	}
	for(int i=0;i<=cnt[0][0];i++)
	{
		cnt[0][0]-=i;
		cnt[1][0]-=i;
		solve(i);
		cnt[0][0]+=i;
		cnt[1][0]+=i;
	}
	//printf("%d %d %d\n",ret,one,num);
	for(int i=0;i<sz;i++)
	{
		if(i<num)
		{
			s1[i]=s2[i]=0;
			cnt[0][0]--;cnt[1][0]--;
		}
		else
		{
			if(one!=-1&&i==num)
			{
				s1[i]=one;
				s2[i]=10-one;
				cnt[0][one]--;cnt[1][10-one]--;
			}
			else
			{
				bool up=false;
				for(int j=0;j<10;j++)
				{
					if(cnt[0][j]>0&&cnt[1][9-j]>0)
					{
						cnt[0][j]--;cnt[1][9-j]--;
						s1[i]=j;
						s2[i]=9-j;
						up=true;
						break;
					}
				}
				if(!up)
				{
					for(int j=0;j<10;j++)
					{
						if(cnt[0][j]>0)
						{
							s1[i]=j;
							cnt[0][j]--;
							break;
						}
					}
					for(int j=0;j<10;j++)
					{
						if(cnt[1][j]>0)
						{
							s2[i]=j;
							cnt[1][j]--;
							break;
						}
					}
				}
			}
		}
	}
	for(int i=sz-1;i>=0;i--) printf("%c",'0'+s1[i]);puts("");
	for(int i=sz-1;i>=0;i--) printf("%c",'0'+s2[i]);puts("");	
	return 0;
}
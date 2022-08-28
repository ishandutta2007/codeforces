#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 1005

using namespace std;

char str[SIZE];
char mp[SIZE];

int main()
{
	int n,p;
	scanf("%d %d",&n,&p);
	scanf("%s",&str);
	if(p==1)
	{
		puts("NO");
		return 0;
	}
	if(p==2)
	{
		if(n>=3)
		{
			puts("NO");
		}
		else if(n==2)
		{
			if(str[0]=='a')
			{
				puts("ba");
			}
			else
			{
				puts("NO");
			}
		}
		else
		{
			if(str[0]=='a')
			{
				puts("b");
			}
			else
			{
				puts("NO");
			}
		}
		return 0;
	}
	bool up=false;
	for(int i=n-1;i>=0;i--)
	{
		if(str[i]=='a'+(p-1)) continue;
		memcpy(mp,str,sizeof(str));
		int c=str[i]-'a'+1;
		bool ok=true;
		for(int j=i;j<n;j++)
		{
			int x=j==0?-1:mp[j-1]-'a';
			int y=j<=1?-1:mp[j-2]-'a';
			while(c<p&&(x==c||y==c)) c++;
			if(c==p)
			{
				ok=false;
				break;
			}
			mp[j]='a'+c;
			c=0;
		}
		if(ok)
		{
			up=true;
			break;
		}
	}
	if(up) printf("%s\n",mp);
	else puts("NO");
	return 0;
}
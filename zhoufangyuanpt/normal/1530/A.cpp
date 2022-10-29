#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[110];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		int ss=0;
		for(int i=1;i<=strlen(s+1);i++)ss=max(ss,s[i]-'0');
		printf("%d\n",ss);
	}
	return 0;
}
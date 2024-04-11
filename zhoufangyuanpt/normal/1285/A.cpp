//luogu
#include<cstdio>
#include<cstring>
using namespace std;
char st[110000];
int main()
{
	int n,s=0,ss=0;
	scanf("%d%s",&n,st+1);
	for(int i=1;i<=n;i++)
	{
		if(st[i]=='L')s++;
		else ss++;
	}
	printf("%d\n",s+ss+1);
	return 0;
}
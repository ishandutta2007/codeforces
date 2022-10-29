//luogu
#include<cstdio>
#include<cstring>
using namespace std;
char s[1100];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		if(n>=2&&s[n-1]=='p'&&s[n]=='o')puts("FILIPINO");
		else if(n>=4&&((s[n-3]=='d'&&s[n-2]=='e'&&s[n-1]=='s'&&s[n]=='u')||(s[n-3]=='m'&&s[n-2]=='a'&&s[n-1]=='s'&&s[n]=='u')))puts("JAPANESE");
		else puts("KOREAN");
	}
	return 0;
}
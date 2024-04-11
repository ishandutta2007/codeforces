#include <cstdio>

using namespace std;

int cnt[15];
char str[10];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<4;i++)
	{
		scanf("%s",&str);
		for(int j=0;j<4;j++) if(str[j]!='.') cnt[str[j]-'1']++;
	}
	bool up=true;
	for(int i=0;i<15;i++) if(cnt[i]>2*n) up=false;
	puts(up?"YES":"NO");
	return 0;
}
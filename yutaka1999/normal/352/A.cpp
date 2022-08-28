#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int cnt=0,cz=0;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		cz+=a==0;
		cnt+=a!=0;
	}
	cnt-=cnt%9;
	if(cz>0&&cnt>0)
	{
		for(int i=0;i<cnt;i++) printf("5");
		for(int i=0;i<cz;i++) printf("0");
		puts("");
	}
	else if(cz>0) puts("0");
	else puts("-1");
	return 0;
}
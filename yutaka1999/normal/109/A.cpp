#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)//
	{
		if(i*4<=n&&(n-i*4)%3==0&&(n-i*4)/3<=i)
		{
			int sv=(n-i*4)/3,fr=i-sv;
			for(int j=0;j<fr;j++) printf("4");
			for(int j=0;j<sv;j++) printf("7");
			puts("");
			return 0;
		}
	}
	puts("-1");
	return 0;
}
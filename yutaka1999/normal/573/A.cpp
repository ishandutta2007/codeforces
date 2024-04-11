#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int last=-1;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		while(a%2==0) a/=2;
		while(a%3==0) a/=3;
		if(last==-1) last=a;
		else if(last!=a)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 105

using namespace std;

int in[SIZE];
int cnt[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	sort(in,in+n);
	int ret=0;
	for(int i=0;i<n;i++)
	{
		bool up=false;
		for(int j=in[i];j>=0;j--)
		{
			if(cnt[j]>0)
			{
				cnt[j]--;
				cnt[j+1]++;
				up=true;
				break;
			}
		}
		if(!up)
		{
			cnt[1]++;
			ret++;
		}
	}
	printf("%d\n",ret);
	return 0;
}
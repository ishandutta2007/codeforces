#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 1005

using namespace std;

bool use[SIZE];
vector <int> ans;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		if(!use[i])
		{
			for(int j=2*i;j<=n;j+=i) use[j]=true;
			int p=i;
			while(p<=n)
			{
				ans.push_back(p);
				p*=i;
			}
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[i]);
	}puts("");
	return 0;
}
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 2005

using namespace std;
typedef long long int ll;

ll dp[SIZE];
char str[SIZE];
vector <int> vec[SIZE];

int main()
{
	scanf("%s",&str);
	int sz=strlen(str);
	for(int i=0;i<sz;i++)
	{
		int l=i,r=i;
		while(l>=0&&r<sz)
		{
			if(str[l]==str[r])
			{
				vec[l].push_back(r);
				l--;r++;
			}
			else break;
		}
		l=i;r=i+1;
		while(l>=0&&r<sz)
		{
			if(str[l]==str[r])
			{
				vec[l].push_back(r);
				l--;r++;
			}
			else break;
		}
	}
	ll ret=0;
	for(int i=sz-1;i>=0;i--)
	{
		dp[i]=vec[i].size()+dp[i+1];
		for(int j=0;j<vec[i].size();j++)
		{
			int to=vec[i][j]+1;
			ret+=dp[to];
		}
	}
	printf("%I64d\n",ret);
	return 0;
}
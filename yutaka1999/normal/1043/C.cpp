#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <cassert>
#define SIZE 1005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

char str[SIZE];

int main()
{
	scanf("%s",&str);
	int n=strlen(str);
	int tp=SIZE;
	vector <int> ans(n+1,0);
	for(int i=0;i<n;i++)
	{
		int x=str[i]-'a';
		if(tp>=x)
		{
			ans[i]^=1;
			tp=x;
			ans[i+1]^=1;
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	puts("");
	return 0;
}
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

void solve()
{
	int n;
	scanf("%d",&n);
	int ret=0;
	for(int i=0;i<9;i++)
	{
		vector <int> S,T;
		for(int j=0;j<n;j++)
		{
			if(j>>i&1) S.push_back(j);
			else T.push_back(j);
		}
		if(!S.empty()&&!T.empty())
		{
			printf("%d %d",S.size(),T.size());
			for(int j=0;j<S.size();j++) printf(" %d",S[j]+1);
			for(int j=0;j<T.size();j++) printf(" %d",T[j]+1);
			puts("");
			fflush(stdout);
			int d;
			scanf("%d",&d);
			ret=max(ret,d);
		}
	}
	printf("-1 %d\n",ret);
	fflush(stdout);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
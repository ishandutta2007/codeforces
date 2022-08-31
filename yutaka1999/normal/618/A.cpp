#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main()
{
	int n;
	scanf("%d",&n);
	vector <int> ans;
	while(n>0)
	{
		int rt=1;
		int cnt=0;
		while(rt<=n)
		{
			rt<<=1;
			cnt++;
		}
		rt/=2;
		n-=rt;
		ans.push_back(cnt);
	}
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[i]);
	}puts("");
	return 0;
}
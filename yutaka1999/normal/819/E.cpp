#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#define SIZE 305

using namespace std;
typedef pair <int,int> P;
typedef pair <int,P> PP;
#define pair <P,P> P2;

int main()
{
	int n;
	scanf("%d",&n);
	vector < vector <int> > ans;
	while(n>=5)
	{
		int sz=n-2;
		for(int i=0;i+1<sz;i++)
		{
			vector <int> nd;
			nd.push_back(i);
			nd.push_back(n-2);
			nd.push_back(i+1);
			nd.push_back(n-1);
			ans.push_back(nd);
		}
		vector <int> nd;
		nd.push_back(0);
		nd.push_back(n-1);
		nd.push_back(n-2);
		ans.push_back(nd);
		nd.clear();
		nd.push_back(sz-1);
		nd.push_back(n-1);
		nd.push_back(n-2);
		ans.push_back(nd);
		n-=2;
	}
	if(n==3)
	{
		vector <int> nd;
		nd.push_back(0);
		nd.push_back(1);
		nd.push_back(2);
		ans.push_back(nd);
		ans.push_back(nd);
	}
	else
	{
		vector <int> nd;
		nd.push_back(0);
		nd.push_back(1);
		nd.push_back(2);
		ans.push_back(nd);
		nd.clear();
		nd.push_back(0);
		nd.push_back(1);
		nd.push_back(3);
		ans.push_back(nd);
		nd.clear();
		nd.push_back(1);
		nd.push_back(2);
		nd.push_back(3);
		ans.push_back(nd);
		nd.clear();
		nd.push_back(2);
		nd.push_back(0);
		nd.push_back(3);
		ans.push_back(nd);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		vector <int> nd=ans[i];
		printf("%d",nd.size());
		for(int j=0;j<nd.size();j++) printf(" %d",nd[j]+1);
		puts("");
	}
	return 0;
}
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

int A[SIZE];
int X[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	vector <int> ans;
	for(int i=1;i<=n;i++)
	{
		int bef=0;
		for(int j=0;j<i;j++)
		{
			X[j]=A[j]-bef;
			bef=A[j];
		}
		bool up=true;
		for(int j=i;j<n;j++)
		{
			int a=A[j]-bef;
			if(a!=X[j%i])
			{
				up=false;
				break;
			}
			bef=A[j];
		}
		if(up) ans.push_back(i);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
	puts("");
	return 0;
}
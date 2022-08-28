#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <functional>
#include <cmath>
#include <map>
#include <string>
#define SIZE 4005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll dam[SIZE];
int v[SIZE],d[SIZE],p[SIZE];
bool use[SIZE];
int n;

void dead(int k)
{
	use[k]=true;
	for(int i=k+1;i<n;i++)
	{
		dam[i]+=d[k];
		if(dam[i]>p[i]&&!use[i]) dead(i);
	}
}
int main()
{
	scanf("%d",&n);
	vector <int> ans;
	memset(dam,0,sizeof(dam));
	for(int i=0;i<n;i++) scanf("%d %d %d",&v[i],&d[i],&p[i]);
	for(int i=0;i<n;i++)
	{
		if(!use[i])
		{
			ans.push_back(i);
			for(int j=i+1;j<n;j++)
			{
				if(v[i]==0) break;
				if(use[j]) continue;
				dam[j]+=(ll) v[i];
				v[i]--;
			}
			for(int j=i+1;j<n;j++)
			{
				if(!use[j]&&dam[j]>p[j])
				{
					dead(j);
				}
			}
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[i]+1);
	}puts("");
	return 0;
}
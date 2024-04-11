#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 300005
#define MX 1000005

using namespace std;

vector <int> vec[MX],pos[MX];
vector <int> ans;
int in[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		pos[a].push_back(i);
		in[i]=a;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=1;j*j<=in[i];j++)
		{
			if(in[i]%j==0)
			{
				if(!pos[j].empty()) vec[j].push_back(i);
				if(j!=in[i]/j&&!pos[in[i]/j].empty()) vec[in[i]/j].push_back(i);
			}
		}
	}
	int mx=-1;
	for(int i=0;i<MX;i++)
	{
		if(vec[i].empty()) continue;
		sort(vec[i].begin(),vec[i].end());
		vec[i].push_back(-MX);
		int l=-1,r=-MX,now=0;
		for(int j=0;j<vec[i].size();j++)
		{
			if(r+1!=vec[i][j])
			{
				while(now<pos[i].size()&&pos[i][now]<l)  now++;
				if(now<pos[i].size()&&pos[i][now]<=r)
				{
					if(r-l>mx)
					{
						mx=r-l;
						ans.clear();
					}
					if(r-l==mx) ans.push_back(l);
				}
				l=r=vec[i][j];
			}
			else r++;
		}
	}
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	printf("%d %d\n",ans.size(),mx);
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[i]+1);
	}puts("");
	return 0;
}
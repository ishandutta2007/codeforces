#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
#include <set>
#include <queue>
#include <stack>
#define SIZE 400005

using namespace std;
typedef pair <int,int> P;

int a[SIZE],b[SIZE];
int c[SIZE],d[SIZE],ct[SIZE];
vector <int> vx;
vector <int> singer[SIZE],note[SIZE];
int ans[SIZE];

int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		vx.push_back(a[i]);
		vx.push_back(b[i]);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&c[i],&d[i],&ct[i]);
		vx.push_back(c[i]);
		vx.push_back(d[i]);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<n;i++)
	{
		a[i]=lower_bound(vx.begin(),vx.end(),a[i])-vx.begin();
		b[i]=lower_bound(vx.begin(),vx.end(),b[i])-vx.begin();
		note[a[i]].push_back(i);
	}
	for(int i=0;i<m;i++)
	{
		c[i]=lower_bound(vx.begin(),vx.end(),c[i])-vx.begin();
		d[i]=lower_bound(vx.begin(),vx.end(),d[i])-vx.begin();
		singer[c[i]].push_back(i);
	}
	set <P> st;
	set <P>::iterator it;
	for(int i=0;i<vx.size();i++)
	{
		for(int j=0;j<singer[i].size();j++)
		{
			int id=singer[i][j];
			st.insert(P(d[id],id));
		}
		for(int j=0;j<note[i].size();j++)
		{
			int id=note[i][j];
			it=st.lower_bound(P(b[id],-1));
			if(it!=st.end())
			{
				int v=(*it).second;
				ans[id]=v;
				ct[v]--;
				if(ct[v]==0)
				{
					st.erase(it);
				}
			}
			else
			{
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[i]+1);
	}puts("");
	return 0;
}
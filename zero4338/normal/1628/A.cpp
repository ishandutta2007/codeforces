#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=2e5+5;
int n;
vector<int>pos[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)pos[read()].push_back(i);
		vector<int>ans;
		int cur=0;
		while(true)
		{
			int v=0;
			int ls=cur;
			for(int i=0;i<=n;i++)
				if(!pos[i].empty()&&pos[i].back()>ls)
				{
					v++;
					cur=max(cur,*upper_bound(pos[i].begin(),pos[i].end(),ls));
				}
				else break;
			if(!v){for(int i=cur+1;i<=n;i++)ans.push_back(0);break;}
			ans.push_back(v);
		}
		for(int i=0;i<=n;i++)pos[i].clear();
		printf("%lu\n",ans.size());
		for(int &i:ans)printf("%d ",i);putchar('\n');
	}
	return 0;
}
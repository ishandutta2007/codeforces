#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,ty,u,v;
vector<int>sr[14];
vector<int>ans1,ans2;
void solve(int p,int l,int r)
{
	if(p==1)return;
	solve(p/2,l,l+p/2-1);
	solve(p/2,l+p/2,r);
	for(int i=0;i<p/2;i++)ans1.push_back(l+i),ans2.push_back(l+p/2+i);
}
bool chk()
{
	int cnt=0;
	for(int i=0;i<14;i++)if(!sr[i].empty())cnt++;
	return cnt>2;
}
int main()
{
	scanf("%d",&n);
	for(int i=13;i>=0;i--)
	{
		if(n&(1<<i))
		{
			solve((1<<i),n-(1<<i)+1,n);
			for(int j=n;j>n-(1<<i);j--)sr[i].push_back(j);
			n-=(1<<i);
		}	
	}
	//printf("%d\n",ans1.size());
	if(chk())
	{
		for(int i=0;i<14;i++)
		{
			if(!sr[i].empty())
			{
				u=i;
				break;
			}
		}
		for(int i=13;i>=0;i--)
		{
			if(!sr[i].empty())
			{
				v=i;
				break;
			}
		}
		for(int j=0;j<sr[u].size();j++)
		{
			ans1.push_back(sr[u][j]);
			ans2.push_back(sr[v][sr[v].size()-1-j]);
		}
		for(int j=0;j<(1<<u);j++)
		{
			int x=sr[v].back();
			sr[v].pop_back();
			sr[u].push_back(x);
		}
		for(int i=u+1;i<v;i++)
		{
			if(sr[i].empty())
			{
				for(int j=0;j<sr[u].size();j++)
				{
					ans1.push_back(sr[u][j]);
					ans2.push_back(sr[v][sr[v].size()-1-j]);
				}
				for(int j=0;j<(1<<i);j++)
				{
					int x=sr[v].back();
					sr[v].pop_back();
					sr[u].push_back(x);
				}
			}
			else
			{
				for(int j=0;j<sr[u].size();j++)
				{
					ans1.push_back(sr[u][j]);
					ans2.push_back(sr[i][j]);
				}
				for(int j=0;j<(1<<i);j++)
				{
					int x=sr[i][j];
					sr[i].pop_back();
					sr[u].push_back(x);
				}
			}
		}
		//printf("%d\n",sr[u].size());
	}
	printf("%d\n",(int)ans1.size());
	for(int i=0;i<ans1.size();i++)printf("%d %d\n",ans1[i],ans2[i]);
	return 0;
}
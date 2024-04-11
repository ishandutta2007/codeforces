#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,p[N];

char s[N];

vector<int>v[4];

int c[N],t[N];

int query(int x)
{
	int ret=0;
	while(x<=n)
	{
		ret+=c[x];
		x+=x&-x;
	}
	return ret;
}

void add(int x,int v)
{
	while(x)
	{
		c[x]+=v;
		x-=x&-x;
	}
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=0;i<4;i++)
			v[i].clear();
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='A')
				v[0].push_back(i);
			if(s[i]=='T')
				v[1].push_back(i);
			if(s[i]=='O')
				v[2].push_back(i);
			if(s[i]=='N')
				v[3].push_back(i);
		}
		for(int i=0;i<4;i++)
			p[i]=i,t[i]=i;
		long long ans=0;
		do
		{
			long long tot=0;
			for(int j=1;j<=n;j++)
				c[j]=0;
			for(int i=0;i<4;i++)
			{
				for(auto x:v[p[i]])
					tot+=query(x),add(x,1);
			}
			if(tot>ans)
			{
				for(int j=0;j<4;j++)
					t[j]=p[j];
				ans=tot;
			}
		}while(next_permutation(p,p+4));
		// printf("%d\n",ans);
		for(int i=0;i<4;i++)
			for(auto x:v[t[i]])
				putchar(s[x]);
		puts("");
	}
	
}
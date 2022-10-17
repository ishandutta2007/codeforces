#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

int T;

int n,m,ans[N],pos[N];

stack<int>st[2];

pii a[N],b[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i].fs),ans[i]=-1;
		for(int i=1;i<=n;i++)
		{
			char ch[2];
			scanf("%s",ch);
			if(ch[0]=='L')
				a[i].sd=-1;
			else
				a[i].sd=1;
		}
		for(int i=1;i<=n;i++)
			b[i]=a[i];
		while(!st[0].empty())
			st[0].pop();
		while(!st[1].empty())
			st[1].pop();
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			pos[lower_bound(a+1,a+n+1,b[i])-a]=i;
		for(int i=1;i<=n;i++)
		{
			int p=a[i].fs&1;
			if(a[i].sd==-1)
			{
				if(st[p].empty())
					st[p].push(i);
				else
				{
					int j=st[p].top();
					st[p].pop();
					ans[pos[i]]=ans[pos[j]]=(a[i].fs-a[j].fs*a[j].sd)/2;
				}
			}
			else
				st[p].push(i);
		}
		for(int p=0;p<2;p++)
		{
			while(st[p].size()>=2)
			{
				int i=st[p].top();
				st[p].pop();
				int j=st[p].top();
				st[p].pop();
				ans[pos[i]]=ans[pos[j]]=(2*m-a[i].fs-a[j].fs*a[j].sd)/2;
			}
		}
		for(int i=1;i<=n;i++)
			printf("%d%c",ans[i]," \n"[i==n]);
	}
}
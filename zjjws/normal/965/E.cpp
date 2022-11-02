#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAX=1e5+3;
struct milk
{
	char x;
	int s;//deep
	int f;
	int to[26];
	milk(){x=s=0;memset(to,0,sizeof(to));}
}t[MAX];
priority_queue<int,vector<int>,less<int> >q[MAX];
string a;
int n,m;
int n_s;
LL ans=0;
inline void dfs(int x)
{
	
	for(int i=0;i<26;i++)
	if(t[x].to[i]>0)
	{
		int y=t[x].to[i];
		dfs(y);
		for(;!q[y].empty();q[y].pop())q[x].push(q[y].top());
	}
	if(t[x].f==1)q[x].push(t[x].s);
	else 
	if(x!=0)
	{
	if(!q[x].empty())q[x].pop();
	q[x].push(t[x].s);
	}
	if(x==0)
	{
		for(;!q[x].empty();q[x].pop())ans+=q[x].top();
	}
	return;
}
LL rin()
{
	LL s=0;
	char c=getchar();
	bool bj=0;
	for(;(c>'9'||c<'0')&&c!='-';c=getchar());
	if(c=='-')bj=true,c=getchar();
	for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
	if(bj)return -s;
	return s;
}
int main() 
{
    int i,j;
    n=rin();
    t[0].s=0;
	n_s=0;
    for(i=1;i<=n;i++)
	{
		cin>>a;
		m=a.size();
		int now_x=0;
		for(j=0;j<m;j++)
		{
			if(t[now_x].to[a[j]-'a']==0)
			{
				for(;j<m;j++)
				{
					t[++n_s].x=a[j];
					t[n_s].f=0;
					t[n_s].s=t[now_x].s+1;
					t[now_x].to[a[j]-'a']=n_s;
					now_x=n_s;
				}
				t[n_s].f=1;
			}
			else
			{
				now_x=t[now_x].to[a[j]-'a'];
				if(j==m-1)t[now_x].f=1;
			}
		}
	}
    dfs(0);
    printf("%lld",ans);
	return 0;
}